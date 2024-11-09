#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int ordem;

    printf("Digite a ordem da matriz: \n");
    scanf("%d", &ordem);

    float coeficientes[ordem][ordem];
    float termosInd[ordem];
    float resultado[ordem];
    float m;
    int maiorL = 0;
    int maiorC = 0;
    float aux;
    float auxC;

    // DIGITAR A MATRIZ
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            printf("Digite o coeficiente A%d%d: \n", i + 1, j + 1);
            scanf("%f", &coeficientes[i][j]);
        }
    }

    // DIGITAR O VETOR DOS TERMOS INDEPENDENTES
    for (int i = 0; i < ordem; i++)
    {
        printf("Digite o termo independente %d: \n", i + 1);
        scanf("%f", &termosInd[i]);
    }

    // IMPRIMIR A MATRIZ DOS COEFICIENTES SEM ALTERACAO
    printf("\nMatriz dos coeficientes:\n");
    for (int i = 0; i < ordem; i++)
    {
        printf("|");
        for (int j = 0; j < ordem; j++)
        {
            printf(" %.2f ", coeficientes[i][j]);
        }
        printf("|\n");
    }


    // IMPRIMIR O VETOR DOS TERMOS INDEPENDENTES SEM ALTERACAO
    printf("\nVetor dos termos independentes:\n");
    for (int i = 0; i < ordem; i++)
    {
        printf("| %.2f |\n", termosInd[i]);
    }

    // ALTERAR A MATRIZ PARA DEIXA-LA TRIANGULAR
    if (ordem >= 2)
    {   

        // FOR PRINCIPAL
        for (int i = 0; i < ordem - 1; i++)
        {   
            maiorL = i;
            maiorC = i;

            // UM FOR DENTRO DO OUTRO PARA DESCOBRIR O MAIOR VALOR
            for (int n = i; n < ordem; n++)
            {   
                for (int column = i; column < ordem; column++)
                {
                    if (fabs(coeficientes[n][column]) >= fabs(coeficientes[maiorL][maiorC])){
                        maiorL = n;
                        maiorC = column;
                    }
                }
                
            }

            // TROCAR AS COLUNAS DE LUGAR DE TODAS AS LINHAS
            if (maiorC != i)
            {
                for (int trocaColunas = 0; trocaColunas < ordem; trocaColunas++)
                {
                    auxC = coeficientes[trocaColunas][i];
                    coeficientes[trocaColunas][i] = coeficientes[trocaColunas][maiorC];
                    coeficientes[trocaColunas][maiorC] = auxC;
                }
                
            }
            
            // TROCAR A LINHA DO MAIOR COM A PRIMEIRA CASO NECESSARIO
            if (maiorL != i)
            {
                for (int l = 0; l < ordem; l++)
                {
                    aux = coeficientes[maiorL][l];
                    coeficientes[maiorL][l] = coeficientes[i][l];
                    coeficientes[i][l] = aux;
                }
                aux = termosInd[maiorL];
                termosInd[maiorL] = termosInd[i];
                termosInd[i] = aux;
            }

            if (coeficientes[i][i] == 0)
            {
                printf("Erro: sistema sem solucao ou indeterminado.\n");
                return -1;
            }
                
            
            // FOR PARA TRIANGULIZAR A MATRIZ    
            for (int k = i; k < ordem - 1; k++)
            {
                m = (coeficientes[k + 1][i] * (-1)) / coeficientes[i][i];
                termosInd[k + 1] = (m * termosInd[i]) + termosInd[k + 1];
                for (int j = 0; j < ordem; j++)
                {
                    coeficientes[k + 1][j] = (m * coeficientes[i][j]) + coeficientes[k + 1][j];
                }
            }
        }
    }

    // IMPRIMIR A MATRIZ TRIANGULAR EQUIVALENTE
    printf("\nMatriz triangular equivalente dos coeficientes:\n");
    for (int i = 0; i < ordem; i++)
    {
        printf("|");
        for (int j = 0; j < ordem; j++)
        {
            printf(" %.2f ", coeficientes[i][j]);
        }
        printf("|\n");
    }

    // IMPRIMIR O VETOR EQUIVALENTE DOS TERMOS INDEPENDENTES 
    printf("\nVetor equivalente dos termos independentes da matriz triangular:\n");
    for (int i = 0; i < ordem; i++)
    {
        printf("| %.2f |\n", termosInd[i]);
    }

    // RESOLVER A MATRIZ TRIANGULAR EQUIVALENTE
    for (int i = ordem - 1; i >= 0; i--)
    {   
        resultado[i] = termosInd[i];
        for (int j = i + 1; j < ordem; j++)
        {
            resultado[i] = resultado[i] - (coeficientes[i][j] * resultado[j]);
        }
        resultado[i] = resultado[i] / coeficientes[i][i]; 
    }

    // IMPRIMIR A MATRIZ DOS RESULTADOS
    printf("Matriz dos resultados: \n");

    for (int i = 0; i < ordem; i++)
    {
        printf("| %.4f |\n", resultado[i]);
    }

    return 0;
}