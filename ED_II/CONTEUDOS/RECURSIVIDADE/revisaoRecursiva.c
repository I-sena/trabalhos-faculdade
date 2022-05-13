/* 1. Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório
dos números de 1 a N.
    2. Faça uma função recursiva que receba um número inteiro positivo N e imprima todos os
números naturais de 0 até N em ordem decrescente.
    3. Faça uma função recursiva que receba um número inteiro positivo N e imprima todos os
números naturais de 0 até N em ordem crescente.
     4. Escreva uma função recursiva que calcule a soma dos primeiros n cubos:
S(n)=1^3+2^3+...+n
     5. Crie uma função recursiva que receba dois inteiros positivos k e n e calcule k^n
     6. Crie um programa que contenha uma função recursiva para encontrar o menor elemento em
um vetor.

*/

#include<stdio.h>
#include <math.h>
#include <stdio.h>

int soma(int n){
    if (n <= 1) return 1;
    else
        return n + soma(n-1);                    
}
void print_n_decre(int n){
    if (n <= 1) return printf("%d.",n);
    else{
        printf("%d ",n);
        return print_n_decre(n-1);
    }
}
void print_crescente(int n){
    if(n <= 1)  return printf("%d ",n);
    else{
        print_crescente(n-1);
        return printf("%d ",n);
    }
}
int soma_ao_cubo(int n){
    const exp = 3;
    int Vsoma = pow(n,exp);
    if (n <= 1) return Vsoma;
    else
        return Vsoma += soma_ao_cubo(n-1);
}
int k_pow_n(int k, int n){
    if (n <= 1) return k;
    else{
        return k*k_pow_n(k,n-1);
    }
}
int menor_elem(int* v, int size){
    int atual_menor = v[size-1];
    if(size <= 1) return atual_menor;
    else{
        int talvez_menor = menor_elem(v,size-1);
        if(atual_menor <= talvez_menor)
            return atual_menor;
        else 
            return talvez_menor;
    }
}

int brinks(int n){
    const exp = 3;
    int Vsoma = k_pow_n(n,exp);
    if (n <= 1) return Vsoma;
    else
        return Vsoma += soma_ao_cubo(n-1);    
}

int main(){
    printf("%d",brinks(5));
    return 0;
}