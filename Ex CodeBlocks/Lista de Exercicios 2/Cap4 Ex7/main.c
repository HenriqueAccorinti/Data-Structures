#include <stdio.h>
#include <stdlib.h>

void menu(){
    printf("\nEstados....\n\n");
    printf("1 - MG\n");
    printf("2 - SP\n");
    printf("3 - RJ\n");
    printf("4 - MS\n");
    printf("5 - Sair");
}


float imposto(float preco, int op){
    if(op == 1){
        preco *= 1.07;
        }
    if(op == 2){
        preco *= 1.12;
        }
    if(op == 3){
        preco *= 1.15;
        }
    if(op == 4){
        preco *= 1.08;
        }
    return preco;
}

int main()
{
int op = 0;
float preco, b;
while(op != 5){
        system("CLS");
        menu();

        printf("\nEntre com Estado desejado: ");
        scanf("%i", &op);

        if (op < 5){
        printf("Informe o valor do produto, por favor: ");
        scanf("%f",&preco);

        b = imposto(preco,op);
        printf("O valor com acrescimo de imposto sera de: %.2f\n", b);

        system("pause");
        }
}
return 0;
}
