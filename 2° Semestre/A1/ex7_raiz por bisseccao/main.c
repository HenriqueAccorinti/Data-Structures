#include <stdio.h>
#include <stdlib.h>

float funcao(float x);
float raiz(float a,float b);

int main()
{
    float a=1, b=2;

    resp = raiz(a,b);
    if(resp == -1){
        printf("Erroooou! A raiz da funcao nao esta no intervalo [a,b]");
    }
    return 0;
}

float f(float x){
    return x**6-x-1;
}

float raiz(float a,float b){
    if(f(a)*f(b)<0){
        c = (a+b)/2;
        raiz(a,b);
    }else{
        return -1;
    }

}
