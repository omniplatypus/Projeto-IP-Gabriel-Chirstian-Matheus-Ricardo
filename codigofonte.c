#include <stdio.h>				//comentar o código faz bem :D
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char nome[30];
	char ingrediente[10][20];		//supus que 10 ingredientes por produto seriam representados assim.
	float preco;
	int estoque;
	int validade[3];
}Produto;

int main()
{
	Produto pizza;
	gets(pizza.ingrediente[0]);
	printf("%s",pizza.ingrediente[0]);
	return 0;
}
