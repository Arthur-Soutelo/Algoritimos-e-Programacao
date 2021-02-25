/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur Antonio Soutelo Araujo
Cartao UFRGS : 00304292
*/
#include "aluguel.h"

void grava_alugueis(aluguel_t *alugueis){
    FILE *arquivo;
    arquivo = fopen ("alugueis.bin", "wb");
    int tamanho = checa_tamanho_aluguel(alugueis);

    if (arquivo != NULL){
    /* "cod_aluguel,cod_cliente,cod_carro,dia,mes,ano,diarias,valor,seguro,situacao" */
        fwrite(alugueis, sizeof(aluguel_t), tamanho, arquivo);
        fclose(arquivo);
    }
    else
        printf("ERRO. Arquivo [alugueis.bin] nao pode ser aberto para gravacao.");

    return;
}

void info_aluguel(int codigo, aluguel_t *alugueis){
    int i;
    int tamanho = checa_tamanho_aluguel(alugueis);

    for (i=0; i < tamanho; i++){
        if (alugueis[i].codigo_aluguel == codigo){
            printf("\nInformacoes do aluguel de codigo [%d]:\n", codigo);
            printf("    Codigo do Cliente: %d \n", alugueis[i].codigo_cliente);
            printf("    Codigo do Carro: %d \n", alugueis[i].codigo_carro);
            printf("    Dia/Mes/ano: %d/%d/%d \n", alugueis[i].dia,alugueis[i].mes,alugueis[i].ano);
            printf("    Numero de Diarias: %d \n", alugueis[i].numero_diarias);
            printf("    Valor: %.2f \n", alugueis[i].valor);
            printf("    Seguro: %c \n", alugueis[i].seguro);
            printf("    Situacao Atual: %c \n", alugueis[i].situacao);
        }
    }
    return;
}

void leitura_alugueis(aluguel_t *alugueis){
    FILE *arquivo;
    arquivo = fopen("alugueis.bin", "rb");

    if (arquivo != NULL){
        fread(alugueis, sizeof(aluguel_t), MAX, arquivo);
        fclose(arquivo);
    }
    else
        printf("O arquivo [alugueis.bin] nao pode ser aberto para leitura. \n");

    return;
}

void lista_alugueis(int codigo, aluguel_t *alugueis){
    int i, tamanho = checa_tamanho_aluguel(alugueis);
    int nenhum_aluguel = 0;
    printf("Alugueis do cliente de codigo %d:\n", codigo);
    imprime_moldura();
    printf("CODIGO_ALUGUEL | CODIGO_CARRO | DIA/MES/ANO | NUMERO DIARIAS |   VALOR   | SEGURO | SITUACAO\n\n");
    for(i=0; i < tamanho; i++){
        if(codigo == alugueis[i].codigo_cliente){
            printf("%14d | %12d |  %2d/%2d/%4d | %14d | %9.2f |      %c |      %c \n",
               alugueis[i].codigo_aluguel, alugueis[i].codigo_carro, alugueis[i].dia, alugueis[i].mes,
               alugueis[i].ano, alugueis[i].numero_diarias, alugueis[i].valor, alugueis[i].seguro, alugueis[i].situacao);
            nenhum_aluguel = 1;
        }
    }
    if(nenhum_aluguel == 0){
        limpa_tela();
        printf("\nEsse cliente nao possui alugueis registrados. \n\n");
    }

    return;
}

