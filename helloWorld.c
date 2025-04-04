#include <stdio.h>
#include <string.h>

#define clrscr() printf("\e[1;1H\e[2J")

struct Produtos
{
    int codProd;
    char nomeProd[100];
    float custoProd;
};

struct Pagamentos
{
    int codpgto;
    char formapgto[100];
    float valorpgto;
};

void addProduct(FILE *file)
{

    struct Produtos produtos;

    int lastID = 0;

    rewind(file);

    while (fread(&produtos, sizeof(struct Produtos), 1, file))
    {
        lastID = produtos.codProd;
    };

    produtos.codProd = lastID + 1;

    getchar();
    printf("Nome do Produto: ");
    fgets(produtos.nomeProd, 100, stdin);
    produtos.nomeProd[strcspn(produtos.nomeProd, "\n")] = '\0';

    printf("Preco do Produto: ");
    scanf("%f", &produtos.custoProd);

    fwrite(&produtos, sizeof(struct Produtos), 1, file);

    clrscr();
};

void addPagamento(char metodoPagamento[100], float totalPagamento)
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

void listProducts(FILE *file)
{
    struct Produtos produtos;

    rewind(file);
    printf("\n");

    while (fread(&produtos, sizeof(struct Produtos), 1, file))
    {
        printf("%d. %s - R$: %.2f\n", produtos.codProd, produtos.nomeProd, produtos.custoProd);
    };
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

};

void painelCardapio(FILE *file)
{
    struct Produtos produtos;
    clrscr();

    /* VARIAVEIS */
    char input;
    int choice;
    char sacola[100] = "Nenhum item adicionado";
    float totalPagamento = 0.00;
    int unidades;

    while (1)
    {
        printf("\n=========\n");
        printf("Cardapio:\n");
        printf("=========\n");

        printf("\nMinha Sacola: %s. Total a Pagar: R$ %.2f\n", sacola, totalPagamento);

        listProducts(file);

        printf("\np. Ir para o Pagamento");
        printf("\n0. Cancelar\n");

        printf("\nEscolha uma opcao: ");
        scanf(" %c", &input); // MANTER O ESPACO
        choice = input - '0';

        rewind(file);

        if (input == 'p')
        {
            clrscr();

            while (1)
            {
                printf("\nMetodos de Pagamento!\n");
                printf("1. Dinheiro\n");
                printf("2. Cartao de Credito\n");
                printf("3. PIX\n");

                printf("\n0. Sair\n");
                printf("\nEscolha uma opcao: ");
                scanf("%d", &choice);

                char metodoPagamento[100] = "dinheiro";

                switch (choice)
                {
                case 1:
                    clrscr();

                    printf("\nPEDIDO PAGO COM ");
                    printf("\033[0;32m");
                    printf("DINHEIRO\n");
                    printf("\033[0m");

                    getchar();
                    getchar();

                    strcpy(metodoPagamento, "dinheiro");
                    //fclose(file);
                    addPagamento(metodoPagamento, totalPagamento);
                    clrscr();
                    return;
                case 2:
                    clrscr();

                    printf("\nPEDIDO PAGO COM ");
                    printf("\033[0;34m");
                    printf("CARTAO DE CREDITO\n");
                    printf("\033[0m");

                    getchar();
                    getchar();

                    strcpy(metodoPagamento, "cartao de credito");
                    addPagamento(metodoPagamento, totalPagamento);
                    clrscr();
                    return;
                case 3:
                    clrscr();

                    printf("\nPEDIDO PAGO COM ");
                    printf("\033[0;35m");
                    printf("PIX\n");
                    printf("\033[0m");

                    getchar();
                    getchar();

                    strcpy(metodoPagamento, "pix");
                    addPagamento(metodoPagamento, totalPagamento);
                    clrscr();
                    return;
                case 0:
                    clrscr();
                    return;
                default:
                    printf("Escolha Invalida. Tente denovo!\n");
                };
            };

            goto AVOID;
        }

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
                goto AVOID;
            };
        };

        if (choice == 0)
        {
            clrscr();
            return;
        }
        else
        {
            printf("Escolha Invalida. Tente denovo!\n");
            getchar();
            getchar();
        };
    AVOID:
        clrscr();
    };
};

void painelAdministracao(FILE *file)
{
    clrscr();
    int choice;
    while (1)
    {
        printf("\n========================\n");
        printf("Painel de Administracao:\n");
        printf("========================\n");
        printf("1. Adicionar Produto\n");
        printf("2. Consultar Pagamentos\n");
        printf("\n0. Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clrscr();
            addProduct(file);
            break;
        case 2:
            clrscr();
            listPagamentos();
            getchar();
            getchar();
            clrscr();
            break;
        case 0:
            clrscr();
            return;
        default:
            printf("Escolha Invalida. Tente denovo!\n");
        };
    };
};

int main()
{
    FILE *file;

    file = fopen("produtos.dat", "ab+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int choice;
    while (1)
    {
        printf("\n================\n");
        printf("Mickey & Donald:\n");
        printf("================\n");
        printf("1. Cardapio\n");
        printf("2. Painel de Administracao\n");
        printf("\n0. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            painelCardapio(file);
            break;
        case 2:
            painelAdministracao(file);
            break;
        case 0:
            fclose(file);
            return 0;
        default:
            printf("Escolha Invalida. Tente denovo!\n");
        };
    };

    return 0;
};