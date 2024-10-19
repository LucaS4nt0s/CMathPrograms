#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int ordem;

    printf("Digite a ordem da matriz: \n");
    scanf("%d", &ordem);

    float coeficientes[ordem][ordem];
    float termosInd[ordem];
    float resultado[ordem];
    // float temp = 0;

    // Recebe matriz triangular, preenchendo com 0 nas partes necessarias ja

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (j < i)
            {
                coeficientes[i][j] = 0;
            }
            else
            {
                printf("Digite o coeficiente A%d%d: \n", i + 1, j + 1);
                scanf("%f", &coeficientes[i][j]);
            }
        }
    }

    // print da matriz de coeficientes

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

    // criação de vetor com os termos independentes

    for (int i = 0; i < ordem; i++)
    {
        printf("Digite o termo independente %d: \n", i + 1);
        scanf("%f", &termosInd[i]);
    }
    printf("\nVetor dos termos independentes:\n");

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