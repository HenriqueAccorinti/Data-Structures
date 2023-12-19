#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 20

typedef struct{
    char nome[MAX_STRING];
} Pessoa;

Pessoa lerPessoa(char linha[]);
void ordenarPessoas(Pessoa pessoas[], int total_elementos);
void lerLinha(char s[], FILE *arquivo);
void exibirPessoas(Pessoa pessoas[], int total_elementos);
int comparar(Pessoa p1, Pessoa p2);
void trocar(Pessoa pessoas[], int posicao);

int main(){
    //Realiza a abertura do arquivo
    FILE *arquivo = fopen("registros.csv", "r");

    //Verifica se o arquivo foi aberto
    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    //Vetor para guardar os dados lidos do arquivo
    Pessoa pessoas[15];

    //Passa pelo arquivo recuperando os items
    for(int i = 0; i < 15; i++){
        char linha[MAX_STRING];
        lerLinha(linha, arquivo);
        pessoas[i] = lerPessoa(linha);
    }

    ordenarPessoas(pessoas, 15);
    exibirPessoas(pessoas, 15);

    fclose(arquivo);
    return 0;
}

Pessoa lerPessoa(char linha[]){
    Pessoa pessoa;
    sprintf(pessoa.nome, "%s", linha); 
    return pessoa;
}

void ordenarPessoas(Pessoa pessoas[], int total_elementos){
    for(int i = total_elementos-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(comparar(pessoas[j],pessoas[j+1]) > 0)
                trocar(pessoas,j);
        }
    }
}

int comparar(Pessoa p1, Pessoa p2){
    return strcmp(p1.nome, p2.nome) > 0;
}

void trocar(Pessoa pessoas[], int posicao){
    Pessoa pessoa = pessoas[posicao];
    pessoas[posicao] = pessoas[posicao+1];
    pessoas[posicao+1] = pessoa;
}

void exibirPessoas(Pessoa pessoas[], int total_elementos){
    for(int i = 0; i < total_elementos; i++)
        printf("%s\n", pessoas[i].nome);    
}

void lerLinha(char s[], FILE *arquivo){
    fgets(s, MAX_STRING, arquivo);
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}