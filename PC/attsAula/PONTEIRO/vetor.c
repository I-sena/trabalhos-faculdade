/*
** Escreva uma função que receba um vetor, o tamanho do vetor e um valor n como argumentos
** e retorne a quantidade de vezes que o valor n aparece no vetor.
*/

#include<stdio.h>

int func_vet(int *vet, int size, int n); 

int main(){

    int size,n,res;
    scanf("%d",&size);
    int vet[size];
    for(int i=0;i<size;i++){
        scanf("%d",&vet[i]);
    }
    scanf("%d",&n);
    res=func_vet(vet,size,n);       // PARA PASSAR VET NAO PRECISA DO "&".
    printf(" o valor %d foi encontado %d vezes.",n,res);
    return 0;
}

int func_vet(int *vet, int size, int n){
    int i,res=0;

    for(i=0;i<size;i++){
        if(vet[i]==n){
            res++;
        }
    }
    return res;
}


