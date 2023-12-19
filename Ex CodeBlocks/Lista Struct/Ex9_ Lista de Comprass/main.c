#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    char produto;
    float preco;
} Compras;


int main()
{
    Compras lista[100];
    int i, N;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%i",&N);
    printf("\n");

    for(i=0;i<N;i++){
        printf("Produto: ");
        LerString(lista[i].produto);
        printf("Preco: ");
        scanf("%f", &lista[i].preco);
        printf("\n");

        printf("Produto: %c" ,lista[i].produto);
        printf("Preco: %.2f", lista[i].preco);
    }

    return 0;
}


void LerString(char s[]){
    fflush(stdin);
    fgets(s, MAX, stdin);
    if(s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}
