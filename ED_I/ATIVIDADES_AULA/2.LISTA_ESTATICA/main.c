#include "conc.h"
#include <stdio.h>

int main(){
    lista* l1=newList();
    lista* l2=newList();

    struct aluno al={"isa",15,12.1,10};
    insert_end(l1,al);

    struct aluno al1={"isabela",13,12.9,10.5};
    insert_end(l1,al1);


    struct aluno al2={"oi",14,25.4,10.6};
    insert_end(l2,al2);

    struct aluno al3={"haley",1,2.4,1.6};
    insert_end(l2,al3);

    lista* l3=concateLista(l1,l2);
    
    printLista(l3);
    deleteList(l1);
    deleteList(l2);
    deleteList(l3);

    return 0;
}