#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>


typedef struct
{

    char nome[200];
    int dia, mes, ano;
    char predileto[30];
    int clientevip;
    int assiduo; // condição para saber se é um cliente assíduo

}Cliente;

typedef struct
{
    char rua[30];
    char bairro[30];
    char cidade[30];
    int numero;


}Endereco;


void cadastroCliente(Cliente cliente[255],Endereco endereco[255])// funçao de cadastro de clientes
{
	int i=0, vip, opmenu, z=3;

    do
    {
        printf("\t\t\t***********************************\n");
        printf("\t\t\t\t Cadastrar clientes ");
        printf("\n\t\t\t***********************************\n");

        while(strlen(cliente[i].nome)>0)
        {
            i++;
        }
		cliente[i].assiduo = 1;
        printf("Digite o nome do cliente:\n");
        gets(cliente[i].nome);

        do
        {// laço para caso seja uma data inválida
            printf("\nDigite a data de nascimento do cliente (dd/mm/aa):\n");
            scanf("%i/%i/%i", &cliente[i].dia, &cliente[i].mes, &cliente[i].ano);
            getchar();
            setbuf(stdin,NULL);



            if(cliente[i].dia>31|| cliente[i].mes>12 || cliente[i].ano>2018 ||cliente[i].dia<=0||cliente[i].mes<=0||cliente[i].ano<=0)
            {
                printf("\nData de nascimento inválida, por favor digite novamente.\n");
            }
            else
            {
                break;
            }
        }while(z==3);

        printf("Qual o endereco do cliente?\n");
        printf("Rua?\n");
        gets(endereco[i].rua);

		printf("Bairro?\n");
        gets(endereco[i].bairro);

		printf("Cidade?\n");
        gets(endereco[i].cidade);

		printf("Numero?\n");
        scanf("%d", &endereco[i].numero);
        setbuf(stdin, NULL);

		printf("Digite qual o prato predileto do cliente:\n");
        gets(cliente[i].predileto);

		printf("%s é cliente VIP?(1-sim/ 0-nao)\n", cliente[i].nome);
        scanf("%d", &vip);
        if(vip==1)
        {
            cliente[i].clientevip = 1;
        }
        else
        {
            cliente[i].clientevip = 0;
        }
        printf("Deseja cadastrar um novo cliente?(1-sim/ 0-nao)\n");
        scanf("%d", &opmenu);
        setbuf(stdin,NULL);
        system("cls");
    }while(opmenu!=0);// lembrar de colocar condição pelo menu.

}

void AlterarCadastro(Cliente cliente[255],Endereco endereco[255])// função para alteração de um cadastro, usando ponteir.
{
	int endcliente, op, z=3;
	char novonome[255];
	char novopredileto[55];
	int novodia, novomes, novoano, novovip, novonumero;
	char novorua[50];
	char novobairro[50];
	char novocidade[50];

	do
    	{
        printf("Digite o  código do cliente:\n");
        scanf("%d", &endcliente);
        getchar();
        	if(strlen(cliente[endcliente].nome)<=0)
        	{
            		printf("Desculpe mas esse codigo nao existe.\n");
            		system("pause");
            		system("cls");
            		break;
        	}

        Cliente *ponteiro;
        ponteiro=&cliente[endcliente];
        Endereco *ponteiro2;
        ponteiro2=&endereco[endcliente];

        printf("\nDigite o novo nome:\n");
        gets(novonome);
        getchar();
        strcpy(ponteiro->nome, novonome);

		do
		{
            		printf("Digite a nova data:\n");
            		scanf("%d/%d/%d", &novodia, &novomes, &novoano);
            		getchar();
            		ponteiro->dia= novodia;
            		ponteiro->mes= novomes;
            		ponteiro->ano= novoano;

		    	if(ponteiro->dia>31|| ponteiro->mes>12 || ponteiro->ano>2018||ponteiro->dia<=0||ponteiro->mes<=0||ponteiro->ano<=0)
		    	{
				printf("Data de nascimento inválida, por favor digite novamente.\n");
		   	}
		   	else
		    	{
				break;
		    	}
		}while(z==3);

        printf("Qual o endereco do cliente?\n");
        printf("Rua?\n");
        gets(novorua);
        strcpy(ponteiro2->rua, novorua);

	printf("Bairro?\n");
        gets(novobairro);
        strcpy(ponteiro2->bairro, novobairro);

	printf("Cidade?\n");
        gets(novocidade);
        strcpy(ponteiro2->cidade, novocidade);
	printf("Numero?\n");
        scanf("%d", &novonumero);
        setbuf(stdin, NULL);
        ponteiro2->numero=novonumero;

        printf("\nDigite o novo prato predileto:\n");
        gets(novopredileto);
        strcpy(ponteiro->predileto, novopredileto);

        printf("\n%s é cliente VIP (1-sim/ 0-nao)?\n", ponteiro->nome);
        scanf("%d", &novovip);
        ponteiro->clientevip = novovip;
        system("cls");
        printf("\tDados Alterados\n\n\n");
        printf("Nome: %s\nData de nascimento: %d/%d/%d\nEndereco: rua %s, bairro %s, %s, n°%d\nPrato predileto: %s\nCliente VIP: %d", ponteiro->nome, ponteiro->dia, ponteiro->mes, ponteiro->ano, ponteiro2->rua, ponteiro2->bairro, ponteiro2->cidade, ponteiro2->numero, ponteiro->predileto, ponteiro->clientevip);
        printf("\n\nDeseja alterar um novo cadastro?(1-sim/ 0-nao)\n");
        scanf("%d", &op);
        setbuf(stdin,NULL);
        system("cls");
	}while(op!=0);
}

