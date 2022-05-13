#ifndef CONC_H
#define CONC_H
#define MAX 50
struct aluno{
    char nome[20];
    int code;
    float n1,n2;
};

typedef struct Lista lista;

lista* newList();                                                       //criar nova lista

void printLista(lista*);                                                //imprimir lista
int insert_end(lista*, struct aluno);                                    //inserir no final
int insert_begin(lista*, struct aluno);                                 // inserir no começo
int insert_middle(lista*,int, struct aluno);                           //inserir aonde quiser
int insert_by_codeOrder(lista*, struct aluno);                        //inserir pelo codigo do aluno,menor para maior                                                                      
void deleteList(lista*);                                            //deletar lista
void emptyList(lista*);                                             //lista vazia
void fullList(lista*);                                             // lista cheia
void sizeList(lista*);                                              //tamanho atual da lista
void printByCode(lista*,int);                                   //imprime o codigo desejado
void removeData_end(lista*);
void removeData_begin(lista*);
void removeData_byCode(lista*,int);
lista* concateLista(lista*,lista*);

#endif