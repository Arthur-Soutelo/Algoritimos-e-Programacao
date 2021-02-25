/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur Antonio Soutelo Araujo
Cartao UFRGS : 00304292
*/
#ifndef CARRO_H_INCLUDED
#define CARRO_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

typedef struct{
    int codigo_carro;
    char marca[50];
    char modelo[50];
    int ano;
    char placa[10];
    float valor_diaria;
    float valor_seguro;
    int quantidade;
}carro_t;

void grava_carros(carro_t *carros);
void info_carro(int codigo, carro_t *carros);
void leitura_carros(carro_t *carros);
void lista_carros(char *marca, carro_t *carros);
void lista_carros_preco(char *marca, carro_t *carros);
void novo_carro(carro_t *carros);

void imprime_moldura();
int checa_tamanho_carro(carro_t *carros);
void banco_de_dados_carro(carro_t *carros);
void limpa_buffer();
void remove_carro(carro_t *carros);
void novo_carro_unico(carro_t *carros);

#endif // CARRO_H_INCLUDED
