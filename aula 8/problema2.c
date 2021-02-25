//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char cpf_char[11];
    int cpf[11];
    int i, j, somaj=0, somak=0;
    int pri, seg;

    printf ("Informe o CPF a ser verificado:\n");
    scanf("%s", cpf_char);
    for (i=0; i<11; i++)
    {
        cpf[i] = cpf_char[i] - '0';
    }
    printf("Os possiveis estados onde o CPF foi registrado sao:\n");
    switch (cpf_char[8])
    {
        case '1':
            printf("DF, GO, MT, MS e TO\n");
            break;
        case '2':
            printf("AC, AP, AM, PA, RO e RR\n");
            break;
        case '3':
            printf("CE, MA e PI\n");
            break;
        case '4':
            printf("AL, PB, PE e RN\n");
            break;
        case '5':
            printf("BA e SE\n");
            break;
        case '6':
            printf("MG\n");
            break;
        case '7':
            printf("ES e RJ\n");
            break;
        case '8':
            printf("SP\n");
            break;
        case '9':
            printf("PR e SC\n");
            break;
        case '0':
            printf("RS\n");
            break;
    }

// calcular j
        for (i=0; i<9; i++)
        {
            j=10-i;
            somaj += cpf[i]*j;
        }
        if (somaj % 11 == 0 || somaj % 11 == 1)
            pri = 0;
        else
            pri = 11 - (somaj%11);
// calcular k
        for (i=0; i<9; i++)
        {
            j=11-i;
            somak += cpf[i]*j;
        }
        somak += pri*2;
        if (somak % 11 == 0 || somak % 11 == 1)
            seg = 0;
        else
            seg = 11 - (somak%11);
//---------------------------------------------------
        if (seg == cpf[10] && pri == cpf[9])
            printf("CPF valido\n");
        else
            printf("CPF invalido\n");


    return 0;
}
