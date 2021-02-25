//Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#include <math.h>
#define MAX 11

    char entrada;
    double soma=0;

void harmonica()
{
    int i;
    printf("\nSerie: ");
    for (i=1; i < MAX; i++){
        soma += 1./i;
        printf("1/%d + ",i);
    }
    printf("\nValor aproximado calculado: %f", soma);
}
void harmonica_alternada()
{
    int i;
    printf("\nSerie: ");
    for (i=1; i < MAX; i++){
        soma += pow(-1, i+1)/(float)i;
        if(i%2)
            printf("1/%d + ", i);
        else
            printf("-1/%d + ", i);
    }
    printf("\nValor aproximado calculado: %f", soma);
}
void geometrica()
{
    int i;
    int pot;
    printf("\nSerie: ");
    for (i=1; i < MAX; i++){
        soma += pow(1/2, i);
        pot = pow(2,i);
        printf("1/%d + ", pot);
    }
    printf("\nValor aproximado calculado: %f", soma);
}
void geometrica_alternada()
{
    int i;
    int pot;
    printf("\nSerie: ");
    for (i=1; i < MAX; i++){
        soma += pow(-1, i+1)/pow(2, i);
        pot = pow(2,i);
        if(i%2)
            printf("1/%d + ", pot);
        else
            printf("-1/%d + ", pot);
    }
    printf("\nValor aproximado calculado: %f", soma);
}
int main ()
{
    do{
        printf("\nPrograma gerador de series:\nH)Serie Harmonica\nA)Serie Harmonica Alternada\nG)Serie Geometrica\nT)Serie Geometrica Alternada\nS)Sair\n");
        scanf(" %c", &entrada);

        switch (entrada){
        case 'h':
            harmonica();
            break;
        case 'a':
            harmonica_alternada();
            break;
        case 'g':
            geometrica();
            break;
        case 't':
            geometrica_alternada();
            break;
        case 's':
            soma=-1;
            break;
        default:
            printf("Comando Invalido");
        }
    }while (soma>= 0);

    return 0;
}
