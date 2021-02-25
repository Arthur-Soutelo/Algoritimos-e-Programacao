//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#include <string.h>

int main()
{
    int tamanho, i = 0,j = 0;
    char nome[60];
    char contr[60];

    printf("Informe o nome completo (maximo 60 caracteres) do autor do gol contra:\n");
    fgets (nome, 60 , stdin);
    strtok(nome, "\n");
    tamanho = strlen(nome);

    while (nome[i] != ' ')
        i++;
    for (; i >= 0; i--)
    {
        contr[j] = nome[i-1];
        j++;
    }
        contr[j]='\0';
        printf("O primeiro nome ao contrario e: <%s>\n", contr);
        printf("O nome completo <%s> tem %d caracteres:\n", nome, tamanho);

    return 0;
}
