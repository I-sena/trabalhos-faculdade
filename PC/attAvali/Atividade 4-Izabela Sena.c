/**
** ALUNA: Izabela Caldeira Sena
** Escreva uma função em C que, dada uma matriz, retorne o valor do seu determinante
*/
#include<stdio.h>
int ordem;
int determinanteM(int[][ordem]);

int main(){
    int deter;
    printf("QUAL A ORDEM DA MATRIZ: ");
    scanf("%d",&ordem);
    int matriz[ordem][ordem];
    for(int linha = 0; linha < ordem; linha++){
        for(int coluna = 0; coluna < ordem; coluna++){
            printf("ELEMENTO->: ");
            scanf("%d",&matriz[linha][coluna]);
        }
    }    
    printf("-> O DETERMINATE DA MATRIZ EH %d",determinanteM(matriz));
    return 0;
}

int determinanteM(int matriz [ordem][ordem]){
    if(ordem == 1)
        return matriz[0][0];
    else if(ordem == 2)
        return( (matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]) );
    else {
        
        int NewM[ordem][ordem+2];
        int linha, coluna, extraCol;
    
        //PREENCHENDO A NOVA MATRIZ
        for(linha = 0; linha < ordem; linha++){
            for(coluna = 0; coluna < ordem; coluna++){
                NewM[linha][coluna] = matriz[linha][coluna];
            }
            int nj = 0;
            for(extraCol = ordem; extraCol <= ordem+1; extraCol++){
                NewM[linha][extraCol] = matriz[linha][nj];
                nj++;
            }
        }

        //CALCULANDO DIAGONA PRINCIPAL
        int aux = 0, somaMP[3], soma = 1, aux2 = ordem;
        while(aux2){
            for(linha = 0; linha < ordem; linha++){
                soma = soma*(NewM[linha][linha+aux]);
            }
            somaMP[aux] = soma;
            soma = 1;
            aux++;
            aux2--;
        }
        // CALCULANDO DIAGONA SECUNDARIA
        soma = 1, aux2 = ordem;
        int k = 2, indiceV = 0;
        int somaMS[3];
        while(aux2){
            aux = k;
            for(linha = 0;linha < ordem; linha++){
                soma = soma*(NewM[linha][aux]);
                aux--;
            }
            aux2--;
            somaMS[indiceV] = soma;
            soma = 1;
            indiceV++;
            k++;
        }
        //  SOMANDO AS DUAS DIAGONAIS
        int deterP = 0, deterS = 0;
        for(int i = 0; i < 3; i++){
            deterP = deterP + somaMP[i];
            deterS = deterS + somaMS[i];
        }
        return deterP - deterS;
    }
}
