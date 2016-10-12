#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char nome[60];
    int numero;
    int cpf;
    char cargo[50];
    float salario;
}Funcionario;

Funcionario funcionario[50];

int numfunc=0;                                 //numero de funcionarios

void cadastro()
{
    int x=0;
    int op;

    do{
            while((strlen(funcionario[x].nome)>0))
            {
                x++;
            }

            printf("digite o nome do funcionario:\n");
            gets(funcionario[x].nome);

            printf("digite o CPF do funcionario:\n");
            scanf("%i", &funcionario[x].cpf);
            getchar();

            printf("digite um numero para contato:\n");
            scanf("%i", &funcionario[x].numero);
            getchar();

            printf("digite o cargo do funcionario:\n");
            gets(funcionario[x].cargo);

            printf("digite o salario do funcionario:\n");
            scanf("%f", &funcionario[x].salario);
            getchar();

            printf("deseja cadastrar outro funcionario?(1-SIM 0-NAO)\n");
            scanf("%i", &op);
            getchar();

            numfunc++;                              //acrescentando o numero de funcionarios


            system("cls");

    }while(op!=0);

}

void vercadastro()
{
    int x, y;

    printf("funcionarios:%i\n", numfunc);

    if(numfunc>0)
    {


    printf("digite o codigo do funcionario:\n");
    scanf("%i", &x);
    getchar();

    printf("Funcionario:%s\nCPF:%i\nCargo:%s\nSalario:%f\nnumero para contato:%i\n", funcionario[x].nome, funcionario[x].cpf, funcionario[x].cargo, funcionario[x].salario, funcionario[x].numero);
    getchar();
    system("cls");
    }
    else
    {
        printf("nao existem funcionarios cadastrados");
        getchar();
        system("cls");
    }
}


int main()
{
    setlocale(LC_ALL, "");
    int menu;
    do
    {
        printf("\t\tMENU DE FUNÇIONARIOS\nDigite o número correspondente à opção desejada:\n1 - Cadastro de Funçionarios\n2 - Visualizaçao de Funçioarios\n0 - Sair do menu de funcionarios\n");
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
