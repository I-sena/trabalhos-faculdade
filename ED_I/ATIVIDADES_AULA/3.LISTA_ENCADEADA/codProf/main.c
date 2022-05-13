  
#include "TLinkedList.h"
#include<stdio.h>

int main(){
  //Sem o no descritor
  TLinkedList* list = TLinkedList_create();
  TLinkedList* list2 = TLinkedList_create();
  int V[] = {1, 5, 7, 2, 6};
  for(int i=0; i < 5; i++){
    if(!TLinkedList_insert_begin((i<3)? list:list2, V[i]))
      printf("Erro ao inserir %i \n", V[i]);
  }
  TLinkedList_print(list);
  TLinkedList_print(list2);
  TLinkedList* list_conc = TLinkedList_concatenate(list, list2);
  TLinkedList_print(list_conc);

  TLinkedList* list_pares = TLinkedList_so_pares(list_conc);
  TLinkedList_print(list_pares);
  return 0;
}