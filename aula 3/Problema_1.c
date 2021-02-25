// Nome: Arthur Antonio Soutelo Araujo
// Cartao UFRGS: 00304292

#include <stdio.h>

int main ()
{
    int idade;
    float peso, altura;

    printf ("Informe a Idade:\n");
    scanf ("%d", &idade);
    printf ("Informe a Altura:\n");
    scanf ("%f", &altura);
    printf ("Informe o Peso:\n");
    scanf ("%f", &peso);

    if (idade < 15)
        printf("\nO atleta tem %d anos, logo se enquadra na categoria Sub-15 ou Infantil", idade);
    else if (idade >= 15 && idade < 17)
        printf("\nO atleta tem %d anos, logo se enquadra na categoria Sub-17 ou Juvenil", idade);
    else if (idade >=17 && idade < 20)
        printf("\nO atleta tem %d anos, logo se enquadra na categoria Sub-20 ou Juniores", idade);
    else if (idade >= 20 && idade < 23)
        printf("\nO atleta tem %d anos, logo se enquadra na categoria Sub-23 ou Olimpica", idade);
    else
        printf("\nO atleta tem %d anos, logo nao se enquadra em nenhuma categoria", idade);

    return 0;
}
