#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define MAX 40
#define MAX_FILA 4

typedef struct{
    int pedido;
    char nome[MAX];
    char item[MAX];
} Dados;

typedef struct{
    Dados elemento[MAX_FILA];
    int quantidade, frente, tras;
} TFila;

//cria uma fila nova
void CriarFila(TFila *f);

//insere elemento
int InserirNaFila(TFila *f, Dados dados);

//retira elemento
int RetirarDaFila(TFila *f, Dados *dados);

//indica se a fila está vazia
int FilaVazia(TFila f);

//indica se a fila está cheia
int FilaCheia(TFila f);

//retorna o tamanho da fila
int QuantidadeNaFila(TFila f);

//exibe a fila
void ExibirFila(TFila f);

void LerString(char s[]);

#endif // FILA_H_INCLUDED
