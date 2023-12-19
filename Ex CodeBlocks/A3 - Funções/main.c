#include <stdio.h>
#include <stdlib.h>

float Media(int , int , int );
void exibeMaior(int , int );

int main(){

    int a, b;
    float media;

    printf("Digite o valor de a: ");
    scanf("%i",&a);

    printf("Digite o valor de b: ");
    scanf("%i",&b);

    //media = Media(a,b,5);
    //printf("O valor da media eh: %.2f",media);

    exibeMaior(a,b);

    return 0;
}

void exibeMaior(int a, int b){
    if(a>b){
        printf("A maior que b");
    }
    else if (a<b){
        printf("A menor que b");
    }
    else{
        printf("A = b");
    }
}

float Media(int a, int b, int c){
    float m;
    m = (a+b+c)/3.0;
    return m;
}

