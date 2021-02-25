//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    srand(time(NULL));
    char resp;
    int matriz[10][10] = {{0}};
    int i, j;

    do
    {
        printf("Programa gerador de matriz triangular\n");
        printf("Escolha uma das opcoes a seguir:\n");
        printf("(1)Triangular Superior\n(2)Triangularinferior\n(3)Diagonal\n(4)SAIR\n");
        fflush(stdin);
        resp = getchar();
        switch (resp)
        {
        case '1':
            for (i=0; i<10; i++)
            {
                for (j=0; j<10; j++)
                {
                    if (j >= i)
                        matriz[i][j] = rand()%500;
                    else
                        matriz[i][j]=0;
                    printf(" %03d", matriz[i][j]);
                }
                printf("\n");
            }
            break;
        case '2':
            for (i=0; i<10; i++)
            {
                for (j=0; j<10; j++)
                {
                    if (j <= i)
                        matriz[i][j] = rand()%500;
                    else
                        matriz[i][j]=0;
                    printf(" %03d", matriz[i][j]);
                }
                printf("\n");
            }
            break;
        case '3':
            for (i=0; i<10; i++)
            {
                for (j=0; j<10; j++)
                {
                    if (j == i)
                        matriz[i][j] = rand()%500;
                    else
                        matriz[i][j]=0;
                    printf(" %03d", matriz[i][j]);
                }
                printf("\n");
            }
            break;
        case '4':
            return 0;
        }
    }
    while(resp != 5);

    return 0;
}
