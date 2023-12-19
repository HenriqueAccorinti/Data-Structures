#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void CriarFila(TFila* f) {
    /* define valores iniciais das propriedades da fila */
    f->quantidade = 0;
    f->frente = 0;
    f->tras = -1;
}


int InserirNaFila(TFila *f, int dados) {
    int fc = FilaCheia(*f);
    if (!fc) {
        f->tras = (f->tras + 1) % MAX_FILA; /* incrementa a posicao "tras" no buffer circular*/
        f->elemento[f->tras] = dados;       /* insere o elemento no fim da fila */
        f->quantidade++;                    /* incrementa a quantidade */
    }
    return !fc; /* retorna se conseguiu inserir o dado */
}


int RetirarDaFila(TFila *f, int *dados) {
    int fv = FilaVazia(*f);
    if (!fv) {
        *dados = f->elemento[f->frente];        /* recupera o dado do inicio da fila */
        f->frente = (f->frente +1) % MAX_FILA;  /* incrementa a posicao "frente" no buffer circular*/
        f->quantidade--;                        /* decrementa a quantidade */
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
