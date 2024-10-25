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
    int maior = 0;
    float aux;

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            printf("Digite o coeficiente A%d%d: \n", i + 1, j + 1);
            scanf("%f", &coeficientes[i][j]);
        }
    }

    for (int i = 0; i < ordem; i++)
    {
        printf("Digite o termo independente %d: \n", i + 1);
        scanf("%f", &termosInd[i]);
    }

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

    printf("\nVetor dos termos independentes:\n");
    for (int i = 0; i < ordem; i++)
    {
        printf("| %.2f |\n", termosInd[i]);
    }

    if (ordem >= 2)
    {
        for (int i = 0; i < ordem - 1; i++)
        {   
            maior = i;
            for (int n = i + 1; n < ordem; n++)
            {
                if (fabs(coeficientes[n][i]) > fabs(coeficientes[maior][i]))
                    maior = n;
            }
            if (maior != i)
            {
                for (int l = 0; l < ordem; l++)
                {
                    aux = coeficientes[maior][l];
                    coeficientes[maior][l] = coeficientes[i][l];
                    coeficientes[i][l] = aux;
                }
                aux = termosInd[maior];
                termosInd[maior] = termosInd[i];
                termosInd[i] = aux;
            }

            if (coeficientes[i][i] == 0)
            {
                printf("Erro: sistema sem solucao ou indeterminado.\n");
                return -1;
            }
                
                
            
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

    printf("\nVetor equivalente dos termos independentes da matriz triangular:\n");
    for (int i = 0; i < ordem; i++)
    {
        printf("| %.2f |\n", termosInd[i]);
    }

    for (int i = ordem - 1; i >= 0; i--)
    {   
        resultado[i] = termosInd[i];
        for (int j = i + 1; j < ordem; j++)
        {
            resultado[i] = resultado[i] - (coeficientes[i][j] * resultado[j]);
        }
        resultado[i] = resultado[i] / coeficientes[i][i]; 
    }

    printf("Matriz dos resultados: \n");

    for (int i = 0; i < ordem; i++)
    {
        printf("| %.4f |\n", resultado[i]);
    }

    return 0;
}