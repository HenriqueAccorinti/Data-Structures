#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 20

typedef struct{
    char nome[MAX_STRING];
    int vida;
    int ataque;
    int defesa;
    int velocidade;
} Personagem;

Personagem lerPersonagem();
void exibirPersonagem(Personagem personagem);
void lerLinha(char s[], FILE *arquivo);
void salvarDados(Personagem personagem, char nome_arquivo[]);
Personagem carregarPersonagem(FILE *arquivo);

int main(){
    //Realiza a abertura do arquivo
    FILE *arquivo = fopen("personagem.txt", "r");
    Personagem personagem;

    //Verifica se o arquivo foi aberto
    if(arquivo == NULL){
        printf("Carregar novo personagem!\n");
        personagem = lerPersonagem();
        
    } else {
        personagem = carregarPersonagem(arquivo);
    }

    exibirPersonagem(personagem);
    salvarDados(personagem, "personagem.txt");
    fclose(arquivo);
    return 0;
}

Personagem lerPersonagem(){
    Personagem personagem;
    printf("Informe um nome:");
    lerLinha(personagem.nome, stdin);
    printf("Vida, ataque, defesa e velocidade:");
    scanf("%i%i%i%i", &(personagem.vida), &(personagem.ataque), &(personagem.defesa), &(personagem.velocidade));
    return personagem;
}
void exibirPersonagem(Personagem personagem){
    printf("Dados do personagem:\n");
    printf("Nome:%s\n", personagem.nome);
    printf("Vida:%i\n", personagem.vida);
    printf("Ataque:%i\n", personagem.ataque);
    printf("Defesa:%i\n", personagem.defesa);
    printf("Velocidade:%i\n", personagem.velocidade);
}
void lerLinha(char s[], FILE *arquivo){
    fgets(s, MAX_STRING, arquivo);
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}
void salvarDados(Personagem personagem, char nome_arquivo[]){
    FILE *arquivo = fopen(nome_arquivo, "w");
    fprintf(arquivo, "%s;%i;%i;%i;%i\n", personagem.nome,
    personagem.vida, personagem.ataque, personagem.defesa, personagem.velocidade);
    fclose(arquivo);

}

Personagem carregarPersonagem(FILE *arquivo){
    char linha[MAX_STRING];
    lerLinha(linha,arquivo);
    Personagem personagem;
    char * token = strtok(linha, ";");
    sprintf(personagem.nome, "%s", token);
    token = strtok(NULL, ";");
    personagem.vida = atoi(token);
    token = strtok(NULL, ";");
    personagem.ataque = atoi(token);
    token = strtok(NULL, ";");
    personagem.defesa = atoi(token);
    token = strtok(NULL, ";");
    personagem.velocidade = atoi(token);
    return personagem;
}