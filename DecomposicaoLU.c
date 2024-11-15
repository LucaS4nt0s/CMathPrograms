#include <stdio.h>
#include <stdlib.h>

int main()
{

    int ordem; 
    int contador = 0;

    printf("Digite a ordem da matriz: \n");
    scanf("%d", &ordem);

    float coeficientes[ordem][ordem];
    float termosInd[ordem];
    float resultado[ordem];
    float matrizL[ordem][ordem];
    float vetorY[ordem];

    float m;

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            printf("Digite o coeficiente A%d%d: \n", i + 1, j + 1);
            scanf("%f", &coeficientes[i][j]);
        }
    }

    // inicia o vetor L com valores 1 na diagonal principal e 0 na parte de cima da matriz
    for (int i = 0; i < ordem; i++)
    {
        matrizL[i][i] = 1;
        for (int j = 0; j < ordem; j++)
        {
            if(j > i){
                matrizL[i][j] = 0;
            }
        }
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

    if (ordem >= 2)
    {
        for (int i = 0; i < ordem - 1; i++)
        {
            for (int k = i; k < ordem - 1; k++)
            {
                m = (coeficientes[k + 1][i] * (-1)) / coeficientes[i][i];
                matrizL[k+1][i] = -m;
                for (int j = 0; j < ordem; j++)
                {
                    coeficientes[k + 1][j] = (m * coeficientes[i][j]) + coeficientes[k + 1][j];
                }
            }
        }
    }
    
    printf("\nMatriz L: \n");
    for (int i = 0; i < ordem; i++)
    {
        printf("| ");
        for (int j = 0; j < ordem; j++)
        {
            printf("%.1f ", matrizL[i][j]);   
        }
        printf(" |\n");
    }

    printf("\nMatriz triangular equivalente dos coeficientes (matriz U):\n");
    for (int i = 0; i < ordem; i++)
    {
        printf("|");
        for (int j = 0; j < ordem; j++)
        {
            printf(" %.2f ", coeficientes[i][j]);
        }
        printf("|\n");
    }

    do
    {
        for (int i = 0; i < ordem; i++)
        {
            printf("Digite o termo independente %d: \n", i + 1);
            scanf("%f", &termosInd[i]);
            vetorY[i] = termosInd[i];
        }

        printf("\nVetor dos termos independentes:\n");
        for (int i = 0; i < ordem; i++)
        {
            printf("| %.2f |\n", termosInd[i]);
        }

        for (int i = 1; i < ordem; i++)
        {   
            for (int j = 0; j < i; j++)
            {
                vetorY[i] = vetorY[i] - (matrizL[i][j] * vetorY[j]);
            }
            vetorY[i] = vetorY[i] / matrizL[i][i]; 
        }  

        printf("Vetor Y: \n");

        for (int i = 0; i < ordem; i++)
        {
            printf("| %.4f |\n", vetorY[i]);
        }

        for (int i = ordem - 1; i >= 0; i--)
        {   
            resultado[i] = vetorY[i];
            for (int j = i + 1; j < ordem; j++)
            {
                resultado[i] = resultado[i] - (coeficientes[i][j] * resultado[j]);
            }
            resultado[i] = resultado[i] / coeficientes[i][i]; 
        }
        
        printf("Resultado: \n");
        for (int i = 0; i < ordem; i++)
        {
            printf("| %.3f |\n", resultado[i]);
        }

        printf("Deseja digitar um novo conjunto de termos independentes para a matriz em questao? [0] Sim [1] Nao\n");
        scanf("%d", &contador);

    } while (contador == 0);
    
    return 0;
}