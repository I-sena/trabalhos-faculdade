/*
* 1. Escreva uma função que retorne o valor de n!.
*/
#include<stdio.h>

int fatorial(int x){
    int fat=1,i;
    for(i=x;i>=1;i--){
        fat=fat*i;
    }
    return fat;
}


int main(){
    int x,fat;
    scanf("%d",&x);
    fat=fatorial(x);
    printf("fat= %d",fatorial(x));
    return 0;
}