/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur Antonio Soutelo Araujo
Cartao UFRGS : 00304292
*/
#include "carro.h"

void grava_carros(carro_t *carros){     /*Grava o vetor de carros no arquivo carros.csv*/
    FILE *arquivo;
    arquivo = fopen ("carros.csv", "w");
    int i;
    int tamanho = checa_tamanho_carro(carros);

    if (arquivo != NULL){
        fputs("codigo_carro,marca,modelo,ano,placa,valor_diaria,valor_seguro,quantidade", arquivo);
        for(i=0; i < tamanho; i++){
            fprintf(arquivo, "\n%d,%s,%s,%d,%s,%.2f,%.2f,%d",
                    carros[i].codigo_carro, carros[i].marca, carros[i].modelo, carros[i].ano, carros[i].placa,
                    carros[i].valor_diaria, carros[i].valor_seguro, carros[i].quantidade);
        }
        fclose(arquivo);
    }
    else
        printf("ERRO. Arquivo [carros.csv] nao pode ser aberto para gravacao.");

    return;
}

void info_carro(int codigo, carro_t *carros){       /*Recebe o codigo de um carro e exibe na tela as informações*/
    int i, valida=1;
    int tamanho = checa_tamanho_carro(carros);

    for (i=0; i < tamanho; i++){
        if (carros[i].codigo_carro == codigo){
            printf("\nInformacoes do carro de codigo [%d]:\n", codigo);
            printf("    Marca: %s \n", carros[i].marca);
            printf("    Modelo: %s \n", carros[i].modelo);
            printf("    Ano: %d \n", carros[i].ano);
            printf("    Placa: %s \n", carros[i].placa);
            printf("    Valor da diaria: %.2f \n", carros[i].valor_diaria);
            printf("    Valor do Seguro: %.2f \n", carros[i].valor_seguro);
            printf("    Quantidade: %d \n", carros[i].quantidade);
            valida++;
        }
    }
    if (valida == 1)
        printf("\nCodigo inserido invalido.\n"
               "Insira um codigo no intervalo entre [1] & [%d]\n\n", tamanho);
    return;
}

void leitura_carros(carro_t *carros){       /*Grava no vetor de carros as informações presentes no arquivo carros.csv*/
    FILE *arquivo;
    arquivo = fopen("carros.csv", "r");
    int i=0;
    char linha[MAX];
    carro_t aux = {0};

    if (arquivo != NULL){
        fgets(linha, 100, arquivo);       /*pula o cabeçalho*/
        linha[0] = '\0';
        do{
            fgets(linha, MAX, arquivo);     /* Pega somente uma linha */
            if(linha[strlen(linha)-1] == '\n')
                linha[strlen(linha)-1] = '\0';  /* Remove o '\n' do final da string */

            aux.codigo_carro = atoi(strtok(linha, ","));
            strcpy(aux.marca, strtok(NULL, ","));
            strcpy(aux.modelo, strtok(NULL, ","));
            aux.ano = atoi(strtok(NULL, ","));
            strcpy(aux.placa, strtok(NULL, ","));
            aux.valor_diaria = atof(strtok(NULL, ","));
            aux.valor_seguro = atof(strtok(NULL, ","));
            aux.quantidade = atoi(strtok(NULL, ","));

            carros[i] = aux;
            i++;
        }while(!feof(arquivo));
        fclose(arquivo);
    }
    else
        printf("O arquivo [carros.csv] nao pode ser aberto para leitura. \n");

    return;
}