void novo_aluguel(aluguel_t *alugueis, carro_t *carros, cliente_t *clientes){    /*Funcao que permite o usuario cadastrar um novo cliente*/
    aluguel_t informacoes;
    int i = 0, saida = 1;
    char sim;

    int tamanho_alu = checa_tamanho_aluguel(alugueis);
    int tamanho_cli = checa_tamanho_cliente(clientes);
    int tamanho_car = checa_tamanho_carro(carros);
    informacoes.codigo_aluguel = tamanho_alu+1;
    float preco_dia, preco_seguro;

    printf("Informe as seguintes informacoes do cliente: \n");
    do{
        sim = 'N';
        do{
            printf(">> Codigo do Cliente entre [1] & [%d]: ", tamanho_cli);
            scanf("%d", &informacoes.codigo_cliente);
        }while(informacoes.codigo_cliente < 1 || informacoes.codigo_cliente > tamanho_cli);
        for(i=0; i < tamanho_cli; i++){     /* Procura o cliente e imprime o nome na tela para confirmação */
            if(informacoes.codigo_cliente == clientes[i].codigo_cliente){
                printf("    Cliente escolhido: %s", clientes[i].nome);
                printf("\nConfirmar cliente? Digite S para sim: ");
                scanf(" %c", &sim);
                if(sim == 's' || sim == 'S')
                    saida = 0;
                i = tamanho_cli; /* Sai do for */
            }
        }
    }while(saida != 0);

    do{
        sim = 'N';
        do{
            printf("\n>> Codigo do Carro entre [1] & [%d]: ", tamanho_car);
            scanf("%d", &informacoes.codigo_carro);
        }while(informacoes.codigo_carro < 1 || informacoes.codigo_carro > tamanho_car);

        for(i=0; i < tamanho_car; i++){
            if(informacoes.codigo_carro == carros[i].codigo_carro){         /*Verifica se o carro escolhido está disponivel*/
                if(carros[i].quantidade == 0)
                    printf("Infelizmente o carro escolhido esta indisponivel.\n"
                           "Escolha outro modelo.\n");
                else{
                    printf("    Carro escolhido: %s, %s", carros[i].marca, carros[i].modelo);
                    printf("\nConfirmar carro? Digite S para sim: ");
                    scanf(" %c", &sim);
                    if(sim == 's' || sim == 'S'){
                        saida = 0;
                        carros[i].quantidade--;
                        preco_dia = carros[i].valor_diaria;
                        preco_seguro = carros[i].valor_seguro;    /*Armazenda o valor do seguro e da diaria*/
                    }
                }
            }
        }
    }while(saida != 0);

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    informacoes.dia = local->tm_mday;
    informacoes.mes = local->tm_mon + 1;    //mes de 0 até 11
    informacoes.ano = local->tm_year + 1900;    // começa a contar a partir do ano 1900
    sim = 'N';
    printf("\n>> Dia, Mes e Ano: ");
    printf("%02d/%02d/%d\n", informacoes.dia, informacoes.mes, informacoes.ano);
    printf("Confirmar data? Digite S para sim: ");
    scanf(" %c", &sim);
    if(sim != 's' && sim != 'S'){
        printf("\n>> Dia, Mes e Ano: ");
        scanf("%d %d %d", &informacoes.dia, &informacoes.mes, &informacoes.ano);
    }

    do{
        printf("\n>> Numero de diarias: ");
        scanf("%d", &informacoes.numero_diarias);
    }while(informacoes.numero_diarias <= 0);
    do{
        printf("\n>> Seguro [S] ou[N]: ");
        scanf(" %c", &informacoes.seguro);
        informacoes.seguro = toupper(informacoes.seguro);  /*Deixa o seguro em letra maiuscula*/
    }while(informacoes.seguro != 'S' && informacoes.seguro != 'N');
    if(informacoes.seguro == 'S')
        informacoes.valor = (preco_dia + preco_seguro) * informacoes.numero_diarias;     /*Calcula o valor*/
    else
        informacoes.valor = preco_dia * informacoes.numero_diarias;

    desconto_diarias(&informacoes.numero_diarias, &informacoes.valor); /*Aplica desconto de acordo com as diarias*/
    printf("\n>> Valor final: %.2f", informacoes.valor);
    informacoes.situacao = 'L';
    alugueis[tamanho_alu] = informacoes;

    printf("\n\nAluguel registrado com sucesso!\n\n");
    grava_alugueis(alugueis);       /*Salva o vetor no arquivo*/
    grava_carros(carros);
    return;
}

