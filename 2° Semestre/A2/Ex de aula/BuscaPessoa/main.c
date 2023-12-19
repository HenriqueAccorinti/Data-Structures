#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct{
    char nome[N];
    int idade;
}Pessoa;

int BuscaBinariaRecursiva(Pessoa listaDePessoas[],char p, int L, int H);

int main() {
/*
    Pessoa listaDePessoas[26] = {
        {"Gohan",23},{"Goku",43},{"Chichi",43},{"Goten",13},
        {"Vegeta",48},{"Bulma",47},{"Trunks",14},{"Mr.Satan",44},
        {"Sanji",19},{"Chopper",19},{"Robin",28},{"Franky",34},
        {"Brook",88},{"All Might",49},{"Tomura",20},{"Aizawa",31},
        {"Hawks",23},{"Midoriya",16},{"Jeanist",36},{"Togata",18},
        {"Endeavour",46},{"Dabi",24},{"Uraraka",15},{"Kirishima",15},
        {"Todoroki",15},{"Bakugo",15}
    };
*/
    Pessoa listaDePessoas[26] = {
        {"Aohan",23},{"Boku",43},{"Chichi",43},{"Doten",13},
        {"Eegeta",48},{"Fulma",47},{"Grunks",14},{"Hr.Satan",44},
        {"Ianji",19},{"Jhopper",19},{"Kobin",28},{"Lranky",34},
        {"Mrook",88},{"Nll Might",49},{"Oomura",20},{"Pizawa",31},
        {"Qawks",23},{"Ridoriya",16},{"Seanist",36},{"Togata",18},
        {"Undeavour",46},{"Vabi",24},{"Wraraka",15},{"Xirishima",15},
        {"Yodoroki",15},{"Zakugo",15}
    };

    int indice;
    char Perdido = "Fulma";

    if (BuscaBinariaRecursiva(listaDePessoas, Perdido, 0, 26) != -1)
        printf("Achou");
        indice = BuscaBinariaRecursiva(listaDePessoas, Perdido, 0, 26);
        resp = listaDePessoas[indice];
        print("Info completa: %s", Perdido);
    else
        printf("Nao achou: %i",BuscaBinariaRecursiva(listaDePessoas, Perdido, 0, 26));

    return 0;
}


int BuscaBinariaRecursiva(Pessoa listaDePessoas[],char p, int L, int H){
    int M;

    if(L>H)
        return 3;

    M = (L+H)/2;
    if(p == listaDePessoas[M].nome)
        return M;
    else if (p < listaDePessoas[M].nome)
        return BuscaBinariaRecursiva(listaDePessoas,p, L, M-1);
    else
        return BuscaBinariaRecursiva(listaDePessoas,p, M+1, H);

}
