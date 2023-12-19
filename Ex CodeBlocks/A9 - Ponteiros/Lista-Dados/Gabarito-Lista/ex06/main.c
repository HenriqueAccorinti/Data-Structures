#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 20

typedef struct {
    char nome[MAX_STRING];
    int idade;
    float altura;
}Atleta;


void lerLinha(char s[], FILE *arquivo);
Atleta lerAtleta(char linha[]);
Atleta encontraMaisVelho(Atleta atletas[], int total_atletas);
Atleta encontraMaisAlto(Atleta atletas[], int total_atletas);

int main(){
    //Realiza a abertura do arquivo
    FILE *arquivo = fopen("atletas.csv", "r");

    //Verifica se o arquivo foi aberto
    if(arquivo == NULL){
        printf("Erro ao carregar o arquivo\n");
        exit(EXIT_FAILURE);
        
    } 

    Atleta atletas[4];
    int total_atletas = 0;
    while(!feof(arquivo)){
        char linha[MAX_STRING];
        lerLinha(linha, arquivo);
        atletas[total_atletas] = lerAtleta(linha);
        total_atletas++;        
    }

    Atleta maisVelho = encontraMaisVelho(atletas, total_atletas);
    Atleta maisAlto = encontraMaisAlto(atletas, total_atletas);
    printf("Dados dos Atletas:\n");
    printf("Atleta mais velho: %s - %i\n", maisVelho.nome, maisVelho.idade);
    printf("Atleta mais alto: %s - %f\n", maisAlto.nome, maisAlto.altura);

    fclose(arquivo);
    return 0;
}

void lerLinha(char s[], FILE *arquivo){
    fgets(s, MAX_STRING, arquivo);
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}

Atleta lerAtleta(char linha[]){
    Atleta atleta;
    char * token = strtok(linha, ";");
    sprintf(atleta.nome, "%s", token);
    token = strtok(NULL, ";");
    atleta.idade = atoi(token);
    token = strtok(NULL, ";");
    atleta.altura = atof(token);
    return atleta;
}

Atleta encontraMaisVelho(Atleta atletas[], int total_atletas){
    Atleta atleta = atletas[0];
    for(int i = 0; i < total_atletas; i++)
        if(atletas[i].idade > atleta.idade)
            atleta = atletas[i];
    return atleta;
}
Atleta encontraMaisAlto(Atleta atletas[], int total_atletas){
    Atleta atleta = atletas[0];
    for(int i = 0; i < total_atletas; i++)
        if(atletas[i].altura > atleta.altura)
            atleta = atletas[i];
    return atleta;
}