#include "./bibliotecas/bibliotecas.c"
#include "./bibliotecas/functions/pagamentos.c"
#include "./bibliotecas/functions/administrador.c"

char getChoice(void painel()) {

        char input;
        char choice;

        while (1) {

                system("cls");
                painel();
                printf("Digite sua Escolha: %c", choice);
                fflush(stdin);
                input = getch();

                if (input == 13) {
                        break;
                }

                choice = input;

        }

        return choice;
        
}


int main() {

        CARDAPIO:

        system("title MiCkey e DONALD");
        hc = GetStdHandle(STD_OUTPUT_HANDLE);

        char choice = getChoice(cardapio);

        if (choice > '0' && choice <= '9') {
                atualizarSacola((choice - '0'));
                goto CARDAPIO;
        }

        switch (choice) {
                
                case '0':
                        break;
                case 'p':

                        choice = getChoice(pagamento);
                        choicePagamento((choice - '0'), totalPagamento);

                        if (totalUnidades > 10) {
                                clrscr();
                                int senha = returnID();
                                printf("Seu pedido possui mais de 10 unidades, por favor aguarde na fila. Sua senha sera chamada: %i", senha);
                                getch();
                                enfileirar(&fila, senha);
                                salvarFilaEmArquivo(&fila);
                        }

                        strcpy(sacola, "Nenhum item adicionado");
                        totalPagamento = 0.00;
                        totalUnidades = 0;

                        goto CARDAPIO;
                        break;

                case '$':

                        ADM:

                        choice = getChoice(administrador);
                        int goBack = choiceAdministrador((choice - '0'));

                        if (goBack == 1) {
                                goto CARDAPIO;
                        }
                        
                        goto ADM;
                        break;

        }

        return 0;

}