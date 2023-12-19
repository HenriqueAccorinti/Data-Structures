#include <stdio.h>
#include <time.h>

int main(){
int vet[100], i;
while(i<100){
    vet[i+1] = vet[i*7];
}
printf(vet);
return 0;
}
