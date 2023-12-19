#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void CriarPilha(TPilha *p){
    /* define valores iniciais das propriedades da pilha */
    p->topo = -1;
}

int InserirNaPilha(TPilha *p, Dados dados) {
    int pc = PilhaCheia(*p);
    if (!pc) {
        p->topo++; /* incrementa posição do topo */
        /* insere elemento no topo da pilha */
        p->elemento[p->topo] = dados;
    }
    return !pc; /* retorna se conseguiu inserir o dado */
}

int RetirarDaPilha(TPilha *p, Dados *dados) {
    int pv;
    pv = PilhaVazia(*p);
    if (!pv) {
        /* recupera informação do topo da pilha */
        *dados = p->elemento[p->topo];
        p->topo--; /* decrementa posição do topo */
    }
    return !pv; /* retorna se conseguiu remover o dado */
}

int PilhaVazia(TPilha p) {
    return p.topo == -1;
}

int PilhaCheia(TPilha p) {
    return p.topo == MAX_PILHA - 1;
}

int QuantidadeNaPilha(TPilha p) {
    return p.topo + 1;
}

void LerString(char s[]){
    fflush(stdin);
    printf("Comando: ");
    fgets(s,MAX,stdin);

    if(s[strlen(s)-1] == '\n'){
        s[strlen(s)-1] = '\0';
    }
}
