#include <stdio.h>
#include <stdlib.h>

float comb(float n, float m);

int main(){

    float n = 9, m = 2;
    float resultado;

    resultado = comb(n,m);
    printf("Resultado: %.2f\n",resultado);

    return 0;
}

float comb(float n, float m){
    if(n!=0 && m==0){
        return 1;
    }
    else if(n == m){
        return 1;
    }
    else{
        return comb(n-1,m-1)+comb(n-1,m);
    }
}
