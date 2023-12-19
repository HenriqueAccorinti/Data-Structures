#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "fila.h"

//Henrique Fortuna Accorinti RA:20.00080-4

int MenorFila(TFila[]);

int main()
{
    //Chamar a função para iniciar o programa
    BomDia();

    //Declarar as variáveis que serão utilizadas no programa
    //IMPORTANTE: considerar a variável N_CAIXAS como tamanho dos vetores. Ela já estará definida
    int h, m, i, j, menor, resto;
    int frenteDeCaixa[N_CAIXAS];

    TFila f[N_CAIXAS];

    //Inicialização dos vetores
    for(i=0;i<N_CAIXAS;i++){
        CriarFila(&f[i]);
        frenteDeCaixa[i]=0;
    }

    //Loop principal de funcionamento
    for(h=8;h<=23;h++){
            for(m=0;m<=59;m++){
            //Atualizar os número de clientes
            AtualizarClientes(h,m);

            //ENQUANTO existirem vagas nas filas e se existem clientes sem fila
            do{
                //Encontrar a menor fila
                menor = MenorFila(f);
                //Inserir o cliente na menor fila
                InserirNaFila(&f[menor], ProximoCliente());
                //ProximoCliente();
            }while(FilaCheia(f[menor])!=1 && ClientesSemFila()>0);

            //PARA CADA caixa na frente dos caixas
            for(j=0;j<N_CAIXAS;j++){
                //Reduzir a quantidade de produtos por minuto
                frenteDeCaixa[j] -= 8;
                //Se a frente do caixa estiver vazia e existirem clientes na fila do caixa
                if(frenteDeCaixa[j]==0 && FilaVazia(f[j])!=1)
                    //Retirar o cliente da fila e colocar no caixa
                    RetirarDaFila(&f[j], &frenteDeCaixa[j]);

                else if (frenteDeCaixa[j] < 0 && !FilaVazia(f[j])){
                    resto = frenteDeCaixa[j];
                    RetirarDaFila(&f[j], &frenteDeCaixa[j]);
                    frenteDeCaixa[j] + resto;
                }
            }
            //Exibir as filas
            ExibirFilas(h, m, f, frenteDeCaixa);
        }
    }

    return 0;
}

int MenorFila(TFila caixas[]){
    int k, menor;

    menor = 0;
    for(k=0; k<N_CAIXAS; k++){
        if(QuantidadeNaFila(caixas[k])<QuantidadeNaFila(caixas[menor]))
            menor = k;
    }
    return menor;
}
