// Arthur Antonio Soutelo Araujo - 00304292

// Esse programa tem o objetivo de realizar a soma entre dois numeros

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float val1, val2, val3; //Declaracao das variaveis de entrada
    float soma; //Declaracao da variavel com a soma
    float produto; //Declaracao da variavel com o produto

    printf ("Primeiro numero\n");
    scanf("%f", &val1); // Leitura do valor

    printf("Segundo numero\n");
    scanf("%f", &val2);

    printf("Terceiro numero\n");
    scanf("%f", &val3);

    soma= val1+val2+val3;
    produto=val1*val2*val3;

    printf("A soma e:\n%.3f", soma);

    printf("\nE o produto e: \n%.3f\n", produto);

    return 0; //Encerra o programa
}
