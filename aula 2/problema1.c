//Arthur Antonio Soutelo Araujo - 00304292

#include <stdio.h>
#include <math.h>

int main()
{
    float franquia;
    float valor1, valor2;
    float peso1, peso2;

    printf("Informe o valor da franquia:\n");
    scanf("%f", &franquia);

    printf("Valor do primeiro pacote:\n");
    scanf("%f", &valor1);
    printf("Peso do primeiro pacote:\n");
    scanf("%f", &peso1);
    printf("Valor do segundo pacote:\n");
    scanf("%f", &valor2);
    printf("Peso do segundo pacote:\n");
    scanf("%f", &peso2);

    if ((peso1 > franquia) && (peso2 > franquia)) // analisa se ambos os pacotes estao no limite
        printf("Nao é possivel levar nenhum dos pacotes pois ambos ultrapassam o limite\n");
    else if ((peso1 > franquia) && (peso2 < franquia))
        printf ("O pacote que deve ser levado na bagagem e o Segundo\n");
    else if ((peso1 < franquia) && (peso2 > franquia))
        printf ("O pacote que deve ser levado na bagagem e o Primeiro\n");
    else if ((peso1 + peso2) <= (franquia)) // analisa se é possivel levar os dois pacotes ou se sera necessario escolher um
        printf ("Ambos os pacotes podem ser levados na bagagem!\n");
    else if (((peso1 + peso2) > (franquia)) && (valor1 >= valor2)) // se o valor do primeiro for maior que o do segundo, escolhe o primeiro
        printf ("O pacote que deve ser levado na bagagem e o Primeiro\n");
    else if (((peso1 + peso2) > (franquia)) && (valor1 < valor2)) // se o valor do segundo for maior que o do primeiro, escolhe o segundo
        printf ("O pacote que deve ser levado na bagagem e o Segundo\n");


    return 0;
}
