#include <stdio.h>

#define MAX_PROD 20

typedef struct
{
    int id_produto;
    char desc_produto[50];
    int qtd_estoque;
    float val_unit;
} tProduto;

void printProduto(tProduto p)
{

}


int main()
{
    tProduto vProduto[MAX_PROD];

    int option = 0;
    int iProd = 0;

    while(option != 9)
    {
        printf("=== Menu de opcoes ===\n"
               "[1] Incluir produto   \n"
               "[2] Mostrar produtos  \n"
               "[3] Pesquisar produtos\n"
               "[9] Sair              \n"
               "======================\n");
        printf("Opcao: ");
        scanf("%d", &option);
        system("cls");

        switch (option)
        {
        case 1:
            system("cls");
            fflush(stdin);
            printf("ID do produto: ");
            scanf("%d", &vProduto[iProd].id_produto);

            while(vProduto[iProd].id_produto != 0 && iProd < MAX_PROD)
            {
                fflush(stdin);
                printf("Descricao do produto..: ");
                gets(vProduto[iProd].desc_produto);

                fflush(stdin);
                printf("Quantidade em estoque.: ");
                scanf("%d", &vProduto[iProd].qtd_estoque);

                fflush(stdin);
                printf("Valor unitario........: ");
                scanf("%f", &vProduto[iProd].val_unit);

                printf("\n");
                iProd++;

                fflush(stdin);
                printf("ID do produto: ");
                scanf("%d", &vProduto[iProd].id_produto);
            }
            system("cls");
            break;
        case 2:
            printf("id produto              qtd val_unit val_total\n");
            float total = 0;
            for(int i = 0; i < iProd; i++)
            {
                tProduto p = vProduto[i];
                float totalProd = p.qtd_estoque * p.val_unit;
                total += totalProd;
                printf("%2d %-20s %3d %8.2f %9.2f\n", p.id_produto, p.desc_produto, p.qtd_estoque, p.val_unit, totalProd);
            }
            printf("----------------------------------------------\n");
            printf("TOTAL %-40.2f\n\n", total);
            break;
        case 3:
            fflush(stdin);
            char pesquisa[50];
            printf("Pesquisar: ");
            gets(pesquisa);

            printf("Resultado da pesquisa:\n");
            printf("id produto              qtd val_unit val_total\n");

            for(int i = 0; i < iProd; i++)
            {
                char* ret = strstr(vProduto[i].desc_produto,pesquisa);
                if (ret != 0)
                {
                    tProduto p = vProduto[i];
                    float totalProd = p.qtd_estoque * p.val_unit;
                    printf("%2d %-20s %3d %8.2f %9.2f\n", p.id_produto, p.desc_produto, p.qtd_estoque, p.val_unit, totalProd);
                }
            }
            printf("\n");
            break;
        case 9:
            printf("Fim do programa");
            break;
        default:
            printf("Opcao invalida");
        }
    }

    return 1;
}


