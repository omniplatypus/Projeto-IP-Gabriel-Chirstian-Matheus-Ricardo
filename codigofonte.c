#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>

// mais um update simples dessa vez com a funçao de alterar cadastro.

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



        if(cliente[i].dia>31|| cliente[i].mes>12 || cliente[i].ano>2018)
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

void AlterarCadastro()
{
    Cliente cliente[255];
	Endereco endereco[255];

	int endcliente, op, z=3;
	char nome[255];
	char predileto[55];
	int novodia, novomes, novoano, vip, numero;
	char rua[50];
	char bairro[50];
	char cidade[50];
	do{
	printf("Digite o  endereço do cliente:\n");
    scanf("%d", &endcliente);
    getchar();

    Cliente *ponteiro = &cliente[endcliente];
    Endereco *ponteiro2 = &endereco[endcliente];

    printf("\nDigite o novo nome:\n");
    gets(nome);
    getchar();
    strcpy(ponteiro->nome, nome);

    do{
    printf("\nDigite a nova data:\n");
    scanf("%d/%d/%d", &novodia, &novomes, &novoano);
    getchar();
    ponteiro->dia= novodia;
    ponteiro->mes= novomes;
    ponteiro->ano= novoano;

    if(ponteiro->dia>31|| ponteiro->mes>12 || ponteiro->ano>2018)
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
        gets(rua);
        strcpy(ponteiro2->rua, rua);

		printf("Bairro?\n");
        gets(bairro);
        strcpy(ponteiro2->bairro, bairro);

		printf("Cidade?\n");
        gets(cidade);
        strcpy(ponteiro2->cidade, cidade);
		printf("Numero?\n");
        scanf("%d", &numero);
        setbuf(stdin, NULL);
        ponteiro2->numero=numero;
    printf("\nDigite o novo prato predileto:\n");
    gets(predileto);
    strcpy(ponteiro->predileto, predileto);

    printf("\n%s é cliente VIP (1-sim/ 2-nao)?\n", ponteiro->nome);
    scanf("%d", &vip);
    ponteiro->clientevip = vip;

    system("pause");

    printf("\tDados Alterados\n\n\n");
    printf("Nome: %s\nData de nascimento: %d/%d/%d\nEndereco: rua %s, bairro %s, %s, n°%d\nPrato predileto: %s\nCliente VIP: %d", ponteiro->nome, ponteiro->dia, ponteiro->mes, ponteiro->ano, ponteiro2->rua, ponteiro2->bairro, ponteiro2->cidade, ponteiro2->numero, ponteiro->predileto, ponteiro->clientevip);

    printf("\n\nDeseja alterar um novo cadastro?(1-sim/ 2-nao)\n");
    scanf("%d", &op);
    setbuf(stdin,NULL);
    system("pause");
    system("cls");
	}while(op!=2);


    system("pause");
    system("cls");
}

            // menu de opções

void menuClientes()
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
        case 2:
            system("cls");
            AlterarCadastro();
            break;
        default:
        	printf("\nOpcao Invalida");
            system("pause");
            system("cls");

    }

    }while(opmenu!=0);
}


int main()
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
