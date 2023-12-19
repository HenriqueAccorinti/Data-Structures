#include <stdio.h>
#include <stdlib.h>
#define N 10

void LerValores(float [][N], float [], int);
void ExibeMatriz(float [][N], int, int);
void ExibeVetor(float [], int);
void Transposta(float [][N], float [][N], int, int);
void Multiplica(float [][N], float [][N], float [][N], int, int , int);
void Inverte2x2(float [][N], float [][N]);
void MultipiicaV(float [][N],float [], float [], int, int);


void main() {
    int n;
    float A[N][N], AT[N][N], B[N], x[N], ATA[N][N], INV[N][N], INVAT[N][N];

	printf("Digite o numero de pontos: ");
	scanf("%i", &n);

	LerValores(A, B, n);
	ExibeMatriz(A,n,2);
	Transposta(A, AT, n, 2);
	ExibeMatriz(AT,2,n);
	Multiplica(AT, A, ATA, 2, n, 2);
	ExibeMatriz(ATA,2,2);
	Inverte2x2(ATA, INV);
	ExibeMatriz(INV,2,2);
	Multiplica(INV, AT, INVAT, 2, 2, n);
	ExibeMatriz(INVAT,2,n);
	MultipiicaV(INVAT, B, x, 2, n);
    ExibeVetor(x, 2);

	printf("y = %4.2f x + %4.2f\n", x[0], x[1]);
}


void LerValores(float A[N][N], float B[N], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Digite x[%i]: ", i);
		scanf("%f", &A[i][0]);
		A[i][1] = 1;
		printf("Digite y[%i]: ", i);
		scanf("%f", &B[i]);
	}
}


void ExibeMatriz(float M[N][N], int m, int n) {
	int i, j;
	printf("\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%4.2f  ", M[i][j]);
		}
		printf("\n");
	}
}


void ExibeVetor(float V[N], int n) {
	int i;
	printf("\n(  ");
	for (i = 0; i < n; i++) {
		printf("%4.2f  ", V[i]);
	}
	printf(")\n\n");
}


void Transposta(float M[N][N], float MT[N][N], int nl, int nc) {
	int i, j;
	for (i = 0; i < nc; i++) {
		for (j = 0; j < nl; j++) {
			MT[i][j] = M[j][i];
		}
	}
}


void Multiplica(float M1[N][N], float M2[N][N], float aux[N][N], int nl, int nigual, int nc)
{
	int i, j, k;
	for (i = 0; i < nl; i++) {
		for (j = 0; j < nc; j++) {
			aux[i][j] = 0;
			for (k = 0; k < nigual; k++) {
				aux[i][j] = aux[i][j] + M1[i][k]*M2[k][j];
			}
		}
	}
}


void Inverte2x2(float M[N][N], float iM[N][N]){
	float d;
	d = 1.0 / (M[0][0]*M[1][1] - M[0][1]*M[1][0]);
	iM[0][0] = +M[1][1]*d;
	iM[0][1] = -M[0][1]*d;
	iM[1][0] = -M[1][0]*d;
	iM[1][1] = +M[0][0]*d;
}


void MultipiicaV(float M[N][N],float V[N], float VR[N], int nl, int nc){
	int i,j;
	for (i = 0; i < nl; i++) {
		VR[i] = 0;
		for (j = 0; j < nc; j++) {
			VR[i] = VR[i] + M[i][j]*V[j];
		}
	}
}
