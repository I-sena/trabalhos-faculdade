// ** ALUNA: IZABELA CALDEIRA SENA

#include<stdio.h>
int main(){

    int n = 5;
    float v[n],  soma = 0;
    int i;

 // * PREENCHENDO O VETOR
    for( i = 0; i < n; i++){ 
        scanf("%f",&v[i]);
    }

 // * ARRUMANDO DO MENOR PARA O MAIOR
    float aux;
    for(i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    for(int d = 0; d < n; d++){
        printf("%.1f, ",v[d]);
        if (d == 10-1 || d == 20-1 || d == 30-1 || d == 40-1 || d == 50-1 || d == 60-1 || d == 70-1 || d == 80-1 || d == 90-1 || d == 99 || d == 109 || d == 119) puts("");
    }
    return 0;
}

