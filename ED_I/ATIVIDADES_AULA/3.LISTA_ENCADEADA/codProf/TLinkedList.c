#include "TLinkedList.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct no{         // isso é a caixinha tipo struct no que passou a ser um tipo TNO
  int info;                 // vao ser criado varios desses; 
  struct no *prox;
} TNo;

struct list{            //isso é uma struct que aponta para a primeira caixinha da lista.
  TNo *inicio;          //isso virou um tipo chamado tlinkedlist no .h
};                      // se cria um desse uma vez, ele meio que é a lista.

/*
Aux funcs
*/

// CRIANDO A CAIXINHA TNo ;
TNo* TNo_createNFill(int info){
  TNo* novo = malloc(sizeof(TNo));
  if(novo){
    novo->info = info;
    novo->prox = NULL;
  } return novo;
}

//  CRIANDO A LISTA
TLinkedList* TLinkedList_create(){                      
  TLinkedList* nova = malloc(sizeof(TLinkedList));
  if(nova){
    nova->inicio = NULL;
  } return nova;
}

//inserindo a caixinha no final;
int TLinkedList_insert_end(TLinkedList* list, int info){
  TNo* novo = TNo_createNFill(info);
  if(novo == NULL || list == NULL) return 0;
  
  if(list->inicio == NULL)       //-> pq ela nao tem nenhuma caixinha ainda
    list->inicio = novo;
  else{                         //-> ja tem caixinhas e tem que achar a ultima, que é a que aponta para NULL
    TNo* aux = list->inicio;        // aux recebe o enderenco de list.inicio, entao eles apontam para o mesmo lugar!!!!
    while(aux->prox != NULL)
      aux = aux->prox;
    aux->prox = novo;           // entao quando mexe com aux mexe na lista tbm,
  }                               // aux.prox aponta para o enderenco de novo e 'novo' esta apontando pra NULL. 
  return 1;
}

// inserindo a caixinha no começo.
int TLinkedList_insert_begin(TLinkedList* list, int info){
  TNo* novo = TNo_createNFill(info);
  if(novo == NULL || list == NULL) return 0;   // nao deu certo a criaçao
  novo->prox = list->inicio; // novo.prox recebe o endereco de onde é o inicio da lista
  list->inicio = novo;      // e o inicio da lista vai para o endereço de novo.
  return 1;
}

// imprimir a lista
void TLinkedList_print(TLinkedList* list){
  TNo* aux = list->inicio;        // PERCORRER A LISTA, SEMPRE USAR UM AUXILIAR. 
  while(aux != NULL){
    printf("[%d]-> ", aux->info);
    aux = aux->prox;
  }
  putchar('\n');
}



TLinkedList* TLinkedList_concatenate(TLinkedList* L1, TLinkedList* L2){
  if (L1 == NULL || L2 == NULL) return NULL;
  TLinkedList* L3 = TLinkedList_create();
  for (TNo* aux = L1->inicio; aux != NULL; aux = aux->prox)
    TLinkedList_insert_end(L3, aux->info);
  for (TNo* aux = L2->inicio; aux != NULL; aux = aux->prox)
    TLinkedList_insert_end(L3, aux->info);
  return L3;
}

TLinkedList* TLinkedList_so_pares(TLinkedList* L1){
  if (L1 == NULL)  return NULL;
  TLinkedList* L2 = TLinkedList_create();
  for (TNo* aux = L1->inicio; aux != NULL; aux = aux->prox)
    if (aux->info % 2 == 0)
      TLinkedList_insert_end(L2, aux->info);
  return L2;
}