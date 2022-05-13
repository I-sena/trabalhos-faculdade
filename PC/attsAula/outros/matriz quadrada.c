/*
** CODIGO DO URI DA MATRIZ QUADRADA COM NUMEROS 
*/

#include<stdio.h>
int main(){

  int n,x;

  scanf("%d",&n); //3
  while(n!=0){
    for(int linha=1; linha<=n;linha++){
      for(int coluna=1;coluna<=n; coluna++){
        x=linha; //1
        if(coluna<x){
          x=coluna;
        }
        if(n-linha+1<x){
          x=n-linha+1;    //x=3
        }
        if(n-coluna+1<x){
          x=n-coluna+1;     //x=3
        }
        printf("%d",x);
        if(coluna<n){
          printf(" ");
        }
        else{
          printf("\n");
        }
      }
    }
    printf("\n");
    scanf("%d",&n);
  }
  return 0;
}