#include <stdio.h>
#include <stdlib.h>

//HenriqueFortunaAccorinti
void cores(f){
    if(f == -2) printf("prateado");if(f == -1) printf("dourada");
    if(f == 0) printf("preto");if(f == 1) printf("marrom");
    if(f == 2) printf("vermelho");if(f == 3) printf("laranja");
    if(f == 4) printf("amarelo");if(f == 5) printf("verde");
    if(f == 6) printf("azul");if(f == 7) printf("violeta");
    if(f == 8) printf("cinza");if(f == 9) printf("branco");
}

int main(){

    int valor=0;
    int a,b;
    int f1,f2,f3;
    int f1f2;

    while(valor >= 0){
        printf("Qual eh o valor da resistencia? ");
        scanf("%i",&valor);
        if(valor>990000000){  //valor maximo que pode ser produzido
            printf("Valor invalido!\n");
        }
        else{
            b=valor;
            a=0;
            do {
                b = b/10;
                a=a+1;

            } while(b != 0);


            a=a+2;
            f3 = a-4;
            f1f2 = valor/pow(10,f3);
            f1 = f1f2/10;
            f2 = f1f2%10;

            printf("f1: %i\nf2: %i\nf3: %i\n",f1,f2,f3);
            cores(f1);
            printf("\n");
            cores(f2);
            printf("\n");
            cores(f3);
            printf("\n\n");
        }
    }

    printf("Fim...");

    return 0;
}
