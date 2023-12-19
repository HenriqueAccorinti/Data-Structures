#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING 20

void lerLinha(char s[], FILE *arquivo);

int main(){
    //Realiza a abertura do arquivo
    FILE *arquivo = fopen("valores.csv", "r");

    //Verifica se o arquivo foi aberto
    if(arquivo == NULL){
        printf("Erro ao carregar o arquivo\n");
        exit(EXIT_FAILURE);
        
    } 

    FILE *arquivo_saida = fopen("tabela.csv", "w");

    while(!feof(arquivo)){
        char linha[MAX_STRING];
        lerLinha(linha, arquivo);
        float valor = atof(linha);
        fprintf(arquivo_saida, "%f;%f\n", valor, valor >= 0? log(valor):0);
        
    }

    fclose(arquivo);
    fclose(arquivo_saida);
    return 0;
}

void lerLinha(char s[], FILE *arquivo){
    fgets(s, MAX_STRING, arquivo);
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}