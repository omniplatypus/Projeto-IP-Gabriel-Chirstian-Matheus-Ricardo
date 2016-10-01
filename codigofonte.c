#include <stdio.h>				//comentar o código faz bem :D
#include <stdlib.h>
#include <string.h>
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
        printf("Deseja cadastrar outro produto? (1-SIM 0-NAO)\n");
        scanf("%i",&op);
        getchar();
    }while(op!=0);
}

int main()
{
    int x=0;
    cadastro();
    printf("Selecione um codigo de produto:\n");
    scanf("%i",&x);
    getchar();
    printf("Produto: %s\nPreco: R$%.2f\nObrigado!",produtos[x].nome, produtos[x].preco);

	return 0;
}
