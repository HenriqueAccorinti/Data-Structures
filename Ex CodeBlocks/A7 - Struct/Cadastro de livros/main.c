#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    char titulo[MAX];
    int quantidade;
    char genero[MAX];
} Livro;

void LerString(char s[]);
void Exibir(int N, Livro L[N]);
void Ordenar(int N, Livro L[N]);

int main(){
    int i,N;

    printf("Quantos livros deseja cadastrar? ");
    scanf("%i",&N);
    printf("\n");

    Livro L[N];

    for(i=0;i<N;i++){
        printf("Titulo do livro %i: ",i+1);
        LerString(L[i].titulo);

        printf("Quantidade de livros '%s': ",L[i].titulo);
        scanf("%i",&L[i].quantidade);

        printf("Genero do livro '%s': ",L[i].titulo);
        LerString(L[i].genero);

        printf("\n\n");
    }

    Ordenar(N, L);
    Exibir(N, L);

    return 0;
}

void LerString(char s[]){
    fflush(stdin);
    fgets(s, MAX, stdin);
    if(s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}

void Ordenar(int N, Livro L[N]){
    int i,j;
    char aux;

    for(i=(N-1); i<1; i--){
        for(j=0; j<(i-1); j++){

            if(L[j].titulo > L[j+1].titulo){
                strcpy(aux, L[j].titulo);
                strcpy(L[j].titulo, L[j+1].titulo);
                strcpy(L[j+1].titulo, aux);

            }
        }
    }
}


void Exibir(int N, Livro L[N]){
    int i;

    printf("Resumo:\n\n");
    printf("Titulo\t\t");
    printf("Qtd\t");
    printf("Genero");
    printf("\n\n");

    for(i=0;i<N;i++){
        printf("%-15s\t", L[i].titulo);
        printf("%i\t", L[i].quantidade);
        printf("%s\t", L[i].genero);
        printf("\n");
    }
}
