//Arthur Antonio Soutelo Araujo - 00304292

#include <stdio.h>
#include <math.h>

int main()
{
    float parte_real1, parte_imag1;
    float parte_real2, parte_imag2;
    float resposta_real, resposta_imag;

    printf("Informe respectivamente a parte real e imaginaria do primeiro numero complexo:\n");
    scanf("%f %f", &parte_real1, &parte_imag1);
    printf("Informe respectivamente a parte real e imaginaria do segundo numero complexo:\n");
    scanf("%f %f", &parte_real2, &parte_imag2);

    resposta_real = (parte_real1 + parte_real2);
    resposta_imag = (parte_imag1 + parte_imag2);

    printf ("A soma entre os dois numeros complexos e:\n %.3f + %.3fi", resposta_real, resposta_imag);

    return 0;

}
