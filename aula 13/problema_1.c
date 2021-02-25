/*
Nome: Arthur Antonio Soutelo Araujo
Cartao UFRGS: 00304292
*/

#include <stdio.h>
#define NUMBAIRROS 80
typedef struct{
    char nome[50];
    int area;
    int populacao;
    float densidade;
}bairro_t;

void exibe_bairros(int n, bairro_t *bairros);
void ordena_bairros_populacao_crescente(bairro_t *bairros);
void ordena_bairros_densidade_decrescente(bairro_t *bairros);
#define POP 10
#define DENS 5

int main(){
    FILE *arquivo;
    bairro_t bairros[NUMBAIRROS];

    arquivo = fopen ("bairrosPOA.bin", "rb");
    fread(bairros, sizeof(bairro_t), NUMBAIRROS, arquivo);
    fclose(arquivo);


    ordena_bairros_populacao_crescente(bairros);
    printf("Bairros de Porto Alegre \n\n");
    printf("\n%d bairros menos populosos:\n\n", POP);
    exibe_bairros(POP, bairros);

    ordena_bairros_densidade_decrescente(bairros);
    printf("\n\n%d bairros mais densamente povoados: \n\n", DENS);
    exibe_bairros(DENS, bairros);

    return 0;
}

void ordena_bairros_populacao_crescente(bairro_t *bairros){
    int i, tamanho = NUMBAIRROS-1;
    int sinal;
    bairro_t aux={0};

    do{
        sinal = 0;
        for(i=0; i < tamanho; i++){
            if(bairros[i].populacao > bairros[i+1].populacao){
                aux = bairros[i];
                bairros[i] = bairros[i+1];
                bairros[i+1] = aux;
                sinal = 1;
            }
        }
    }while(sinal == 1);

    return;
}

void ordena_bairros_densidade_decrescente(bairro_t *bairros){
    int i, tamanho = NUMBAIRROS-1;
    int sinal;
    bairro_t aux={0};

    do{
        sinal = 0;
        for(i=0; i < tamanho; i++){
            if(bairros[i].densidade < bairros[i+1].densidade){
                aux = bairros[i];
                bairros[i] = bairros[i+1];
                bairros[i+1] = aux;
                sinal = 1;
            }
        }
    }while(sinal == 1);

    return;
}

void exibe_bairros(int n, bairro_t *bairros){
    int i;
    printf("Area    |   Pop.    |   Densidade   |   Nome \n\n");
    for (i=0; i < n; i++){
        printf("%8d | %8d | %f | %s \n", bairros[i].area, bairros[i].populacao, bairros[i].densidade, bairros[i].nome);
    }

    return;
}
