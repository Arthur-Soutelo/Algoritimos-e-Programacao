//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int jogada(){
    int entrada;

    do{
        printf ("Escolha uma opcao:\n");
        printf ("(1) Pedra \n(2) Papel \n(3) Tesoura \n");
        scanf("%d", &entrada);
    }while (entrada != 1 && entrada != 2 && entrada != 3);

    return entrada;
}

void imprime(int entrada, int pc){
    switch(entrada){
    case 1:
        printf("Usuario jogou: >> Pedra\n");
        break;
    case 2:
        printf("Usuario jogou: >> Papel\n");
        break;
    case 3:
        printf("Usuario jogou: >> Tesoura\n");
        break;
    }
      switch(pc){
    case 1:
        printf("Programa jogou: >> Pedra\n");
        break;
    case 2:
        printf("Programa jogou: >> Papel\n");
        break;
    case 3:
        printf("Programa jogou: >> Tesoura\n");
        break;
    }
    return;
}

int calculo(int entrada, int jogada){
    int saida;

// 7 -> EMPATE, 8 -> vitoria do USUARIO, 9 -> vitoria do PROGRAMA

    if (entrada == jogada)
        saida = 7;
    else if (entrada == 1 && jogada == 2)
        saida = 9;
    else if (entrada == 1 && jogada == 3)
        saida = 8;
    else if (entrada == 2 && jogada == 1)
        saida = 8;
    else if (entrada == 2 && jogada == 3)
        saida = 9;
    else if (entrada == 3 && jogada == 1)
        saida = 9;
    else if (entrada == 3 && jogada == 2)
        saida = 8;

    return saida;
    }

int main(){
    int usuario, pc, saida;
    char sim;
    int rodadas = 1, vit_pc = 0, vit_usu = 0, empate = 0;
    srand(time(NULL));

    do{
        pc = (rand()%3)+1;
        usuario = jogada();

        imprime(usuario, pc);
        saida = calculo(usuario, pc);

        switch(saida){
        case 7:
            printf("Empate! \n");
            empate++;
            break;
        case 8:
            printf("Vitoria do Usuario!!\nVoce ganhou!! :) \n\n");
            vit_usu++;
            break;
        case 9:
            printf("Vitoria do Programa!\nVoce perdeu :( \n\n");
            vit_pc++;
            break;
        }
        printf("Digite S para jogar novamente: ");
        scanf(" %c", &sim);
        rodadas++;
    }while (sim == 's' || sim == 'S');

    printf("Empates: %d\n", empate);
    printf("Usuario venceu: %d\n", vit_usu);
    printf("Programa venceu: %d\n", vit_pc);

    return 0;
}
