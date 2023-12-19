//Allan Barcessat - 20.00045-6
//Gustavo Henrique dos Santos - 20.01758-8
//Matheus Ferreira Palú - 20.00332-3
//Henrique Fortuna Accorinti - 20.00080-4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"


void ExibePilha(TPilha *pilha, int topo);

int main(){
    char op[MAX];
    TPilha pilha;
    Dados dados;

    CriarPilha(&pilha);

    printf("****** Calculadora RPN ******\nPara exibir a pilha digite 'E'\n\n");
    int topo = 0;

    do{
        LerString(op);

        float esq, dir, dados;

        if (op == '+'){
            dir = RetirarDaPilha(&pilha, &dados); // numero da direita
            esq = RetirarDaPilha(&pilha, &dados); // numero da esquerda
            dados = esq + dir;
        }

        else if (op == '-'){
            dir = RetirarDaPilha(&pilha, &dados); // numero da direita
            esq = RetirarDaPilha(&pilha, &dados); // numero da esquerda
            dados = esq - dir;
        }

        else if (op == '*'){
            dir = RetirarDaPilha(&pilha, &dados); // numero da direita
            esq = RetirarDaPilha(&pilha, &dados); // numero da esquerda
            dados = esq * dir;
        }

        else if (op == '/'){
            dir = RetirarDaPilha(&pilha, &dados); // numero da direita
            esq = RetirarDaPilha(&pilha, &dados); // numero da esquerda

            if (dir == 0)
                printf("Erro: Divisão por 0");
            else
            dados = esq / dir;
        }

        else if (strcmpi(op, "SIN") == 0){
            dir = RetirarDaPilha(&pilha, &dados); // numero da direita
            dados = sin(dir);
        }

        else if (strcmpi(op, "COS") == 0){
            dir = RetirarDaPilha(&pilha, &dados); // numero da direita
            dados = cos(dir);
        }

        else if (strcmpi(op, "RAIZ") == 0){
            dir = RetirarDaPilha(&pilha, &dados); // numero da direita

            if (dir < 0)
                printf("Erro: Raiz negativa");
            else
            dados = pow(dir,1/2);
        }

        else if (strcmpi(op, "PI") == 0)
            dados = M_PI;
        else if (strcmpi(op, "E") == 0)
            ExibePilha(&pilha, topo);
        else
            dados = atof(op);

       printf("%f\n", dados);
       InserirNaPilha(&pilha, &dados);

    }while(strcmpi(op, "FIM") != 0);
}


void ExibePilha(TPilha *pilha, int topo){
    int i;

    printf("\nPilha: ");
    if (topo == 0)
        printf("Vazia\n");
    else {
        for (i = 0; i < topo; i++) {
            if (i > 0) printf(", ");
            printf("%f", pilha[i]);
        }
        printf("nivel: %i", topo);
        printf("\n\n");
    }
}
