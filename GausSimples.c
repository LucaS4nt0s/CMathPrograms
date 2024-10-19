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
        for (int i = 0; i < ordem - 1; i++)
        {
            for (int k = i; k < ordem - 1; k++)
            {
                m = (coeficientes[k + 1][i] * (-1)) / coeficientes[i][i];
                // arrumar vetor de termos independentes
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