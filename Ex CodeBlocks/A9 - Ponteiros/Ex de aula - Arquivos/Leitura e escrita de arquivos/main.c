#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void lerArquivo(FILE *arq);

//ESCREVER NO ARQUIVO
int main(){

    FILE *arquivo;
    char linha[MAX];

    char c = '1';

    arquivo = fopen("arq.txt","w");

    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    while(c != '0'){
        printf("Digite um caractere: ");
        fflush(stdin);
        scanf("%c",&c);

        if(c != '0'){
            fprintf(arquivo,"%c\n",c);
        }
    }

    fclose(arquivo);


    //Exibição
    arquivo = fopen("arq.txt","r");

    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    printf("\n\nLeitura do arquivo\n");

    lerArquivo(arquivo);

    fclose(arquivo);


    return 0;
}

void lerArquivo(FILE *arq){
    char linha[MAX];

    while( fgets(linha,MAX,arq) != NULL ){ // laco para a leitura do restante
        printf("%s", linha);
    }

}
