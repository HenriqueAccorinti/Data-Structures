#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    char nome[MAX];
    int idade;
    char armadura[MAX];
    int atingiuSetimoSentido;
} Cavaleiro;

int main(){

    Cavaleiro ouro[3];
    Cavaleiro teste;
    int valor,i;
    char leitura[MAX];

    for(i=0;i<3;i++){
        printf("Entre com o valor para a idade: ");
        scanf("%i",&ouro[i].idade);
        printf("Atingiu: ");
        scanf("%i",&ouro[i].atingiuSetimoSentido);
    }
    printf("\n\n");

    for(i=0;i<3;i++){
        printf("Idade do ouro[%i]: %i\n",i,ouro[i].idade);
        printf("Atingiu: %i\n",ouro[i].atingiuSetimoSentido);
    }

    printf("Entre com o valor para a idade: ");
    scanf("%i",&teste.idade);
    printf("Idade do teste: %i\n",teste.idade);

    return 0;
}
