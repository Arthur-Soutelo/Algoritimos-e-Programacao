// Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>

int main()
{
    int sem = 21, dia = 0;

    while (sem >= 0)
    {

        printf("Faltam %d semanas e %d dias para o nascimento!!\n", sem, dia);
    if (dia == 0 && sem > -1)
        {
        dia = 6;
        sem--;
        }
    else
        dia --;

    }

    printf ("Nasceu!\n");

    return 0;
}
