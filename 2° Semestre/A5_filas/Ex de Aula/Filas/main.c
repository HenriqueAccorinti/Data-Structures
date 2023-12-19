#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    TFila fila;
    Dados dado;
    int n, i;

    CriarFila(&fila);

    printf("Digite a quantidade de valores: ");
    scanf("%i",&n);

    for(i=0;i<n;i++){
        printf("\nValor: ");
        scanf("%f",&dado.valor);
        InserirNaFila(&fila,dado);
    }

    ExibirFila(fila);

    return 0;
}
