#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Lucas Marcelino de Melo Lopes 19.00319-6
// Carlos Alberto Matias da Costa 20.01308-6
// Gustavo Henrique dos Santos Aivazoglou 20.01758-8

#include <math.h>
#define MAX 255
#define Ro 6372795.477598
#define VALOR_PI 3.1415

// **************
//    Criar a estrutura de dados GPS
// **************
typedef struct
{
    float lat, lon, alt;
    int tempo;
} GPS;
// **************


// **************
//        Prototipos das funcoes
// **************
void LerLinha(char[], FILE*);
void Trocar(char[], char, char);
GPS ConverterGPS(char[]);
float CalcularDistancia(GPS, GPS);
// **************


int main()
{
    // ***************
    //   declaracao das variaveis
    char linha[MAX], ponto_anterior[MAX];
    FILE *arquivo;
    FILE *saida;
    GPS ponto,ponto_a;
    float dist,sum_dist=0, velo, DH, DV;
    // ***************





    // ***************





    // ***************
    //    abertura do arquivo de entrada
    // ***************
    arquivo = fopen("rio_do_ouro.csv", "r");
    // ***************

    // ***************
    //    abertura do arquivo de saida
    // ***************
    saida = fopen("saida.csv", "w");
    // ***************

    if(arquivo==NULL || saida == NULL)
    {

        printf("Algo deu errado!\n");
        exit(EXIT_FAILURE);
    }



    // ***************
    //    Ler o cabecalho do arquivo
    // ***************

    LerLinha(linha, arquivo);
    printf("%s", linha);

    // ***************





    // ***************
    //    Ler o primeiro dado do arquivo
    //    e armazenar como um "ponto anterior"
    // ***************
    LerLinha(linha, arquivo);
    printf("\n oi \n");
    ponto_a = ConverterGPS(linha);
    printf("%f , %f, %f, %i", ponto_a.lat, ponto_a.lon, ponto_a.alt, ponto_a.tempo);

    ponto_a.lat=(ponto_a.lat*VALOR_PI)/180;
    ponto_a.lat=(ponto_a.lat*VALOR_PI)/180;


    // ***************




    // ***************
    //    Ler os demais dados do arquivo
    // ***************

    while(!feof(arquivo))
    {
        LerLinha(linha, arquivo);
        Trocar(linha, ',', '.');

        GPS ponto = ConverterGPS(linha);
        //printf("\n%f",ponto.lat);
        ponto.lat=(ponto.lat*VALOR_PI)/180;
        ponto.lon=(ponto.lon*VALOR_PI)/180;
        //printf("\n%f",ponto.lat);

        if(!((ponto.lat==ponto_a.lat&&ponto.lon==ponto_a.lon&&ponto.alt==ponto.alt)))
        {
            DH=Ro*acosf(sinf(ponto_a.lat)*sinf(ponto.lat)+cosf(ponto_a.lat)*cosf(ponto.lat)*cosf(ponto_a.lon-ponto.lon));
            DV=ponto.alt-ponto_a.alt;
            dist = sqrt(pow(DH,2)+pow(DV,2));
            sum_dist+=dist;
            velo = 3.6*(dist/(ponto.tempo-ponto_a.tempo));
            Trocar(linha, '.', ',');
            fprintf(saida,"%f;%f;%f;%i",(ponto.lat,ponto.lon,ponto.alt,ponto.tempo));
            printf("\nDH:%.2f; DV:%.2f; dist:%.2f; soma de distancias:%.2f; velocidade:%f",DV,DV,dist,sum_dist,velo);
        }

    }



        // ***************
        //    exibir o total percorrido
        // ***************
        printf("\n\ndistancia total percorrida: %f",sum_dist);
        // ***************





        // ***************
        //    Fechar os arquivos
        // ***************
        fclose(arquivo);
        fclose(saida);
        // ***************

    return 0;
}


// **************
//       Ler uma linha do arquivo
// **************
void LerLinha(char linha[], FILE *arq)
{
    fgets(linha,MAX,arq);
    if (linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1] = '\0';
}
// **************



// **************
//  Trocar o caractere antigo pelo novo
// **************
void Trocar(char linha[], char antigo, char novo)
{
    int i;
    for (i = 0; i < strlen(linha); i++)
        if (linha[i] == antigo)
            linha[i] = novo;
}
// **************



// ****************
//  Divide uma string pelo caractere separador
//  nos campos da estrutura de dados GPS
// ****************
GPS ConverterGPS(char msg[])
{
    GPS ajuda;
    char *token = strtok(msg,";");
    ajuda.lat = atof(token);
    token = strtok(NULL,";");
    ajuda.lon = atof(token);
    token = strtok(NULL,";");
    ajuda.alt = atof(token);
    token = strtok(NULL,";");
    ajuda.tempo = atoi(token);
    return ajuda;
}
// **************



// ***************
//  Retorna a distancia entre os pontos A e B
// NÃO ESQUECER DE CONVERTER OS VALORES DE ENTRADA
// AS FUNÇÕES TRIGONOMÉTRICAS PARA RADIANO!!
// ***************
float CalcularDistancia(GPS A, GPS B)
{

}
// **************
