// Lucas Romanato de Oliveira      RA: 20.00313-7
// Henrique Fortuna Accorinti      RA: 20.00080-4
// Pedro Marques Felippe de Souza  RA:

#include <stdio.h>
#include <stdlib.h>
#define NP 3
#define NA 4

// protótipos das sub-rotinas
// atenção com os tipos de dados dos parâmetros
float CustokWh(int cons, int bandeira); // uso obrigatório
void DigitarConsumo(int [NP][NA]);
void CustoDosPredios(int [NP][NA], int, float [NP]);
float CustoTotal(float cPredio[NP]);
void ExibirResumo(float cPredio[NP], float cTotal);
void ExibirPorApartamento(int cCond[NP][NA], int bandeira, float cTotal);

// programa principal
int main(){

    int cCond[NP][NA], bandeira;
    float cPredio[NP], cTotal;

    printf("Informe a bandeira tarifaria:\n0)Verde\n1)Amarela\n2)Vermelha - patamar 1\n3)Vermelha - patamar 2\nEscolha a opcao (0/1/2/3): ");
    scanf("%i", &bandeira);
    DigitarConsumo(cCond);
    CustoDosPredios(cCond, bandeira, cPredio);
    cTotal = CustoTotal(cPredio);
    ExibirResumo(cPredio, cTotal);
    ExibirPorApartamento(cCond, bandeira, cTotal);
    return 0;

}

// escreva as sub-rotinas aqui
float CustokWh(int cons, int bandeira){
    float TUDS = 0.25971;
    float TE = 0.25588;
    float custo, tarifa;

    if(bandeira == 0){
        tarifa = 0;
    }
    if(bandeira == 1){
        tarifa = 1.35*(cons/100);
    }
    if(bandeira == 2){
        tarifa = 4.17*(cons/100);
    }
    if(bandeira == 3){
        tarifa = 6.28*(cons/100);
    }

    custo = (cons*TUDS + cons*TE)*1.12 + tarifa;

    return custo;
}

void DigitarConsumo(int cCond[NP][NA]){
    int i, j;
    char predio=65;

    for(i=1; i<=NP; i++){
        for(j=1; j<=NA; j++){
            printf("\nDigite o consumo do apartamento %i do predio %c: ", j, predio);
            scanf("%i",&cCond[i][j]);
        }
    predio +=1;
    }
}

void CustoDosPredios(int cCond[NP][NA], int bandeira, float cPredio[NP]){
    int i, j;

    for(i=1; i<=NP; i++){
            for(j=1; j<=NA; j++){
                cPredio[i] += CustokWh(cCond[i][j], bandeira);
            }
    }
}

float CustoTotal(float cPredio[NP]){
    float custot;

    custot = cPredio[1] + cPredio[2] + cPredio[3];

    return custot;
}

void ExibirResumo(float cPredio[NP], float cTotal){
    printf("\nPredio %c: %.2f", 65, cPredio[1]);
    printf("\nPredio %c: %.2f", 66, cPredio[2]);
    printf("\nPredio %c: %.2f", 67, cPredio[3]);
    printf("\nCusto total: R$%.2f\n\n", cTotal);
}

void ExibirPorApartamento(int cCond[NP][NA], int bandeira, float cTotal){
    int i, j;
    float media;
    int CustoAp[NP][NA];
    int LCond[NP];

    media = cTotal/(NP*NA);

    for(i=0;i<NP;i++){
        LCond[i]=cCond[i][0];
        for(j=0;j<NA;j++){
        CustoAp[i][j] = CustokWh(LCond[i],bandeira);
        }
    }

    for(i=0;i<NP;i++){
        for(j=0;j<NA;j++){
            if(CustoAp[i][j] > media){
            printf("%i%c\t",cCond[i][j],'!');
            }else{
            printf("%i\t",cCond[i][j]);
            }
        }
        printf("\n");
    }
}
