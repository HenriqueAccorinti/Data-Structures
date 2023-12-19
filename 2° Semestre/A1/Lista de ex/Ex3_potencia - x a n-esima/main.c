#include <stdio.h>
#include <stdlib.h>

float pot(float x, float n );

int main(){

    float x = 9.2, n = 2;
    float resultado;

    resultado = pot(x,n);
    printf("Resultado: %.2f\n",resultado);

    return 0;
}

float pot(float x, float n ){
    if(n == 0){
        return 1;
    }
    else if(n/2 == 0){
        return pot(x*x,n/2);
    }
    else{
        return pot(x,n-1)*x;
    }
}
