#include "../default.c"
#include "fila.c"

int choiceAdministrador(int choice) {

    switch (choice)
    
    {
        case 1:

            clrscr();
            addProduct();

            break;

        case 2:

            clrscr();
            listPagamentos();
            getch();
            clrscr();

            break;

        case 3:

            clrscr();
            listCartoes();
            getch();
            clrscr();

            break;

        case 4:

            clrscr();
            imprimirFila(&fila);
            clrscr();

            break;

        case 5:

            clrscr();
            desenfileirar(&fila);
            salvarFilaEmArquivo(&fila);
            clrscr();

            break;

        case 0:

            clrscr();
            return 1;

    }
    return 0;
}