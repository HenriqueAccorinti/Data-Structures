#include <stdio.h>
#include <stdlib.h>
/*
int fatorial(int n );

int main(){

    int N = 6;
    int resultado;

    resultado = fatorial(N);
    printf("Resultado: %i\n",resultado);

    return 0;
}

int fatorial(int n ){
    if(n == 0){
        return 1;
    }
    else{
        return n*fatorial(n-1);
    }
}


int mult(int n, int m );

int main(){

    int a=5;
    int b=3;
    int resultado;

    resultado = mult(a,b);
    printf("Resultado: %i\n",resultado);

    return 0;
}

int mult(int n,int m){
    if(m == 0){
        return 0;
    }
    else{
        return n+mult(n,m-1);
    }
}
*/

int fibonacci(int n );

int main(){

    int N = 9;
    int resultado;

    resultado = fibonacci(N);
    printf("Resultado: %i\n",resultado);

    return 0;
}

int fibonacci(int n ){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
