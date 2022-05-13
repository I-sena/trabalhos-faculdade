#include<stdio.h>
#include<math.h>

int potencia(int base, int exp);

int main(){

    int base, exp, res;
    scanf("%d",&base);
    scanf("%d",&exp);
    res=potencia(base,exp);
    printf("%d",res);

    return 0;
}

int potencia(int base, int exp){
    int res;
    res=pow(base,exp);
    
    return res;
}