// Nome: Arthur Antonio Soutelo Araujo
// Cartao UFRGS: 00304292

#include <stdio.h>

int main()
{
    int presenca;
    float nota1, nota2, media;

    printf("Numero de presencas:\n");
    scanf ("%d", &presenca);

    if (presenca >= 8 && presenca <11)
    {
        printf("Nota da primeira avaliacao:\n");
        scanf("%f", &nota1);
        printf("Nota da segunda avaliacao:\n");
        scanf("%f", &nota2);
    media = (nota1+nota2)/2;
        if (media >= 6)
        printf("Aluno aprovado com media %.2f", media);
        else
        printf("Aluno reprovado com media %.2f", media);
    }
    else
    printf("Aluno reprovado por faltas");
    return 0;
}
