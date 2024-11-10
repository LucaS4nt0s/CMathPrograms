#include <stdio.h>
#include <stdlib.h>

int main()
{

    int ordem;

    printf("Digite a ordem da matriz: \n");
    scanf("%d", &ordem);

    float coeficientes[ordem][ordem];
    float termosInd[ordem];
    float resultado[ordem];

    float m;

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
        for (int i = 0; i < ordem; i++)
        {
            for (int k = 0; k < ordem; k++)
            {   
                if(k != i){ 
                    m = (coeficientes[k][i] * (-1)) / coeficientes[i][i];
                    termosInd[k] = (m * termosInd[i]) + termosInd[k];
                    for (int j = 0; j < ordem; j++)
                    {
                        coeficientes[k][j] = (m * coeficientes[i][j]) + coeficientes[k][j];
                    }
                }
            }
        }
    }

    printf("\nMatriz equivalente dos coeficientes:\n");
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
        printf("| %.3f |\n", termosInd[i]);
    }

    printf("Matriz dos resultados: \n");
    for (int i = 0; i < ordem; i++)
    {
        resultado[i] = termosInd[i] / coeficientes[i][i];
        printf("| %.3f |\n", resultado[i]);
    }

    return 0;
}