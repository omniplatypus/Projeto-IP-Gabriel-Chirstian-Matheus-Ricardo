#include <stdio.h>				//comentar o código faz bem :D
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
	char nome[64];
	char ingrediente[10][20];		//supus que 10 ingredientes por produto seriam representados assim.
	float preco;
	int estoque;
	int validade[3];
	int ativo;
}Produto;

void cadastroProduto(Produto produtos[255])
{
    int x=0;                        //indice das estruturas de repetição
    int op=0;                       //variável pra opção no menu
    do
    {
        while(strlen(produtos[x].nome)>0)           //esse while checa se já tem produto cadastrado naquele índice. Se tem, ele pula pro próximo.
        {
            x++;
        }
        printf("Digite o nome do produto:\n");
        gets(produtos[x].nome);
        printf("Digite o preco do produto:\n");
        scanf("%f",&produtos[x].preco);
        getchar();
        printf("Quantas unidades no estoque?");
        scanf("%i", &produtos[x].estoque);
        getchar();
        produtos[x].ativo = 1;
        printf("Deseja cadastrar outro produto? (1-SIM 0-NAO)\n");
        scanf("%i",&op);
        getchar();

        system("cls");
    }while(op!=0);
}

void vercadastroProduto (Produto produtos[255])
{
    int x=0;                //variável para armazenar e selecionar um código de produto.
    printf("Selecione um codigo de produto:\n");
    scanf("%i",&x);
    getchar();
    printf("Produto: %s\nPreco: R$%.2f.\nExistem %i unidades no estoque.\nObrigado!\n",produtos[x].nome, produtos[x].preco, produtos[x].estoque);
    getchar();
    system("cls");
}

void alteraProduto (Produto produtos[255])
{
    int x=0;                //variável para armazenar e selecionar um código de produto.
    printf("Selecione um codigo de produto:\n");
    scanf("%i",&x);
    getchar();

    int op=0;                       //variável pra opção no menu
    do
    {
        printf("Digite o novo nome do produto:\n");
        gets(produtos[x].nome);
        printf("Digite o novo preco do produto:\n");
        scanf("%f",&produtos[x].preco);
        getchar();
        printf("Quantas unidades no estoque?");
        scanf("%i", &produtos[x].estoque);
        getchar();
        printf("Deseja alterar outro produto? (1-SIM 0-NAO)\n");
        scanf("%i",&op);
        getchar();

        system("cls");
    }while(op!=0);
}


void relatorioProduto(Produto produtos[255])
{
    int i=0;

    for(i=0; i<=255; i++)
    {
        if(produtos[i].ativo == 1)
            printf("%i - %s\n", i, produtos[i].nome);
    }
}


void menuProdutos(Produto produtos[255])
{
    setlocale(LC_ALL, "");
    int menu=0;
    do
    {
        printf("\t\tMENU PRODUTOS\nDigite o número correspondente à opção desejada:\n1 - Função cadastro de produtos\n2 - Função alteração de cadastro\n3 - Função de visualização dos cadastros de produtos\n4 - Relatório de produtos (código - Nome do produto)\n0 - Sair do menu produtos\n");
        scanf("%i", &menu);
        getchar();
        switch (menu)
        {
            case 1:
                system("cls");
                cadastroProduto(produtos);
                break;
            case 2:
                system("cls");
                alteraProduto(produtos);
                break;
            case 3:
                system("cls");
                vercadastroProduto(produtos);
                break;
            case 4:
                system("cls");
                relatorioProduto(produtos);
                break;
            case 0:
                break;
            default:
                printf("Código inválido\n");
                break;
        }
    }
    while(menu!=0);
    system("cls");
}

int main()
{
  setlocale(LC_ALL, "");
    int menu=0;
    Produto produtos[255];
    do
    {
        printf("\t\tMENU PRINCIPAL\nDigite o número correspondente à opção desejada:\n1 - Menu produtos\n2 - Menu funcionários\n0 - Sair do programa\n");
        scanf("%i", &menu);
        getchar();
        switch (menu)
        {
            case 1:
                system("cls");
                menuProdutos(produtos);
                break;
            case 2:
                system("cls");
   //             menuFuncionarios();
                break;
            case 0:
                break;
            default:
                printf("Código inválido\n");
                break;
        }
    }while(menu!=0);
	return 0;
}
