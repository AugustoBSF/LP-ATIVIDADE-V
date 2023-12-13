#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<locale.h>

struct Produto
{
    int estoque;
};
void limpatela()
{
    system("cls||clear");
}

void definirMetas()
{
    int i;
    char nomeFuncionarios[3][200];
    int numeroDeVendas[3];
    for (i = 0; i < 3; i++)
    {
        fflush(stdin);
        printf("Escreva seu nome: ");
        gets(nomeFuncionarios[i]);
        fflush(stdin);
        printf("Escreva seu número de vendas: ");
        scanf("%d", &numeroDeVendas[i]);
        fflush(stdin);
    }

    int metaDaEmpresa = 200;

  
    for (i = 0; i < 3; i++)
    {
        printf("Nome %s\n", nomeFuncionarios[i]);
        printf("Numero de vendas %d\n", numeroDeVendas[i]);
        if (metaDaEmpresa < numeroDeVendas[i])
        {
            printf("Bateu a meta!!!");
        }
        else
        {
            printf("Não bateu a meta!!!");
        }
    }
}

void reporProduto(struct Produto *produto)
{
    int reposicao;
    printf("Quantas camisas deseja repor? ");
    scanf("%d", &reposicao);
    printf("Produto comprado.\n");
    produto->estoque = produto->estoque + reposicao;
}

void venderProdutos(struct Produto *produto)
{
    int venda;
    int opcao;
    printf("---------------Produtos---------------\n");
    printf("Opção---------------Produto --------------- Preço\n");
    printf("1---------------Camisa Polo --------------- R$ 70,00\n");

    printf("Escolha a opção correspondente ao prduto: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        printf("Digite quantidade de camisas que deseja comprar: ");
        scanf("%d", &venda);
        produto->estoque = produto->estoque - venda;
        break;
    default:
        break;
    }
    printf("Produto comprado.\n");
}

void verificarEstoque(struct Produto produto)
{
    printf("Estoque está com %d\n", produto.estoque);
    printf("Estoque de vendas verificado.\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Produto produto;
    produto.estoque = 3000;

    int escolha;
    do
    {
        printf("\n1. Definir Metas de Vendas\n2. Comprar Produto\n3. Vender Produtos\n4. Verificar Estoque\n0. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            definirMetas();
            break;
        case 2:
            reporProduto(&produto);
            break;
        case 3:
            venderProdutos(&produto);
            break;
        case 4:
            verificarEstoque(produto);
            break;
        case 0:
            printf("Saindo do programa. Obrigado!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
