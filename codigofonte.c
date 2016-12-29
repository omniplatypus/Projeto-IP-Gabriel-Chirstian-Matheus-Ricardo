#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>



typedef struct endereco ENDERECO;
struct endereco{
    char rua[60];
    char bairro[60];
    char cidade[60];
    int numero;
};

typedef struct cliente CLIENTE;
struct cliente{
    char nome[200];
    int dia, mes, ano;
    char predileto[60];
    int clientevip;
    int ativo;//1=ativo/2=excluído.
    ENDERECO end;
};

typedef struct cadastro CADASTRO;
struct cadastro
{
    char login[20];
    char senha[20];
};



void cadastroCliente()// funçao de cadastro de clientes
{
    FILE *arquivo;
    CLIENTE cll;

    int vip, opmenu, z=3;
    arquivo = fopen("cliente.dat", "ab");

    if(arquivo==NULL)// condição de erro
	{
		printf("\nNão foi possível abrir o arquivo, arquivo nulo.");
		exit(0);
	}
    else{
    do
    {
        printf("\t\t\t***********************************\n");
        printf("\t\t\t\t Cadastrar clientes ");
        printf("\n\t\t\t***********************************\n");

         printf("Digite o nome do cliente:\n");
        do
        {
            gets(cll.nome);
            setbuf(stdin,NULL);
            if(strcmp(cll.nome,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.nome,"\0")==0);

        printf("\nDigite a data de nascimento do cliente (dd/mm/aa):\n");
        do
        {// laço para caso seja uma data inválida
            scanf("%d/%d/%d", &cll.dia, &cll.mes, &cll.ano);
            getchar();

            if(isalpha(cll.dia) || isalpha(cll.ano)|| isalpha(cll.mes))
            {
                printf("%c\nData inválida", 7);

            }
            else if(cll.dia>31|| cll.mes>12 || cll.ano>2018 ||cll.dia<=0||cll.mes<=0||cll.ano<=0)
            {
                printf("%c\nData inválida", 7);
            }
            else
            {
                break;
            }
        }while(z==3);

        printf("Qual o endereco do cliente?\n");
        printf("Rua?\n");
        do
        {
            gets(cll.end.rua);
            setbuf(stdin,NULL);
            if(strcmp(cll.end.rua,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.end.rua,"\0")==0);

        printf("Bairro?\n");
        do
        {
            gets(cll.end.bairro);
            setbuf(stdin,NULL);
            if(strcmp(cll.end.bairro,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.end.bairro,"\0")==0);

        printf("Cidade?\n");
        do
        {
            gets(cll.end.cidade);
            setbuf(stdin,NULL);
            if(strcmp(cll.end.cidade,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.end.cidade,"\0")==0);

		printf("Numero?\n");
        scanf("%d", &cll.end.numero);
        getchar();

        printf("Digite qual o prato predileto do cliente:\n");
        do
        {
            gets(cll.predileto);
            setbuf(stdin,NULL);
            if(strcmp(cll.predileto,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }

        }while(strcmp(cll.predileto,"\0")==0);

		    printf("%s é cliente VIP?(1-sim/ 0-nao)\n", cll.nome);
        scanf("%d", &vip);
        getchar();
        if(vip==1)
        {
            cll.clientevip = 1;
        }
        else
        {
            cll.clientevip = 0;
        }

        cll.ativo=1;
        fwrite(&cll, sizeof(CLIENTE), 1, arquivo);


        printf("Deseja cadastrar um novo cliente?(1-sim/ 0-nao)\n");
        scanf("%d", &opmenu);
        getchar();
        system("cls");

    }while(opmenu!=0);// lembrar de colocar condição pelo menu.

    fclose(arquivo);
}

}

void excluirCadastro()
{
    FILE *arquivo;
    CLIENTE cll;
    arquivo = fopen("cliente.dat", "r+b");
    int posicao=0, regnum=0;
    char op, desejo,nome[60];
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
    else
    {
        setbuf(stdin,NULL);
        printf("Digite o nome do cadastrado a ser excluído:\n");
        do
        {
            gets(nome);
            setbuf(stdin,NULL);
            if(strcmp(nome,"\n")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(nome,"\n")==0);

        while(fread(&cll,sizeof(CLIENTE),1,arquivo)==1){
                if(strstr(strlwr(cll.nome),strlwr(nome))&&cll.ativo==1)
                {
                printf("\n");
                printf("Nome: %s\n", cll.nome);
                printf("Data de nascimento: %d/%d/%d\n", cll.dia, cll.mes, cll.ano);
                printf("Prato Predileto: %s\n",cll.predileto);
                printf("Cliente vip: %d\n", cll.clientevip);
                printf("Rua: %s\n", cll.end.rua);
                printf("Bairro: %s\n", cll.end.bairro);
                printf("Cidade: %s\n", cll.end.cidade);
                printf("número: %d", cll.end.numero);
                printf("\n------------------------------------------------------------------\n");
                printf("\nEsse é o registro que está procurando?(s/n)\n");
                op=getchar();
                getchar();

                if(strstr(strlwr(cll.nome),strlwr(nome))&&op=='s')
            {
                    regnum=posicao+1;
                    system("pause");
                    break;
            }
               }
                system("cls");
                posicao++;

}
        if(regnum==0)
        {
            printf("\n\nDesculpe nenhum registro encontrado...\n");
            system("pause");
            system("cls");

        }
        else
        {
            printf("\nDeseja excluir esse registro?(s/n)\n");
            desejo=getchar();
            getchar();
        }
        if(desejo=='s')
        {
            printf("\n\t  **** Cadastro excluído com sucesso! ****\n");
            cll.ativo=0;
            fseek(arquivo,sizeof(CLIENTE)*(regnum-1),SEEK_SET);
            fwrite(&cll,sizeof(CLIENTE),1,arquivo);
        }
        else
        {
            printf("\nOperação cancelada...\n");
        }
    }
    system("pause");
    system("cls");
    fclose(arquivo);
}



void relatorioClientes()// função para imprimir os clientes cadastrados e seus códigos.
{
    FILE *arquivo;
    CLIENTE cll;
    arquivo = fopen("cliente.dat", "rb");
    if(arquivo==NULL)// condição de erro
	{
		printf("\nNão foi possível abrir o arquivo, arquivo nulo.");
		exit(0);
	}
	else{
            while(fread(&cll,sizeof(CLIENTE), 1, arquivo)==1)
            {
                if(cll.ativo==1)
                {
                printf("Nome: %s\n", cll.nome);
                printf("Data de nascimento: %d/%d/%d\n", cll.dia, cll.mes, cll.ano);
                printf("Prato Predileto: %s\n",cll.predileto);
                printf("Cliente vip: %d\n", cll.clientevip);
                printf("Rua: %s\n", cll.end.rua);
                printf("Bairro: %s\n", cll.end.bairro);
                printf("Cidade: %s\n", cll.end.cidade);
                printf("número: %d", cll.end.numero);
                printf("\n------------------------------------------------------------------\n");
                }
            }
	}
	fclose(arquivo);
    system("pause");
    system("cls");
    }

void verClientes()// função para ver as  informações de um cliente
{
    FILE *arquivo;
    CLIENTE cll;
    char nome[200], c;
    arquivo = fopen("cliente.dat", "rb");
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
    else
    {
    setbuf(stdin,NULL);
       printf("Digite uma informação a respeito do cadastrado a ser pesquisada:\n");
       do
        {
            gets(nome);
            setbuf(stdin,NULL);
            if(strcmp(nome,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(nome,"\0")==0);
        while(!feof(arquivo)){
        if(fread(&cll,sizeof(CLIENTE),1,arquivo)==1){
        if(cll.ativo==1){
        if(strstr(strlwr(cll.nome),strlwr(nome))||strstr(strlwr(cll.predileto),strlwr(nome))||strstr(strlwr(cll.end.rua),strlwr(nome))||strstr(strlwr(cll.end.bairro),strlwr(nome))||strstr(strlwr(cll.end.cidade),strlwr(nome))||cll.dia==atoi(nome)||cll.mes==atoi(nome)||cll.ano==atoi(nome))
        {
                printf("\n");
                printf("Nome: %s\n", cll.nome);
                printf("Data de nascimento: %d/%d/%d\n", cll.dia, cll.mes, cll.ano);
                printf("Prato Predileto: %s\n",cll.predileto);
                printf("Cliente vip: %d\n", cll.clientevip);
                printf("Rua: %s\n", cll.end.rua);
                printf("Bairro: %s\n", cll.end.bairro);
                printf("Cidade: %s\n", cll.end.cidade);
                printf("número: %d", cll.end.numero);
                printf("\n------------------------------------------------------------------\n");
                printf("\n\nÉ este cadastro que estava procurando?(s/n)");
                c=getche();
                if(c=='s')
                {
                    printf("\n");
                    break;

                }
                else
                {
                    printf("\nIndo para o próximo cadastro...");
                    system("pause");
                    system("cls");
                }
        }
        }
        }
                if(feof(arquivo))
                {
                    printf("\nDesculpe nenhum cadastro encontrado com esse nome\n");
                    break;
                }
}

fclose(arquivo);
system("pause");
system("cls");
}
}



void alterarCadastro()// alterar cadastro
{
    FILE *arquivo;
    CLIENTE cll;
    char c;
    int vip, z=3;
    int posicao=0, regnum=0,desejo;
    char nome[200];
    arquivo = fopen("cliente.dat", "r+b");
    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
    else
    {
            printf("Digite um nome do cliente a ser alterado:\n");
            do
            {
                gets(nome);
                setbuf(stdin,NULL);
                if(strcmp(nome,"\0")==0)
                {
                    printf("Desculpe mas você não digitou nada...\n");
                }
            }while(strcmp(nome,"\0")==0);

        while(!feof(arquivo)){
        if(fread(&cll,sizeof(CLIENTE),1,arquivo)==1){
        char op;
        if(strstr(strlwr(cll.nome),strlwr(nome))&&cll.ativo==1)
        {
                printf("\n");
                printf("Nome: %s\n", cll.nome);
                printf("Data de nascimento: %d/%d/%d\n", cll.dia, cll.mes, cll.ano);
                printf("Prato Predileto: %s\n",cll.predileto);
                printf("Cliente vip: %d\n", cll.clientevip);
                printf("Rua: %s\n", cll.end.rua);
                printf("Bairro: %s\n", cll.end.bairro);
                printf("Cidade: %s\n", cll.end.cidade);
                printf("número: %d", cll.end.numero);
                printf("\n------------------------------------------------------------------\n");
                printf("\nEra esse o cadastro que estava procurando?(s/n)\n");
                op=getchar();
                getchar();
                if(op=='s')
                {
                regnum=posicao+1;
                break;
                }
                else
                {
                    system("pause");
                    system("cls");
                }

        }
        }
        posicao++;
        }

        if(regnum==0)
        {
            printf("\n****Desculpe nenhum cadastro encontrado com esse nome****\n");
        }
        else{
            printf("Deseja alterar esse cadastro?(s/n)\n");
            c=getchar();
            setbuf(stdin,NULL);
            system("cls");
        }
        if(c=='s')
        {
        printf("\n");

        printf("\t\t\t***********************************\n");
        printf("\t\t\t\t Atualização de cadastro ");
        printf("\n\t\t\t***********************************\n");
        printf("\n\n");
        printf("\n1 - Nome do cliente\n");
        printf("2 - Data de nascimento do cliente\n");
        printf("3 - Endereço do cliente\n");
        printf("4 - Prato predileto do cliente\n");
        printf("5 - Condição vip\n");
        printf("6 - Todas as anteriores\n");
        printf("\n\n");
        printf("O que você deseja alterar?\n");
        scanf("%d", &desejo);
        getchar();

            switch(desejo)
            {
                case 1:
                    printf("Digite o nome do cliente:\n");
                    do
                    {
                        gets(cll.nome);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.nome,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.nome,"\0")==0);
                    break;
                case 2:
                    printf("\nDigite a data de nascimento do cliente (dd/mm/aa):\n");
                    do
                    {// laço para caso seja uma data inválida
                        scanf("%d/%d/%d", &cll.dia, &cll.mes, &cll.ano);
                        getchar();
                        setbuf(stdin,NULL);

                        if(isalpha(cll.dia) || isalpha(cll.ano)|| isalpha(cll.mes))
                        {
                            printf("%c\nData inválida", 7);

                        }
                        else if(cll.dia>31|| cll.mes>12 || cll.ano>2018 ||cll.dia<=0||cll.mes<=0||cll.ano<=0)
                        {
                            printf("%c\nData inválida", 7);
                        }
                        else
                        {
                            break;
                        }
                    }while(z==3);

                    break;

                case 3:
                    printf("Qual o endereco do cliente?\n");
                    printf("Rua?\n");
                    do
                    {
                        gets(cll.end.rua);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.end.rua,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.rua,"\0")==0);

                    printf("Bairro?\n");
                    do
                    {
                        gets(cll.end.bairro);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.end.bairro,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.bairro,"\0")==0);


                    printf("Cidade?\n");
                    do
                    {
                        gets(cll.end.cidade);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.end.cidade,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.cidade,"\0")==0);

                    printf("Numero?\n");
                    scanf("%d", &cll.end.numero);
                    getchar();
                    break;
                case 4:

                     printf("Digite qual o prato predileto do cliente:\n");
                    do
                    {
                        gets(cll.predileto);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.predileto,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.predileto,"\0")==0);
                    break;

                case 5:
                    printf("%s é cliente VIP?(1-sim/ 0-nao)\n", cll.nome);
                    scanf("%d", &vip);
                    getchar();
                    if(vip==1)
                    {
                        cll.clientevip = 1;
                    }
                    else
                    {
                        cll.clientevip = 0;
                    }
                    break;

                case 6:
                    printf("Digite o nome do cliente:\n");
                    do
                    {
                        gets(cll.nome);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.nome,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.nome,"\0")==0);

                    printf("\nDigite a data de nascimento do cliente (dd/mm/aa):\n");
                    do
                    {// laço para caso seja uma data inválida
                        scanf("%d/%d/%d", &cll.dia, &cll.mes, &cll.ano);
                        getchar();
                        setbuf(stdin,NULL);

                        if(isalpha(cll.dia) || isalpha(cll.ano)|| isalpha(cll.mes))
                        {
                            printf("%c\nData inválida", 7);

                        }
                        else if(cll.dia>31|| cll.mes>12 || cll.ano>2018 ||cll.dia<=0||cll.mes<=0||cll.ano<=0)
                        {
                            printf("%c\nData inválida", 7);
                        }
                        else
                        {
                            break;
                        }
                    }while(z==3);


                    printf("Qual o endereco do cliente?\n");
                    printf("Rua?\n");
                    do
                    {
                        gets(cll.end.rua);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.end.rua,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.rua,"\0")==0);

                    printf("Bairro?\n");
                    do
                    {
                    gets(cll.end.bairro);
                    setbuf(stdin,NULL);
                        if(strcmp(cll.end.bairro,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.bairro,"\0")==0);

                    printf("Cidade?\n");
                    do
                    {
                        gets(cll.end.cidade);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.end.cidade,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.cidade,"\0")==0);

                    printf("Numero?\n");
                    scanf("%d", &cll.end.numero);
                    getchar();

                    printf("Digite qual o prato predileto do cliente:\n");
                    do
                    {
                        gets(cll.predileto);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.predileto,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }

                    }while(strcmp(cll.predileto,"\0")==0);

                    printf("%s é cliente VIP?(1-sim/ 0-nao)\n", cll.nome);
                    scanf("%d", &vip);
                    getchar();
                    if(vip==1)
                    {
                        cll.clientevip = 1;
                    }
                    else
                    {
                        cll.clientevip = 0;
                    }
                    break;
                default:
                    printf("\nOPÇÃO INVÁLIDA!!!\n");
                    system("pause");
                    system("cls");
        }
        fseek(arquivo,sizeof(CLIENTE)*(regnum-1),SEEK_SET);
        fwrite(&cll,sizeof(CLIENTE),1,arquivo);
        printf("\n\t****Cadastro atualizado com sucesso...!****");
        printf("\n");
        }
        system("pause");
        system("cls");
    }
    fclose(arquivo);

}


