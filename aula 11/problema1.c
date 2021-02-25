//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAR 2
#define IMPAR 1
#define ELEMENTOS 15

int verificacao_par();
int intervalo();
void exibicao();
void aleatorio();
void leitura_teclado();
void contagem();
int *primeiro_elemento();


int main(){
    srand(time(NULL));
    char entrada;
    int a, b;
    int limite_inferior = 0, limite_superior = 99999;
    int v[ELEMENTOS];
    int *par, *impar;
    int total_par = 0, total_impar = 0;

    par = &total_par;
    impar = &total_impar;

    printf("Programa que encontra numeros pares no intrt\n"
           "Escolha o metodo de preenchimento:\n (A) Preenchimento Aleatorio\n (T) Preenchimento por leitura\n");
    printf("Informe sua escolha: ");
    scanf("%c", &entrada);
    entrada = tolower(entrada);

    printf("\nLimite inferior do intervalo [%d, %d] : ", limite_inferior, limite_superior);
    a = intervalo(limite_inferior, limite_superior);
    printf("\nLimite superior do intervalo [%d, %d] : ", limite_inferior, limite_superior);
    b = intervalo(limite_inferior,limite_superior);

    switch(entrada){
    case 'a':
        aleatorio(v, ELEMENTOS, a, b);
        break;
    case 't':
        leitura_teclado(v, ELEMENTOS, a, b);
        break;
    }

    contagem(v, ELEMENTOS, par, impar);
    exibicao(v, ELEMENTOS);

    return 0;
}

int verificacao_par(int num){
   int saida;
    saida = num % 2;

    return saida;
}


int intervalo(int a, int b){
    int resp;

    do{
        scanf("%d", &resp);
    }while (resp > b || resp < a);

    return resp;
}

void exibicao(int *v, int elementos){
    int i;
    for (i=0; i < elementos; i++)
        printf("%d ",v[i]);

    return;
}

void leitura_teclado(int *v, int elementos , int a, int  b){
    int i;
    for (i=0; i < elementos; i++){
        printf("Valor da posicao [%d]", i+1);
        v[i] = intervalo(a, b);
    }
   return;
}

void aleatorio(int *v, int elementos , int a, int  b){
    int i;
        for (i=0; i < elementos; i++)
            v[i] = (a + (rand()%(b-a+1)));
    return;
}

void contagem(int *v, int elementos, int *par, int *impar){
     int i;

     for (i=0; i < elementos; i++){
        if (verificacao_par(v[i]) == 0)
            *par += 1;
        else
            *impar += 1;
    }
    printf("O vetor contem %d valores pares e %d valores impares\n\n", *par, *impar);

    return;
}

int *primeiro_elemento(int *v, int elementos){
    int *saida;
    int i = 0;

    do{
        i++;
     }while(verificacao_par(v[i]) != 0);
    saida = v+i;

    return saida;
}
