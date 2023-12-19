#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/////menu/////

////alunos
////////////Allan M. A. Barcessat - 20.00045-6
///////////Henrique Accorinti - 20.00080-4
//////////Luiza Caparrós - 20.00857-0

void menu();

float soma(float, float);

float subtrac(float, float);

float multiplica(float, float);

float divide(float, float);

float potencia(float, float);

float raiz(float, float);

float seno(float);

float cosseno(float);


////principal////
int main(){
    int op = 0;
    float x,y,r;

    while(op != 9){
        system("CLS");
        menu();
        printf("\nEntre com a opcao desejada: ");
        scanf("%i", &op);

        switch (op){
            case 1:
                printf("Soma\n");
                printf("\nEntre com o primeiro valor: ");
                scanf("%f", &x);
                printf("\nEntre com o segundo valor: ");
                scanf("%f", &y);
                r = soma(x,y);
                printf("\nResultado: %.2f\n",r);
                break;

            case 2:
                printf("\nSubtracao\n");
                printf("\nEntre com o primeiro valor: ");
                scanf("%f", &x);
                printf("\nEntre com o segundo valor: ");
                scanf("%f", &y);
                r = subtrac(x,y);
                printf("\nResultado: %.2f\n",r);
                break;

            case 3:
                printf("\nMultiplicacao\n");
                printf("\nEntre com o primeiro valor: ");
                scanf("%f", &x);
                printf("\nEntre com o segundo valor: ");
                scanf("%f", &y);
                r = multiplica(x,y);
                printf("\nResultado: %.2f\n",r);
                break;

            case 4:
                printf("\nDivisao\n");
                printf("\nEntre com o primeiro valor: ");
                scanf("%f", &x);
                printf("\nEntre com o segundo valor: ");
                scanf("%f", &y);
                while (y==0){
                printf("Valor invalido");
                printf("\nEntre com o segundo valor: ");
                scanf("%f", &y);
                }
                r = divide(x,y);
                printf("\nResultado: %.2f\n",r);
                break;


            case 5:
                printf("\nPotencia\n");
                printf("\nEntre com o valor da base: ");
                scanf("%f", &x);
                printf("\nEntre com o valor do expoente: ");
                scanf("%f", &y);
                r = potencia(x,y);
                printf("\nResultado: %.2f\n",r);
                break;

            case 6:
                printf("\nRaiz N-esima\n");
                printf("\nEntre com o valor da base: ");
                scanf("%f", &x);
                printf("\nEntre com o valor do indice: ");
                scanf("%f", &y);
                r = raiz(x,y);
                printf("\nResultado: %.2f\n",r);
                break;

            case 7:
                printf("\nSeno\n");
                printf("\nEntre com o valor do angulo em graus: ");
                scanf("%f", &x);
                r = seno(x);
                printf("\nResultado: %.2f\n",r);
                break;

            case 8:
                printf("\nCosseno\n");
                printf("\nEntre com o valor do angulo em graus: ");
                scanf("%f", &x);
                r = cosseno(x);
                printf("\nResultado: %.2f\n",r);
                break;

            case 9:
                printf("\nSair\n");
                break;

            default:
                printf("\nOpcao Invalida\n");
                break;
        }
        system("pause");
    }
    printf("\n\nfim....\n\n");

    return 0;}

/////funções/////
void menu(){
    printf("\nCalculadora....\n\n"); //
    printf("1 - Soma\n");     //
    printf("2 - Subtracao\n"); //
    printf("3 - Multiplicacao\n");//
    printf("4 - Divisao\n"); //
    printf("5 - Potencia\n");
    printf("6 - Raiz\n");
    printf("7 - Sen\n");
    printf("8 - Cos\n");
    printf("9 - Sair\n");
}
float soma(float x,float y){
    return x + y;
}

float subtrac(float x, float y){
    return x - y;
}

float multiplica(float x, float y){
    return x*y;
}
float divide(float x, float y){
    return x/y;
}

float potencia(float x, float y){
    return pow(x,y);
}

float raiz(float x, float y){
    return pow(x,1/y);
}
float seno(float x){
    x = (x*M_PI)/180;
    return sin(x);
}

float cosseno(float x){
    x = (x*M_PI)/180;
    return cos(x);
}
