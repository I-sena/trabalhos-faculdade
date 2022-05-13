//2. Escreva uma funcao que, recebendo um parâmetro n,
// retorne o valor de: 1 + 1/2 + 1/3 + ... + 1/n



#include<stdio.h>

float func(float a){
    int i;
    float res;
    res=0;
    for(i=1; i<=a; i++){
        res=res+(float)(1/i);
    }
    return res;
}

int main(){
    float n,res;

    printf("numero:");
    scanf("%f",&n);
    res=func(n);
    printf("%.2f",res);

    return 0;
}