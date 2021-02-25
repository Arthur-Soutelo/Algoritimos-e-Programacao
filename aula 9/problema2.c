//Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>

int main ()
{
    int n [3][3], m [3][3], resposta[3][3];
    int i, j;

    printf("Informe os valores da primeira matriz do produto:\n");
    for (i=0; i < 3; i++){
        for (j=0; j < 3; j++){
            printf("\nElemento [%d,%d]:", i+1, j+1);
            scanf("%d", &m[i][j]);
        }
    }
    printf("Informe os valores da segunda matriz do produto:\n");
    for (i=0; i < 3; i++){
        for (j=0; j < 3; j++){
            printf("\nElemento [%d,%d]:", i+1, j+1);
            scanf("%d", &n[i][j]);
        }
    }
//----------------------------------------------------------
    for (i=0; i < 3; i++){
        for (j=0; j < 3; j++){
            resposta[i][j] = (m[i][1]*n[1][j])+(m[i][2]*n[2][j])+(m[i][3]*n[3][j]);
        }
    }
//----------------------------------------------------------
    printf("Primeira matriz:\n");
    for (i=0; i < 3; i++){
        for (j=0; j < 3; j++){
            printf("%04d ", m[i][j]);
        }
    printf("\n");
    }
    printf("Segunda matriz:\n");
    for (i=0; i < 3; i++){
        for (j=0; j < 3; j++){
            printf("%04d ", n[i][j]);
        }
    printf("\n");
    }
    printf("\nMatriz produto:\n");
    for (i=0; i < 3; i++){
        for (j=0; j < 3; j++){
            printf("%04d ", resposta[i][j]);
        }
    printf("\n");
    }
    return 0;
}
