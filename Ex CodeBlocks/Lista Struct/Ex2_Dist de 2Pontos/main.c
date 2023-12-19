#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct{
    int hora;
    int minuto;
    int segundo;
} horario;

void exibeHora(horario[]);
horario maiorHora(horario[]);

int main(){
    horario vetHorarios[N];
    horario maior;
    int i;

    for(i=0;i<N;i++){
        printf("Entre com a hora[%i]: ",i);
        scanf("%i",&vetHorarios[i].hora);
        printf("Entre com o minuto[%i]: ",i);
        scanf("%i",&vetHorarios[i].minuto);
        printf("Entre com o segundo[%i]: ",i);
        scanf("%i",&vetHorarios[i].segundo);
        printf("\n");
    }

    //exibeHora(vetHorarios);

    maior = maiorHora(vetHorarios);
    printf("Maior horario: %02i:%02i:%02i\n",maior.hora,maior.minuto,maior.segundo);
    return 0;
}

void exibeHora(horario v[]){
    int i;

    for(i=0;i<N;i++){
        printf("hora[%i]: %i\n",i,v[i].hora);
        printf("minuto[%i]: %i\n",i,v[i].minuto);
        printf("segundo[%i]: %i\n",i,v[i].segundo);
        printf("\n");
    }
}

horario maiorHora(horario v[]){
    int i;
    horario aux;

    aux.hora = v[0].hora;
    aux.minuto = v[0].minuto;
    aux.segundo = v[0].segundo;


    for(i=0;i<N;i++){
        if(v[i].hora > aux.hora){
            aux.hora = v[i].hora;
            aux.minuto = v[i].minuto;
            aux.segundo = v[i].segundo;
        }
    }
    return aux;
}
