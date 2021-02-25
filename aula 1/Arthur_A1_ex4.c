// Arthur Antonio Soutelo Araujo - 00304292

// Esse programa tem o objetivo de realizar a soma entre dois numeros

#include <stdio.h>

int main()
{
    float val1, val2; //Declaracao das variaveis de entrada
    float soma; //Declaracao da variavel com o resultado

    printf ("Primeiro numero\n");
    scanf("%f", &val1);

    printf("Segundo numero\n");
    scanf("%f", &val2);

    soma = val1 + val2;

    printf("A soma e:\n%f\n", soma);

    return 0;
}
