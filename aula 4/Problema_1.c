//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

//Problema que informa quantos numeros positivos e negativos foram inseridos

#include <stdio.h>

int main()
{
    int positivo, negativo, num, i, qualquer;

    printf("Insira um nomero inteiro positivo:\n");
    scanf("%d", &num);

    positivo = 0;
    negativo = 0;

    for (i = 0; i < num; i ++)
    {
        printf("Insira um valor inteiro qualquer:\n");
        scanf("%d", &qualquer);
        if (qualquer < 0)
            negativo ++;
        else
            positivo ++;

    }
    printf("Foram lidos %d numeros positivos e %d numeros negativos\n", positivo, negativo);

    return 0;
}
