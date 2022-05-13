/*
** Escreva uma função que receba um vetor, o tamanho do vetor e um valor n como argumentos 
** e retorne a posição da primeira ocorrência do valor n no vetor. Retorne -1 caso o valor
** não seja encontrado.
*/

#include<stdio.h>

int func_vet(int *vet, int size, int n);

int main(){
    int size, i, n, res;

    scanf("%d",&size);
    int vet[size]; 

    for(i=0; i<size; i++){
        scanf("%d",&vet[i]);
    }

    scanf("%d",&n);
    res=func_vet(vet,size,n);
    printf("O valor %d foi encontrado na %d posicao do vetor",n,res);

    return 0;
}

int func_vet(int *vet, int size, int n){
    int i,res=-1;;

    for(i=0; i<size; i++){
        if(vet[i]==n){
            res=i;      
            return res+1;
        }
    }
    return res;
}
