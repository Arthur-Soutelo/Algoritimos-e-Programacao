/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur Antonio Soutelo Araujo
Cartao UFRGS : 00304292
*/
#include "cliente.h"
#include "carro.h"
#include "aluguel.h"

void imprime_moldura();
void limpa_buffer();

int main(){
    int escolha;
    aluguel_t alugueis[MAX] = {{0}};
    cliente_t clientes[MAX] = {{0}};
    carro_t carros[MAX] = {{0}};

    int saida = 1;
    do{
        int codigo = 0;
        int saida_dentro = 1, saida_dentro2 =1;
        char marca[50];
        char sim = 'N';

        leitura_clientes(clientes);
        leitura_carros(carros);
        leitura_alugueis(alugueis);

        int tamanho_alu = checa_tamanho_aluguel(alugueis);
        int tamanho_cli = checa_tamanho_cliente(clientes);
        int tamanho_car = checa_tamanho_carro(carros);

        limpa_tela();
        imprime_moldura();
        printf("                             >>| LocAU! - [LOCADORA DE AUTOMOVEIS LTDA.] |<< \n");     //imprime cabeçalho
        imprime_moldura();//linha
        printf("Escolha uma opcao: \n\n"
               "(1)Informacoes              (2)Cadastros / Remocoes / Devolucoes \n\n"
               "(3)Listas                   (4)Banco de dados*\n\n"                         /* Opções no menu com o [*] ao lado representam funções extras */
               "___________________\n(0)SAIR"
               "\n\n");
            printf("Escolha: ");
            scanf("%d", &escolha);
            limpa_tela();
            limpa_buffer();
        imprime_moldura();//linha

        switch(escolha){
        case 1:                     //INFORMACAO
            do{
                printf("Informacoes sobre: \n\n");
                printf("(1)Cliente                      (2)Carro                      (3)Aluguel \n\n");
                printf("___________________\n(0)VOLTAR AO MENU \n\n");
                printf("Escolha: ");
                scanf("%d", &escolha);
                limpa_tela();
                limpa_buffer();
                imprime_moldura();//linha
                switch(escolha){
                case 1:
                    do{
                        do{
                            printf("Insira o codigo do cliente entre [1] & [%d]: ", tamanho_cli);
                            scanf("%d", &codigo);
                            limpa_buffer();
                        }while(codigo < 1 || codigo > tamanho_cli);
                    limpa_tela();
                    info_cliente(codigo, clientes);
                    printf("\nOutro cliente? Digite S para Sim: ");
                    scanf(" %c", &sim);
                    limpa_tela();
                    }while(sim == 'S' || sim == 's');
                    imprime_moldura();//linha
                    break;
                case 2:
                    do{
                        do{
                            printf("Insira o codigo do carro entre [1] & [%d]: ", tamanho_car);
                            scanf("%d", &codigo);
                            limpa_buffer();
                        }while(codigo < 1 || codigo > tamanho_car);
                    limpa_tela();
                    info_carro(codigo, carros);
                    printf("\nOutro carro? Digite S para Sim: ");
                    scanf(" %c", &sim);
                    limpa_tela();
                    }while(sim == 'S' || sim == 's');
                    imprime_moldura();//linha
                    break;
                case 3:
                    do{
                        do{
                            printf("Insira o codigo do aluguel entre [1] & [%d]: ", tamanho_alu);
                            scanf("%d", &codigo);
                            limpa_buffer();
                        }while(codigo < 1 || codigo > tamanho_alu);
                    limpa_tela();
                    info_aluguel(codigo, alugueis);
                    printf("\nOutro aluguel? Digite S para Sim: ");
                    scanf(" %c", &sim);
                    limpa_tela();
                    }while(sim == 'S' || sim == 's');
                    imprime_moldura();//linha
                    break;
                case 0:
                    saida_dentro = 0;
                    break;
                default:
                    printf("Opcao invalida\n");
                }
            }while(saida_dentro !=0);
            break;
        case 2:                     //INCLUSAO & ATUALIZACAO & REMOÇÃO
            do{
                tamanho_alu = checa_tamanho_aluguel(alugueis);
                tamanho_cli = checa_tamanho_cliente(clientes);
                tamanho_car = checa_tamanho_carro(carros);
                printf("Cadastrar um(a): \n\n");
                printf("(1)Novo Cliente                 (2)Novo Carro \n\n"
                       "(3)Novo Aluguel                 (4)Devolucao \n\n"
                       "(5)Remocao*\n\n");
                printf("___________________\n(0)VOLTAR AO MENU \n\n");
                printf("Escolha: ");
                scanf("%d", &escolha);
                limpa_tela();
                limpa_buffer();
                imprime_moldura();//linha
                switch(escolha){
                case 1:
                    novo_cliente(clientes);
                    imprime_moldura();//linha
                    break;
                case 2:
                    printf("Deseja adicionar um novo: \n\n"
                           "(1)Modelo                    (2)Unico Carro \n\n");
                    printf("Escolha: ");
                    scanf("%d", &escolha);
                    limpa_buffer();
                    limpa_tela();
                    switch(escolha){
                    case 1:
                        novo_carro(carros);
                        break;
                    case 2:
                        novo_carro_unico(carros);
                        break;
                    }
                    imprime_moldura();//linha
                    break;
                case 3:
                    printf("Cadastrar aluguel por: \n"
                            "(1)CNH*                 (2)Codigo do Cliente\n\n");
                    printf("=====================================");
                    printf("\n | -Temos Descontos! \t\t   |\n");
                    printf(" |\tDe 10 a 20 diarias -> 10 %c |\n", '%');
                    printf(" |\tDe 20 a 30 diarias -> 20 %c |\n", '%');
                    printf(" |\tMais de 30 diarias -> 30 %c |\n", '%');
                    printf("=====================================");
                    printf("\n\nEscolha: ");
                    scanf("%d", &escolha);
                    limpa_tela();
                    switch(escolha){
                    case 1:
                        novo_aluguel_por_cnh(alugueis, carros, clientes);
                        break;
                    case 2:
                        novo_aluguel(alugueis, carros, clientes);
                        break;
                    }
                    imprime_moldura();//linha
                    break;
                case 4:
                    printf("Registrar devolucao por: \n\n"
                            "(1)CNH do cliente*                 (2)Codigo do Aluguel\n\n");
                    printf("Escolha: ");
                    scanf("%d", &escolha);
                    switch(escolha){
                    case 1:
                        devolucao_por_cnh(clientes, alugueis, carros);
                        break;
                    case 2:
                        do{
                            printf("Insira o codigo do aluguel entre [1] & [%d]: ", tamanho_alu);
                            scanf("%d", &codigo);
                            limpa_tela();
                            limpa_buffer();
                        }while(codigo < 1 || codigo > tamanho_alu);
                        devolucao(codigo, alugueis, carros);
                        imprime_moldura();//linha
                        break;
                    default:
                        printf("Opcao invalida\n");
                        }
                    break;
                case 5:
                    do{
                        tamanho_cli = checa_tamanho_cliente(clientes);
                        printf("Remover um:\n\n");
                        printf("(1)Cliente                      (2)Carro\n\n"
                            "___________________\n(0)SAIR"
                            "\n\n");
                        printf("Escolha: ");
                        scanf("%d", &escolha);
                        limpa_tela();
                        limpa_buffer();
                        imprime_moldura();//linha
                        switch(escolha){
                        case 1:
                            banco_de_dados_cliente(clientes);
                            imprime_moldura();//linha
                            printf("Remocao de clientes: \n");
                            do{
                                printf("Informe o codigo do cliente a ser removido entre [1] & [%d]: ", tamanho_cli);
                                scanf("%d", &codigo);
                            }while(codigo < 1 || codigo > tamanho_cli);
                            printf("\n>>> ATENCAO: Remover um cliente ira tambem remover TODOS os alugueis relacionados ao mesmo.");
                            printf("\nTem certeza que deseja remover esse cliente? Digite S para Sim: ");
                            scanf(" %c", &sim);
                            if(sim == 's' || sim == 'S'){
                                remove_cliente(codigo, clientes);
                                remove_aluguel_do_cliente(codigo, alugueis);
                            }
                            imprime_moldura();//linha
                            break;
                        case 2:
                            banco_de_dados_carro(carros);
                            imprime_moldura();//linha
                            remove_carro(carros);
                            imprime_moldura();//linha
                            break;
                        case 0:
                            saida_dentro2 =0;
                            break;
                        default:
                            printf("Opcao invalida\n");
                        }
                    }while(saida_dentro2 != 0);
                    break;
                case 0:
                    saida_dentro = 0;
                    break;
                default:
                    printf("Opcao invalida\n");
                }
            }while(saida_dentro !=0);
            break;
        case 3:                     //RELATORIOS
            do{
                printf("Listar: \n\n");
                printf("(1)Carros por marca             (2)Carros por marca(ordem de preco)\n\n"
                       "(3)Clientes                     (4)Alugueis do cliente\n\n"
                       "(5)Alugueis Ativos \n\n");
                printf("___________________\n(0)VOLTAR AO MENU \n\n");
                printf("Escolha: ");
                scanf("%d", &escolha);
                limpa_tela();
                limpa_buffer();
                imprime_moldura();//linha
                switch(escolha){
                case 1:
                    printf("Informe a marca: ");
                    fgets(marca, 50, stdin);
                    marca[strlen(marca)-1] = '\0';    //remove o '\n'
                    limpa_tela();
                    lista_carros(marca, carros);
                    imprime_moldura();//linha
                    break;
                case 2:
                    printf("Informe a marca: ");
                    fgets(marca, 50, stdin);
                    marca[strlen(marca)-1] = '\0';    //remove o '\n'
                    limpa_tela();
                    lista_carros_preco(marca, carros);
                    imprime_moldura();//linha
                    break;
                case 3:
                    lista_clientes(clientes);
                    imprime_moldura();//linha
                    break;
                case 4:
                    do{
                        printf("Insira o codigo do cliente entre [1] & [%d]: ", tamanho_cli);
                        scanf("%d", &codigo);
                        limpa_tela();
                        limpa_buffer();
                    }while(codigo < 1 || codigo > tamanho_cli);
                    lista_alugueis(codigo, alugueis);
                    imprime_moldura();//linha
                    break;
                case 5:
                    lista_atrasados(alugueis, clientes);
                    imprime_moldura();//linha
                    break;
                case 0:
                    saida_dentro = 0;
                    break;
                default:
                    printf("Opcao invalida\n");
                }
            }while(saida_dentro != 0);
            break;
        case 4:
            do{
                printf("Exibir dados salvos de:\n\n");
                printf("(1)Alugueis              (2)Carros              (3)Clientes\n\n"
                        "___________________\n(0)SAIR"
                        "\n\n");
                printf("Escolha: ");
                scanf("%d", &escolha);
                limpa_tela();
                limpa_buffer();
                imprime_moldura();//linha
                switch(escolha){
                case 1:
                    banco_de_dados_aluguel(alugueis);
                    imprime_moldura();//linha
                    break;
                case 2:
                    banco_de_dados_carro(carros);
                    imprime_moldura();//linha
                    break;
                case 3:
                    banco_de_dados_cliente(clientes);
                    imprime_moldura();//linha
                    break;
                case 0:
                    saida_dentro =0;
                    break;
                default:
                    printf("Opcao invalida\n");
                }
            }while(saida_dentro != 0);
            break;
        case 0:
            saida = 0;
            break;
        default:
            printf("Opcao invalida\n");
        }
        grava_alugueis(alugueis);
        grava_carros(carros);
        grava_clientes(clientes);
    }while(saida != 0);
    return 0;
}

void imprime_moldura()                       //Funcao que imprime uma linha de "Moldura"
{
    int i;
    for(i=0; i<110; i++)
        printf("=");
    printf("\n");
    return;
}

void limpa_buffer() {                       //Função que limpa o buffer de entrada
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}
