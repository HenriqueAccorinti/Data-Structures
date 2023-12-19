#include "grafo.h"

//Henrique Fortuna Accorinti      RA: 20.00080-4
//Guilherme Nami Bortolozi        RA: 20.00333-0
//Ana Helena                      RA: 20.01305-0
//Christian Cunha Paes de Almeida RA: 20.01795-2

void CriarGrafo (Grafo *g, int n, int dig)
{
    int i, j;
    g->nVertices = n;
    g->digrafo = dig;
    for (i=0; i < g->nVertices; i++)
        for (j=0; j < g->nVertices; j++)
            g->Pesos[i][j] = 0;
}


void InserirAresta (Grafo *g, int de, int para, float peso)
{
    g->Pesos[de][para] = peso;
    if (!g->digrafo)
        g->Pesos[para][de] = peso;
}


void RemoverAresta (Grafo *g, int de, int para)
{
    g->Pesos[de][para] = 0;
    if (!g->digrafo)
        g->Pesos[para][de] = 0;
}


float PesoDaAresta (Grafo g, int de, int para)
{
    return g.Pesos[de][para];
}


int GrauDeEntrada (Grafo g, int v){
int i, soma=0;

    for(i=0;i<3;i++){
        if(PesoDaAresta(g, i, v)!=0)
            soma += 1;
    }
    return soma;
}


int GrauDeSaida (Grafo g, int v){
int j, soma=0;

    for(j=0;j<3;j++){
        if(PesoDaAresta(g, v, j)!=0)
            soma += 1;
    }
    return soma;
}


int Vertedouro (Grafo g, int v){
//Se GrauDeEntrada (Grafo g, int a,b,c..) = 0
    if (GrauDeEntrada(g, v)==0){
        return 1;
    }
    return 0;
}


int Sorvedouro (Grafo g, int v){
//Se GrauDeSaida (Grafo g, int a,b,c..) = 0
    if (GrauDeSaida(g, v)==0){
        return 1;
    }
    return 0;
}


int Adjacente(Grafo g, int de, int para){
    if(PesoDaAresta(g,para,de)!=0)
        return 1;
    else
        return 0;
}

void Warshall (Grafo g, int W[MAX_VERT][MAX_VERT]){
//Entrada g: Grafo com matriz de adjacências ou de pesos do dígrafo
//Saída W: a matriz “lógica” de vértices Alcançáveis

int i, j, k;

    for(i=0;i<MAX_VERT;i++){
        for(j=0;j<MAX_VERT;j++){
            W[i][j] = PesoDaAresta(g,i,j) != 0;
        }
    }
    for(k=0;k<MAX_VERT;k++){
        for(i=0;i<MAX_VERT;i++){
            for(j=0;j<MAX_VERT;j++){
                W[i][j] = W[i][j] || (W[i][k] && W[k][j]);
            }
        }
    }
}


int Alcanca (Grafo g, int de, int para){
    int w[MAX_VERT][MAX_VERT];
    Warshall(g, w);
    return (w[de][para] != 0);;
}


float PesoDoPasseio (Grafo g, ListaDeVertices p){
    int i, soma=0;
    for(i=0;i<10;i++){
        soma += PesoDaAresta(g,p.vertices[i],p.vertices[i+1]);
    }

}
