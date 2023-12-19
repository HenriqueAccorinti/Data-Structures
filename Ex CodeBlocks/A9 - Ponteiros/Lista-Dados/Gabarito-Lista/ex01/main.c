#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 20

typedef struct{
    char nome[MAX_STRING];
    int quantidade;
    float preco_unitario;
} Item;

Item lerItem(char linha[]);
float calculaTotal(Item items[], int total_elementos);
void lerLinha(char s[], FILE *arquivo);

int main(){
    //Realiza a abertura do arquivo
    FILE *arquivo = fopen("compras.txt", "r");

    //Verifica se o arquivo foi aberto
    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    //Vetor para guardar os dados lidos do arquivo
    Item items[7];

    //Passa pelo arquivo recuperando os items
    for(int i = 0; i < 7; i++){
        char linha[MAX_STRING];
        lerLinha(linha, arquivo);
        items[i] = lerItem(linha);
    }

    printf("Total: %.2f\n", calculaTotal(items, 7));

    fclose(arquivo);
    return 0;
}

Item lerItem(char linha[]){
    char temp[MAX_STRING];
    int conta_linha = 0, conta_atual = 0;
    Item item;
    /*
    int elemento = 0;
    for(conta_atual = 0; conta_atual<strlen(linha); conta_atual++){
        if(linha[conta_atual] != ';'){
            temp[conta_linha] = linha[conta_atual];
            conta_linha++;
        }else{
            temp[conta_linha] = '\0';
            switch(elemento){
                case 0: sprintf(item.nome, "%s", temp); break;
                case 1: item.quantidade = atoi(temp); break;
                case 2: item.preco_unitario = atof(temp); break;
            }
            elemento++;
            conta_linha = 0;
        }
    }
    temp[conta_linha] = '\0';
            switch(elemento){
                case 0: sprintf(item.nome, "%s", temp); break;
                case 1: item.quantidade = atoi(temp); break;
                case 2: item.preco_unitario = atof(temp); break;
            }
            */
    
    //Rastreando elementos na string com strtok()
    //Para passar para os alunos:
    //https://www.cplusplus.com/reference/cstring/strtok/
    //https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    
    char *token = strtok(linha, ";");
    sprintf(item.nome, "%s", token); 
    token = strtok(NULL, ";");
    item.quantidade = atoi(token); 
    token = strtok(NULL, ";");
    item.preco_unitario = atof(token);
    printf("%s\t%i\t%f\n", item.nome, item.quantidade, item.preco_unitario);
    return item;
}


float calculaTotal(Item items[], int total_elementos){
    float total = 0;
    for(int i = 0; i < total_elementos; i++)
        total += items[i].quantidade * items[i].preco_unitario;
    return total;
}


void lerLinha(char s[], FILE *arquivo){
    fgets(s, MAX_STRING, arquivo);
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}