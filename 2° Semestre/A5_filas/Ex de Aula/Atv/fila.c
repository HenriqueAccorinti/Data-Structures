#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void CriarFila(TFila* f) {
    /* define valores iniciais das propriedades da fila */
    f->quantidade = 0;
    f->frente = 0;
    f->tras = -1;
}

int InserirNaFila(TFila *f, Dados dados) {
    int fc = FilaCheia(*f);
    if (!fc) {
        /* incrementa a posição "trás" no buffer circular*/
        f->tras = (f->tras + 1) % MAX_FILA;
        /* insere o elemento no fim da fila */
        f->elemento[f->tras] = dados;
        /* incrementa a quantidade */
        f->quantidade++;
    }
    return !fc; /* retorna se conseguiu inserir o dado */
}

int RetirarDaFila(TFila *f, Dados *dados) {
    int fv = FilaVazia(*f);
    if (!fv) {
        /* recupera o dado do início da fila */
        *dados = f->elemento[f->frente];
        /* incrementa a posição "frente" no buffer circular*/
        f->frente = (f->frente +1) % MAX_FILA;
        /* decrementa a quantidade */
        f->quantidade--;
    }
    return !fv; /* retorna se conseguiu remover o dado */
}

int FilaVazia(TFila f) {
    return f.quantidade == 0;
}

int FilaCheia(TFila f) {
    return f.quantidade == MAX_FILA;
}

int QuantidadeNaFila(TFila f) {
    return f.quantidade;
}

void ExibirFila(TFila f){
    Dados dado;
    int i;
    int n = f.quantidade;

    printf("\n\n\nAdministrativo:\n");
    printf("+---+--------------------+--------------------+\n");
    printf("|ped|      cliente       |        item        |\n");
    printf("+---+--------------------+--------------------+\n");

    for(i=0; i<n ;i++){
        RetirarDaFila(&f,&dado);
        printf("|  %i|%20s|%20s|\n", dado.pedido, dado.nome, dado.item);

    }
    printf("+---+--------------------+--------------------+\n\n");
}

void LerString(char s[]){
    fflush(stdin);
    fgets(s,MAX,stdin);

    if(s[strlen(s)-1] == '\n'){
        s[strlen(s)-1] = '\0';
    }
}
