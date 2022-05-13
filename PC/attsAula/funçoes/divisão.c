//2. Escreva uma função que, recebendo um parâmetro n,
// retorne o valor de: 1 + 1/2 + 1/3 + ... + 1/n

#include<stdio.h>

float divisao(int x){
    int i;
    float resul=0;
    for(i=1;i<=x;i++){
        resul=resul+(float)1/i;
    }
    return resul;
}

int main(){
    float resul;
    int n;
    scanf("%d",&n);
    resul=divisao(n);
    printf("resul = %0.2f",resul);
    return 0;
}