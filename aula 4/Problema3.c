//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

// Mensalidade Neymar

#include <stdio.h>

int main()
{
    float valorx, valory, pagar, diferenca;
    int i, ano = 2020;

    printf("Informe o valor mensal do servico no momento do contrato:\n");
    scanf("%f", &valorx);
    valory = valorx;

    printf("Em 2019, Neymar vai pagar mensalmente %.2f euros pelo servico.\n\n", valorx);
    for (i = 0; i < 4; i++, ano ++)
    {
        pagar = valory * 1.053;
        valory = pagar;
        printf("Em %d, Neymar vai pagar mensalmente %.2f euros pelo servico.\n\n", ano, pagar);
    }
    diferenca = pagar - valorx;
    printf("A mensalidade no ultimo ano tem valor de %.2f euros.\nTeve u
           m aumento de %.2f euros sobre o valor inicial de %.f euros.\n", pagar, diferenca, valorx);
    return 0;
}