void anivMes()
{
    FILE *arquivo;
    CLIENTE cll;
    int mes;
    arquivo = fopen("cliente.dat", "rb");
    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
    else{
        setbuf(stdin,NULL);
        printf("De qual mês deseja saber os aniversariantes? [0-12]\n");
        scanf("%d",&mes);
        getchar();
        system("cls");
        printf("Aniversariantes:\n");
        while(fread(&cll,sizeof(CLIENTE),1,arquivo)==1){
            if(cll.mes==mes&&cll.ativo==1){
                printf("%s\n", cll.nome);
                printf("%d/%d/%d", cll.dia,cll.mes,cll.ano);
                printf("\n--------------------------------------\n");
            }
        }
        fclose(arquivo);
        system("pause");
        system("cls");
    }
}


            // menu de opções de clientes

void menuClientes()
{

    int opmenu;
    do
    {

        printf("\t\t\t***********************************\n");
        printf("\t\t\t\t Menu de Clientes ");
        printf("\n\t\t\t***********************************\n");
        printf("\n\n");
        printf("1 - Cadastrar novo cliente\n");
        printf("2 - Alterar Cadastro\n");
        printf("3 - Lista de Clientes\n");
        printf("4 - Pesquisar cadastrados\n");
        printf("5 - Aniversariantes do mês\n");
        printf("6 - Excluir cadastro\n");
        printf("0 - Para sair dessa opcao\n");
        printf("\nQual operação deseja realizar?\n");
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
                alterarCadastro();
                break;
            case 3:
                system("cls");
                relatorioClientes();
                break;
            case 4:
                system("cls");
                verClientes();
                break;
            case 5:
            	system("cls");
            	anivMes();
            	break;
            case 6:
                system("cls");
                excluirCadastro();
                break;

            default:
                printf("\nOpcao Inválida");
                system("pause");
                system("cls");
    }

    }while(opmenu!=0);
}