void devolucao(int codigo, aluguel_t *alugueis, carro_t *carros){
    int i, j;
    int tamanho_alu = checa_tamanho_aluguel(alugueis);
    int tamanho_car = checa_tamanho_carro(carros);

    for (i=0; i < tamanho_alu; i++){
        if (alugueis[i].codigo_aluguel == codigo){
            if(alugueis[i].situacao == 'L'){
                alugueis[i].situacao = 'E';
                for(j=0; j < tamanho_car; j++){
                    if(alugueis[i].codigo_carro == carros[j].codigo_carro)
                        carros[j].quantidade++;         /*Adiciona um a quantidade de carros no carro devolvido*/
                }
                printf("Devolucao registrada com sucesso!\n");
            }
            else
                printf("O codigo informado se refere a um aluguel cujo veiculo ja foi entregue. \n"
                       "Insira um codigo valido. \n");
        }
    }
    grava_alugueis(alugueis);
    grava_carros(carros);
    return;
}

void lista_atrasados(aluguel_t *alugueis, cliente_t *clientes){
    int i, j;
    int tamanho_cli = checa_tamanho_cliente(clientes);
    int tamanho_alu = checa_tamanho_aluguel(alugueis);

    printf("Clientes que possuem carros nao entreges:\n");
    imprime_moldura();
    printf("CODIGO_CLIENTE |              NOME              |       CNH       |  DDD  |    TELEFONE   \n\n");
    for(i=0; i < tamanho_cli; i++){ /*Começa percorrendo o vetor de clientes*/
        for(j=0; j < tamanho_alu; j++){
            if(clientes[i].codigo_cliente == alugueis[j].codigo_cliente){   /*Ao encontrar um aluguel do cliente verifica a situaçao e imprimi na tela*/
                if(alugueis[j].situacao == 'L'){
                    printf("%14d | %30s | %15s |  %4s | %12s \n",
                                clientes[i].codigo_cliente, clientes[i].nome, clientes[i].cnh, clientes[i].ddd, clientes[i].telefone);
                    j = tamanho_alu;    /*Após imprimir na tela já pula para o proximo cliente. Para n exibir mais de uma vez o mesmo cliente*/
                }
            }
        }
    }
    return;
}

int checa_tamanho_aluguel(aluguel_t *alugueis){
    int i=0;
    while(alugueis[i].codigo_aluguel != 0){
        i++;
    }
    return i;
}

/*VVVVV ---Funções extras--- VVVVV*/

void banco_de_dados_aluguel(aluguel_t *alugueis){   /*Imprime na tela uma tabela com as informações do arquivo*/
    int i, tamanho = checa_tamanho_aluguel(alugueis);
    printf("CODIGO_ALUGUEL | CODIGO_CLIENTE | CODIGO_CARRO | DIA/MES/ANO | NUMERO DIARIAS |   VALOR   | SEGURO | SITUACAO\n\n");
    for(i=0; i < tamanho; i++){
        printf("%14d | %14d | %12d |  %2d/%2d/%4d | %14d | %9.2f |      %c |      %c \n",
               alugueis[i].codigo_aluguel, alugueis[i].codigo_cliente, alugueis[i].codigo_carro, alugueis[i].dia, alugueis[i].mes,
               alugueis[i].ano, alugueis[i].numero_diarias, alugueis[i].valor, alugueis[i].seguro, alugueis[i].situacao);
    }
    return;
}

