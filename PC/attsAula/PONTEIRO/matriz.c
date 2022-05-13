/*
** 6- Escreva uma função que receba de parâmetros uma matriz e suas dimensões
** e retorne 0 caso a matriz não seja simétrica e 1 caso seja simétrica. 
** Em uma matriz simétrica, qualquer elemento A[i][j] possui o mesmo valor de A[j][i]. 
*/

#include<stdio.h>
#include<stdlib.h>
int csize;

int func_matriz(int matriz[][csize], int linha);

int main(){
    int Lsize, res;
    scanf("%d",&Lsize);
    scanf("%d",&csize);

    int matriz[Lsize][csize];
    
    for(int linha=0; linha<Lsize; linha++){
        for(int coluna=0; coluna<csize; coluna++){
            scanf("%d",&matriz[linha][coluna]);
        }
    }

    res= func_matriz(matriz,Lsize);
    printf("resultado= %d\n",res);

    return 0;
}

int func_matriz(int matriz[][csize], int linha){
    int l,c;

   /* COMO ERA::
        int res=0;
        int aux=csize*linha;

        for( l=0; l<linha; l++){
            for(c=0; c<csize; c++){
                if(matriz[l][c]== matriz[c][l]){
                    res++;
                }
            }
        }

        if(res == aux)
            return 1;
        else
            return 0;
    */
   // COMO REFIZ:

    for( l=0; l<linha; l++){
        for(c=l+1; c<csize; c++){
            if(matriz[l][c]!= matriz[c][l]){
                return 0;
            }
        }
    }
    return 1;
}

