#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

void main(){

    char string[MAX];
    int i;

    printf("Digite um valor com ';' : ");
    gets(string);
    printf("%s\n",string);

    for(i=0; i<strlen(string); i++){
        if(string[i]==';'){
            string[i]='\n';
        }
    }

    printf("%s\n", string);

    return 0;
}
