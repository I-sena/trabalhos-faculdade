/*
1- Escreva um programa em C, que através do uso de funções, solicite o total gasto pelo 
cliente de uma loja, imprime as opções de pagamento, solicita a opção desejada 
e imprime o valor total das prestações (se houverem).

1) Opção: a vista com 10% de desconto
2) Opção: em duas vezes (preço da etiqueta)
3) Opção: de 3 até 10 vezes com 3% de juros ao mês (somente para compras acima de R$ 100,00).

*/

#include<stdio.h>

void pagamento(float ttl,int tipo);
int op_pag(float ttl);

int main(){
    float total;
    int tipo, op;
    printf("* TOTAL GASTO NA LOJA: ");
    scanf("%f",&total);
    op = op_pag(total);
    pagamento(total,op);

    return 0;
}

int op_pag(float ttl){
    int tipo;
    printf("---- OPCOES DE PAGAMENTO ----\n");
    printf("[1] - A vista com 10 porcento de desconto\n");
    printf("[2] - Em duas vezes (preco da etiqueta)\n");
    if(ttl > 100){
        printf("[3] - De 3 ate 10 vezes com 3 porcento de juros ao mes.\n");
    }
    printf("QUAL TIPO DE PAGAMENTO DESEJA: ");
    scanf("%d",&tipo);
    return tipo;
}

void pagamento(float ttl,int tipo){
    float novo_ttl,juros;
    int p;
    switch(tipo)
    {
        case 1:{
            printf("--- OPCAO DE PAGAMENTO [1] ---\n");
            novo_ttl = ttl - (ttl*0.1);
            printf("* O VALOR A PAGAR SERA DE %.2f REAIS.\n",novo_ttl);
            break;
        }
        case 2:{
            printf("--- OPCAO DE PAGAMENTO [2] ---\n");
            novo_ttl = ttl/2;
            printf("* O VALOR A PAGAR SERA DUAS PARCELAS DE %.2f REAIS.\n",novo_ttl);
            break;
        }
        case 3:{
            printf("--- OPCAO DE PAGAMENTO [3] ---\n");
            printf("* de quantas vezes deseja parcelar: ");
            scanf("%d",&p);
            juros = ttl*0.03*p;
            novo_ttl = ttl+juros;
            printf("* O VALOR A PAGAR SERA %d PARCELAS DE %.2f REAIS.\n",p,novo_ttl/p);
            printf("* O NOVO VALOR TOTAL EH DE %.2f REAIS.\n",novo_ttl);
            break;
        }
    }
}
