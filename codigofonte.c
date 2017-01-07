#include <stdio.h>				//comentar o código faz bem :D
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int numero;                  //numero da mesa
	char entregue[15][30];       // pedidos que já foram entregues
	int conta;
	int ocupada;            // 0 desocupada, 1 ocupada
}Mesas;
int SelecionarMesa()
{
	int mesaselec;
	Mesas mesa[10];
	printf("digite a mesa que deseja selecionar:\n");
	scanf("%i",&mesaselec);
	return mesaselec;
}
void ChecarDados(int i);
{
	int aux;                                  //variavel pro for
	printf("Mesa:%i",i);
	printf("\nConta: %i"mesa[i].conta);
	for(aux=0;aux<15;aux++)
	{
		printf("Pratos entregues:\n");           // eu n sei como printar uma matriz de char   (?)
	}
	
}
void AdicionarPratos(int i)
{
	int j;
	do
	{
		printf("digite quais pratos foram entregues a mesa:");
		gets(mesa[i].entregue[j][0]);                                  // n sei se essa parte ta certa  (?)
		j++;
	}
	while(menu!=0)	
}
void PreencherMesas()   //trabalhando
{
	
}

void ResetarMesa()     //trabalhando
{
		
}

void AlterarDados() // trabalhando
{
	
}

void MenuMesas()
{
	int menu,i;
	printf("Menu de mesas\n\n\n");
	i = SelecionarMesa();         // i é a variável que identifica a mesa 
	printf("Mesa: %i",i);
	printf("\n digite o numero correpondente a funcao desejada");
	scanf("%i",&menu);
	switch(menu)
	{
		case 1:
		{
			ChecarDados(i);
			break;
		}
		case 2:
		{
			AdicionarPratos(i);
			break;
		}	
		case 3:
		{
			AlterarDados(i);
			break;
		}	
	}
}

main()
{
	
}
