#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void lerArqPorLinha(FILE *arq);
void Separar(char string[MAX]);

    typedef struct{
        char produto;
        int qtd;
        float preco;
    }Compras;

int main(){
    int i;

    //Exibição do Arquivo
    FILE *arquivo;
    arquivo = fopen("compras.txt","r");

    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    printf("Leitura do arquivo...\n\n");

    char linha[MAX], texto[MAX];

    while(fgets(linha,MAX,arquivo) != NULL){ // laco para a leitura do restante
        printf("%s", linha);
        scanf("%s", &texto);
    }
    printf("%s",texto);
    Separar(texto);

    //Struct
    Compras lista[7];
    int j;
    float total = 0;

    for(j=0;j<6;j++){

    total += lista[j].preco * lista[j].qtd;
    }

    printf("\n\nCusto total: R$%.2f\n", total);


    fclose(arquivo);
    return 0;
}




/*/Subrotinas
void lerArq(FILE *arq){
char linha[MAX], texto[MAX];
    int i;

    while(fgets(linha,MAX,arq) != NULL){ // laco para a leitura do restante
        printf("%s", linha);
        scanf("%s", &texto);
    }
    printf("%s",texto);
    return texto;
}
}
*/
void Separar(char string[]){

    int i;

    for(i=0; i<strlen(string); i++){
        if(string[i]==';'){
            string[i]='\n';
        }
    }
    printf("%s\n", string);
    return 0;
}
