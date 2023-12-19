#include <stdio.h>
#include <stdlib.h>

float Euclides(int m, int n);

int main(){

    //0 <= m < n
    int m = 2, n = 4;
    float resultado;

    resultado = Euclides(m,n);
    printf("Resultado: %.2f\n",resultado);

    return 0;
}

float Euclides(int m, int n){
    if(m==0){
        return n;
    }
    else{
        return Euclides(n%m,m);
    }
}
