/**
 * Curso de Ciencia da Computacao - UFT
 * Estruturas de dados I - Listas simplesmente encadeadas
 * Prof. Rafael Lima
 * NAO ALTERE ESTE ARQUIVO.
 */

#include "TLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

struct list{
  struct node *inicio;    // lista, ponteiro para o inicio
};

TLinkedList* TLinkedList_create(){
  TLinkedList* nova = malloc(sizeof(TLinkedList*)); //armazenou do tamanho de um ponteiro tlinkedlist
  if(nova){
    nova->inicio = NULL;
  }
  return nova;
}
TNo* TLinkedList_getInicio(TLinkedList* list){
  if(list){
    return list->inicio;
  } return NULL;
}
TNo* TNo_create(int info){
  TNo* novo=malloc(sizeof(TNo));
  if(novo){
    novo->info = info;
    novo->prox = NULL;
  } return novo;
}

int TLinkedList_insert_end(TLinkedList* list, int info){
  TNo** where = &(list->inicio);
  while(*where!=NULL)
    where = &(*where)->prox;
  *where = TNo_create(info);
  return (*where!=NULL);
}
void TLinkedList_print(TLinkedList* list, int limit){
  TNo* aux = list->inicio;
  while(aux && limit--){
    printf("[%d]-> ", aux->info);
    aux = aux->prox;
  } puts("");
}
void TLinkedList_make_loop(TLinkedList* list, int altura){
  TNo** where = &(list->inicio);
  TNo* loop_node = NULL;
  while(*where){
    if(--altura==0)
      loop_node = *where;
    where = &(*where)->prox;
  }
  *where = loop_node;
}