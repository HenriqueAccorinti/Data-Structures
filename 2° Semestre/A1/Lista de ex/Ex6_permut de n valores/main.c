#include <stdio.h>
#include <stdlib.h>

void trocar(int vetor[], int i, int j);
void ExibirVetor(int v[]);
int perm(int v[], int k, int n );

int main(void) {
    int v[] = {1, 2, 3, 4};
    perm(v, 0, 4);
    return 0;
}

//Exibir um Vetor v[]
void ExibirVetor(int v[]){
    int i,N=4;

    for(i=0;i<N;i++){
        printf("%i ", v[i]);
    }
    printf("\n");
}

void trocar(int vetor[], int i, int j){
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int perm(int v[], int k, int n ){
    int i;

    if(k==n-1){
        ExibirVetor(v);
    }
    else{
        for(i=k;i<n;i++){
            trocar(v,k,i);
            perm(v,k+1,n);
            trocar(v,k,i);
        }
    }
}
