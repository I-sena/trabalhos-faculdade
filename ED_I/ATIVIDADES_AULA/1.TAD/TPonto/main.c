#include "TPonto.h"

int main(){
  Ponto* p1 = Ponto_create(10, 6);
  Ponto* p2 = Ponto_create(9, -3);
  Ponto* p3 = Ponto_create(16,1.3);
  Ponto_print(p1);
  Ponto_print(p2);
  Ponto_print(p3);
  return 0;
}