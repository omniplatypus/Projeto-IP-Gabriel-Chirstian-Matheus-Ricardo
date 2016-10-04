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
}Produto;

Produto produtos[255];

void cadastro()
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
        printf("Deseja cadastrar outro produto? (1-SIM 0-NAO)\n");
        scanf("%i",&op);
        getchar();
        system("cls");
    }while(op!=0);
}

void vercadastro ()
{
    int x=0;                //variável para armazenar e selecionar um código de produto.
    printf("Selecione um codigo de produto:\n");
    scanf("%i",&x);
    getchar();
    printf("Produto: %s\nPreco: R$%.2f.\nExistem %i unidades no estoque.\nObrigado!\n",produtos[x].nome, produtos[x].preco, produtos[x].estoque);
    getchar();
    system("cls");
}

int main()
{
    setlocale(LC_ALL, "");
    int menu=0;
    do
    {
        printf("\t\tMENU PRINCIPAL\nDigite o número correspondente à opção desejada:\n1 - Função cadastro\n2 - Função de visualização dos cadastros\n0 - Sair do programa\n");
        scanf("%i", &menu);
        getchar();
        switch (menu)
        {
            case 1:
                system("cls");
                cadastro();
                break;
            case 2:
                system("cls");
                vercadastro();
                break;
            case 0:
                break;
            default:
                printf("Código inválido\n");
                break;
        }
    }
    while(menu!=0);
	return 0;
}
