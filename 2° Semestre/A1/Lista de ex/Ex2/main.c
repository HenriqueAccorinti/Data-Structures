#include <stdio.h>
#include <stdlib.h>

int busca_linear(int i, int n, int v[]);

int main(){
    int n, valor;
    int v[] = {2,4,6,8,10,12,14};
    int i = sizeof(v) - 1;

    printf("Digite o valor de n: ");
    scanf("%i", &n);

    valor = busca_linear(i, n, v);
    printf("O numero desejado esta na posicao %i\n", valor + 1);

    return 0;
}

int busca_linear(int i, int n, int v[]){
    if(v[i/2] == n){
        return i/2;
    }
    else if(v[i/2] > n){
        return busca_linear(i/2,n,v);
    }
    else{
        return busca_linear((3*i)/2,n,v);
    }
}
