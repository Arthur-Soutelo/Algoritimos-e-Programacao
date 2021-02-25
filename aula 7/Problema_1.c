//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>

int main()
{
    int i;
    int pessoas ,pri=0, seg=0;
    float media, soma = 0;

    do
    {
    printf("Informe o numero total de participantes:\n");
    scanf("%d", &pessoas);
    }
    while (pessoas <= 0);
    float alturas[pessoas];

   for (i = 0; i < pessoas; i++)
    {
        printf("Informe a altura em metros do participante <%d>:\n", i+1);
        scanf("%f", &alturas[i]);
        soma += alturas[i];
    }

    media = soma / pessoas;
    printf("A media das alturas entre %d pessoas e: %.3f\n", pessoas, media);
    for (i = 0; i < pessoas; i++)
    {
        if (alturas[i] < media)
            pri++;
        else
            seg++;
    }
    printf ("%d participante(s) deve(m) ficar na primeira fileira.\n", pri);
    printf ("%d participante(s) deve(m) ficar na primeira fileira.\n", seg);
    return 0;
}
