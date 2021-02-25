//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#include<string.h>
#define MAX 25

typedef struct{
    char nome[100];
    int matricula;
    float nota;
    int faltas;
}aluno_t;

void limpa_buffer() {
char c;
while ((c = getchar()) != '\n' && c != EOF);
}

void entrada(aluno_t *turma, int num_alunos){
    int i;
    for (i = 0; i < num_alunos; i++){
        printf("Informe os dados do aluno %d", i+1);
        printf("\n    Nome: ");
        limpa_buffer();
        fgets(turma[i].nome, 100 , stdin);
        turma[i].nome[strlen(turma[i].nome)-1] = '\0';
        printf("\n    Matricula: ");
        scanf("%d", &turma[i].matricula);
        printf("\n    Nota: ");
        scanf("%f", &turma[i].nota);
        printf("\n    Faltas: ");
        scanf("%d", &turma[i].faltas);
        printf("\n");
    }
    return;
}
void exibe_alunos(aluno_t *turma, int num_alunos){
    int i;

    for(i=0; i < num_alunos; i++){
        printf("Nome: %s \n", (turma+i)->nome);
        printf("Matricula: %d \n", (turma+i)->matricula);
        printf("Nota: %.2f \n", (turma+i)->nota);
        printf("Faltas: %d \n\n", (turma+i)->faltas);
    }
    return;
}

int troca(aluno_t *posicao1, aluno_t *posicao2){
    int sinal=0;
    aluno_t aux={0};
    if(posicao1->nota > posicao2->nota){
                aux = *posicao1;
                *posicao1 = *posicao2;
                *posicao2 = aux;
                sinal = 1;
            }
    return sinal;
}

void ordena_alunos(aluno_t *turma, int num_alunos){
    int i, sinal;
    int fim = num_alunos-1;
    do{
        sinal = 0;
        for(i=0; i < fim; i++){
            sinal = troca(&turma[i], &turma[i+1]);
        }
        fim--;
    }while(sinal == 1);

    return;
}

int main(){
    int num_alunos;
    do{
        printf("Informe o numero de alunos da turma (max 25): ");
        scanf("%d", &num_alunos);
    }while (num_alunos > MAX || num_alunos < 0);
    aluno_t turma[MAX];

    entrada(turma, num_alunos);
    printf("\nTurma antes do ordenamento:\n");
    exibe_alunos(turma, num_alunos);
    ordena_alunos(turma, num_alunos);
    printf("******************************");
    printf("\nTurma depois do ordenamento:\n");
    exibe_alunos(turma, num_alunos);

    return 0;
}