void lista_carros(char *marca, carro_t *carros){        /*Recebe uma marca e exibe na tela as informações dos carros*/
    int i, j, contagem = 1;
    int tamanho = checa_tamanho_carro(carros);

    char marca_carro_uniforme[50];  /*Inicializacao de uma string para receber uma marca do vetor e deixa-la uniforme*/
    for (j=0; j < 50; j++)
        marca[j] = toupper(marca[j]);

    imprime_moldura();
    for(i=0; i < tamanho; i++){
        for(j=0; j < 50; j++){
            marca_carro_uniforme[j] = toupper(carros[i].marca[j]);  /*Permite a idencificação mesmo se existirem letras maiusculas ou minusculas*/
        }
        if(strcmp(marca, marca_carro_uniforme) == 0){
            if(contagem == 1){  /*Imprimi só uma vez*/
                printf("CODIGO_CARRO |   MARCA   |        MODELO        |  ANO  |   PLACA  | VALOR_DIARIA | VALOR_SEGURO | QUANTIDADE\n\n");
            }
            printf("%12d | %9s | %20s |  %4d | %8s | %12.2f | %12.2f | %5d \n",
               carros[i].codigo_carro, carros[i].marca, carros[i].modelo, carros[i].ano, carros[i].placa,
               carros[i].valor_diaria, carros[i].valor_seguro, carros[i].quantidade);
            contagem++;
        }
    }
    if (contagem == 1)
        printf("\nMarca nao encontrada.\n\n");
    return;
}

void novo_carro(carro_t *carros){    /*Permite o usuario cadastrar um novo carro*/
    carro_t informacoes;

    int tamanho = checa_tamanho_carro(carros);
    informacoes.codigo_carro = tamanho+1;

    printf("Informe as seguintes informacoes do carro: \n");
    printf("\n>> Marca: ");
    fgets(informacoes.marca, 50, stdin);
    informacoes.marca[strlen(informacoes.marca)-1] = '\0';
    printf("\n>> Modelo: ");
    fgets(informacoes.modelo, 50, stdin);
    informacoes.modelo[strlen(informacoes.modelo)-1] = '\0';
    printf("\n>> Ano: ");
    scanf("%d", &informacoes.ano);
    printf("\n>> Placa: ");
    limpa_buffer();
    fgets(informacoes.placa, 10, stdin);
    informacoes.placa[strlen(informacoes.placa)-1] = '\0';
    printf("\n>> Valor da Diaria: ");
    scanf(" %f", &informacoes.valor_diaria);
    printf("\n>> Valor do Seguro: ");
    scanf(" %f", &informacoes.valor_seguro);
    printf("\n>> Quantidade: ");
    scanf(" %d", &informacoes.quantidade);

    carros[tamanho] = informacoes;

    grava_carros(carros);
    printf("\n\nCarro registrado com sucesso!\n\n");
    return;
}

void lista_carros_preco(char *marca, carro_t *carros){
    int i, j, k=0;
    carro_t carros_dec[MAX] = {{0}};
    int tamanho = checa_tamanho_carro(carros);

    char marca_carro_uniforme[50];  /*Inicializacao de uma string para receber uma marca do vetor e deixa-la uniforme*/
    for (j=0; j < 50; j++)
        marca[j] = toupper(marca[j]);

    for(i=0; i < tamanho; i++){
        for(j=0; j < 50; j++){
            marca_carro_uniforme[j] = toupper(carros[i].marca[j]);  /*Permite a idencificação mesmo se existirem letras maiusculas ou minusculas*/
        }
        if(strcmp(marca, marca_carro_uniforme) == 0){
            carros_dec[k] = carros[i];
            k++;
        }
    }

    int sinal, fim;
    carro_t aux;
    fim = k-1;
    do {
        sinal = 0;
        for (i = 0; i < fim; i++)
            if (carros_dec[i].valor_diaria < carros_dec[i+1].valor_diaria) {
                aux = carros_dec[i];
                carros_dec[i] = carros_dec[i+1];
                carros_dec[i+1] = aux;
                sinal = 1;
            }
        fim--;
    } while (sinal == 1);

    if(k == 0)      /* Caso a marca digitada nao exista */
        printf("\nMarca nao encontrada.\n\n");
    else{
        printf("Carros da %s em ordem de preco decrescente:\n", marca);
        imprime_moldura();
        printf("CODIGO_CARRO |   MARCA   |        MODELO        |  ANO  |   PLACA  | VALOR_DIARIA | VALOR_SEGURO | QUANTIDADE\n\n");
        for(i=0; i < k; i++){
            printf("%12d | %9s | %20s |  %4d | %8s | %12.2f | %12.2f | %5d \n",
                    carros_dec[i].codigo_carro, carros_dec[i].marca, carros_dec[i].modelo, carros_dec[i].ano, carros_dec[i].placa,
                    carros_dec [i].valor_diaria, carros_dec[i].valor_seguro, carros_dec[i].quantidade);
        }
    }
    return;
}

