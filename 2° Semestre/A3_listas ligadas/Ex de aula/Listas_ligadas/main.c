#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MAX 20

typedef struct {
    float valor;
    char texto[MAX];
} Dados;

typedef struct SLista {
    Dados dados;
    struct SLista *prox;
} TLista;

void LerString(char s[])
{
  setbuf(stdin, 0);
  // ou fflush(stdin);
  fgets(s, MAX, stdin);
  if (s[strlen(s)-1] == '\n')
      s[strlen(s)-1] = '\0';
}

TLista* CriarLista(void) {
  TLista *p;   /* Ponteiro para a lista */
  p = (TLista*) malloc(sizeof(TLista));
  if (p == NULL){
    printf("Não pode criar a lista");
    exit(EXIT_FAILURE);
  }

  p->prox = NULL;   /* Atribui ponteiro nulo */
  return p;   /* Retorna endereço da lista */
}


void InserirNoFim(TLista *p, Dados dados) {
    TLista* novo;
    novo = (TLista*) malloc(sizeof(TLista));
    if (novo == NULL) {
        printf("Nao foi possivel alocar memoria!");
        exit(EXIT_FAILURE);
    }

    novo->dados = dados;

    TLista *aux;
    aux = p;
    while(aux->prox != NULL)
        aux = aux->prox;

    novo->prox = NULL;
    aux->prox = novo;
}

void ExibirLista(TLista *p) {
    TLista *aux;
    aux = p;
    aux = aux->prox;
    while(aux != NULL) {
        printf("%4.2f\t%s\n",
                  aux->dados.valor,
                  aux->dados.texto);
        aux = aux->prox;
    }
}

TLista* DestruirLista(TLista *p) {
    TLista *aux;
    aux = p;
    while(aux->prox != NULL) {
        aux = aux->prox;
        free(p);
        p = aux;
    }
    free(p);
    return NULL;
}


int main() {
    char op;
    Dados dados;
    TLista *lista;
    lista = CriarLista();
    do {
        printf("valor: ");
        scanf("%f",&dados.valor);
        printf("texto: ");
        LerString(dados.texto);
        InserirNoFim(lista, dados);
        printf("Mais itens (S/N)? ");
        scanf("%c", &op);
    } while (toupper(op) != 'N');
    ExibirLista(lista);
    lista = DestruirLista(lista);
    return 0;
}
