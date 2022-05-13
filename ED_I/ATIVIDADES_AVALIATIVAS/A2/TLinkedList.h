
/**
 * Curso de Ciencia da Computacao - UFT 
 * Estruturas de dados I - Listas simplesmente encadeadas
 * Prof. Rafael Lima
 * NAO ALTERE ESTE ARQUIVO.
 */
#ifndef TLINKED_LIST_H
#define TLINKED_LIST_H

typedef struct node{
  int info;
  struct node *prox;
} TNo;

typedef struct list TLinkedList;

TLinkedList* TLinkedList_create();
TNo* TLinkedList_getInicio(TLinkedList*);
int TLinkedList_insert_end(TLinkedList*, int);
void TLinkedList_make_loop(TLinkedList*, int);
void TLinkedList_print(TLinkedList*, int);
#endif