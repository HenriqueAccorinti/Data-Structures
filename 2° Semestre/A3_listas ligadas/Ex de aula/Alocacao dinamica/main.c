#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, *dados;
    printf("Informe o tamanho do vetor: ");
    scanf("%i", &n);
    dados = (int*) malloc(n * sizeof(int));

    printf("Digite %i elementos:\n",n);
    for (i = 0; i < n; i++)
        scanf("%i", (dados+i) );

    for (i = 0; i < n; i++)
        printf("Elemento na posicao %p: %i\n",(dados+i), *(dados+i) );

    free(dados);
    return 0;
}
