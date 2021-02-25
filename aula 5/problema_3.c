// Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>

int main()
{
    int pop, soma = 0, max_pop = 0, i = 0;
    float media;
    char sim;

    printf("Deseja continuar?\n");
    scanf(" %c", &sim);

while (sim == 's')
{
    printf("Informe a populacao:\n");
    scanf("%d", &pop);
    soma = soma + pop;
    i++;
    if (pop > max_pop)
        max_pop = pop;
    printf("Deseja continuar?\n");
    scanf(" %c", &sim);
}
media = soma / i;

printf("A media da populacao entre as %i cidades e %f e a maior populacao e %d\n", i, media, pop);

 return 0;
}
