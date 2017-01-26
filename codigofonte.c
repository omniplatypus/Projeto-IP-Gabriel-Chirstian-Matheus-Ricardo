#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Mesas{
	int numero;                  //numero da mesa
	char entregue[200];       // pedidos que ja¡ foram entregues
	float conta;
	int estado;            // 0 desocupada, 1 ocupada
}mesa;

void ChecarDados()
{
    FILE *arq;
	int pesquisa;
	if((arq = fopen("texto.dat","rb")) == NULL)
	{
	    printf("erro");
	    system("pause");
	}
	printf("digite qual mesa deseja checar ou zero se deseja voltar para o menu.\n");
	scanf("%i",&pesquisa);
	if(pesquisa!=1 || pesquisa!=2 ||pesquisa!=3 ||pesquisa!=4||pesquisa!=5||pesquisa!=0)
    {
        printf("mesa nao localizada.\n");
        system("pause");
        if(pesquisa==0)
        {
            MenuMesas();
        }
    }
    else
    {
        fseek(arq,sizeof(struct Mesas)*(pesquisa-1),SEEK_SET);
        if(fread(&mesa, sizeof(struct Mesas), 1, arq)==1)
        {
            printf("Mesa %i\nPratos entregues:%s\nconta:R$%f",mesa.numero, mesa.entregue, mesa.conta);
        }
        else
        {
            printf("Cadastro nao encontrado\n");
        }
    }
    fclose (arq);
}
void AdicionarPratos()
{
    FILE *arq;
    int pesquisa, pos=0, regnum=0;
    float soma;
    if(arq=fopen("texto.dat","a+b") == NULL)
    {
        printf("falha ao abrir o arquivo");
        system("pause");
    }
    printf("Digite o numero da mesa que deseja alterar");
    scanf("%i", &pesquisa);
    while(!feof(arq))
    {
        if(fread(mesa,sizeof(struct Mesas),1,arq)==1)
        {
            if(strcmp(mesa.numero,pesquisa)==0)
            {
                printf("Mesa %i \n Pratos entregues:%s\n Conta:R$%f",mesa.numero, mesa.entregue,mesa.conta);
                regnum=pos+1;
            }
        }
        pos++;
    }
    if(regnum==0)
    {
        printf("nenhuma mesa encontrada");
        system("pause");
    }
    else
    {
        printf("Digite o nome do prato entregue:\n");
        gets(mesa.entregue);
        mesa.estado=1;
        printf("Digite o valor do prato:\n");
        scanf("%f",&soma);
        mesa.conta=mesa.conta+soma;
        fseek(arq,sizeof(struct Mesas)*(regnum-1),SEEK_SET);
        fwrite(mesa,sizeof(struct Mesas),1,arq);
    }
    fclose(arq);
}
void PreencherMesas()
{
    int aux;
    char entg [10]="NADA";
    arq=fopen("texto.dat","a+b");
    for(aux=0;aux<5;aux++)
    {
            mesa.numero= aux+1;
            strcpy(mesa.entregue,entg);
            mesa.conta=0,00;
            mesa.estado=0;
            fwrite(mesa, sizeof(struct Mesas),1 , arq);
    }
    fclose(arq);
}
void ResetarMesa()     //trabalhando
{
    int reset;
    printf("Digite o numero da mesa que deseja resetar ou zero para voltar pra o menu.\n");
    scanf("%i",&reset);
    if(reset==0)
    {
        MenuMesas()
    }
    arq = fopen("texto.dat","wb");
    if (arq==null)
    {
        printf("Erro\n digite zero para voltar pra o menu");
        scanf("%i",&reset);
        if(reset==0)
            {
                MenuMesas()
            }
    }
    fseek(arq,sizeof(struct Mesas)*(reset-1),1,SEEK_SET);
    mesa.numero= aux+1;
    strcpy(mesa.entregue,entg);
    mesa.conta=0,00;
    mesa.estado=0;
    fwrite(mesa, sizeof(struct Mesas),1 , arq);
    fclose(arq);
    printf("Mesa resetada");
}

void MenuMesas()
{
	int menu,i;
	printf("Menu de mesas\n\n\n");
	printf("/n digite o numero correpondente a funcao desejada");
	scanf("%i",&menu);
	switch(menu)
	{
		case 1:
		{
			ChecarDados();
			break;
		}
		case 2:
		{
			AdicionarPratos();
			break;
		}
		case 3:
		{
			PreencherMesas();
			break;
		}
		case 4:
        {
            ResetarMesa();
            break;
        }
	}
}

main()
{
    MenuMesas();
}

