/**     ATIVIDADE AVALIATIVA A3 - ARQUIVOS
 * ALUNA: Izabela Caldeira Sena
 * PROFESSORA: Anna Paula
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char palavra[500], palavra2[500], fraseArq[500], novafrase[500];
    char* token;

    printf("DIGITE A PRIMEIRA PALAVRA:\n");
    gets(palavra);
    printf("DIGITE A SEGUNDA PALAVRA:\n");
    gets(palavra2);
    FILE* orig = fopen("theArq.txt","r");
    int size = strlen(palavra);

    while(1){
        fgets(fraseArq, 500, orig);
        if(feof(orig)) break;   
    }

    token = strtok(fraseArq," ,");
    strcpy(novafrase,"");

    while(token){
        if(!strncmp(token, palavra, size))
            strcat(novafrase, palavra2);
        else
            strcat(novafrase, token);
        strcat(novafrase," ");
        token = strtok(NULL," ,");
    }
    
    fclose(orig);
    FILE* novo = fopen("theArq.txt","w");
    fputs(novafrase, novo);
    fclose(novo);
    return 0;
}