#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX 20
#define MAX_PILHA 10
typedef struct {
    float valor;
    char texto[MAX];
} Dados;

typedef struct {
    Dados elemento[MAX_PILHA];
    int topo;
} TPilha;

//cria uma pilha nova
void CriarPilha(TPilha *p);
//insere
int InserirNaPilha(TPilha *p, Dados dados);
//retira
int RetirarDaPilha(TPilha *p, Dados *dados);
//indica se a pilha está vazia
int PilhaVazia(TPilha p);
//indica se a pilha está cheia
int PilhaCheia(TPilha p);
//retorna o tamanho da pilha
int QuantidadeNaPilha(TPilha p);

void lerString(char s[]);

#endif // LISTA_H_INCLUDED
