/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur Antonio Soutelo Araujo
Cartao UFRGS : 00304292
*/
#ifndef ALUGUEL_H_INCLUDED
#define ALUGUEL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "carro.h"
#include "cliente.h"

#define MAX 1000

typedef struct{
    int codigo_aluguel;
    int codigo_cliente;
    int codigo_carro;
    int dia;
    int mes;
    int ano;
    int numero_diarias;
    float valor;
    char seguro; // 'S' ou 'N'
    char situacao; // 'L'(locado) ou 'E'(entregue)
}aluguel_t;

void leitura_alugueis(aluguel_t *alugueis);
void grava_alugueis(aluguel_t *alugueis);
void info_aluguel(int codigo_aluguel, aluguel_t *alugueis);
void novo_aluguel(aluguel_t *alugueis, carro_t *carros, cliente_t *clientes);
void lista_alugueis(int codigo, aluguel_t *alugueis);
void devolucao(int codigo, aluguel_t *alugueis, carro_t *carros);
void lista_atrasados(aluguel_t *alugueis, cliente_t *clientes);

int checa_tamanho_aluguel(aluguel_t *alugueis);
void imprime_moldura();
void limpa_buffer();
void banco_de_dados_aluguel(aluguel_t *alugueis);
void novo_aluguel_por_cnh(aluguel_t *alugueis, carro_t *carros, cliente_t *clientes);
void desconto_diarias(int *numero_diarias, float *valor_total);
void devolucao_por_cnh(cliente_t *clientes, aluguel_t *alugueis, carro_t *carros);
void remove_aluguel_do_cliente(int codigo, aluguel_t *alugueis);
#endif // ALUGUEL_H_INCLUDED

/*  Idendifica qual o sistema operacional para compatibilidade do comamdo do sistema de limpar a tela  */
#ifdef _WIN32
    #define limpa_tela() system("cls")
#elif _WIN64
    #define limpa_tela() system("cls")
#else
    #define limpa_tela() system("clear")
#endif // _WIN32

