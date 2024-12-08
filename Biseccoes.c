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
    float primeiro, segundo;
    int sair = 0;
    int opcao;
    int podeSair = 0;
    int iteracoes = 0;
    int maiorQueZero1 = 0;
    int maiorQueZero2 = 0;
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

    while (podeSair == 0)
    {
        printf("Digite os valores iniciais: \n");
        printf("Digite o numero 1: \n");
        scanf("%f", &chute1);
        printf("Digite o numero 2: \n");
        scanf("%f", &chute2);

        switch (opcao)
        {
        case 1:

            primeiro = funcao1(chute1);
            segundo = funcao1(chute2);

            if (primeiro > 0)
            {
                maiorQueZero1 = 1;
            }
            else if (primeiro < 0)
            {
                maiorQueZero1 = 0;
            }

            if (segundo > 0)
            {
                maiorQueZero2 = 1;
            }
            else if (segundo < 0)
            {
                maiorQueZero2 = 0;
            }

            if ((maiorQueZero1 != maiorQueZero2) || (primeiro == 0) || (segundo == 0))
            {
                podeSair = 1;
            }
            else
            {
                printf("Conjunto de valores invalido\n");
                podeSair = 0;
            }

            break;
        case 2:

            primeiro = funcao2(chute1);
            segundo = funcao2(chute2);

            if (primeiro > 0)
            {
                maiorQueZero1 = 1;
            }
            else if (primeiro < 0)
            {
                maiorQueZero1 = 0;
            }

            if (segundo > 0)
            {
                maiorQueZero2 = 1;
            }
            else if (segundo < 0)
            {
                maiorQueZero2 = 0;
            }

            if ((maiorQueZero1 != maiorQueZero2) || (primeiro == 0) || (segundo == 0))
            {
                podeSair = 1;
            }
            else
            {
                printf("Conjunto de valores invalido\n");
                podeSair = 0;
            }

            break;
        case 3:

            primeiro = funcao3(chute1);
            segundo = funcao3(chute2);

            if (primeiro > 0)
            {
                maiorQueZero1 = 1;
            }
            else if (primeiro < 0)
            {
                maiorQueZero1 = 0;
            }

            if (segundo > 0)
            {
                maiorQueZero2 = 1;
            }
            else if (segundo < 0)
            {
                maiorQueZero2 = 0;
            }

            if ((maiorQueZero1 != maiorQueZero2) || (primeiro == 0) || (segundo == 0))
            {
                podeSair = 1;
            }
            else
            {
                printf("Conjunto de valores invalido\n");
                podeSair = 0;
            }

            break;
        case 4:

            primeiro = funcao4(chute1);
            segundo = funcao4(chute2);

            if (primeiro > 0)
            {
                maiorQueZero1 = 1;
            }
            else if (primeiro < 0)
            {
                maiorQueZero1 = 0;
            }

            if (segundo > 0)
            {
                maiorQueZero2 = 1;
            }
            else if (segundo < 0)
            {
                maiorQueZero2 = 0;
            }

            if ((maiorQueZero1 != maiorQueZero2) || (primeiro == 0) || (segundo == 0))
            {
                podeSair = 1;
            }
            else
            {
                printf("Conjunto de valores invalido\n");
                podeSair = 0;
            }

            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }

    if ((primeiro == 0) || (segundo == 0))
    {
        printf("A raiz e: %f\n", primeiro == 0 ? chute1 : chute2);
    }
    else
    {
        printf("Quantas iteracoes deseja fazer?\n");
        scanf("%d", &iteracoes);

        while (iteracoes > 0)
        {
            switch (opcao)
            {
            case 1:
                x = (chute1 + chute2) / 2;
                printf("Iteracao %d\n", contador++);
                printf("A raiz esta entre %f e %f\n", chute1, chute2);
                printf("O valor de f(x) e: %f\n", opcao == 1 ? funcao1(x) : opcao == 2 ? funcao2(x)
                                                                        : opcao == 3   ? funcao3(x)
                                                                                       : funcao4(x));
                if (fabs(funcao1(x)) <= 0.0001)
                {
                    printf("=====================================\n");
                    printf("A raiz eh aproximadamente: %f\n", x);
                    printf("=====================================\n");
                    iteracoes = 0;
                }
                if (funcao1(x) * funcao1(chute1) < 0)
                {
                    chute2 = x;
                }
                else
                {
                    chute1 = x;
                }
                break;
            case 2:
                x = (chute1 + chute2) / 2;
                printf("Iteracao %d\n", contador++);
                printf("A raiz esta entre %f e %f\n", chute1, chute2);
                printf("O valor de f(x) e: %f\n", opcao == 1 ? funcao1(x) : opcao == 2 ? funcao2(x)
                                                                        : opcao == 3   ? funcao3(x)
                                                                                       : funcao4(x));
                if (fabs(funcao2(x)) <= 0.0001)
                {
                    printf("=====================================\n");
                    printf("A raiz eh aproximadamente: %f\n", x);
                    printf("=====================================\n");
                    iteracoes = 0;
                }
                if (funcao2(x) * funcao2(chute1) < 0)
                {
                    chute2 = x;
                }
                else
                {
                    chute1 = x;
                }
                break;
            case 3:
                x = (chute1 + chute2) / 2;
                printf("Iteracao %d\n", contador++);
                printf("A raiz esta entre %f e %f\n", chute1, chute2);
                printf("O valor de f(x) e: %f\n", opcao == 1 ? funcao1(x) : opcao == 2 ? funcao2(x)
                                                                        : opcao == 3   ? funcao3(x)
                                                                                       : funcao4(x));
                if (fabs(funcao3(x)) <= 0.0001)
                {
                    printf("=====================================\n");
                    printf("A raiz eh aproximadamente: %f\n", x);
                    printf("=====================================\n");
                    iteracoes = 0;
                }
                if (funcao3(x) * funcao3(chute1) < 0)
                {
                    chute2 = x;
                }
                else
                {
                    chute1 = x;
                }
                break;
            case 4:
                x = (chute1 + chute2) / 2;
                printf("Iteracao %d\n", contador++);
                printf("A raiz esta entre %f e %f\n", chute1, chute2);
                printf("O valor de f(x) e: %f\n", opcao == 1 ? funcao1(x) : opcao == 2 ? funcao2(x)
                                                                        : opcao == 3   ? funcao3(x)
                                                                                       : funcao4(x));
                if (fabs(funcao4(x)) <= 0.0001)
                {
                    printf("=====================================\n");
                    printf("A raiz eh aproximadamente: %f\n", x);
                    printf("=====================================\n");
                    iteracoes = 0;
                }
                if (funcao4(x) * funcao4(chute1) < 0)
                {
                    chute2 = x;
                }
                else
                {
                    chute1 = x;
                }
                break;
            default:
                printf("Opcao invalida\n");
                break;
            }
            iteracoes--;
        }
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
