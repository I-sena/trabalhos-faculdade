#include "TLinkedListUtils.h"
#include "TLinkedList.h"

#include<stdio.h>
#include<stdlib.h>

typedef struct nova{
  int position ;                
  struct node *address;        
  struct nova *next;
}caixinha;

struct lista{
  struct nova* inicio;
  struct nova* final;
  int qty;
};

LISTA* new(){
  LISTA* L= malloc(sizeof(LISTA));
  if(L != NULL){
    L->inicio=NULL;
    L->final= NULL;
    L->qty=0;
  }
  return L;
}

int FindLoop(LISTA* L, TNo* aux){
  if(L == NULL)
    return -1;
  int i, loop=0;          
  while(loop==0 && aux != NULL){
    caixinha *nova = malloc(sizeof(caixinha));
    if(nova == NULL)
      return -1;
    L->qty++;
    nova->position = L->qty;
    nova->address = aux;
    nova->next= NULL;
    if(L->inicio == NULL)       
      L->inicio = nova;          
    else
      L->final->next= nova;
    L->final=nova;
    caixinha *whileBox = L->inicio;
    for(i=1; i<L->qty; i++){
      if(nova->address==whileBox->address){
        loop=whileBox->position;
        return loop;
      }
      whileBox=whileBox->next;
    }
  aux=aux->prox;
  }
  return loop;
}

int TLinkedList_hasLoop(TLinkedList* list){                                                    
  TNo *aux = TLinkedList_getInicio(list);
  if(list == NULL || aux == NULL)
    return -1;
  int loop;
  LISTA* L = new();
  loop=FindLoop(L,aux);
  return loop;
}