//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

int main()
{
    int l, c;
    int i, j;

    do
    {
    printf("Informe o numero de linhas para a matriz:\n");
    scanf("%d", &l);
    printf("Informe o numero de colunas para a matriz:\n");
    scanf("%d", &c);
    }
    while (l<2 && c<2);

    float matriz[l][c];
    float m[l];
    for (int i=0; i<l; i++)
        m[i]= FLT_MAX;

    for (i=0; i < l; i++)
    {
        for (j=0; j < c; j++)
        {
            matriz[i][j] = (rand()%1000)+1;
        }
    }
    for (i=0; i < l; i++)
    {
        for (j=0; j < c; j++)
        {
            if (matriz[i][j] < m[i])
                m[i] = matriz [i][j];
        }
    }
    for (i=0; i < l; i++)
    {
        for (j=0; j < c; j++)
        {
            (matriz[i][j] /= m[i]);
                m[i] = matriz [i][j];
        }
    }
    printf("Matriz preenchida:\n\n");
    printf("%.3f", matriz);

    return 0;
}
