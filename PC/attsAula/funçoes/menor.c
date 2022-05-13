#include<stdio.h>

int menor(int a, int b);

int main(){
    int a,b,res;

    scanf("%d",&a);
    scanf("%d",&b);
    res=menor(a,b);
    printf("%d",res);
    
    return 0;
}

int menor(int a, int b){
    if(a>b)
        return b;
    else
        return a;
}
