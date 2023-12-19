#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// RA Nome
// RA Nome
// RA Nome

#include <math.h>
#define MAX 255
#define Ro 6372795.477598
#define VALOR_PI 3.1415

// **************************************
//    Criar a estrutura de dados GPS
// **************************************
typedef struct
{

} GPS;
// **************************************


// **************************************
//        Prot�tipos das fun��es
// **************************************
void LerLinha(char[], FILE*);
void Trocar(char[], char, char);
GPS ConverterGPS(char[]);
float CalcularDistancia(GPS, GPS);
// **************************************


int main()
{
    // *******************************************
    //   declara��o das vari�veis
    // *******************************************


    // *******************************************




    // *******************************************
    //    abertura do arquivo de entrada
    // *******************************************


    // *******************************************




    // *******************************************
    //    abertura do arquivo de saida
    // *******************************************


    // *******************************************




    // *******************************************
    //    Ler o cabe�alho do arquivo
    // *******************************************
 

    // *******************************************





    // *******************************************
    //    Ler o primeiro dado do arquivo
    //    e armazenar como um "ponto anterior"
    // *******************************************
 


    // *******************************************





    // *******************************************
    //    Ler os demais dados do arquivo
    // *******************************************
    while ( /*ler o arquivo até o final*/ )
    {
        // *********************************************
        //    Ler uma linha e separar os dados do ponto
        // *********************************************
        

        // *******************************************





        // *****************************************************
        //   Se o "tempo atual" for igual ao "tempo anterior"
        //   OU
        //   se todas as coordenadas do "ponto atual" forem
        //    iguais as do "ponto anterior"
        //   O PONTO DEVE SER IGNORADO
        // *****************************************************
        if (  /*Condicao descrita acima*/ ) {

            // **********************************************************************
            //  calcular a dist�ncia entre o "ponto atual" e o "ponto antrior" em m,
            //  calcular o somat�rio da dist�ncia total em m,
            //  calcular a velocidade instant�nea em km/s
            //  exibir o que foi processado
            //  acrescantar ao novo arquivo as informa��es lidas e a velocidade
            // **********************************************************************
             

            // *******************************************

        }  // fim do if
        // *******************************************



        // *******************************************
        //    Atualizar o "ponto anterior"
        // *******************************************
         


        // *******************************************
    } // fim do while


    // *******************************************
    //    exibir o total percorrido
    // *******************************************
     

    // *******************************************





    // *******************************************
    //    Fechar os arquivos
    // *******************************************
     

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
    
}
// **************************************



// *******************************************
//  Retorna a dist�ncia entre os pontos A e B
// NÃO ESQUECER DE CONVERTER OS VALORES DE ENTRADA 
// AS FUNÇÕES TRIGONOMÉTRICAS PARA RADIANO!!
// *******************************************
float CalcularDistancia(GPS A, GPS B)
{
     
}
// **************************************
