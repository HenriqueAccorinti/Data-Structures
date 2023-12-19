#include <stdio.h>
#include <stdlib.h>
#include <math.h>  /* para usar o INFINITY */
#include "grafo.h"

void ExibirGrafo (Grafo g)
{
    int i, j;
    system("CLS");
    printf ("Numero de vertices do %s: %i\n", g.digrafo==0?"GRAFO":"DIGRAFO",g.nVertices);

    // primeira linha com nomes dos vértices
    printf("    ");
    for (i=0; i <g.nVertices; i++)
        printf("%c   ", 65+i);
    printf("%\n");

    for (i=0; i <g.nVertices; i++)
    {
        // primeira coluna com nomes dos vértices
        printf("%c   ", 65+i);
        for (j=0; j < g.nVertices; j++)
            printf ("%0.0f   ", PesoDaAresta (g, i, j));
        printf ("\n");
    }
    printf ("\n");
}


int main ()
{
    int n, dig, i, origem, destino;
    Grafo g;
    ListaDeVertices caminho;
    float custo;
    float dist[MAX_VERT];
    int ant[MAX_VERT];


    /* **********************************************
               DADOS DO GRAFO DO PROBLEMA
    ********************************************** */

    // grafo do PPT
    n = 7;
    dig = 0;
    origem = 0;
    destino = 3;
    CriarGrafo (&g, n, dig);
    //InserirAresta (&g, , , );

    InserirAresta (&g, 0, 1, 9);
    InserirAresta (&g, 0, 5, 4);
    InserirAresta (&g, 0, 6, 5);
    InserirAresta (&g, 1, 2, 4);
    InserirAresta (&g, 1, 4, 9);
    InserirAresta (&g, 1, 5, 6);
    InserirAresta (&g, 1, 6, 9);
    InserirAresta (&g, 2, 3, 3);
    InserirAresta (&g, 2, 4, 6);
    InserirAresta (&g, 2, 5, 6);
    InserirAresta (&g, 3, 4, 10);
    InserirAresta (&g, 4, 5, 5);
    InserirAresta (&g, 5, 6, 5);


    /* **********************************************
               DADOS DO GRAFO DO PROBLEMA
    ********************************************** */


    ExibirGrafo (g);


    printf ("Dijkstra: \n");
    Dijkstra(g, origem, destino, dist, ant, &caminho);
    printf("Vert\tAnt\tDist\n");
    for (i=0; i<g.nVertices; i++)
        if (dist[i] != INFINITY)
            printf(" %i\t%i\t%5.2f\n",i, ant[i], dist[i]);
        else
            printf(" %i\t%i\t +inf\n",i, ant[i]);
    printf ("\n");

    printf ("Caminho: ");
    for (i=0; i<caminho.nVertices; i++)
        printf("%i   ", caminho.vertices[i]);
    printf ("\n\n\n");



    printf ("Prim: \n");
    Prim(g, origem, ant, &custo);
    printf("Vert\tAnt\n");
    for (i=0; i<g.nVertices; i++)
        printf(" %i\t%i\n",i, ant[i]);
    printf ("\n");
    printf("Custo: %.2f   ", custo);
    printf ("\n\n");


    return 0;
}
