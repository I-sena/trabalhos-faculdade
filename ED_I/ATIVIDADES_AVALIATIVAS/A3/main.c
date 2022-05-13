#include"circular.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int qtyTeste, qtySold, Number;
    int i, luckyNumber;
    scanf("%d",&qtyTeste);
    while(qtyTeste > 0){
        scanf ("%d %d",&qtySold,&Number);
        LISTA* L = newList();
        for (i = 1; i <= qtySold; i++){
            if(!insertEnd(L,i))             
                printf("Erro ao inserir.\n");
        }
        luckyNumber = rightPosition(L,qtySold,Number);
        printf("%d\n",luckyNumber);
        qtyTeste--;
    }
    return 0;
}