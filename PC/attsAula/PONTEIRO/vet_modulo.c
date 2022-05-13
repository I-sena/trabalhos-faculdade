/*
** Escreva uma função que substitua todos os valores de um vetor 
** por seu respectivo módulo. 
*/

#include<stdio.h>

void fun_modulo(int *vet,int size);

int main(){
    int size,i;

    scanf("%d",&size);
    int vet[size];

    for(i=0; i<size; i++){
        scanf("%d",&vet[i]);
    }
    
    printf("---- ANTES DA FUNCAO ---\n");
    for(i=0;i<size; i++){
        printf("vet[%d]= %d\n",i,vet[i]);
    }

    fun_modulo(vet,size);

    printf("---- DPS DA FUNCAO ----\n");
    for(i=0;i<size; i++){
        printf("vet[%d]= %d\n",i,vet[i]);
    }

    return 0;
}

void fun_modulo(int *vet, int size){
    int i;
    for(i=0; i<size; i++){
        if(vet[i]<0){
            vet[i]= vet[i]*(-1);
        }
    }
}
