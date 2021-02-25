/*
Nome: Arthur Antonio Soutelo Araujo
Cartao UFRGS: 00304292
*/
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 100
#include <locale.h>
typedef struct{
    int id;
    char endereco[100];
    int vagas;
}parq_t;
int checa_tamanho(parq_t *vetor);
void le_arquivo(parq_t *vetor);
void divide_vetor(parq_t *vetor, parq_t *par, parq_t *impar);
void grava_arquivos(parq_t *pares, parq_t *impares);

int main(){
    parq_t vetor[TAM]={{0}};
    parq_t pares[TAM]={{0}};
    parq_t impares[TAM]={{0}};

    setlocale(LC_ALL, "Portuguese");

    le_arquivo(vetor);
    int tam_vetor = checa_tamanho(vetor);
    divide_vetor(vetor, pares, impares);

    int tam_par = checa_tamanho(pares);
    int tam_impar = checa_tamanho(impares);

    printf("Parquímetros de Porto Alegre!\n"
           "O total é de [%d] parquímetros, sendo:\n"
           "    Parquímetros com total de vagas par: [%d] \n"
           "    Parquímetros com total de vagas ímpar: [%d] \n", tam_vetor, tam_par, tam_impar);
    grava_arquivos(pares, impares);

    return 0;
}

int checa_tamanho(parq_t *vetor){
    int i=0;
    while(vetor[i].id != 0){
        i++;
    }
    return i;
}

void le_arquivo(parq_t *vetor){
    FILE *arquivo;
    arquivo = fopen("parquimetros.csv", "r");
    if(arquivo == NULL){
        printf("Nao foi possivel aprir o arquivo [parquimetros.csv] para leitura. \n");
        return;
    }
    char linha[200];
    parq_t info;
    int i=0;
    fgets(linha, 200, arquivo); /*Pula o cabecalho*/
    linha[0] = '\0';
    while (fgets(linha, 200, arquivo) != NULL){
        linha[strlen(linha)-1]='\0';    /*Remove o \n do final da string*/
        info.id = atoi(strtok(linha, ","));
        strcpy(info.endereco, strtok(NULL, ","));
        info.vagas = atoi(strtok(NULL, ","));
        vetor[i] = info;
        i++;
    }
    fclose(arquivo);
    return;
}

void divide_vetor(parq_t *vetor, parq_t *par, parq_t *impar){
    int i, j=0, k=0;
    int tamanho = checa_tamanho(vetor);

    for(i=0; i < tamanho; i++){
        if(vetor[i].vagas % 2){
            impar[j] = vetor[i];
            j++;
        }
        else{
            par[k] = vetor[i];
            k++;
        }
    }
    return;
}

void grava_arquivos(parq_t *pares, parq_t *impares){
    FILE *arquivo_par;
    FILE *arquivo_impar;
    arquivo_par = fopen("pares.csv", "w");
    arquivo_impar = fopen("impares.csv", "w");
    int tam_par = checa_tamanho(pares);
    int tam_impar = checa_tamanho(impares);
    int i;

    fprintf(arquivo_par, "id,Endereco,Vagas\n");
    for(i=0; i < tam_par; i++){
        fprintf(arquivo_par, "%d,%s,%d\n", pares[i].id, pares[i].endereco, pares[i].vagas);
    }
    fprintf(arquivo_impar, "id,Endereco,Vagas\n");
    for(i=0; i < tam_impar; i++){
        fprintf(arquivo_impar, "%d,%s,%d\n", impares[i].id, impares[i].endereco, impares[i].vagas);
    }
    fclose(arquivo_impar);
    fclose(arquivo_par);
    return;
}
