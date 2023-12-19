/*
Henrique Fortuna Accorinti RA:20.00080-4
Matheus D'Angelo Falcão    RA:20.00494-0
Maruan Gaudino             RA:18.01457-7
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// programa principal. Não crie funções
int main()
{

    int x = 123, y = 50, q = 0, r = 0;
    int Lx[MAX];
    // crie outras variáveis aqui
    int i=0; Lx[0]=x;

    // while que preenche a lista Lx
    while(Lx[i]>0){
        Lx[i+1] = Lx[i]/2;
        printf("Lx[%i]: %i\n", i, Lx[i]);
        i+=1;

    }
        printf("\nIteracoes: %i\n", i);

    // for que calcula q e r
    r = Lx[i]%2;
    for(i=i-1; i>=0; i--){
        q = q*2;

        r = r*2;


        if(Lx[i]%2 != 0){
            r+=1;
        }
        if(r>=y){
            r = r-y;
            q += 1;

        }
        printf("%i",q);
        printf("  %i\n",r);
    }
    return 0;
}
