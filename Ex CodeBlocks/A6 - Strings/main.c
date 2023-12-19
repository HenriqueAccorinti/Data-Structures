#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

void lerString(char []);
void retirarEspaco(char [], char []);
void Inverter(char [], char []);

int main(){

    int a;
    char s1[MAX];
    char s2[MAX];
    char s3[MAX];

    lerString(s1);

    retirarEspaco(s1,s2);

    Inverter(s2,s3);

    printf("String 1: %s\n",s1);
    printf("String 2: %s\n",s2);
    printf("String 3: %s\n",s3);

    return 0;
}

void lerString(char s[]){
    fflush(stdin);
    printf("Digite seu texto: ");
    fgets(s,MAX,stdin);

    if(s[strlen(s)-1] == '\n'){
        s[strlen(s)-1] = '\0';
    }
}

void retirarEspaco(char s1[], char s2[])
{
    int i, j = 0;
    for (i = 0; i < strlen(s1); i++)
        if (s1[i] != ' '){
            s2[j] = s1[i];
            j++;
        }
    s2[j] = '\0';  // finalizar a string
}

void Inverter(char s1[], char s2[]){
    int i, j, N;
    N = strlen(s1);
    for (i = N-1; i >= 0; i--)
        s2[N-i-1] = s1[i];
    s2[N-i-1] = '\0';     // finalizar a string
}
