#include "../default.c"
//#include "../design/paineis.c"

char metodoPagamento[STRING_SIZE];
char inputCartao[STRING_SIZE];

void choicePagamento(int choice, float totalPagamento) {
    switch (choice)
    {
        case 1:

            clrscr();

            printf("\nPEDIDO PAGO COM ");
            c_green();
            printf("DINHEIRO\n");
            c_white();

            getch();

            strcpy(metodoPagamento, "dinheiro");
            addPagamento(metodoPagamento, totalPagamento);

            clrscr();
            break;

        case 2:

            clrscr();  

            while (1) {

                clrscr();
                printf("\nNumero do Cartao: ");
                fgets(inputCartao, STRING_SIZE, stdin);

                if (strlen(inputCartao) - 1 == 16) {
                    
                    c_green();
                    printf("\nPermitido!");
                    c_white();
                    getch();
                    clrscr();
                    break;
                    
                } else {

                    c_red();
                    printf("\nNegado, tente denovo!");
                    c_white();
                    
                }

            }

            printf("\nPEDIDO PAGO COM ");
            c_blue();
            printf("CARTAO DE CREDITO\n");
            c_white();

            getch();

            strcpy(metodoPagamento, "cartao de credito");
            addPagamento(metodoPagamento, totalPagamento);

            inputCartao[4] = '*';
            inputCartao[5] = '*';
            inputCartao[6] = '*';
            inputCartao[7] = '*';
            inputCartao[8] = '*';
            inputCartao[9] = '*';
            inputCartao[10] = '*';
            inputCartao[11] = '*';

            addCartao(inputCartao);
            clrscr();

            break;

        case 3:

            clrscr();

            printf("\nPEDIDO PAGO COM ");
            c_purple();
            printf("PIX\n");
            c_white();

            getch();

            strcpy(metodoPagamento, "pix");
            addPagamento(metodoPagamento, totalPagamento);
            clrscr();

            break;

        case 0:
            break;
    }
}