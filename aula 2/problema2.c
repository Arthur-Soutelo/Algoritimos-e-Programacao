//Arthur Antonio Soutelo Araujo - 00304292

#include <stdio.h>
#include <math.h>

int main()
{
    int segundos, minutos, horas, dias;

    printf("Quantos segundos?\n");
    scanf("%d", &segundos);

    dias = (segundos / 86400);
    segundos = (segundos % 86400);
    horas = (segundos / 3600);
    segundos = (segundos % 3600);
    minutos = (segundos / 60);
    segundos = (segundos % 60);

    printf ("Isso e igual a:\n%d dias, %d horas, %d minutos, %d segundos", horas, minutos, segundos);

    return 0;
}
