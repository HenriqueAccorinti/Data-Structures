#include <stdio.h>
#include <stdlib.h>
#include <math.h>  /* para usar o INFINITY */
#include "grafo.h"

void ExibirGrafo (Grafo g)
{
    int i, j;
    system("CLS");
    printf ("Numero de vertices do %s: %i\n", g.digrafo==0?"GRAFO":"DIGRAFO",g.nVertices);
    for (i=0; i <g.nVertices; i++)
    {
        for (j=0; j < g.nVertices; j++)
            printf ("%0.1f   ", PesoDaAresta (g, i, j));
        printf ("\n");
    }
    printf ("\n");
}


int main (){
    int n, dig, i;
    Grafo g;
    int origem = 0;
    int destino = 12; // opcional
    int grafoConexo = 0;
    ListaDeVertices caminho;


    // grafo do PPT
    n = 17;
    dig = 0;
    CriarGrafo (&g, n, dig);
    InserirAresta (&g, 0, 1, 1);
    InserirAresta (&g, 1, 2, 1);
    InserirAresta (&g, 1, 3, 1);
    InserirAresta (&g, 1, 5, 1);
    InserirAresta (&g, 4, 5, 1);
    InserirAresta (&g, 5, 6, 1);
    InserirAresta (&g, 6, 7, 1);
    InserirAresta (&g, 6, 8, 1);
    InserirAresta (&g, 6, 11, 1);
    InserirAresta (&g, 7, 9, 1);
    InserirAresta (&g, 8, 9, 1);
    InserirAresta (&g, 9, 10, 1);
    InserirAresta (&g, 9, 11, 1);
    InserirAresta (&g, 10, 13, 1);
    InserirAresta (&g, 10, 15, 1);
    InserirAresta (&g, 11, 12, 1);
    InserirAresta (&g, 12, 16, 1);
    InserirAresta (&g, 13, 14, 1);
    InserirAresta (&g, 13, 16, 1);
    InserirAresta (&g, 15, 16, 1);

    ExibirGrafo (g);


    printf ("Busca em profundidade: \n");
    DFS(g, origem, destino, &caminho);
    for (i=0; i < caminho.nVertices; i++)
        printf("%c    ",caminho.vertices[i]+65);
    printf ("\n\n");


    printf ("Busca em largura: \n");
    float dist[g.nVertices];
    BFS(g, origem, destino, dist, &caminho);
    for (i=0; i < g.nVertices; i++)
        if (dist[i] != INFINITY)
            printf("%c: %5.2f\n",caminho.vertices[i]+65,dist[i]);
        else{
            printf("%c:  +inf\n",caminho.vertices[i]+65);
            grafoConexo++;
        }
    if (grafoConexo != 0)
        printf("Grafo Nao Conexo\n");
    else
        printf("Grafo Conexo\n");

    return 0;
}
