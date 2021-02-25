//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

// Programa que calcula o IMC

#include <stdio.h>

int main()
{
    float peso, altura, imc = 1, imc_menor = 1000;
    float m_altura, m_peso;
    int i;


        for(i = 0; i < 12; i++)
        {
        printf("Insira a altura:\n");
        scanf("%f", &altura);
        printf ("Insira o peso:\n");
        scanf("%f", &peso);

        imc = peso / (altura*altura);

        if (imc < imc_menor)
            {
            imc_menor = imc;
            m_altura = altura;
            m_peso = peso;
            }
        }
        printf("A altura e o peso da pessoa com o menor IMC sao: %f e %f", m_altura, m_peso);

    return 0;
}
