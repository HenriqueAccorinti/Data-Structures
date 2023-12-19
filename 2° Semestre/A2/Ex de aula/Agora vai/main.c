/*Andr� Polgrymas Gers RA: 19.00578-4
Henrique Fortuna Accorinti RA: 20.00080-4
Paulo Masayoshi De Luca Ito RA: 19.00254-8*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct{
    char nome[N];
    int idade;
}Pessoa;

void quick(Pessoa *listaDePessoas, int l, int r);
int particionar(Pessoa *listaDePessoas, int l, int r, int p);
void trocar(Pessoa *a, Pessoa *b);
void LerString(char s[]);
int busca_binaria_recursiva(Pessoa *listaDePessoas, int l, int r, char string[]);

int main(){

    Pessoa listaDePessoas[26] = {
        {"Gohan",23},{"Goku",43},{"Chichi",43},{"Goten",13},
        {"Vegeta",48},{"Bulma",47},{"Trunks",14},{"Mr.Satan",44},
        {"Sanji",19},{"Chopper",19},{"Robin",28},{"Franky",34},
        {"Brook",88},{"All Might",49},{"Tomura",20},{"Aizawa",31},
        {"Hawks",23},{"Midoriya",16},{"Jeanist",36},{"Togata",18},
        {"Endeavour",46},{"Dabi",24},{"Uraraka",15},{"Kirishima",15},
        {"Todoroki",15},{"Bakugo",15}
    };
    int i;
    int indice;
    char nomeDigitado[N];
    printf("\n\n***Lista Desordenada***\n\n");
    printf("Nome\t       Idade\n\n");
    for(i = 0; i<26; i++){
        printf("%-10s\t%i\n",listaDePessoas[i].nome,listaDePessoas[i].idade);
    }

    quick(listaDePessoas,0,25);

    printf("\n\n***Lista Ordenada***\n\n");
    printf("Nome\t       Idade\n\n");
    for(i = 0; i<26; i++){
        printf("%-10s\t%i\n",listaDePessoas[i].nome,listaDePessoas[i].idade);
    }

    printf("\nDigite o nome do personagem mais brabo: ");
    LerString(nomeDigitado);

    indice = busca_binaria_recursiva(listaDePessoas, 0, 25, nomeDigitado);

    printf("\nPessoa: %s\t \nIdade: %i\n", listaDePessoas[indice].nome, listaDePessoas[indice].idade);

    return 0;
}

void quick(Pessoa *listaDePessoas, int l, int r){
    int pivo, novoPivo;
    if(l<r){
        pivo = (l+r)/2;
        novoPivo = particionar(listaDePessoas,l,r,pivo);
        quick(listaDePessoas, l, novoPivo - 1);
        quick(listaDePessoas, novoPivo + 1, r);
    }
}

int particionar(Pessoa *listaDePessoas, int l, int r, int p){
    int i, j;
    Pessoa valor_pivo = listaDePessoas[p];

    trocar(&listaDePessoas[p], &listaDePessoas[r]);
    j = l;
    for(i=l; i<=r-1;i++){
        if(strcmp(listaDePessoas[i].nome, valor_pivo.nome)<0){
            trocar(&listaDePessoas[i],&listaDePessoas[j]);
            j++;
        }
    }
    trocar(&listaDePessoas[j],&listaDePessoas[r]);
    return j;
}

void trocar(Pessoa *a, Pessoa *b){
    Pessoa aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void LerString(char s[]){
    fflush(stdin);
    fgets(s, N, stdin);
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}

int busca_binaria_recursiva(Pessoa *listaDePessoas, int l, int r, char string[]) {
    int m;
    if (l > r)
        return -1;
    m = (l + r)/2;
    if (strcmp(string,listaDePessoas[m].nome)==0)  //achou
        return m;
    else if (strcmp(string,listaDePessoas[m].nome)<0)
        return busca_binaria_recursiva(listaDePessoas, l, m - 1, string);
    else
        return busca_binaria_recursiva(listaDePessoas, m + 1, r, string);
}


