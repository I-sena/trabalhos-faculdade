/** 1- Dado o código a seguir, comente o mesmo nos locais marcados, de forma a identificar as
**funcionalidades de cada trecho do código.
** ALUNA: Izabela Caldeira Sena
*/

#include <stdio.h>
#include <string.h>
int main() {
    /** 1- Qual a funcionalidade da linha a seguir?
     * RESPOSTA: Ela cria um ponteiro do tipo FILE que foi nomeado de "arq" e depois abre o arquivo "ex1_arq1.txt" em modo de leitura
     * que vai ser associado ao ponteiro "arq".
    */
    FILE *arq = fopen("ex1_arq1.txt", "r");
    char buffer[120];
    char *token;
    /** 2- Qual a funcionalidade da linha a seguir?
     * RESPOSTA: Ela armazenar na variavel "busca" a string que deve ser encontrada no arquivo, nesse exemplo a palavra "lorem".
    */
    char busca[] = "lorem";
    int contagem = 0;
    /** 3- Qual a funcionalidade do laço de repetição a seguir?
     * RESPOSTA: Ele vai percorrer todo o conteudo presente no arquivo, pegando com a função fgets esse conteudo e passando para a 
     * variavel buffer até que o arquivo chegue ao final.
    */
    while(1) {
        fgets(buffer, 120, arq);
        if(feof(arq)){
            break;
        }
    }
    /** 4- Qual a funcionalidade da linha a seguir?
     * RESPOSTA: A função strtok vai separar a string buffer, sempre que ela achar um espaço ou algum dos sinais de pontuação que foram 
     * passados como parametro para ela e ela vai retornar para a variavel "token" a palavra que foi "cortada" antes de achar um 
     * desses critérios. 
    */ 
    token = strtok(buffer, " .,!?");
    /** 5- Qual a funcionalidade do laço de repetição a seguir?
     * RESPOSTA: Serve para continuar separando a string que foi passada na linha acima até que ela chegue ao final,então retorna NULL,
     *  e o if dentro dele serve para ver se a palavra armazenada em "token" é igual a palavra que se esta procurando, se elas
     *  forem igual a varivel contadora vai se encrementando. 
    */
    while(token != NULL) {
        // se igual cont++
        if(strcmp(token, busca) == 0) {
            contagem++;
        }
        token = strtok(NULL, " .,!?");
    }
    /** 6- Qual a saída do código?
     * RESPOSTA: A saida vai ser a string que se estava procurando e esta armazenada na variavel busca, nesse exemplo a palavra "lorem", e a outra
     * vai ser variavel contagem que armazena a quantidade de vezez que essa palavra foi encontrada no conteudo do arquivo.
    */
    printf("ocorrencias de %s: %d\n", busca, contagem);
    fclose(arq);
 return 0;
}