#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct mesas MESAS;
	struct mesas{
	int numero;                  //numero da mesa
	char entregue[200];       // pedidos que ja｡ foram entregues
	float conta;
	int estado;            // 0 desocupada, 1 ocupada
};

void ChecarDados()
{
    system("cls");
    FILE *arq;
    MESAS atl;
	int pesquisa;
	arq = fopen("texto.dat","rb");
	if(arq==NULL)
	{
	    printf("erro");
	    system("pause");
	    exit(1);
	}
	do{
	printf(" Digite o numero da mesa deseja checar ou 0 se deseja voltar para o menu.\n");
	scanf("%i",&pesquisa);
	system("cls");
	if(pesquisa!=1 && pesquisa!=2 &&pesquisa!=3 &&pesquisa!=4&&pesquisa!=5&&pesquisa!=0)
    {
        printf("mesa nao localizada.\n");
    }
    if(pesquisa==0)
    {
        break;
    }
    }while(pesquisa!=1 && pesquisa!=2 &&pesquisa!=3 &&pesquisa!=4&&pesquisa!=5&&pesquisa!=0);
    fseek(arq,sizeof(MESAS)*(pesquisa-1),SEEK_SET);
    if(fread(&atl, sizeof(MESAS),1, arq)==1)
        {
            printf("Mesa %i\nPratos entregues:%s\nconta:R$%.2f\n\n",atl.numero, atl.entregue, atl.conta);
        }
    else
        {
            printf("Cadastro nao encontrado\n");
        }

    fclose(arq);
}
void AdicionarPratos()
{
    system("cls");
    FILE *arq;
    MESAS atl;
    int pesquisa, pos=0, regnum=0;
    float soma;
    arq=fopen("texto.dat","a+b");
    if(arq == NULL)
    {
        printf("falha ao abrir o arquivo");
        system("pause");
        exit(1);
    }
    do{
    printf("Digite o numero da mesa que deseja alterar ou 0 para voltar pra o menu\n");
    scanf("%i", &pesquisa);
    if(pesquisa==0)
    {
        break;
    }
    if(pesquisa!=1 && pesquisa!=2 &&pesquisa!=3 &&pesquisa!=4&&pesquisa!=5&&pesquisa!=0)
    {
        printf("mesa nao localizada.\n");
    }
    }while(pesquisa!=1 && pesquisa!=2 &&pesquisa!=3 &&pesquisa!=4&&pesquisa!=5&&pesquisa!=0);
    while(!feof(arq))
    {
        if(fread(&atl,sizeof(MESAS),1,arq)==1)
        {
            if(atl.numero==pesquisa)
            {
                printf("Mesa %i \n Pratos entregues:%s\n Conta:R$%f",atl.numero, atl.entregue,atl.conta);
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
        gets(atl.entregue);
        atl.estado=1;
        printf("Digite o valor do prato:\n");
        scanf("%f",&soma);
        atl.conta=atl.conta+soma;
        fseek(arq,sizeof(MESAS)*(regnum-1),SEEK_SET);
        fwrite(&atl,sizeof(MESAS),1,arq);
    }
    fclose(arq);
}
void PreencherMesas()
{
    FILE *arq;
    MESAS atl;
    int aux;
    char entg [10]="NADA";
    arq=fopen("texto.dat","a+b");
    for(aux=0;aux<5;aux++)
    {
            atl.numero= aux+1;
            strcpy(atl.entregue,entg);
            atl.conta=0;
            atl.estado=0;
            fwrite(&atl, sizeof(MESAS),1 , arq);
    }
    fclose(arq);
}
void ResetarMesa()
{
    FILE *arq;
    MESAS atl;
    int reset;
    arq = fopen("texto.dat","wb");
    if (arq==NULL)
    {
            {
                printf("Voltando ao menu...\n");
                getchar();
                exit(1);
            }
    }

    do{
    printf("Digite o numero da mesa que deseja resetar ou zero para voltar pra o menu.\n");
    scanf("%i", &reset);
    system("cls");
    if (reset==0);
    {
    printf("Voltando ao menu...\n");
    getchar();
    break;
    }

    fseek(arq,sizeof(MESAS)*(reset-1),SEEK_SET);
    strcpy(atl.entregue,"NADA");
    atl.conta=0;
    atl.estado=0;
    fwrite(&atl, sizeof(MESAS),1 , arq);
    fclose(arq);
    printf("Mesa resetada");
    }while(reset!=0);
}
void AlterarConta()
{
    printf("Digite o numero correpondente a funcao desejada\n 1-Alterar o valor da conta");
    system("cls");
    FILE *arq;
    MESAS atl;
    int pesquisa, pos=0, regnum=0;
    float soma;
    arq=fopen("texto.dat","w+b");
    if(arq == NULL)
    {
        printf("falha ao abrir o arquivo");
        system("pause");
        exit(1);
    }
    do{
    printf("Digite o numero da mesa que deseja alterar ou 0 para voltar pra o menu\n");
    scanf("%i", &pesquisa);
    if(pesquisa==0)
    {
        break;
    }
    if(pesquisa!=1 && pesquisa!=2 &&pesquisa!=3 &&pesquisa!=4&&pesquisa!=5&&pesquisa!=0)
    {
        printf("mesa nao localizada.\n");
    }
    }while(pesquisa!=1 && pesquisa!=2 &&pesquisa!=3 &&pesquisa!=4&&pesquisa!=5&&pesquisa!=0);
    while(!feof(arq))
    {
        if(fread(&atl,sizeof(MESAS),1,arq)==1)
        {
            if(atl.numero==pesquisa)
            {
                printf("Mesa %i \n Conta:R$%f",atl.numero, atl.conta);
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
        atl.estado=1;                                                          // como fzr para digitar apenas numeros?
        printf("digite a operacao que deseja fazer:\n");
        scanf("%f",&soma);
        atl.conta=atl.conta+soma;
        fseek(arq,sizeof(MESAS)*(regnum-1),SEEK_SET);
        fwrite(&atl,sizeof(MESAS),1,arq);
    }
    fclose(arq);
}

int main()
{
	int menu;
	do{
	printf("Menu de mesas\n\n\n");
	printf("Digite o numero correpondente a funcao desejada\n 1-Checar Dados\n 2-Adicionar Pratos\n 3-Preencher Mesas\n 4-Resetar Mesa\n 5-Alterar conta\n");
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
        case 5:
        {
              AlterarConta();
        }
        case 0:
        {
            printf("ate mais...!");
            getchar();
        }
        default:
        {
            printf("\nessa opcao nao existe\n");
            system("cls");
        }
	}
	}while(menu!=0);
	exit(1);
}
