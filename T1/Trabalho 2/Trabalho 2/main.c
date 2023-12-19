#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 20.00080-4 Henrique Fortuna Accorinti
// 19.02404-5 Guilherme Sanches Rossi
// 20.00780-9 Matheus Andrade Mastroeni
// 20.00045-6 Allan Barcessat


#include <math.h>
#define MAX 255
#define Ro 6372795.477598
#define VALOR_PI 3.1415

// **************************************
//    Criar a estrutura de dados GPS
// **************************************
typedef struct
{
    float lat, lon, alt;
    int tempo;
} GPS;
// **************************************


// **************************************
//        Prototipos das funcoes
// **************************************
void LerLinha(char[], FILE*);
void Trocar(char[], char, char);
GPS ConverterGPS(char[]);
float CalcularDistancia(GPS, GPS);
// **************************************


int main()
{
    // *******************************************
    //   declaracao das variaveis
    // *******************************************
    GPS gps[2039];
    float somaDist=0, velInst;
    char linha[MAX];
    int i = 0;
    // *******************************************




    // *******************************************
    //    abertura do arquivo de entrada
    // *******************************************
    FILE *arquivo = fopen("rio_do_ouro.csv", "r");

    //Verifica se o arquivo foi aberto
    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }
    // *******************************************




    // *******************************************
    //    abertura do arquivo de saida
    // *******************************************
    FILE *arquivoSaida1 = fopen("rio_do_ouro_saida.csv", "w");

    //Verifica se o arquivo foi aberto
    if(arquivoSaida1 == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    // *******************************************




    // *******************************************
    //    Ler o cabecalho do arquivo
    // *******************************************
    LerLinha(linha, arquivo);
    printf("%s\n", linha);
    // *******************************************


    // *******************************************
    //    Ler os demais dados do arquivo
    // *******************************************
    while (fgets(linha,MAX,arquivo) != NULL)
    {
        // *********************************************
        //    Ler uma linha e separar os dados do ponto
        // *********************************************
        LerLinha(linha, arquivo);
        Trocar(linha, ',', '.');
        gps[i] = ConverterGPS(linha);

        // *******************************************





        // *****************************************************
        //   Se o "tempo atual" for igual ao "tempo anterior"
        //   OU
        //   se todas as coordenadas do "ponto atual" forem
        //    iguais as do "ponto anterior"
        //   O PONTO DEVE SER IGNORADO
        // *****************************************************
        if ( !(gps[i+1].tempo == gps[i].tempo || ((gps[i+1].lat == gps[i].lat)
               &&(gps[i+1].lon == gps[i].lon)&&(gps[i+1].alt == gps[i].alt))) ) {

            // **********************************************************************
            //  calcular a distancia entre o "ponto atual" e o "ponto antrior" em m,
            //  calcular o somatorio da distancia total em m,
            //  calcular a velocidade instantanea em km/s
            //  exibir o que foi processado
            //  acrescantar ao novo arquivo as informacoes lidas e a velocidade
            // **********************************************************************


            somaDist += CalcularDistancia(gps[i], gps[i+1]);

            velInst = 3.6*(CalcularDistancia(gps[i],gps[i+1]))/(gps[i+1].tempo - gps[i].tempo);

            fprintf(arquivoSaida1,"%.2f;%.2f;%.2f;%i;",gps[i+1].lat,gps[i].lon,gps[i+1].alt,gps[i+1].tempo);
            fprintf(arquivoSaida1,"%f\n",velInst);


            // *******************************************

       }  // fim do if
        // *******************************************
        i += 1;


        // *******************************************
    } // fim do while


    // *******************************************
    //    exibir o total percorrido
    // *******************************************
    printf("\nTotal Percorrido: %.2f km\n", somaDist/1000);

    // *******************************************





    // *******************************************
    //    Fechar os arquivos
    // *******************************************
    fclose(arquivo);
    fclose(arquivoSaida1);
    // *******************************************

    return 0;
}


// **************************************
//       Ler uma linha do arquivo
// **************************************
void LerLinha(char linha[], FILE *arq)
{
    fgets(linha,MAX,arq);
    if (linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1] = '\0';
}
// **************************************



// **************************************
//  Trocar o caractere antigo pelo novo
// **************************************
void Trocar(char linha[], char antigo, char novo)
{
    int i;
    for (i = 0; i < strlen(linha); i++)
        if (linha[i] == antigo)
            linha[i] = novo;
}
// **************************************



// ********************************************
//  Divide uma string pelo caractere separador
//  nos campos da estrutura de dados GPS
// ********************************************
GPS ConverterGPS(char msg[])
{
    GPS gps;

    char *token = strtok(msg, ";");

    gps.lat = atof(token);
    token = strtok(NULL, ";");

    gps.lon = atof(token);
    token = strtok(NULL, ";");

    gps.alt = atof(token);
    token = strtok(NULL, ";");

    gps.tempo = atoi(token);

    printf("%f   %f   %f   %i\n", gps.lat, gps.lon, gps.alt, gps.tempo);
    return gps;
}
// **************************************



// *******************************************
//  Retorna a distancia entre os pontos A e B
// NÃO ESQUECER DE CONVERTER OS VALORES DE ENTRADA
// DAS FUNÇÕES TRIGONOMÉTRICAS PARA RADIANO!!
// *******************************************
float CalcularDistancia(GPS A, GPS B)
{
    float dh, dv, Dist;
    //Passando para radianos
    A.lat = A.lat *VALOR_PI/180;
    B.lat = B.lat *VALOR_PI/180;
    A.lon = A.lon *VALOR_PI/180;
    B.lon = B.lon *VALOR_PI/180;

    dh = Ro*acos(( sin(A.lat)*sin(B.lat)) +
        cos(A.lat)*cos(B.lat)*cos(A.lon-B.lon));

    dv = B.alt - A.alt;
    Dist = sqrt(pow(dh,2)+ pow(dv,2));

    return Dist;
}
// **************************************

