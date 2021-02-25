// Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>

int main()
{
    int v = 0;
    int i, j;

    i = 1;
    j = 1;

    while (v < 1)
        {
        printf ("Informe um valor inteiro e positivo:\n");
        scanf ("%d", &v);
        }
//------------------------------------------------------------------
    while (i < v)
    {
        while( j < v)
        {
            if( j == i)
            {
                printf("1 ");
                j++;
            }
            else
            {
                printf("0 ");
                j++;
            }
        }
        printf("\n");
        i++;
        j = 1;
    }

    return 0;
}
