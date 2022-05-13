#include<stdio.h>

int fatorial(int num){
    if(num <= 1) return 1;
    else return num*fatorial(num-1);
}
int fibonacci(num){
    if(num <= 0){
        return 0;
    }
    else{
        return fibonacci(num-1) + 1;
    }
}

/** FORMULA: Fn = Fn - 1 + Fn - 2*/

int multiplicacao_rec(int num1, int num2){
    if(num2 <= 1) 
        return num1;
    else
        return num1+multiplicacao_rec(num1,num2-1);
}
int par_recursiva_crescente(int num){
    if(num <= 0){
        printf("%d ",num);
        return 0;
    }else{
        if(!par_recursiva_crescente(num-1) == 0){
            printf("%d ",num);
            return 0;
        }
        else
            return 1;
    }
}
int par_recursiva_decrescente(int num){
    if(num <= 0){
        printf("%d ",num);
        return 0;
    }else{
        if(num % 2 == 0)
            printf("%d ",num);
        return par_recursiva_decrescente(num-1);
    }
}

int main(){
    //int num = 4;
    par_recursiva_decrescente(15);
    return 0;
}