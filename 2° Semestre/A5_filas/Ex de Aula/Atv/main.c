#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
    TFila fila;
    Dados dado;
    int n, i;
    char op;

    CriarFila(&fila);

    while(toupper(op)!='S'){

        printf("\nEscolha uma opcao:\n(C)adastrar novo pedido\n(E)ntregar bebida\n(A)dmnistrativo\n(S)air do programa\n\n>> ");
        scanf("%c",&op);

        switch(toupper(op)){
            case 'C':
                if (FilaCheia(fila)!=1){

                    printf("\nPedido: ");
                    scanf("%i",&dado.pedido);
                    printf("Nome: ");
                    LerString(dado.nome);
                    printf("Item: ");
                    LerString(dado.item);

                    InserirNaFila(&fila,dado);
                    break;

                }else{
                    printf("Nao foi possivel cadastrar! (FILA CHEIA)\n");
                    break;
                }

            case 'A':
                ExibirFila(fila);
                break;

            case 'E':
                if (FilaVazia(fila)!=1){
                    RetirarDaFila(&fila, &dado);
                    printf("Final: %i\n%s!\n%s pronto\n\n",dado.pedido, strupr(dado.nome), dado.item);
                    break;

                }else{
                    printf("Todos os pedidos ja foram entregues! (FILA VAZIA)\n");
                    break;
                }

            default:
                printf("Opcao invalida\n");
                //Parece que ta entrando sempre q aperta A ou E tb
        }
    }
    printf("\nPrograma Finalizado\n\n");
    return 0;
}
