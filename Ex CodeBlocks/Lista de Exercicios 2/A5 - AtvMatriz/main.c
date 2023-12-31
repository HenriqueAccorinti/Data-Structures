//Henrique Fortuna Accorinti   RA:20.00080-4
//Ana Helena Marcacini         RA:20.01305-0
//Artthur augusto Pires        RA:20.01004-4
//Guilherme Sanches Rossi      RA:19.02404-5

#include <stdio.h>
#include <stdlib.h>
#define N 38

// prot�tipos das sub-rotinas
void ExibirMatriz(int[][N]);
int Filtrar(int[][N], int[3][3]);
void Convoluir(int[][N], int[3][3], int[][N]);
int min(int M[N][N]);
int max(int M[N][N]);

// programa principal
int main()
{
    int M[N][N] = {
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 15, 15, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  5,  5,  5,  5,  5,  5, 15, 15, 15, 15,  5,  5,  5, 15, 15, 15, 15, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  5,  5,  5,  5,  5,  5,  5,  5,  5, 15, 15,  5,  5,  5,  5,  5, 15, 15, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  5,  5,  5, 15, 15, 15, 15,  5,  5,  5,  5, 15, 15, 15,  5,  5,  5,  5, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  5,  5,  5, 15, 15, 15, 15,  5,  5,  5,  5, 15, 15, 15, 15, 15, 15, 15,  5,  5, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0,  0,  0},
    {  0,  0,  0,  5,  5,  5,  5,  5, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  5,  5, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0,  0,  0},
    {  0,  0,  0,  5,  5,  5,  5,  5, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  5,  5,  5,  5,  5,  5,  5, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  5,  5,  5,  5, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 10, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  5, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  5,  5,  5,  5, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  5,  5,  5,  5,  5,  5, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0},
    {  0,  0,  0,  5,  5,  5,  5,  5,  5,  5, 10,  5, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10,  5, 10,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0},
    {  0,  0,  0,  5,  5,  5,  5,  5,  5,  5, 10, 10, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10, 10, 10,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0},
    {  0,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0},
    {  0,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0},
    {  0,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10, 10, 15, 15, 10, 10, 10, 10, 10, 10, 10, 10, 10, 15, 15, 10, 10,  5,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0},
    {  0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0},
    {  0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0},
    {  0,  0,  0, 15, 15, 15, 15, 15, 15, 15, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 15, 15, 15, 15, 15, 15, 15,  0,  0,  0,  0},
    {  0,  0,  0, 15, 15, 15, 15, 15, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 15, 15, 15, 15, 15,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0,  0},
    {  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0},
    {  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0},
    {  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 10, 10, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0},
    {  0,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0},
    {  0,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    };

    int F[3][3] = {{-1, -1, -1},
                   {-1,  8, -1},
                   {-1, -1, -1}};
    int R[N][N] = {0};

    // fazer a chamada para a exibi��o da matriz M, aguardar que alguma tecla seja pressionada e limpar a tela
    ExibirMatriz(M);
    system("pause");
    system("cls");

    // chamar o procedimento para convolu��o e exibir a matriz R
    Convoluir(M,F,R);
    ExibirMatriz(R);

    return 0;
}

// as sub-rotinas
void ExibirMatriz(int M[][N]){
    int i, j;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){

            // estou usando o Code::Blocks
            if (M[i][j] < 3)
                printf("%c", 32);
            else
            if (M[i][j] < 6)
                printf("%c", 176);
            else
            if (M[i][j] < 9)
                printf("%c", 177);
            else
            if (M[i][j] < 12)
                printf("%c", 178);
            else
                printf("%c", 219);

            // estou usando o repl.it
            /*
            if (M[i][j] < 3)
                printf(" ");
            else
            if (M[i][j] < 6)
                printf(".");
            else
            if (M[i][j] < 9)
                printf("-");
            else
            if (M[i][j] < 12)
                printf("+");
            else
                printf("X");
            */
        }
        printf("\n");
    }
}

int Filtrar(int M[][N], int F[3][3]){
    int x, y, r[3][3], R[N][N];
    int i, j;
    int cor;
    // 2 la�os de repeti��o (obrigat�rios) para multiplicar os 9 elementos e fazer a soma da nova cor
        for(i=1; i<N-1; i++){
            for(j=1; j<N-1; j++){
                cor = 0;
                r[i][j]= 0;
                r[1][1]+= M[i][j];
                r[0][0]+= M[i-1][j-1];
                r[0][1]+= M[i-1][j];
                r[0][2]+= M[i-1][j+1];
                r[1][0]+= M[i][j-1];
                r[1][2]+= M[i][j+1];
                r[2][0]+= M[i+1][j-1];
                r[2][1]+= M[i+1][j];
                r[2][2]+= M[i+1][j+1];
                for(x=0;x<3;x++){
                    for(y=0;y<3;y++){
                    cor += r[x][y] * F[x][y];
                }
            }
            R[i][j]= cor;
        }
    }
    printf(R);
    return R;
}

void Convoluir(int M[][N], int F[3][3], int R[][N]){
    int i, j, cor;
    int maior=-255, menor=+255;

    //Determinar o maior e menor valor da cor calculada
    R = Filtrar(M,F);
    maior = max(R);
    menor = min(R);

    // 2 la�os de repeti��o para normalizar a matriz R
    for(i=1; i<N-1; i++){
        for(j=1; j<N-1; j++){
            R[i][j] += fabs(menor);
            R[i][j] *= 15;
            R[i][j] /= (maior - menor);
        }
    }
    return R;
}


int max(int M[N][N]){
    int i, j, maior = M[0][0];

    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(M[i][j] > maior){
            maior = M[i][j];
        }
        }
    }
    return maior;
}

int min(int M[N][N]){
    int i, j, menor = M[0][0];

    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(M[i][j] < menor){
            menor = M[i][j];
        }
        }
    }
    return menor;
}