void CadastroADM()
{
    FILE *senha;
    CADASTRO cad;
    char c;
    int a=0,op=0,i;
    senha=fopen("cadastro.dat", "wb");
    if(senha==NULL)
    {
        printf("\nNão foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
    else
    {
    do{
    printf("\t\t\t***********************************\n");
    printf("\t\t\t*       CADASTRO DE ADM           * ");
    printf("\n\t\t\t***********************************\n");
    printf("\n\n");
    printf("\t\tDIGITE SEU LOGIN\n\t\t");
    do{
		setbuf(stdin,NULL);
		gets(cad.login);
		if((strcmp(cad.login,"\0")==0))
        {
            printf("\t\tDesculpe, mas você não digitou nada...\n");
            printf("\t\t");
        }
		}while(strcmp(cad.login,"\0")==0);
    printf("\t\tDIGITE SUA SENHA\n\t\t");
    do{
    do{
        c=getch();
        if(isprint(c))
        {
            cad.senha[a]=c;
            a++;
                printf("%c",c);
        }
        else if(c==8&&a!=0)
        {
            cad.senha[a]='\0';
            printf("\b \b");
            a--;
        }
        if(a==0){
                cad.senha[0]='\0';
            }
        }while(cad.senha[0]=='\0');
		}while(c!=13);
    char op;
    printf("\nDeseja registrar esse login e senha?(s/n)");
    scanf("%c",&op);
    if(op=='s')
    {
        cad.senha[a]='\0';
        a=0;
        system("cls");
        break;
    }else{
        system("cls");
        a=0;
    }
    }while(op!='s');

    fwrite(&cad,sizeof(CADASTRO),1,senha);
    fclose(senha);
    printf("\nCADASTRO DE ADM EFETUADO COM SUCESSO");
    system("pause");
    system("cls");
}
}
void teladeLogin()
{
        FILE *senha;
        CADASTRO cad;
        char tentativalogin[20], tentativasenha[20];
        int chances=3, a=0,logado=5;
        char c;
        senha = fopen("cadastro.dat", "rb");
        if(senha == NULL)
        {
            printf("\nNão foi possível abrir o arquivo, arquivo nulo!\n");
            exit(0);
        }
        else{
        do{
        senha = fopen("cadastro.dat", "rb");
        printf("\t\t\t***********************************\n");
        printf("\t\t\t*       TELA DE LOGIN ADM         * ");
        printf("\n\t\t\t***********************************\n");
        printf("\n\n");
		printf("\t\tDIGITE SEU LOGIN:\n\t\t");
		do{
		setbuf(stdin,NULL);
		gets(tentativalogin);
		if((strcmp(tentativalogin,"\0")==0))
        {
            printf("\t\tDesculpe, mas você não digitou nada...\n");
            printf("\t\t");
        }
		}while(strcmp(tentativalogin,"\0")==0);
		printf("\t\tDIGITE SUA SENHA:\n\t\t");
		do{
            c=getch();
            if(isprint(c))
            {
                tentativasenha[a]=c;
                a++;
                printf("*");
            }
            else if(c==8&&a!=0)
            {
                tentativasenha[a]='\0';
                a--;
                printf("\b \b");
            }
		}while(c!=13);
		tentativasenha[a]='\0';
        if(fread(&cad,sizeof(CADASTRO),1,senha)==1&&!strcmp(cad.login,tentativalogin)&&!strcmp(cad.senha,tentativasenha))
        {
            printf("\n\n\t\t **** Seja bem-vindo %s !****", tentativalogin);
            printf("\n");
            system("pause");
            fclose(senha);
            logado=0;
        }
        else
        {
            printf("\n\t **** SENHA OU LOGIN INCORRETOS ****");
            printf("\n");
            system("pause");
            system("cls");
            a=0;
            chances--;
        }
        }while(chances!=0&&logado!=0);
        if(chances==0)
        {
            printf("\nVocê excedeu o numero de tentativas, saindo do programa...\n");
            fclose(senha);
            exit(0);
        }
        system("cls");
}
}


int main()
{
    setlocale(LC_ALL, "");
    int menu;
    FILE *senha;
    senha = fopen("cadastro.dat", "rb");
    if(senha==NULL)
    {
        CadastroADM();
    }
    else
    {
    teladeLogin();
    }
    do
    {
        printf("\t\tMENU PRINCIPAL\nDigite o número correspondente à opção desejada:\n1 - Menu produtos\n2 - Menu funcionários\n3 - Menu Clientes\n0 - Sair do programa\n");
        printf("\nQual operação deseja realizar?\n");
        scanf("%d", &menu);
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
                printf("Até mais!");
                exit(0);
            default:
                printf("Código inválido\n");
                system("pause");
                system("cls");
        }
    }while(menu!=0);

    exit(0);
}

