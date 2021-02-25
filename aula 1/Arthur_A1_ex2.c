// Arthur Antonio Soutelo Araujo - 00304292

// Esse programa tem o objetivo de realizar a soma entre dois numeros

#include <stdio.h>

int main()
{
    int val1, val2; //Declaracao das variaveis de entrada
    int soma; //Declaracao da variavel com o resultado

    printf ("Primeiro numero\n");
    scanf("%d", &val1);

    printf("Segundo numero\n");
    scanf("%d", &val2);

    soma = val1 + val2;

    printf("A soma e:\n%d\n", soma);

    return 0;
}
