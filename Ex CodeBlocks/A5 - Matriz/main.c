#include <stdlib.h>

#define N 2

void lerMatriz(int [][N]);
void exibirMatriz(int [][N]);
void multiplicaMatriz(int [][N],int [][N],int [][N]);

int main(){
    //int NL,NC;
    int A[N][N];
    int B[N][N];
    int C[N][N];

    //printf("Entre com NL: ");
    //scanf("%i",&NL);

    //printf("Entre com NC: ");
    //scanf("%i",&NC);

    lerMatriz(A);
    printf("\n\n");
    lerMatriz(B);

    multiplicaMatriz(A,B,C);

    printf("\n\n");

    exibirMatriz(C);

    return 0;
}

void lerMatriz(int m[][N]){
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("Digite o valor para mat[%i][%i]: ",i,j);
            scanf("%i",&m[i][j]);
        }
    }
}

void exibirMatriz(int m[][N]){
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%i\t",m[i][j]);
        }
        printf("\n");
    }
}

int max(int M[NL][NC]){
    int i, j, maior = M[0][0];

    for (int i=0; i<NL; i++){
        for(int j=0; j<NC; j++){
            if(M[i][j] > maior){
            maior = M[i][j];
        }
        }
    }
    return maior;
}

int min(int M[NL][NC]){
    int i, j, menor = M[0][0];

    for (int i=0; i<NL; i++){
        for(int j=0; j<NC; j++){
            if(M[i][j] < menor){
            menor = M[i][j];
        }
        }
    }
    return menor;
}
