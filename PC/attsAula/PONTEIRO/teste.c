void func(int *px, int *py){

    printf("------- começo-------\n");
    printf("px= %d,py= %d\n",px,py);
    printf("*px= %d,*py= %d\n",*px,*py);


    px = py; // AQUI O PONTEIRO PX RECEBE O ENDERECO DE ONDE O PONTEIRO PY ESTA APONTANDO, OU SEJA A VARIAVEL Y;
                // OS DOIS, PX E PY, PASSAM A APONTAR PARA A VARIAVEL Y E SEU ENDEREÇO;

    printf("---- depois do px=py ------\n");
    printf("px= %d,py= %d\n",px,py);
    printf("*px= %d,*py= %d\n",*px,*py);


    *py = (*py) * (*px);    // O VALOR ARMAZENADO NO ENDERECO DA VARIALVEL Y MUDA PQ *PY FOI TRABALHADO, PORTANTO O VALOR DE PX 
                            //MUDAR TBM PQ ELES APONTAM PARA O MESMO LUGAR E O VALOR ARMAZENADO LÁ VOI MODIFICADO.

    printf("----- depois da multi de py -------\n");
    printf("py = %d\n",*py);
    printf("px = %d\n",*py);

    *px = *px + 2;      //NOVAMENTE O VALOR DE QUE FICA NO ENDERECO DA VARIAVEL Y FOI MODIFICADO SO QUE DESSA VEZ PELO PONTEIRO PX
                        // ENTAO O VALOR DE *PY TBM MUDOU .

    printf("---- depois da multi de px -----\n");
    printf("px= %d\n\n",*px);

    //NO FINAL SO FOI TRABALHADO O VALOR DA VARIAVEL Y, E O VALOR DE X CONTINUA O MESMO QUE FOI COLOCADO EM NA MAIN.

}

void main(void)

{

    int x, y;

    scanf("%d",&x); 

    scanf("%d",&y); 

    printf("x=%d, y=%d\n",x,y);

    func(&x,&y);

    printf("--- dentro da main ----\n");
    printf("x = %d, y = %d", x, y);         //X CONTINUA O MESMO E Y VAI VALER *PX+2;

}