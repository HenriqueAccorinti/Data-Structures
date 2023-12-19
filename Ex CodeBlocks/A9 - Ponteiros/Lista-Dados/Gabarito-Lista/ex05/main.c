#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING 20

typedef struct {
    char nome[MAX_STRING];
    int dia, mes, ano, idade;
}Usuario;


void lerLinha(char s[], FILE *arquivo);
Usuario lerUsuario(char linha[]);
void atualizarIdade(Usuario *usuario);

int main(){
    //Realiza a abertura do arquivo
    FILE *arquivo = fopen("usuarios.csv", "r");

    //Verifica se o arquivo foi aberto
    if(arquivo == NULL){
        printf("Erro ao carregar o arquivo\n");
        exit(EXIT_FAILURE);
        
    } 

    FILE *arquivo_saida = fopen("usuarios_idade.csv", "w");

    while(!feof(arquivo)){
        char linha[MAX_STRING];
        lerLinha(linha, arquivo);
        Usuario usuario = lerUsuario(linha);
        atualizarIdade(&usuario);
        fprintf(arquivo_saida, "%s;%i\n", usuario.nome, usuario.idade);
        
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

Usuario lerUsuario(char linha[]){
    Usuario usuario;
    char * token = strtok(linha, ";");
    sprintf(usuario.nome, "%s", token);
    token = strtok(NULL, ";");
    usuario.dia = atoi(token);
    token = strtok(NULL, ";");
    usuario.mes = atoi(token);
    token = strtok(NULL, ";");
    usuario.ano = atoi(token);
    return usuario;
}
void atualizarIdade(Usuario *usuario){
    //Pega a data atual do sistema
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int ano_atual, mes_atual, dia_atual;
    ano_atual = tm.tm_year + 1900;
    mes_atual = tm.tm_mon + 1;
    dia_atual = tm.tm_mday;

    (*usuario).idade = ano_atual - (*usuario).ano - 1;
    if (mes_atual > (*usuario).mes)
        (*usuario).idade += 1;
    else if(mes_atual == (*usuario).mes){
        if(dia_atual >= (*usuario).dia)
            (*usuario).idade += 1;
    }

}