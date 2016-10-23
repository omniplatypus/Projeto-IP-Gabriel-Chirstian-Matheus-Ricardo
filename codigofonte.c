#include <stdio.h>				//comentar o código faz bem :D
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<locale.h>
#include<ctype.h>

// está devidamente identado! eu acho.
typedef struct
{

    char nome[200];
    int dia, mes, ano;
    char predileto[30];
    int clientevip;

}Cliente;

typedef struct
{
    char rua[30];
    char bairro[30];
    char cidade[30];
    int numero;


}Endereco;


void cadastroCliente()
{
	Cliente cliente[255];
	Endereco endereco[255];
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

        printf("Digite o nome do cliente:\n");
        gets(cliente[i].nome);

        do{
	printf("\nDigite a data de nascimento do cliente (dd/mm/aa):\n");
        scanf("%i/%i/%i", &cliente[i].dia, &cliente[i].mes, &cliente[i].ano);
        getchar();
        setbuf(stdin,NULL);


        if(cliente[i].dia>31|| cliente[i].mes>12 || cliente[i].ano>2018)// Desisti de usar o Isalpha(), pra tentar impedir que usassem letras... Preciso pensar em  outra coisa.
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

		printf("%s é cliente VIP?(1-sim/ 2-nao)\n", cliente[i].nome);
        scanf("%d", &vip);
        if(vip==1)
        {
            cliente[i].clientevip = 1;
        }
        else
        {
            cliente[i].clientevip = 0;
        }


        printf("Deseja cadastrar um novo cliente?(1-sim/ 2-nao)\n");
        scanf("%d", &opmenu);
        setbuf(stdin,NULL);

            system("pause");
            system("cls");



    }while(opmenu!=2);// lembrar de colocar condição pelo menu.
    system("cls");
}

            // menu de opções

void menuClientes()// Menu de opções de clientes, por enquanto, so a função cadastrar está implementada.
{
    int opmenu;
    do
    {

    printf("\t\t\t***********************************\n");
    printf("\t\t\t\t Menu de Clientes ");
    printf("\n\t\t\t***********************************\n");
    printf("\n\n");
    printf("\n1- Cadastrar novo cliente\n");
    printf("\n2- Alterar cadastro do cliente\n");
    printf("\n3- Excluir Cadastro do cliente\n");
    printf("\n0- Para sair dessa opcao\n");
    scanf("%d", &opmenu);
    setbuf(stdin,NULL);

    switch(opmenu)
    {
        case 0:
            system("cls");
            break;

        case 1:
            system("cls");
            cadastroCliente();
            break;
        default:
        	printf("\nOpcao Invalida");
            system("pause");
            system("cls");

    }

    }while(opmenu!=0);
}


int main()// Menu Padrão de todos
{
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
                menuClientes();
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
