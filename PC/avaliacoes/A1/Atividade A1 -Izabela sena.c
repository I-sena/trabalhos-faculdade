#include <stdio.h>

char tab[3][3];
char jogador(int);
int movimento(int, int,char);
int situacao(int, int,char);
void print_tab(char[3][3]);

int main(){
    char player;
    int jogadas = 0, venceu;
    int lin, col;
    while(venceu != 0 && jogadas < 9){
        player = jogador(jogadas);
        printf("-> jogado %c, linha e coluna:",player);
        scanf("%d %d",&lin, &col);
        if(!movimento(lin-1,col-1,player)){
            printf("ERRO: Casa indisponivel, escolha outra.\n");
            scanf("%d %d",&lin, &col);
        }
        venceu = situacao(lin-1,col-1,player);
        print_tab(tab);
        jogadas++;
        if(jogadas == 9 && venceu != 0)
            printf("-> DEU VELHO, EMPATE.\n");
    }
    return 0;
}

char jogador(int jogadas){
    char player;
    if((jogadas%2) == 0)
        player = 'X';
    else    
        player = 'O';
    return player;
}

int movimento(int lin, int col, char player){
    if(tab[lin][col] == 'X' || tab[lin][col] == 'O')
        return 0;
    tab[lin][col] = player;
    return 1;
}

int situacao(int l, int c, char player){
    int contc = 0, contl = 0, contDP = 0, contDS = 0, aux = 2;;
    for(int j = 0; j < 3; j++){
 //  ** GANHANDO PELA LINHA
        if(tab[l][j] == player){
            contl++;
            if(contl == 3){
                printf("|JOGADOR %C GANHOU PELA LINHA.|\n", player);
                return 0;
            }
        }
//  ** GANHANDO PELA COLUNA
        if(tab[j][c] == player){
            contc++;
            if(contc == 3){
                printf("|JOGADOR %c GANHOU PELA COLUNA.|\n",player);
                return 0;
            }
        }
//  ** GANHANDO PELA DIAGONAL PRINCIPAL
        for(int i = 0; i < 3;i++){
            if(j == i){
                if(tab[j][i] == player){
                    contDP++;
                    if(contDP == 3){
                        printf("|JOGADOR %c GANHOU PELA DIAGONAL PRINCIPAL.|\n",player);
                        return 0;
                    }
                }
            }
        }
//  ** GANHANDO PELA DIAGONAL SECUNDARIA
        if(tab[j][aux] == player){
            contDS++;
            aux--;
            if(contDS == 3){
                printf("|JOGADOR %c GANHOU PELA DIAGONAL SECUNDARIA.|\n",player);
                return 0;
            }
        }
    }
//  ** NINGUEM GANHOU AINDA
    printf("| MOVIMENTO EFETUADO COM SUCESSO |\n ");
    return -1;
}

void print_tab(char tab[3][3]){
    int L,C;
    for(L = 0; L < 3; L++){
        for(C = 0; C < 3; C++){
            if(C == 2)
                printf("%c \n",tab[L][C]);
            else
                printf("%c| ",tab[L][C]);
        }
    }
}