void novo_aluguel_por_cnh(aluguel_t *alugueis, carro_t *carros, cliente_t *clientes){    /*Funcao que permite o usuario cadastrar um novo cliente*/
    aluguel_t informacoes = {0};
    int i = 0, saida = 1;
    char sim;

    int tamanho_alu = checa_tamanho_aluguel(alugueis);
    int tamanho_cli = checa_tamanho_cliente(clientes);
    int tamanho_car = checa_tamanho_carro(carros);
    informacoes.codigo_aluguel = tamanho_alu+1;
    float preco_dia, preco_seguro;

    printf("Informe as seguintes informacoes do cliente: \n");
    printf(">> CNH: ");
    char cnh[15];
    limpa_buffer();
    fgets(cnh, 15, stdin);
    cnh[strlen(cnh)-1] = '\0';
    for(i=0; i < tamanho_cli; i++){
        if (strcmp(cnh, clientes[i].cnh) == 0){
            informacoes.codigo_cliente = clientes[i].codigo_cliente;
            printf("Cliente: %s", clientes[i].nome);
        }
    }
    if(informacoes.codigo_cliente == 0){
        printf("\nCNH nao encontrada. \n");
        return;
    }

    do{
        sim = 'N';
        do{
            printf("\n>> Codigo do Carro entre [1] & [%d]: ", tamanho_car);
            scanf("%d", &informacoes.codigo_carro);
        }while(informacoes.codigo_carro < 1 || informacoes.codigo_carro > tamanho_car);

        for(i=0; i < tamanho_car; i++){
            if(informacoes.codigo_carro == carros[i].codigo_carro){         /*Verifica se o carro escolhido está disponivel*/
                if(carros[i].quantidade == 0)
                    printf("Infelizmente o carro escolhido esta indisponivel.\n"
                           "Escolha outro modelo.\n");
                else{
                    printf("    Carro escolhido: %s, %s", carros[i].marca, carros[i].modelo);
                    printf("\nConfirmar carro? Digite S para sim: ");
                    scanf(" %c", &sim);
                    if(sim == 's' || sim == 'S'){
                        saida = 0;
                        carros[i].quantidade--;
                        preco_dia = carros[i].valor_diaria;
                        preco_seguro = carros[i].valor_seguro;    /*Armazenda o valor do seguro e da diaria*/
                    }
                }
            }
        }
    }while(saida != 0);

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    informacoes.dia = local->tm_mday;
    informacoes.mes = local->tm_mon + 1;    //mes de 0 até 11
    informacoes.ano = local->tm_year + 1900;    // começa a contar a partir do ano 1900
    sim = 'N';
    printf("\n>> Dia, Mes e Ano: ");
    printf("%02d/%02d/%d\n", informacoes.dia, informacoes.mes, informacoes.ano);
    printf("Confirmar data? Digite S para sim: ");
    scanf(" %c", &sim);
    if(sim != 's' && sim != 'S'){
        printf("\n>> Dia, Mes e Ano: ");
        scanf("%d %d %d", &informacoes.dia, &informacoes.mes, &informacoes.ano);
    }

    do{
        printf("\n>> Numero de diarias: ");
        scanf("%d", &informacoes.numero_diarias);
    }while(informacoes.numero_diarias <= 0);
    do{
        printf("\n>> Seguro [S] ou[N]: ");
        scanf(" %c", &informacoes.seguro);
        informacoes.seguro = toupper(informacoes.seguro);  /*Deixa o seguro em letra maiuscula*/
    }while(informacoes.seguro != 'S' && informacoes.seguro != 'N');
    if(informacoes.seguro == 'S')
        informacoes.valor = (preco_dia + preco_seguro) * informacoes.numero_diarias;     /*Calcula o valor*/
    else
        informacoes.valor = preco_dia * informacoes.numero_diarias;

    desconto_diarias(&informacoes.numero_diarias, &informacoes.valor); /*Aplica desconto de acordo com as diarias*/
    printf("\n>> Valor final: %.2f", informacoes.valor);
    informacoes.situacao = 'L';
    alugueis[tamanho_alu] = informacoes;

    printf("\n\nAluguel registrado com sucesso!\n\n");
    grava_alugueis(alugueis);       /*Salva o vetor no arquivo*/
    grava_carros(carros);
    return;
}
void desconto_diarias(int *numero_diarias, float *valor_total){ /*Aplica um desconto referente ao numero de diárias*/
    float valor_antes = *valor_total;

    if(*numero_diarias >= 10 && *numero_diarias < 20){
        *valor_total = (0.9 * (*valor_total));
        printf("\nDesconto de 10%c concedido relativo aos %d dias! \n", '%', *numero_diarias);
        printf("Valor antes do deconto: %.2f \n", valor_antes);
        printf("Valor depois do desconto: %.2f \n", *valor_total);
    }
    else if(*numero_diarias >= 20 && *numero_diarias < 30){
        *valor_total = (0.8 * (*valor_total));
        printf("\nDesconto de 20%c concedido relativo aos %d dias!\n", '%', *numero_diarias);
        printf("Valor antes do deconto: %.2f \n", valor_antes);
        printf("Valor depois do desconto: %.2f \n", *valor_total);
    }
    else if(*numero_diarias >= 30){
        *valor_total = (0.7 * (*valor_total));
        printf("\nDesconto de 30%c concedido relativo aos %d dias!\n", '%', *numero_diarias);
        printf("Valor antes do deconto: %.2f \n", valor_antes);
        printf("Valor depois do desconto: %.2f \n", *valor_total);
    }
    return;
}

