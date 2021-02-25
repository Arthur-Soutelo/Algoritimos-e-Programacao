/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur Antonio Soutelo Araujo
Cartao UFRGS : 00304292
*/
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

typedef struct{
    int codigo_cliente;
    char nome[50];
    char cnh[15];
    char ddd[4];
    char telefone[11];
}cliente_t;

void grava_clientes(cliente_t *clientes);
void info_cliente(int codigo, cliente_t *clientes);
void lista_clientes(cliente_t *clientes);
void leitura_clientes(cliente_t *clientes);
void novo_cliente(cliente_t *clientes);

void imprime_moldura();
int checa_tamanho_cliente(cliente_t *clientes);
void banco_de_dados_cliente(cliente_t *clientes);
void limpa_buffer();
void remove_cliente(int codigo, cliente_t *clientes);

#endif // CLIENTE_H_INCLUDED
