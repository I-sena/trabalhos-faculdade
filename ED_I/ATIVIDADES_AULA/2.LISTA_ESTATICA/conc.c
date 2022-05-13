#include "conc.h"
#include <stdlib.h>
#include <stdio.h>

struct Lista{
    int qty;
    struct aluno dados[MAX];
};

lista* newList(){
    lista* new = malloc(sizeof(lista));
    if (new){
        new->qty = 0;
    }  
    return new;
}

void printLista(lista* list){
    for (int i = 0; i < list->qty; i++){
        printf("code= %d\n",list->dados[i].code);
        printf("nome= %s\n",list->dados[i].nome);
        printf("nota 1= %.1f\n",list->dados[i].n1);
        printf("nota 2= %.1f\n",list->dados[i].n2);
        printf("------------------------------------\n");
    }
}

int insert_end(lista* list, struct aluno al){
    if (list == NULL || list->qty == MAX)   return 0;
    list->dados[list->qty] = al;
    list->qty++;
    return 1;
}

int insert_begin(lista* list,struct aluno al){
    if (list == NULL || list->qty == MAX)    return 0;
    for (int i = list->qty; i > 0; i--)
        list->dados[i] = list->dados[i-1];
    list->dados[0] = al;
    list->qty++;
}

int insert_middle(lista* list ,int position, struct aluno al){
    if (list == NULL || list->qty == MAX || position < 1)   return 0;
    for (int i = list->qty; i > position-1; i--)   //o igual
        list->dados[i] = list->dados[i-1];
    list->dados[position-1] = al;
    list->qty++;
}

int insert_by_codeOrder(lista* list, struct aluno al){
    if(list == NULL || list->qty == MAX)    return 0;
    int i = 0;
    while (i < list->qty && list->dados[i].code < al.code)
        i++;
    for (int k = list->qty; k > i; k--)
        list->dados[k] = list->dados[k-1];
    list->dados[i] = al;
    list->qty++;
    return 1;
}

void deleteList(lista* list){
    free(list);
}

void emptyList(lista* list){
    if(list == NULL)
        printf("lista invalida.\n");
    else{
        if(list->qty == 0)
            printf("lista vazia.\n");
        else    
            printf("lista nao esta vazia.\ncontem %d dados.\n",list->qty);
    }
}

void fullList(lista* list){
    if(list == NULL)
        printf("lista invalida.\n");
    else{
        if(list->qty == MAX)
            printf("lista cheia.\n");
        else    
            printf("lista nao esta cheia.\ncontem %d dados.\n",list->qty);
    }
}

void sizeList(lista* list){
    if(list == NULL)
        printf("lista invalida.\n");
    else
        printf("lista contem %d dados.\n",list->qty);
}

void printByCode(lista* list,int code){
    if(list == NULL || list->qty == 0)
        printf("lista invalida.\n");
    else{
        for (int i = 0; i < list->qty-1; i++){
            if(list->dados[i].code == code){
                printf("code= %d\n",list->dados[i].code);
                printf("nome= %s\n",list->dados[i].nome);
                printf("nota 1= %.1f\n",list->dados[i].n1);
                printf("nota 2= %.1f\n",list->dados[i].n2);
                printf("------------------------------------\n");
                break;
            }
        }
        printf("codigo nao encontrado.");
    }
}

void removeData_end(lista* list ){
    if(list == NULL || list->qty == 0){
        printf("lista invalida.\n");
    }
    else{
        list->qty--;
        printf("dado removido.\n");
    }
}

void removeData_begin(lista* list){
    if(list == NULL || list->qty == 0){
        printf("lista invalida.\n");
    }
    else{
        for(int i = 0; i < list->qty-1; i++){
            list->dados[i] = list->dados[i+1];
        }
        list->qty--;
        printf("dado removido.\n");
    }
}

void removeData_byCode(lista* list, int code){
    if(list == NULL || list->qty == 0){
        printf("lista invalida.\n");
    }
    else{
        int i=0;
        while (i < list->qty-1 && list->dados[i].code != code)
            i++;
        for (int k=i; k<list->qty; k++)
            list->dados[k] = list->dados[k+1];
        list->qty--;
    }
}

// 1. Faça uma função para concatenar duas listas em uma terceira lista que deverá ser retornada pela
// função. Faça duas versões: uma que se utilize das funções já implementadas e outra que não usa
// qualquer função já feita do TAD.
lista* concateLista(lista* l1, lista* l2){
    lista* new = newList();
    if(l1 == NULL || l2 == NULL || new == NULL){
        printf("ERRO \n");
    }
    else{
        if(l1->qty + l2->qty <= MAX){
            int i;
            for (i = 0; i < l1->qty; i++){
                insert_end(new,l1->dados[i]);
            }
            for(i = 0; i < l2->qty; i++){
                insert_end(new,l2->dados[i]);
            }
        }
    }
    return new;
}
