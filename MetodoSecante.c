#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float funcao1(float x);
float funcao2(float x);
float funcao3(float x);
float funcao4(float x);

int main()
{

    float x;
    float chute1, chute2;
    int sair = 0;
    int opcao;
    int iteracoes = 0;
    int contador = 1;

    while (sair == 0)
    {
        printf("Escolha a funcao: \n");
        printf("Digite 1 para F1(x) = e^x - sen(x) - 2\n");
        printf("Digite 2 para F2(x) = x^2 - cos(x)\n");
        printf("Digite 3 para F3(x) = x - 2sen(x) - 1\n");
        printf("Digite 4 para F4(x) = x^2 - 5\n");
        scanf("%d", &opcao);

        if ((opcao < 1) || (opcao > 4))
        {
            printf("Opcao invalida\n");
        }
        else
        {
            sair = 1;
        }
    }

    printf("Digite os valores iniciais: \n");
    printf("Digite o numero 1: \n");
    scanf("%f", &chute1);
    printf("Digite o numero 2: \n");
    scanf("%f", &chute2);
    
    printf("Quantas iteracoes deseja fazer?\n");
    scanf("%d", &iteracoes);

    while (iteracoes > 0)
    {

        switch (opcao)
        {
        case 1:
            x = ((chute1 * (funcao1(chute2))) - (chute2 * (funcao1(chute1))))/ (funcao1(chute2) - funcao1(chute1));
            printf("Iteracao %d\n", contador++);
            printf("A = %f\n", chute1);
            printf("B = %f\n", chute2);
            printf("A raiz e aproximadamente %f\n", x);
            printf("O valor de f(x) e: %f\n", funcao1(x));
            if (fabs(funcao1(x)) <= 0.0001)
            {
                printf("=====================================\n");
                printf("A raiz eh aproximadamente: %f\n", x);
                printf("=====================================\n");
                iteracoes = 0;
            }
      
            chute1 = chute2;
            chute2 = x;

            break;
        case 2:
            x = ((chute1 * (funcao2(chute2))) - (chute2 * (funcao2(chute1))))/ (funcao2(chute2) - funcao2(chute1));
            printf("Iteracao %d\n", contador++);
            printf("A = %f\n", chute1);
            printf("B = %f\n", chute2);
            printf("A raiz e aproximadamente %f\n", x);
            printf("O valor de f(x) e: %f\n", funcao2(x));
            if (fabs(funcao2(x)) <= 0.0001)
            {
                printf("=====================================\n");
                printf("A raiz eh aproximadamente: %f\n", x);
                printf("=====================================\n");
                iteracoes = 0;
            }

            chute1 = chute2;
            chute2 = x;

            break;

        case 3:
            x = ((chute1 * (funcao3(chute2))) - (chute2 * (funcao3(chute1))))/ (funcao3(chute2) - funcao3(chute1));
            printf("Iteracao %d\n", contador++);
            printf("A = %f\n", chute1);
            printf("B = %f\n", chute2);
            printf("A raiz e aproximadamente %f\n", x);
            printf("O valor de f(x) e: %f\n", funcao3(x));
            if (fabs(funcao3(x)) <= 0.0001)
            {
                printf("=====================================\n");
                printf("A raiz eh aproximadamente: %f\n", x);
                printf("=====================================\n");
                iteracoes = 0;
            }

            chute1 = chute2;
            chute2 = x;

            break;
        case 4:
            x = ((chute1 * (funcao4(chute2))) - (chute2 * (funcao4(chute1))))/ (funcao4(chute2) - funcao4(chute1));
            printf("Iteracao %d\n", contador++);
            printf("A = %f\n", chute1);
            printf("B = %f\n", chute2);
            printf("A raiz e aproximadamente %f\n", x);
            printf("O valor de f(x) e: %f\n", funcao4(x));
            if (fabs(funcao4(x)) <= 0.0001)
            {
                printf("=====================================\n");
                printf("A raiz eh aproximadamente: %f\n", x);
                printf("=====================================\n");
                iteracoes = 0;
            }
            
            chute1 = chute2;
            chute2 = x;

            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
        iteracoes--;
    }
    return 0;
}



float funcao1(float x)
{
    return exp(x) - sin(x) - 2;
}

float funcao2(float x)
{
    return (x * x) - cos(x);
}

float funcao3(float x)
{
    return x - (2 * sin(x)) - 1;
}

float funcao4(float x)
{
    return (x * x) - 5;
}