void relatorioClientes(Cliente cliente[255],Endereco endereco[255])// função para imprimir os clientes cadastrados e seus códigos.
{
	int i=0;
	for(i=0; i<256; i++)
    {
        if(cliente[i].assiduo==1)
        {
            printf("%i - %s\n", i, cliente[i].nome);
        }
    }
	system("pause");
	system("cls");
}

void verClientes(Cliente cliente[255],Endereco endereco[255])// função para ver as  informações de um cliente
{
    int codigocliente, op;
    do
    {
    printf("Digite  o código do cliente\n");
    scanf("%d", &codigocliente);
        if(strlen(cliente[codigocliente].nome)<=0)
        {
            printf("Desculpe mas esse codigo nao existe.\n");
            system("pause");
            system("cls");
            break;
        }
        Cliente *ponteiro;
        ponteiro=&cliente[codigocliente];
        Endereco *ponteiro2;
        ponteiro2=&endereco[codigocliente];
        printf("Nome: %s\nData de nascimento: %d/%d/%d\nEndereco: rua %s, bairro %s, %s, n°%d\nPrato predileto: %s\nCliente VIP: %d", ponteiro->nome, ponteiro->dia, ponteiro->mes, ponteiro->ano, ponteiro2->rua, ponteiro2->bairro, ponteiro2->cidade, ponteiro2->numero, ponteiro->predileto, ponteiro->clientevip);
        printf("\n\nDeseja visualizar mais algum cadastro? (1-Sim/0-Não)\n");
        scanf("%d", &op);
        system("cls");
    }while(op!=0);
}

            // menu de opções de clientes

void menuClientes(Cliente cliente[255],Endereco endereco[255])
{
    int opmenu;
    do
    {

        printf("\t\t\t***********************************\n");
        printf("\t\t\t\t Menu de Clientes ");
        printf("\n\t\t\t***********************************\n");
        printf("\n\n");
        printf("1 - Cadastrar novo cliente\n");
        printf("2 - Alterar cadastro do cliente\n");
        printf("3 - Relatório de Clientes\n");
        printf("4 - Visualizar Cadastro de cliente\n");
        printf("0 - Para sair dessa opcao\n");
        scanf("%d", &opmenu);
        setbuf(stdin,NULL);

        switch(opmenu)
        {
            case 0:
                system("cls");
                break;

            case 1:
                system("cls");
                cadastroCliente(cliente,endereco);
                break;
            case 2:
                system("cls");
                AlterarCadastro(cliente,endereco);
                break;
            case 3:
                system("cls");
                relatorioClientes(cliente,endereco);
                break;
            case 4:
                system("cls");
                verClientes(cliente,endereco);
                break;
            default:
                printf("\nOpcao Inválida");
                system("pause");
                system("cls");
    }

    }while(opmenu!=0);
}


int main()
{
	Cliente cliente[255];
	Endereco endereco[255];
    setlocale(LC_ALL, "");
    int menu=0;
    do
    {
        printf("\t\tMENU PRINCIPAL\nDigite o número correspondente à opção desejada:\n1 - Menu produtos\n2 - Menu funcionários\n3 - Menu Clientes\n0 - Sair do programa\n");
        scanf("%i", &menu);
        getchar();
        switch (menu)
        {
            case 1:
                system("cls");
//                menuProdutos();
                break;
            case 2:
                system("cls");
  //              menuFuncionarios();
                break;
            case 3:
                system("cls");
                menuClientes(cliente,endereco);
                break;
            case 0:
                break;
            default:
                printf("Código inválido\n");
                system("pause");
                system("cls");
        }
    }
    while(menu!=0);

    return 0;
}
