#include <stdio.h>
#include "complex.h"

int main(){
    complex* n1= newComplex(10,12);
    complex* n2= newComplex(1.3, 1.9);
    printComplex(n1);
    printComplex(n2);
    complex* n3= somaComplex(n1,n2);
    complex* n4= subComplex(n1,n2);
    printComplex(n3);
    printComplex(n4);
    deleteComplex(n1);
    deleteComplex(n2);
    deleteComplex(n3);
    deleteComplex(n4);

    return 0;
}