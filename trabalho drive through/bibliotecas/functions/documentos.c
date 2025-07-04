#include "../default.c"

char sacola[STRING_SIZE] = "Nenhum item adicionado";
float totalPagamento = 0.00;
int totalUnidades = 0;

struct Produtos
{
    int codProd;
    char nomeProd[STRING_SIZE];
    float custoProd;
};

struct Pagamentos
{
    int codpgto;
    char formapgto[100];
    float valorpgto;
};

struct Cartoes
{
    int codpgto;
    char numcartao[100];
};

void listProducts()
{

    FILE *file;

    file = fopen("produtos.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    struct Produtos produtos;

    rewind(file);
    printf("\n");

    while (fread(&produtos, sizeof(struct Produtos), 1, file))
    {
        printf("                              %d.     %s     -     R$: %.2f          \n", produtos.codProd, produtos.nomeProd, produtos.custoProd);
    };

    fclose(file);

};

void atualizarSacola(int choice) {

    int unidades;

    FILE *file;

    file = fopen("produtos.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    struct Produtos produtos;

    rewind(file);

    while (fread(&produtos, sizeof(struct Produtos), 1, file))
    {
        if (choice == produtos.codProd)
        {
            printf("\nProduto escolhido: %s\n", produtos.nomeProd);

            printf("\nNumero de Unidades: ");
            scanf("%d", &unidades);

            if (strcmp(sacola, "Nenhum item adicionado") == 0)
            {
                strcpy(sacola, "");
                sprintf(sacola, "%s (%d)", produtos.nomeProd, unidades);
            }
            else
            {
                sprintf(sacola, "%s, %s (%d)", sacola, produtos.nomeProd, unidades);
            };

            totalPagamento = totalPagamento + (unidades * produtos.custoProd);
            totalUnidades = totalUnidades + unidades;

        };
    };

    fclose(file);
}


void addPagamento(char metodoPagamento[STRING_SIZE], float totalPagamento)
{

    struct Pagamentos pagamentos;

    FILE *file;

    file = fopen("pagamentos.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int lastCod = 0;

    rewind(file);

    while (fread(&pagamentos, sizeof(struct Pagamentos), 1, file))
    {
        lastCod = pagamentos.codpgto;
    };

    pagamentos.codpgto = lastCod + 1;
    strcpy(pagamentos.formapgto, metodoPagamento);
    pagamentos.valorpgto = totalPagamento;

    fwrite(&pagamentos, sizeof(struct Pagamentos), 1, file);
    fflush(file);

    clrscr();
};

void addCartao(char numcartao[STRING_SIZE])
{

    /* INICIO PEGAR CODIGO */
    
    struct Pagamentos pagamentos;
    FILE *file;
    
    file = fopen("pagamentos.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    int lastCod = 0;

    rewind(file);

    while (fread(&pagamentos, sizeof(struct Pagamentos), 1, file))
    {
        lastCod = pagamentos.codpgto;
    };
    
    fclose(file);
    
    /* FIM PEGAR CODIGO */
    
    struct Cartoes cartoes;
    
    file = fopen("cartoes.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    rewind(file);

    cartoes.codpgto = lastCod;
    strcpy(cartoes.numcartao, numcartao);

    fwrite(&cartoes, sizeof(struct Cartoes), 1, file);
    fflush(file);

    fclose(file);

    clrscr();
};

void addProduct()
{

    /* INICIO PEGAR CODIGO */
    
    struct Produtos produtos;
    FILE *file;
    
    file = fopen("produtos.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    /* FIM PEGAR CODIGO */

    int lastID = 0;

    rewind(file);

    while (fread(&produtos, sizeof(struct Produtos), 1, file))
    {
        lastID = produtos.codProd;
    };

    produtos.codProd = lastID + 1;

    printf("Nome do Produto: ");
    fgets(produtos.nomeProd, 100, stdin);
    produtos.nomeProd[strcspn(produtos.nomeProd, "\n")] = '\0';

    printf("Preco do Produto: ");
    scanf("%f", &produtos.custoProd);

    fwrite(&produtos, sizeof(struct Produtos), 1, file);

    fclose(file);

    clrscr();
};

void listPagamentos()
{
    struct Pagamentos pagamentos;

    FILE *file;

    file = fopen("pagamentos.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    rewind(file);
    printf("\n");

    while (fread(&pagamentos, sizeof(struct Pagamentos), 1, file))
    {

        printf("%d. %s - R$: %.2f\n", pagamentos.codpgto, pagamentos.formapgto, pagamentos.valorpgto);

    };

    fclose(file);

};

void listCartoes()
{
    struct Cartoes cartoes;

    FILE *file;

    file = fopen("cartoes.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    rewind(file);
    printf("\n");

    while (fread(&cartoes, sizeof(struct Cartoes), 1, file))
    {

        printf("%d. %s\n", cartoes.codpgto, cartoes.numcartao);

    };

    fclose(file);

};

int returnID() {

    /* INICIO PEGAR CODIGO */
    
    struct Pagamentos pagamentos;
    FILE *file;
    
    file = fopen("pagamentos.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    
    int lastCod = 0;

    rewind(file);

    while (fread(&pagamentos, sizeof(struct Pagamentos), 1, file))
    {
        lastCod = pagamentos.codpgto;
    };
    
    fclose(file);
    
    /* FIM PEGAR CODIGO */

    return lastCod;
}
