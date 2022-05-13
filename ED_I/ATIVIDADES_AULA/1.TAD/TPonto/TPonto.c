#include "TPonto.h"
#include <stdlib.h>
#include <stdio.h>

struct ponto{
  float x, y;
};


Ponto* Ponto_create(float x, float y){
  Ponto* novo = malloc(sizeof(Ponto));
  if(novo){
    (*novo).x = x;
    novo->y = y;
  }
  return novo;
}
//Remove
void Ponto_delete(Ponto* ponto){
  free(ponto);
}

//Imprime um dado ponto
void Ponto_print(const Ponto* p){
  if(p)
    printf("(%.1f, %.1f)\n", p->x, p->y);
}