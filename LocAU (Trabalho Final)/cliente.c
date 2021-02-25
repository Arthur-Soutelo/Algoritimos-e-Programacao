/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur Antonio Soutelo Araujo
Cartao UFRGS : 00304292
*/
#include "cliente.h"

void grava_clientes(cliente_t *clientes){     /*Grava o vetor de clientes no arquivo clientes.csv*/
    FILE *arquivo;
    arquivo = fopen ("clientes.csv", "w");
    int i;
    int tamanho = checa_tamanho_cliente(clientes);

    if (arquivo != NULL){
        fputs("codigo_cliente,nome,cnh,ddd,telefone", arquivo);
        for(i=0; i < tamanho; i++){
            fprintf(arquivo, "\n%d,%s,%s,%s,%s",
                    clientes[i].codigo_cliente, clientes[i].nome, clientes[i].cnh, clientes[i].ddd, clientes[i].telefone);
        }
        fclose(arquivo);
    }
    else
        printf("ERRO. Arquivo [clientes.csv] nao pode ser aberto para gravacao.");

    return;
}

void info_cliente(int codigo, cliente_t *clientes){       /*Recebe o codigo de um cliente e exibe na tela as informações*/
    int i, valida=1;
    int tamanho = checa_tamanho_cliente(clientes);

    for (i=0; i < tamanho; i++){
        if (clientes[i].codigo_cliente == codigo){
            printf("\nInformacoes do cliente de codigo [%d]:\n", codigo);
            printf("    Nome: %s \n", clientes[i].nome);
            printf("    CNH: %s \n", clientes[i].cnh);
            printf("    ddd: %s \n", clientes[i].ddd);
            printf("    Telefone: %s \n", clientes[i].telefone);
            valida++;
        }
    }
    if (valida == 1)
        printf("\nCodigo inserido invalido.\n"
               "Insira um codigo no intervalo entre [1] & [%d]\n\n", tamanho);
    return;
}

void leitura_clientes(cliente_t *clientes){       /*Grava no vetor de clientes as informações presentes no arquivo clientes.csv*/
    FILE *arquivo;
    arquivo = fopen("clientes.csv", "r");
    int i=0;
    char linha[MAX];
    cliente_t aux = {0};

    if (arquivo != NULL){
        fgets(linha, 100, arquivo);       //pula o cabeçalho
        linha[0] = '\0';
        while(!feof(arquivo)){
            fgets(linha, MAX, arquivo);     //Pega somente uma linha
            if(linha[strlen(linha)-1] == '\n')
                linha[strlen(linha)-1] = '\0';  //Remove o '\n' do final da string

            aux.codigo_cliente = atoi(strtok(linha, ","));
            strcpy(aux.nome, strtok(NULL, ","));
            strcpy(aux.cnh, strtok(NULL, ","));
            strcpy(aux.ddd, strtok(NULL, ","));
            strcpy(aux.telefone, strtok(NULL, ","));

            clientes[i] = aux;
            i++;
        }
        fclose(arquivo);
    }
    else
        printf("O arquivo [clientes.csv] nao pode ser aberto para leitura. \n");
    return;
}

void novo_cliente(cliente_t *clientes){    /*Permite o usuario cadastrar um novo cliente*/
    cliente_t informacoes;

    int tamanho = checa_tamanho_cliente(clientes);

    informacoes.codigo_cliente = tamanho+1;

    printf("Informe as seguintes informacoes do cliente: \n");
    printf("\n>> Nome: ");
    fgets(informacoes.nome, 50, stdin);
    informacoes.nome[strlen(informacoes.nome)-1] = '\0';
    informacoes.nome[0] = toupper(informacoes.nome[0]); /* Primeira letra para maiuscula para n interferir no processo de ordem alfabetica */
    printf("\n>> CNH: ");
    fgets(informacoes.cnh, 15, stdin);
    informacoes.cnh[strlen(informacoes.cnh)-1] = '\0';
    printf("\n>> ddd: ");
    fgets(informacoes.ddd, 5, stdin);
    informacoes.ddd[strlen(informacoes.ddd)-1] = '\0';
    printf("\n>> Telefone: ");
    fgets(informacoes.telefone, 11, stdin);
    informacoes.telefone[strlen(informacoes.telefone)-1] = '\0';

    clientes[tamanho] = informacoes;

    grava_clientes(clientes);   //Salva no arquivo
    printf("\n\nCliente registrado com sucesso!\n\n");
    return;
}

void lista_clientes(cliente_t *clientes){        /*Exibe na tela as informações dos clientes em ordem alfabetica*/
    int i;
    int tamanho = checa_tamanho_cliente(clientes);
    cliente_t clientes_alf[MAX] = {{0}};

    for(i=0; i < tamanho; i++){
        clientes_alf[i] = clientes[i];
    }

    int sinal, fim;
    cliente_t aux;
    fim = tamanho - 1;
    do{
        sinal = 0;
        for (i = 0; i < fim; i++)
            if(strcmp(clientes_alf[i].nome, clientes_alf[i+1].nome) > 0){
                aux = clientes_alf[i];
                clientes_alf[i] = clientes_alf[i+1];
                clientes_alf[i+1] = aux;
                sinal = 1;

            }
        fim--;
    }while (sinal == 1);

    printf("Clientes em ordem de alfabetica:\n");
    imprime_moldura();
    printf("CODIGO_CLIENTE |              NOME              |       CNH       |  DDD  |    TELEFONE \n\n");
    for(i=0; i < tamanho; i++){
        printf("%14d | %30s | %15s |  %4s | %12s \n",
               clientes_alf[i].codigo_cliente, clientes_alf[i].nome, clientes_alf[i].cnh, clientes_alf[i].ddd, clientes_alf[i].telefone);
    }
    return;
}

int checa_tamanho_cliente(cliente_t *clientes){
    int i=0;
    while(clientes[i].codigo_cliente != 0){
        i++;
    }
    return i;
}
/*VVVVV ---Funções extras--- VVVVV*/

void banco_de_dados_cliente(cliente_t *clientes){       /*Imprime na tela uma tabela com as informações do arquivo*/
    int i, tamanho = checa_tamanho_cliente(clientes);
    printf("CODIGO_CLIENTE |              NOME              |       CNH       |  DDD  |    TELEFONE \n\n");
    for(i=0; i < tamanho; i++){
        printf("%14d | %30s | %15s |  %4s | %12s \n",
               clientes[i].codigo_cliente, clientes[i].nome, clientes[i].cnh, clientes[i].ddd, clientes[i].telefone);
    }
    return;
}

void remove_cliente(int codigo, cliente_t *clientes){
    int i, j;
    int tamanho = checa_tamanho_cliente(clientes);

    for(i=0; i < tamanho; i++){
        if(codigo == clientes[i].codigo_cliente){
            for(j=i; j < tamanho-1; j++){
                clientes[j] = clientes[j+1];
                clientes[j].codigo_cliente = codigo;    /* Sunstitui os codigos dos clientes de modo a ainda permanecerem em ordem */
                codigo++;
            }
        }
    }
    clientes[tamanho-1].codigo_cliente = 0;
    grava_clientes(clientes);
    printf("Cliente removido.\n");
    return;
}
