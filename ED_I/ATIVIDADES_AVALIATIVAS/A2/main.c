/**
 * Curso de Ciencia da Computacao - UFT
 * Estruturas de dados I - Listas simplesmente encadeadas
 * Prof. Rafael Lima
 * NAO ALTERE ESTE ARQUIVO.
 */
#include<stdio.h>
#include "TLinkedList.h"
#include "TLinkedListUtils.h"

int main(){
  int numInputs, qty, j, loop, info;
  scanf("%d", &numInputs);
  TLinkedList *lista;
  for(int i=0; i<numInputs; i++){
    lista = TLinkedList_create();
    scanf("%d %d", &qty, &loop);
    j = qty;
    while(j){
      scanf("%d", &info);
      TLinkedList_insert_end(lista, info);
      j--;
    }
    //Descomente o codigo abaixo apenas durante o desenvolvimento
    TLinkedList_print(lista, 2*qty);
   if(loop>0){
      TLinkedList_make_loop(lista, loop);
      //Descomente o codigo abaixo apenas durante o desenvolvimento
      TLinkedList_print(lista, 2*qty);
    //}
    printf("%d\n", TLinkedList_hasLoop(lista));
  }
  }
  return 0;
}