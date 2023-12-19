//dist de dois pontos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}Ponto;

int main()
{
    float distancia;
    Ponto P1,P2;

    printf("Digite as coordenadas de x e y do ponto P1: ");
    scanf("%f",&P1.x);
    scanf("%f",&P1.y);
    printf("Digite as coordenadas de x e y do ponto P2: ");
    scanf("%f",&P2.x);
    scanf("%f",&P2.y);

    distancia = pow(pow(fabs(P1.x - P2.x),2)+ pow(fabs(P1.y - P2.y),2), 0.5);

    printf("A distancia dos pontos: %.2f",distancia);

    return 0;
}
