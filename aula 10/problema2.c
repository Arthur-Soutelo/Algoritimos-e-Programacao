//Nome: Arthur Antonio Soutelo Araujo
//Cartao UFRGS: 00304292

#include <stdio.h>
#define NUM 2

float calculo(float peso, float altura){
    int imc;

    imc = peso / (altura*altura);

    return imc;
}

float leitura(){
    int lido;

        do{
            scanf("%f", &lido);
        }while(lido < 0);

    return lido;
}

void categoria(float peso, float altura){

        if (calculo(peso, altura) < 17)
            printf("Resultado: Muito abaixo do peso");
        else if (calculo(peso, altura) >= 17 && calculo(peso, altura) < 18.5)
            printf("Resultado: Abaixo do peso");
        else if (calculo(peso, altura) >= 18.5 && calculo(peso, altura) < 25)
            printf("Resultado: Peso Normal");
        else if (calculo(peso, altura) >= 25 && calculo(peso, altura) < 30)
            printf("Resultado: Acima do Peso");
        else if (calculo(peso, altura) >= 30 && calculo(peso, altura) < 35)
            printf("Resultado: Obesidade I");
        else if (calculo(peso, altura) >= 35 && calculo(peso, altura) < 40)
            printf("Resultado: Obesidade II (severa)");
         else if (calculo(peso, altura) > 40)
            printf("Resultado: Obesidade III (morbida)");
    return;
}

int main(){
    float peso, altura, imc = 1, imc_menor = 1000;
    float m_altura, m_peso;
    int i;

    for(i = 0; i < NUM; i++){
        printf("\nInforme a altura da %da pessoa em [m]: ", i+1);
        altura = leitura();
        printf("Informe o peso da %da pessoa em [kg]: ", i+1);
        peso = leitura();

        categoria(peso, altura);
        printf("\n");

        if (imc < imc_menor){
            imc_menor = imc;
            m_altura = altura;
            m_peso = peso;
        }
    }

        printf("\nA altura e o peso da pessoa com o menor IMC sao: %.3f e %.3f", m_altura, m_peso);

    return 0;
}
