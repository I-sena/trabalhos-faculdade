#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDesc.h" //inclui os prot�tipos
//Defini��o do tipo lista

// ESSA STRUCT AQUI É A CAIXINHA
struct elemento{    
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem; // CAIXINHA DO TIPO Elem

//Defini��o do N� Descritor
// ISSO AQUI É A 'LISTA', A STRUCT VIRA UM TIPO NO .H CHAMADA LISTA.
struct descritor{   
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};


Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;       // criando uma caixinha auxiliar
        while((li->inicio) != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    return li->qtd;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL) //nao foi criada
        return 1;
    if(li->inicio == NULL) // foi criada mas nao tem nunhuma caixinha
        return 1;
    return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;       //cria uma caixinha nova
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)      // nao deu certo a criação
        return 0;
    no->dados = al;             // a nova caixa recebe os dados
    no->prox = li->inicio;         // o prox da nova caixinha aponta para onde é o inicio da lista.
    if(li->inicio == NULL)
        li->final = no;             // -> se a caixinha for a primeira a ser colocada o final tbm aponta pra ela.
    li->inicio = no;                // o inicio da lista passa a ser a nova caixinha
    li->qtd++;                          // conta a quantidade
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no;                   // nova caixinha
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(li->inicio == NULL)          //lista vazia: insere inicio
        li->inicio = no;
    else
        li->final->prox = no;  // a caixinha que era a ultima passa a apontar para a nova

    li->final = no;             // o final da lista passa a apontar para a nova caixinha
    li->qtd++;                      // conta a quantidade
    return 1;
}


int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->inicio == NULL)          //lista vazia
        return 0;

    Elem *no = li->inicio;   // no recebe o endereço da primeira caixinha
    li->inicio = no->prox;          // a primeira caixinha passa a ser asegunda
    free(no);                       // a antiga primeira é eliminada
    if(li->inicio == NULL)          // todas as caixinhas foram excluidas, a lista esta vazia
        li->final = NULL;           // final recebe NULL pq nao tem mais caixinhas
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->inicio == NULL)              //lista vazia
        return 0;

    Elem *ant, *no = li->inicio;   // no ta apontando pra primeira caixinha da lista
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == li->inicio){                   //a lista so tem uma caixinha
        li->inicio = NULL;                  // lista vazia
        li->final = NULL;                   // lista vazia
    }else{
        ant->prox = no->prox;               // a penultima caixinha recebe NULL
        li->final = ant;                    // e o final passa a apontar pra penultima caixinha
    }
    free(no);                               // elimina a que era a ultima
    li->qtd--;
    return 1;
}
//=================================================

// consultar posição
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || li->inicio == NULL || pos <= 0) //lista nao criada/ sem caixinhas/ posição negativa
        return 0;
    Elem *no = li->inicio;          //no recebe o endereço do primeiro elemento da lista
    int i = 1;
    while(no != NULL && i < pos){       //enquando nao chegar no final da lista e achar a posição desejada
        no = no->prox;
        i++;
    }
    if(no == NULL)          // nao achou a posição
        return 0;
    else{
        *al = no->dados;          // passa os dados para o usuario
        return 1;
    }
}

// consultar por matricula
int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL || li->inicio == NULL) //-> lista nao criada ou lista vazia
        return 0;
    Elem *no = li->inicio;          // no recebe o endereço da primeira caixinha da lista 
    while(no != NULL && no->dados.matricula != mat)     // nao chegar no final da lista e os dados de matricula forem diferentes
        no = no->prox;
    if(no->dados.matricula != mat)      // dados de matricula nao encontrado
        return 0;
    else{
        *al = no->dados;            // passa os dados de quem tinha a matricula pra a main
        return 1;
    }
}


void imprime_lista(Lista* li){
    if(li == NULL || li->inicio == NULL)
        return;
    Elem* no = li->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}
