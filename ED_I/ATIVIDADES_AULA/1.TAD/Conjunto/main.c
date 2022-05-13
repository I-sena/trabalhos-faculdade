#include "conjunto.h"

int main(){

    conj* c1=new(3); //conjunto com 3 numeros

    newdata(c1,1);
    print(c1);
    
    newdata(c1,2);
    print(c1);

    newdata(c1,2);
    print(c1);

    newdata(c1,3);
    print(c1);
    
    newdata(c1,4);

    deleteC(c1,2);
    print(c1);

    return 0;
}