/*
Nome: Arthur Antonio Soutelo Araujo
Cartao UFRGS: 00304292
*/
#include <stdio.h>
#include <string.h>
#define TAM 5000

void imprev(char txt[], int tam);

int main(){
    char txt[TAM];
    printf("Informe um texto: \n\t");
    fgets(txt, TAM, stdin);
    txt[strlen(txt)-1] = '\0';
    printf("Inverso: \n\n");
    imprev(txt, strlen(txt));
    return 0;
}

void imprev(char txt[], int tam){
    if(tam == 1){
        printf("%c", txt[tam-1]);
        return;
    }
    else{
        printf("%c", txt[tam-1]);
        imprev(txt, tam-1);
        return;
    }
}
