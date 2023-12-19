//NOMES - RA

//Henrique Fortuna Accorinti - 20.00080-4
//
//
//

#include <stdio.h>
#include <stdlib.h>

#define N 100

//Struct
typedef struct{
    char nome[N];
    int idade;
}Pessoa;


//Prototipos das funcoes
void trocar(int *x, int *y);
int particionar(int *v, int l, int r, int p);
void quicksort(int *v, int l, int r);
int procuraBinRec(char *p, Pessoa ps[], int n, int offset);

//Prog Principal
int main()
{
    Pessoa listaDePessoas[26] = {
        {"Gohan",23},{"Goku",43},{"Chichi",43},{"Goten",13},
        {"Vegeta",48},{"Bulma",47},{"Trunks",14},{"Mr.Satan",44},
        {"Sanji",19},{"Chopper",19},{"Robin",28},{"Franky",34},
        {"Brook",88},{"All Might",49},{"Tomura",20},{"Aizawa",31},
        {"Hawks",23},{"Midoriya",16},{"Jeanist",36},{"Togata",18},
        {"Endeavour",46},{"Dabi",24},{"Uraraka",15},{"Kirishima",15},
        {"Todoroki",15},{"Bakugo",15}
    };


   if (BuscaBinariaRecursiva(listaDePessoas, &perdido, 0, 26) != -1)
        printf("Achou");
        indice = BuscaBinariaRecursiva(listaDePessoas, &perdido, 0, 26);

    else
        printf("Nao achou: %i",BuscaBinariaRecursiva(listaDePessoas, &perdido, 0, 26));

    return 0;
}


//Funcoes
void trocar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int particionar(int *v, int l, int r, int p){
    int i, j;
    int valor_pivo = v[p];
    trocar(&v[p], &v[r]);
    j = l;
    for (i = l; i <= r - 1; i++) {
        if (v[i] <= valor_pivo) {
            trocar(&v[i], &v[j]);
            j++;
        }
    }
    trocar(&v[j], &v[r]);
    return j;
}

void quicksort(Pessoa *listaDePessoas, int l, int r) {
    int pivo, novoPivo;
    /* se a lista possui 2 ou mais elementos */
    if (l < r) {
        /* escolher o índice do meio como pivô */
        pivo = (l + r) / 2;
        novoPivo = particionar(listaDePessoas, l, r, pivo);
        /* ordenação recursiva dos subvetores */
        quicksort(v, l, novoPivo - 1);
        quicksort(v, novoPivo + 1, r);
    }
}

void quicksort(int *v, int l, int r) {
    int pivo, novoPivo;
    /* se a lista possui 2 ou mais elementos */
    if (l < r) {
        /* escolher o índice do meio como pivô */
        pivo = (l + r) / 2;
        novoPivo = particionar(v, l, r, pivo);
        /* ordenação recursiva dos subvetores */
        quicksort(v, l, novoPivo - 1);
        quicksort(v, novoPivo + 1, r);
    }
}

