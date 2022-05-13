#include "conjunto.h"
int main(){
    conj* a1= new(7);
    conj* a2= new(7);

    for(int i=1; i<=6;i++){
        newdata(a1,i);
    }
    newdata(a1,8);
    int x=1;
    for(int j=0; j<7; j++){
        newdata(a2,x);
        x=x+2;
    }

    print(a1);
    print(a2);
    print(a1);

    conj* a3=new(3);
    newdata(a3,3);
    print(a3);

    return 0;
}