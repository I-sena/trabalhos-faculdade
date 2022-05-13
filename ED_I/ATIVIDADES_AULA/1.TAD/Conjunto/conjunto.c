#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>

// 3. Crie um TAD para representar um tipo conjunto de números inteiros. A struct deve
// armazenar a quantidade de elementos do conjunto e os dados deverão ser armazenados em um
// vetor. O TAD deverá ter as seguintes funções:

struct Conjunto{
    int qty;
    int aux;
    int nums[];
};

// a) Criação de um conjunto vazio;
conj* new(int qty){
    conj* new= malloc(sizeof(conj));
    if(new){
        printf("conjunto criado\n");    //-------- TIRAR DPS
        new->qty=qty;
        new->aux=0;
    }
    return new;
}

// b) Inserção de um elemento a um conjunto (aqui deve-se verificar se o elemento já existe no
// conjunto);
void newdata(conj* x,int data){
    int i;
    if(x->aux!=x->qty){
        for(i=0; i<x->aux; i++){
            if(x->nums[i]==data){
                printf("numero ja existe no conjunto.\n");
                break;
            }
        }
        if(i==x->aux){
            x->nums[x->aux]=data;
            x->aux++;
        }
    }
    else
        printf("nao ha mais espaco.\n");
}

void print(conj* x){
    for(int i=0; i<x->aux; i++){
        printf("%d, ",x->nums[i]);
    }
    puts("\n");
}

// c) Remoção de um elemento do conjunto (deve ser verificado se ele existe);
void deleteC(conj* x,int data){ 
    int j,i;
    for(i=0; i<x->aux; i++){
        if(data==x->nums[i]){
            x->nums[i]=0;       
            printf("data removido.\n");
            x->aux--;
            for(j=i; j<x->aux; j++){ 
                x->nums[j]=x->nums[j+1]; 
            }
        }
    }
}

// d) Interseção (deve receber dois conjuntos e criar um outro que represente a interseção);
conj* interscConj(conj* x, conj* y){
    int Cx,Cy,newqty=0;
    for(Cx=0;Cx<x->aux;Cx++){
        for(Cy=0; Cy<y->aux; Cy++){
            if(x->nums[Cx]==y->nums[Cy]){
                newqty++;
            }
        }
    } 
    conj* newc= new(newqty);
 
    for(Cx=0;Cx<x->aux;Cx++){
        for(Cy=0; Cy<y->aux; Cy++){
            if(x->nums[Cx]==y->nums[Cy]){
                newc->nums[newc->aux]= y->nums[Cy];
                newc->aux++;
            }
        }
    }

    return newc;
}

// e) Diferença entre dois conjuntos (mesma interface da letra d);
conj* difeConj(conj* x, conj*y){
    int Cx,Cy,ax,newqty=0;
    for(Cx=0; Cx<x->aux;Cx++){
        ax=0;
        for(Cy=0; Cy<y->aux; Cy++){
            if(x->nums[Cx]== y->nums[Cy]){
                ax=1;
                break;
            }
        }
        if(ax==0){
            newqty++;
        }
    }
    conj* newco= new(newqty);

    for(Cx=0; Cx<x->aux; Cx++){
        ax=0;
        for(Cy=0; Cy<y->aux; Cy++){
            if(x->nums[Cx]==y->nums[Cy]){
                ax++;
                break;
            }
        }
        if(ax==0){
            newco->nums[newco->aux]= x->nums[Cx];
            newco->aux++;
        }
    }
    return newco;
}