#include "fracao.h"

int main(){
    
    fracao* n1=newNum(10,3);
    fracao* n2=newNum(4,3);
    print(n1);
    print(n2);

    fracao* n3=somaNum(n1,n2);
    fracao* n4= multNum(n1,n2);
    print(n3);
    print(n4);

    sameNUm(n1,n2);
    sameNUm(n3,n4);
    sameNUm(n1,n1);
    
    deleteN(n1);
    deleteN(n2);
    deleteN(n3);
    deleteN(n4);

    return 0;
}