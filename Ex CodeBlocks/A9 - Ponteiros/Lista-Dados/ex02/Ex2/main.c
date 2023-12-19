#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void lerArquivo(FILE *arq);

    //Exibição
    arquivo = fopen("registros.csv","r");

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
