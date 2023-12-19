#include <stdio.h>
#include <stdlib.h>

/*
//EXERCICIO 2 E 3
int main(){
    int int1 = 44;
    int int2 = 9;

    int *p_int1 = &int1;
    int *p_int2 = &int2;

    printf("Endereco: %p    ===> valor: %i\n", &int1, int1);
    printf("Endereco: %p    ===> valor: %i\n", &int2, int2);

    *p_int1 = 99;
    *p_int2 = 55;

    printf("Endereco: %p    ===> valor: %i\n", &int1, int1);
    printf("Endereco: %p    ===> valor: %i\n", &int2, int2);

    if( &int1 > &int2 ){
        printf("Endereco: %p    ===> valor: %i\n", &int1, int1);
    }
    else{
        printf("Endereco: %p    ===> valor: %i\n", &int2, int2);
    }

    return 0;
}
*/

/*
//EXERCICIO 4
void troca(int *A, int *B);
void troca2(int *, int *);
int main(){
    int int1;
    int int2;

    printf("A: ");
    scanf("%i", &int1);

    printf("B: ");
    scanf("%i", &int2);

    troca(&int1,&int2);
    printf("\nInvertendo...\nA: %i\nB: %i\n\nChama!\n",int1, int2);

    troca2(&int1,&int2);
    printf("\nDesinvertendo...\nA: %i\nB: %i\n\nChama!\n",int1, int2);

    return 0;
}

void troca(int *A, int *B){
   int aux;
   aux = *A;
   *A = *B;
   *B = aux;
   //troca2(A, B);    //destrocar dentro do trocar,o & não pode ser usado
}

void troca2(int *A, int *B){
   int aux;
   aux = *A;
   *A = *B;
   *B = aux;
}
*/
