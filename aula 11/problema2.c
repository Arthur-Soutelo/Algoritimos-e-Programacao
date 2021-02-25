//Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#include <math.h>


double harmonica(int termos){
    int i;
    double soma=0;

    printf("\nSerie: ");
    for (i=1; i < termos; i++){
        soma += 1./i;
        printf("1/%d + ",i);
    }
    return soma;
}
double harmonica_alternada(int termos){
    int i;
    double soma=0;

    printf("\nSerie: ");
    for (i=1; i < termos; i++){
        soma += pow(-1, i+1)/(float)i;
        if(i%2)
            printf("1/%d + ", i);
        else
            printf("-1/%d + ", i);
    }
    return soma;
}
double geometrica(int termos){
    int i;
    int pot;
    double soma=0;

    printf("\nSerie: ");
    for (i=1; i < termos; i++){
        soma += pow(1/2, i);
        pot = pow(2,i);
        printf("1/%d + ", pot);
    }
    return soma;
}
double geometrica_alternada(int termos){
    int i;
    int pot;
    double soma=0;

    printf("\nSerie: ");
    for (i=1; i < termos; i++){
        soma += pow(-1, i+1)/pow(2, i);
        pot = pow(2,i);
        if(i%2)
            printf("1/%d + ", pot);
        else
            printf("-1/%d + ", pot);
    }
   return soma;
}
int main (){
    int termos;
    char entrada;
    int saida = 0;
    double soma;

    do{
        printf("**************************************************");
        printf("\nPrograma gerador de series:\nH)Serie Harmonica\nA)Serie Harmonica Alternada\nG)Serie Geometrica\nT)Serie Geometrica Alternada\nS)Sair\n");
        scanf(" %c", &entrada);
        if(entrada != 's'){
            printf("Informe o numero de termos a ser usado: ");
            scanf("%d", &termos);
        }

        switch (entrada){
        case 'h':
            soma = harmonica(termos);
            printf("\nValor aproximado calculado: %f", soma);
            break;
        case 'a':
            soma = harmonica_alternada(termos);
            printf("\nValor aproximado calculado: %f", soma);
            break;
        case 'g':
            soma = geometrica(termos);
            printf("\nValor aproximado calculado: %f", soma);
            break;
        case 't':
            soma = geometrica_alternada(termos);
            printf("\nValor aproximado calculado: %f", soma);
            break;
        case 's':
            saida = 1;
            break;
        default:
            printf("Comando Invalido");
        }
        printf("\n");
    }while (saida == 0);

    return 0;
}
