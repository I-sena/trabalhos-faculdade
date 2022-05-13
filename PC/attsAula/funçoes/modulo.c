#include<stdio.h>

void modulo(int num);
int soma(int num);

int main(){

    int num,res;
    for(int i=0; i<5; i++){
        scanf("%d",&num);
        modulo(num);
        res=soma(num);
        printf("soma=%d\n",res);
    }

    return 0;
}


void modulo(int num){
    int res;
    if(num<0){
        printf("* %d nao eh positivo\n",num);
       
    }
    else{
        printf("* numero eh positivo.\n");
    }
}

int soma(int num){
    int i,res=0;
    for(i=1;i<num; i++){
        if((num%i)==0){
            res=res+i;
        }
    }
    return res;
}