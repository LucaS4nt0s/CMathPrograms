#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int ordem;

    printf("Digite a ordem da matriz: \n");
    scanf("%d", &ordem);

    float coeficientes[ordem][ordem];
    float termosInd[ordem];
    float bLinha[ordem];
    float conta = 0;
    float erro = 0;
    float auxX = 0;
    int iteracoes = 0;
    float x[ordem];
    float xAnt[ordem];

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

    for (int i = 0; i < ordem; i++)
    {
        printf("Digite o chute inicial %d: \n", i + 1);
        scanf("%f", &x[i]);
        xAnt[i] = x[i];
    }

    printf("Quantas iteracoes deseja fazer? \n");
    scanf("%d", &iteracoes);

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            conta = conta + coeficientes[i][j] * x[i];
        }
        bLinha[i] = conta;
    }

    for (int i = 0; i < ordem; i++)
    {
        erro = erro + ((termosInd[i] - bLinha[i]) * (termosInd[i] - bLinha[i]));
    }
    
    erro = sqrt(erro);
    printf("\n================\n");
    printf("Erro = %.5f\n", erro);
    
    for (int chutes = 0; chutes < iteracoes; chutes++)
    {
        erro = 0;
        conta = 0;
        for (int i = 0; i < ordem; i++)
        {
            auxX = 0;
            for (int j = 0; j < ordem; j++)
            {
                if (i != j){
                    auxX = auxX + (coeficientes[i][j] * xAnt[j]);
                }
            }
            x[i] = (termosInd[i] - auxX) / coeficientes[i][i];
        }

        for (int i = 0; i < ordem; i++)
        {   
            xAnt[i] = x[i];
            for (int j = 0; j < ordem; j++)
            {
                conta = conta + coeficientes[i][j] * x[j];
            }
            bLinha[i] = conta;
            conta = 0;
        }
        
        for (int i = 0; i < ordem; i++)
        {
            erro = erro + ((termosInd[i] - bLinha[i]) * (termosInd[i] - bLinha[i]));
        }
        
        erro = sqrt(erro);

        printf("\n================\n");
        printf("Iteracao %d\n", chutes + 1);
        for (int i = 0; i < ordem; i++)
        {
            printf("bLinha %d = %.2f\n", i + 1, bLinha[i]);
        }
        printf("Erro = %.5f\n", erro);


        for (int i = 0; i < ordem; i++)
        {
            printf("X%d = %.2f\n", i + 1, x[i]);
        }
        printf("\n================\n");
        
    }    
    
    return 0;
}