int checa_tamanho_carro(carro_t *carros){
    int i=0;
    while(carros[i].codigo_carro != 0){
        i++;
    }
    return i;
}

/*VVVVV ---Funções extras--- VVVVV*/

void banco_de_dados_carro(carro_t *carros){     /*Imprime na tela uma tabela com as informações do arquivo*/
    int i, tamanho = checa_tamanho_carro(carros);
    printf("CODIGO_CARRO |   MARCA   |        MODELO        |  ANO  |   PLACA  | VALOR_DIARIA | VALOR_SEGURO | QUANTIDADE\n\n");
    for(i=0; i < tamanho; i++){
        printf("%12d | %9s | %20s |  %4d | %8s | %12.2f | %12.2f | %5d \n",
               carros[i].codigo_carro, carros[i].marca, carros[i].modelo, carros[i].ano, carros[i].placa,
               carros[i].valor_diaria, carros[i].valor_seguro, carros[i].quantidade);
    }
    return;
}

void remove_carro(carro_t *carros){
    int tamanho = checa_tamanho_carro(carros);
    int codigo, escolha;
    int i, j;
    char saida = 'n';

    printf("Remocao de carros: \n");
    imprime_moldura();
    printf("Deseja remover um: \n"
           "(1)Modelo                    (2)Unico Carro \n\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    do{
        printf("\n\nInforme o codigo do carro a ser removido entre [1] & [%d]: ", tamanho);
        scanf("%d", &codigo);
    }while(codigo < 1 || codigo > tamanho);
    printf("\nTem certeza que deseja remover esse carro? Digite S para Sim: ");
    scanf(" %c", &saida);
    if(saida == 's' || saida == 'S'){
        switch(escolha){
        case 1:
            for(i=0; i < tamanho; i++){
                if(codigo == carros[i].codigo_carro){
                    for(j=i; j < tamanho-1; j++){
                        carros[j] = carros[j+1];    /* Remove um carro do vetor de carros */
                        carros[j].codigo_carro = codigo;
                        codigo++;
                    }
                }
            }
            carros[tamanho-1].codigo_carro = 0;
            break;
        case 2:
            for(i=0; i < tamanho; i++){
                if(codigo == carros[i].codigo_carro){
                    carros[i].quantidade--;     /* Tira 1 carro da quantidade */
                }
            }
            break;
        default:
            printf("Opcao invalida\n");
        }
        grava_carros(carros);
        printf("Carro removido.\n");
    }
    return;
}

void novo_carro_unico(carro_t *carros){ /* Função que adiciona 1 a quantidade de carros em um certo modelo */
    int i, codigo, tamanho = checa_tamanho_carro(carros);
    char sim = 'N';
    do{
        printf("Informe o codigo do carro no qual sera adicionado 1 veiculo a quantidade. \nUm codigo entre [1] & [%d]: ", tamanho);
        scanf("%d", &codigo);
    }while(codigo < 1 || codigo > tamanho);

     for(i=0; i < tamanho; i++){
        if(codigo == carros[i].codigo_carro){
            printf("\n    Carro escolhido: %s, %s", carros[i].marca, carros[i].modelo);
            printf("\nConfirmar carro? Digite S para sim: ");
            scanf(" %c", &sim);
            if(sim == 's' || sim == 'S'){
                carros[i].quantidade++;
                printf("\nCarro adicionado. \n");
            }
        }
     }
    return;
}
