#include "LDouble.h"
#include <stdlib.h>
#include <stdio.h>

struct no{
  int info;
  struct no *prox, *ant;
};

struct no* TNo_createnfill(int info){
  struct no* novo = (struct no*) malloc(sizeof(struct no));
  if(novo){
    novo->info = info;
    novo->prox = NULL;
    novo->ant = NULL;
  }
  return novo;
}

struct double_linked{
  struct no *inicio;
  struct no *fim;
};

TDList* TDList_create(){
  TDList* nova = (TDList*) malloc(sizeof(TDList));
  if(nova){
    nova->inicio = NULL;
    nova->fim = NULL;
  }
  return nova;
}

void TDList_destroy(TDList* list){
  TNo* aux = list->fim;
  while(aux != NULL){
    if(aux->ant == NULL){
      list->fim = aux->ant; 
      list->inicio = list->fim;
    }
    else{
      aux->ant->prox = NULL;
      list->fim = aux->ant;
    }
    free(aux);
    aux = list->fim;
  }
  free(aux);
  return;
}

void TDList_print(TDList* list){
  if(list){
    struct no* aux = list->inicio;
    while(aux){
      printf("%d", aux->info);
      aux = aux->prox;
    }
    puts("");
  }
}
//Veja no LDouble.h para verificar os tipos de retorno
TDList* TDList_generate(char* charNum){
  printf("Ola, eu sou a funcao TDList_generate(). Vou imprimir o numero como char: ");
  puts(charNum);
  TDList* newList = TDList_create();
  int i = 0, num;
  while(charNum[i] != '\0' && charNum[i] != '\n'){
    num = charNum[i] - '0';
    TNo* newBox = TNo_createnfill(num);
    if(!insert_end(newList, newBox))     
      printf("Erro de insercao.\n");
    i++;
  }
  return newList;
}
//Veja no LDouble.h para verificar os tipos de retorno
TDList* TDList_sum(TDList* l1, TDList* l2){
  TDList* L3 = TDList_create();
  TNo *auxL1 = l1->fim;
  TNo *auxL2 = l2->fim;
  TNo *newbox;
  
  // ** INSERINDO EM L3 ATE UM DOS DOIS "NUMEROS" ACABAR, OU OS DOIS(SE ELES FOREM DO MESMO TAMANHO);
  while(auxL1 != NULL && auxL2 != NULL){
    int sum = auxL1->info+auxL2->info;
    newbox = TNo_createnfill(sum);
    insert_begin(L3,newbox);
    auxL1 = auxL1->ant;
    auxL2 = auxL2->ant;
  }
  // ** SE UM NUMERO FOR MAIOR QUE O OUTRO, ENTÃO "DESCE" O QUE RESTA.
  if(auxL1 == NULL && auxL2 != NULL){
    while(auxL2 != NULL){
      newbox = TNo_createnfill(auxL2->info);
      insert_begin(L3,newbox);
      auxL2 = auxL2->ant;
    }
  }
  else if(auxL2 == NULL && auxL1 != NULL){
    while(auxL1 != NULL){
      newbox = TNo_createnfill(auxL1->info);
      insert_begin(L3,newbox);
      auxL1 = auxL1->ant;
    }
  }
  //**  ARRUMANDO L3.
  TNo *auxL3 = L3->fim;
  while(auxL3 != NULL){
    if(auxL3->info > 9){ 
      int stay = (auxL3->info)%10;
      int leave = (auxL3->info)/10;
      if(auxL3->ant == NULL){
        auxL3->info = stay;
        TNo* NewFirst = TNo_createnfill(leave);
        insert_begin(L3,NewFirst);
      }
      else{
        auxL3->info = stay;
        auxL3->ant->info += leave;
      }
    }
    auxL3 = auxL3->ant;
  }
  return L3;
}

int insert_end(TDList* lista, TNo* Newbox){
  if(lista == NULL || Newbox == NULL) 
    return 0;
  if(lista->inicio == NULL){
    lista->inicio = Newbox;
    lista->fim = Newbox;
  }
  else{
    lista->fim->prox = Newbox;
    Newbox->ant = lista->fim;
    lista->fim = Newbox;
  }
  return -1;
}

int insert_begin(TDList* lista,TNo* N_box){
  if(lista == NULL || N_box == NULL) 
    return 0;
  if(lista->inicio == NULL){
    lista->inicio = N_box;
    lista->fim = N_box;
  }
  else{
    lista->inicio->ant = N_box;
    N_box->prox = lista->inicio;
    lista->inicio = N_box;
  }
  return -1;
}