void devolucao_por_cnh(cliente_t *clientes, aluguel_t *alugueis, carro_t *carros){
    int tamanho_alu = checa_tamanho_aluguel(alugueis);
    int tamanho_cli = checa_tamanho_cliente(clientes);
    int i, j;
    int erro = 1;

    printf("\n>> CNH: ");
    char cnh[15];
    limpa_buffer();
    fgets(cnh, 15, stdin);
    cnh[strlen(cnh)-1] = '\0';
    for(i=0; i < tamanho_cli; i++){
        if (strcmp(cnh, clientes[i].cnh) == 0){
            printf("\nAlugueis ativos do cliente [%s]: \n", clientes[i].nome);
            erro = 0;   //achou a cnh
            for(j=0 ; j < tamanho_alu; j++){
                if(clientes[i].codigo_cliente == alugueis[j].codigo_cliente && alugueis[j].situacao == 'L'){
                    printf(">>Codigo do Aluguel: [%d] \n", alugueis[j].codigo_aluguel);
                    printf("   Codigo do Carro: %d \n", alugueis[j].codigo_carro);
                    printf("   Valor: %.2f \n\n", alugueis[j].valor);
                }
            }
        }
    }
    if(erro == 1){
        limpa_tela();
        printf("CNH nao encontrada. \n");
        imprime_moldura();
        return;
    }
    printf("Digite o codigo do aluguel: ");
    int codigo;
    scanf("%d", &codigo);
    limpa_tela();
    devolucao(codigo, alugueis, carros);
    imprime_moldura();
    return;
}

void remove_aluguel_do_cliente(int codigo, aluguel_t *alugueis){
    int i, j;
    int tamanho;
    int saida;

    do{
        tamanho = checa_tamanho_aluguel(alugueis);
        saida = 0;
        for(i=0; i < tamanho; i++){
            if(codigo == alugueis[i].codigo_cliente){   /* Remove o aluguel cujo codigo_cliente é o mesmo do codigo digitado */
                saida = 1;
                for(j=i; j < tamanho-1; j++){
                    alugueis[j] = alugueis[j+1];
                    if(alugueis[j].codigo_aluguel != '0')
                        alugueis[j].codigo_aluguel--;   /* Diminui o codigo do aluguel relativo ao numero de alugueis removidos */
                }
                alugueis[tamanho-1].codigo_aluguel = 0;
            }
        }
    }while(saida == 1);

    for(i=0; i < tamanho; i++){
        if(alugueis[i].codigo_cliente > codigo)   /* Diminui o codigo do cliente salvo em cada aluguel se o mesmo for maior do que o codigo do cliente removido */
            alugueis[i].codigo_cliente --;
    }
    grava_alugueis(alugueis);
    return;
}
