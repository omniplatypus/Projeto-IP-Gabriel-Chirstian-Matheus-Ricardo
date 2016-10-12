#include <stdio.h>				//comentar o código faz bem :D
#include <stdlib.h>
#include <string.h>

int main()
{
  setlocale(LC_ALL, "");
    int menu=0;
    do
    {
        printf("\t\tMENU PRINCIPAL\nDigite o número correspondente à opção desejada:\n1 - Menu produtos\n2 - Menu funcionários\n0 - Sair do programa\n");
        scanf("%i", &menu);
        getchar();
        switch (menu)
        {
            case 1:
                system("cls");
                menuProdutos();
                break;
            case 2:
                system("cls");
                menuFuncionarios();
                break;
            case 0:
                break;
            default:
                printf("Código inválido\n");
                break;
        }
    }
    while(menu!=0);
