#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
    Heap* A = Create();
    for(int i = 0; i < 9; i++){
        if(!Heap_Insert(A,vet[i]))
            printf("ERRO AO INSERIR\n");
    }
    Build_Max_Heap(A);
    Print_Heap(A);
    troca(A);
    /*printf("\n%d  >   %d",Right(Parent(Parent(8))));
    printf("\n%d ",Left(Right(Parent(1))));
    printf("\n%d    %d",Right(Left(2)));
    printf("\n%d",Left(Parent(Right(1))));*/
    return 0;
}