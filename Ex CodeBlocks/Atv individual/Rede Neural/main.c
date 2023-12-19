#include <stdio.h>
#include <stdlib.h>
#define N 5

void lerVetor(int []);
void ExibeVetor(float [], int);

int main()
{
    int i, soma=0;
    float Ent[N],Peso[N],Mult[N];

    lerVetor(Ent);
    printf("\n");
    lerVetor(Peso);

    ExibeVetor(Ent,N);
    ExibeVetor(Peso,N);

    for(i=0;i<N;i++){
        Mult[i]=Ent[i]*Peso[i];
        printf("%.2f", Mult[i]);
        soma += Mult[i];
    }

    if(soma>0){
        printf("Saida 1");
    }else{
        printf("Saida 0");
    }

    return 0;
}

//sub-rotinas
void lerVetor(int v[]){
    int i;

    for(i=0;i<N;i++){
        printf("entre com o valor[%i]: ",i);
        scanf("%i",&v[i]);
    }
}

void ExibeVetor(float V[N], int n) {
	int i;
	printf("\n( ");
	for (i = 0; i<N; i++) {
		printf("%.2f ", i);
	}
	printf(")\n\n");
}
