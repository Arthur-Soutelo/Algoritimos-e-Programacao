/*
Nome: Arthur Antonio Soutelo Araujo
Cartao UFRGS: 00304292
*/
#include <stdio.h>
/* Calcula numero de movimentos minimos torre de Hanói */
int hanoiMin(int n);

int main(){
    int entrada;
    int movimentos;
    do{
        printf("Informe o numero de discos presentes na torre: ");
        scanf("%d", &entrada);
    }while(entrada < 1);
    movimentos = hanoiMin(entrada);
    printf("\n\tO numero minimo de movimentos necessarios eh: %d \n", movimentos);

    return 0;
}

int hanoiMin(int n){
    if(n == 1){
        return 1;
    }
    else{
        return (2*hanoiMin(n-1))+1;
    }
}
