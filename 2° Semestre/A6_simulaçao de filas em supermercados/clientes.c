#include <time.h>
#include "fila.h"
#include "clientes.h"

TFila NovosClientes;


void BomDia() {
    // Numero de caixas
    srand (time(NULL));
    N_CAIXAS = 3 + rand() % 3;
    // Fila de clientes
    CriarFila(&NovosClientes);
}

void AtualizarClientes(int h, int m) {
    int itensNoCarrinho;
    int i, temCliente, quantosClientes;
    if (h >= 8 && h < 22) {
        temCliente = rand() % 100;
        if (temCliente < 40) {
            switch (h) {
            case 12:
                quantosClientes = 1 + rand() % 4;
                break;
            case 19:
                quantosClientes = 2 + rand() % 3;
                break;
            default:
                quantosClientes = rand() % 3;
                break;
            }

            for (i=0; i<quantosClientes; i++) {
                itensNoCarrinho = 5 + rand() % 60;
                InserirNaFila(&NovosClientes,itensNoCarrinho);
            }
        }
    }
}


int ProximoCliente() {
    int dados;
    int clientes;
    clientes = RetirarDaFila(&NovosClientes, &dados);
    if (clientes != 0)
        return dados;
    else
        return 0;
}


int ClientesSemFila() {
    return NovosClientes.quantidade;
}


void ExibirFilas(int h, int m, TFila fila[], int fc[]) {
    int i, s = 0;

    if (m == 0) {
        printf("\n");
        printf("hh:mm\t");
        for (i=0; i<N_CAIXAS; i++)
            printf("Fila %i\t\t", i);
        printf("S/Fila\tTotal\n");
    }

    if (h < 10)
        printf("0%i:",h);
    else
        printf("%i:",h);

    if (m < 10)
        printf("0%i\t",m);
    else
        printf("%i\t",m);


    for (i=0; i<N_CAIXAS; i++) {
        s += fila[i].quantidade;
        if (FilaVazia(fila[i]))
            printf("%i\t\t",fila[i].quantidade);
        else
            if (fc[i] != 0)
                printf("%i (%i)\t\t",fila[i].quantidade, fc[i]);
            else
                printf("%i     \t\t",fila[i].quantidade);
    }

    printf("%i", ClientesSemFila());

    if (ClientesSemFila() > 0)
        printf("\t%i CRITICO!\n",s);
    else {
        if ((h < 22) && (s > MAX_FILA*N_CAIXAS*0.7))
            printf("\t%i ATENCAO\n",s);
        else if ((h < 22) && (s < MAX_FILA*N_CAIXAS*0.1))
            printf("\t%i FRACO\n",s);
        else
            printf("\t%i\n",s);
    }

    //if ((m == 29) || (m == 59))
    if (m == 59)
        system("PAUSE");
}

int nCaixas(){
    return N_CAIXAS;
}
