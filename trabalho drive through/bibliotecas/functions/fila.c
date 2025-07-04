#include "../default.c"

#define TAMANHO_FILA 6 // BUG - COLOCAR SEMPRE UM A MAIS
#define ARQUIVO "fila.dat"

typedef struct {
    int itens[TAMANHO_FILA];
    int frente;
    int tras;
} Fila;

Fila fila;

void inicializarFila(Fila* fila) {
    fila->frente = 0;
    fila->tras = 0;
}

int filaVazia(Fila* fila) {
    return fila->frente == fila->tras;
}

int filaCheia(Fila* fila) {
    return (fila->tras + 1) % TAMANHO_FILA == fila->frente;
}

void enfileirar(Fila* fila, int item) {
    if (!filaCheia(fila)) {
        fila->itens[fila->tras] = item;
        fila->tras = (fila->tras + 1) % TAMANHO_FILA;
    } else {
        printf("\nFila cheia! Nao e posssvel adicionar mais itens.\n");
        getch();
    }
}

void desenfileirar(Fila* fila) {
    if (!filaVazia(fila)) {
        fila->frente = (fila->frente + 1) % TAMANHO_FILA;
    } else {
        printf("\nFila vazia! Nao e possivel remover itens.\n");
        getch();
    }
    
}

void salvarFilaEmArquivo(Fila* fila) {
    FILE* file = fopen(ARQUIVO, "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(fila, sizeof(Fila), 1, file);
    fclose(file);
}

void carregarFilaDeArquivo(Fila* fila) {
    FILE* file = fopen(ARQUIVO, "rb");
    if (file == NULL) {
        printf("\nErro ao abrir o arquivo. A fila será inicializada.\n");
        inicializarFila(fila);
        return;
    }
    fread(fila, sizeof(Fila), 1, file);
    fclose(file);
}

void imprimirFila(Fila* fila) {
    printf("\n\nFila:\n\n");
    for (int i = fila->frente; i != fila->tras; i = (i + 1) % TAMANHO_FILA) {
        printf("%d \n", fila->itens[i]);
    }
    printf("\n");
    getch();
}
