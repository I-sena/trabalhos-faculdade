#include <stdio.h>
#include "queue.h"

int main(){
    int id_orig, id_dest, N;
    float valor;
    int tempO, tempD;
    float tempV;

    scanf("%d",&N);
    Queue* banco = Queue_create(N);
    scanf("%d %d %f%*c",&id_orig,&id_dest,&valor);
    do{
        if(IsFull(banco)){
            while(Dequeue(banco,&tempO,&tempD,&tempV))
                printf("(%d, %d, %.2f),",tempO,tempD,tempV);
            puts("");
        }
        if(!Enqueue(banco,id_orig,id_dest,valor))
            printf("ERRO AO INSERIR NA FILA.\n");
        scanf("%d %d %f%*c",&id_orig,&id_dest,&valor);       
    }while(!(id_orig == 0 && id_dest == 0));

    if(!(IsEmpty(banco))){
        while(Dequeue(banco,&tempO,&tempD,&tempV))
            printf("(%d, %d, %.2f),",tempO,tempD,tempV);
        puts("");
    } 
    Destroy(banco);
    return 0;
}