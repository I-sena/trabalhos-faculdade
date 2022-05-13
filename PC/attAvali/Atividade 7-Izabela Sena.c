/**
    1- Escreva um programa em C que, dada uma string informada pelo usuário, inverta a ordem das palavras na frase. 
    Exemplo:
    *Entrada: Uma frase qualquer
    *Saída: qualquer frase Uma
    ALUNA: Izabela Caldeira Sena.
*/

#include<stdio.h>
#include<string.h>

int main(){
    char frase[50], novafrase[50],buffer[50];
    char* palavra;
    printf("INFORME A FRASE DESEJADA:\n");
    gets(frase);
    strcpy(novafrase,"");
    palavra = strtok(frase," ");
    while(palavra){
        strcpy(buffer,novafrase);
        strcpy(novafrase,palavra);
        strcat(novafrase," ");
        strcat(novafrase,buffer);
        palavra = strtok(NULL," ");
    }
    printf("-A FRASE INVERTIDA FICOU:\n%s",novafrase);
    return 0;
}

