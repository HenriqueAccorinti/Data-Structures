#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,i;
    int vet1[8] = {4,8,12,45,1,0,8,55};
    int vet2[8] = {5,7,1,2,8,66,12,4};

    for(i=0;i<8;i++){
        vet1[i] = 8;
        vet2[i] = (2*i)-2;
    }

    for(i=0;i<8;i++){
        printf("\nvet1[%i] = %i",i,vet1[i]);
        printf("\tvet2[%i] = %i",i,vet2[i]);
    }

    printf("\nx: ");
    scanf("%i",&x);

    printf("y: ");
    scanf("%i",&y);

    printf("\n\nSoma de vet1[%i] = %i + vet2[%i] = %i = %i", x,vet1[x],y,vet2[y],vet1[x]+vet2[y]);

    return 0;
}
