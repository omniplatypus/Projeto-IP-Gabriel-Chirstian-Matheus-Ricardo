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

typedef struct funcionario FUNCIONARIO;
struct funcionario{
    char nome[200];
    char data[11];
    char cargo[100];
    char cpf[50];
    char salario[200];
    int ativo;//1=ativo/0=excluído.
    ENDERECO end;
};

typedef struct adm ADM;// STRUCT DE CADASTRO DE USUÁRIO ADM, DO PROGRAMA.
struct adm
{
    char login[20];
    char senha[20];
};



void cadastroFuncionario()// funçao de cadastro de clientes
{
    FILE *arquivo;
    FUNCIONARIO cll;

    int vip, opmenu, z=3;
    arquivo = fopen("funcionario.dat", "ab");
    char a[5];
    char data[11];
    if(arquivo==NULL)// condição de erro
	{
		printf("\nNão foi possível abrir o arquivo, arquivo nulo.");
		exit(0);
	}
    else{
    do
    {
        printf("\t\t\t***********************************\n");
        printf("\t\t\t\t Cadastrar funcionario ");
        printf("\n\t\t\t***********************************\n");

         printf("Digite o nome do funcionario:\n");
        do
        {
            gets(cll.nome);
            setbuf(stdin,NULL);
            if(strcmp(cll.nome,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.nome,"\0")==0);

        printf("Digite o cpf do funcionario:\n");
        do
        {
            gets(cll.cpf);
            setbuf(stdin,NULL);
            if(strcmp(cll.cpf,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.cpf,"\0")==0);

        printf("\nDigite a data de nascimento do funcionario(dd/mm/aaaa) :\n");
        do
        {// laço para caso seja uma data inválida
            fgets(data,11,stdin);
            data[10]='\0';
            setbuf(stdin,NULL);
            if((data[0]>='a' && data[0]<='z')||(data[0]>='A' && data[0]<='Z')||(data[1]>='a' && data[1]<='z')||(data[1]>='A' && data[1]<='Z')||data[2]!='/'||(data[3]>='a' && data[3]<='z')||(data[3]>='A' && data[3]<='Z')||(data[4]>='a' && data[4]<='z')||(data[4]>='A' && data[4]<='Z')||data[5]!='/'||(data[6]>='a' && data[6]<='z')||(data[6]>='A' && data[6]<='Z')||(data[7]>='a' && data[7]<='z')||(data[7]>='A' && data[7]<='Z')||(data[8]>='a' && data[8]<='z')||(data[8]>='A' && data[8]<='Z')||(data[9]>='a' && data[9]<='z')||(data[9]>='A' && data[9]<='Z')){

                printf("%c\nData inválida\n", 7);
                setbuf(stdin,NULL);
            }

            else
            {
                strcpy(cll.data,data);
                setbuf(stdin,NULL);
                break;
            }

        }while(z==3);
        getchar();
        printf("Qual o endereco do funcionario?\n");
        printf("Rua?\n");

        do
        {
            gets(cll.end.rua);
            setbuf(stdin,NULL);
            if(strcmp(cll.end.rua,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
                setbuf(stdin,NULL);
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
                setbuf(stdin,NULL);
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
                setbuf(stdin,NULL);
            }
        }while(strcmp(cll.end.cidade,"\0")==0);

		printf("Numero?\n");
        do{
        setbuf(stdin,NULL);
        fgets(a,5,stdin);
        setbuf(stdin,NULL);
        getchar();
        if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')||(a[1]>='a' && a[1]<='z')||(a[1]>='A' && a[1]<='Z')||(a[2]>='a' && a[2]<='z')||(a[2]>='A' && a[2]<='Z')||(a[3]>='a' && a[3]<='z')||(a[3]>='A' && a[3]<='Z'))
        {
            printf("%c\nData inválida\n", 7);
            setbuf(stdin,NULL);

        }
        else
        {
            cll.end.numero=atoi(a);
            setbuf(stdin,NULL);
            break;
        }
        }while(z==3);
        printf("Digite o cargo do funcionario:\n");
        do
        {
            gets(cll.cargo);
            setbuf(stdin,NULL);
            if(strcmp(cll.cargo,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.cargo,"\0")==0);

		printf("Digite o salario do funcionario:\n");
        do
        {
            gets(cll.salario);
            setbuf(stdin,NULL);
            if(strcmp(cll.salario,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.salario,"\0")==0);

        cll.ativo=1;
        fwrite(&cll, sizeof(FUNCIONARIO), 1, arquivo);


        printf("Deseja cadastrar um novo funcionario?(1-sim/ 0-nao)\n");
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
    FUNCIONARIO cll;
    arquivo = fopen("funcionario.dat", "r+b");
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

        while(fread(&cll,sizeof(FUNCIONARIO),1,arquivo)==1){
                if(strstr(strlwr(cll.nome),strlwr(nome))&&cll.ativo==1)
                {
                printf("\n");
                printf("Nome: %s\n", cll.nome);
                printf("CPF: %s\n", cll.cpf);
                printf("Data de nascimento: %s\n", cll.data);
                printf("Rua: %s\n", cll.end.rua);
                printf("Bairro: %s\n", cll.end.bairro);
                printf("Cidade: %s\n", cll.end.cidade);
                printf("Número: %d\n", cll.end.numero);
                printf("Cargo: %s\n", cll.cargo);
                printf("Salario: %s\n", cll.salario);
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
            fseek(arquivo,sizeof(FUNCIONARIO)*(regnum-1),SEEK_SET);
            fwrite(&cll,sizeof(FUNCIONARIO),1,arquivo);
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


void relatorioFuncionarios()// função para imprimir os clientes cadastrados e seus códigos.
{
    FILE *arquivo;
    FUNCIONARIO cll;
    arquivo = fopen("funcionario.dat", "rb");
    if(arquivo==NULL)// condição de erro
	{
		printf("\nNão foi possível abrir o arquivo, arquivo nulo.");
		exit(0);
	}
	else{
            while(fread(&cll,sizeof(FUNCIONARIO), 1, arquivo)==1)
            {
                if(cll.ativo==1)
                {
                printf("Nome: %s\n", cll.nome);
                printf("cpf: %s\n", cll.cpf);
                printf("Data de nascimento: %s\n", cll.data);
                printf("Rua: %s\n", cll.end.rua);
                printf("Bairro: %s\n", cll.end.bairro);
                printf("Cidade: %s\n", cll.end.cidade);
                printf("Número: %d\n", cll.end.numero);
                printf("Cargo: %s\n", cll.cargo);
                printf("Salario: %s\n", cll.salario);
                printf("\n------------------------------------------------------------------\n");
                }
            }
	}
	fclose(arquivo);
    system("pause");
    system("cls");
    }

void verFuncionarios()// função para ver as  informações de um cliente
{
    FILE *arquivo;
    FUNCIONARIO cll;
    char nome[200], c;
    arquivo = fopen("funcionario.dat", "rb");
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
        if(fread(&cll,sizeof(FUNCIONARIO),1,arquivo)==1){
        if(cll.ativo==1){
        if(strstr(strlwr(cll.nome),strlwr(nome))||strstr(strlwr(cll.cpf),strlwr(nome))||strstr(strlwr(cll.end.rua),strlwr(nome))||strstr(strlwr(cll.end.bairro),strlwr(nome))||strstr(strlwr(cll.end.cidade),strlwr(nome))||strstr(strlwr(cll.data),strlwr(nome)))
        {
                printf("\n");
                printf("Nome: %s\n", cll.nome);
                printf("CPF: %s\n", cll.cpf);
                printf("Data de nascimento: %s\n", cll.data);
                printf("Rua: %s\n", cll.end.rua);
                printf("Bairro: %s\n", cll.end.bairro);
                printf("Cidade: %s\n", cll.end.cidade);
                printf("número: %d\n", cll.end.numero);
                printf("Cargo: %s\n", cll.cargo);
                printf("Salario: %s\n", cll.salario);
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
    FUNCIONARIO cll;
    char c, a[5], data[11];
    int vip, z=3;
    int posicao=0, regnum=0,desejo;
    char nome[200];
    arquivo = fopen("funcionario.dat", "r+b");
    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
    else
    {
            printf("Digite um nome do funcionario a ser alterado:\n");
            do
            {
                gets(nome);
                setbuf(stdin,NULL);
                if(strcmp(nome,"\0")==0)
                {
                    printf("Desculpe mas você não digitou nada...\n");
                    setbuf(stdin,NULL);
                }
            }while(strcmp(nome,"\0")==0);

        while(!feof(arquivo)){
        if(fread(&cll,sizeof(FUNCIONARIO),1,arquivo)==1){
        char op;
        if(strstr(strlwr(cll.nome),strlwr(nome))&&cll.ativo==1)
        {
                printf("\n");
                printf("Nome: %s\n", cll.nome);
                printf("CPF: %s\n", cll.cpf);
                printf("Data de nascimento: %s\n", cll.data);
                printf("Rua: %s\n", cll.end.rua);
                printf("Bairro: %s\n", cll.end.bairro);
                printf("Cidade: %s\n", cll.end.cidade);
                printf("número: %d\n", cll.end.numero);
                printf("Cargo: %s\n", cll.cargo);
                printf("Salario: %s\n", cll.salario);
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
        printf("\n1 - Nome do funcionario\n");
        printf("2 - CPF do funcionario\n");
        printf("3 - Data de nascimento do funcionario\n");
        printf("4 - Endereço do funcionario\n");
        printf("5 - Cargo do funcionario\n");
        printf("6 - Salario do funcionario\n");
        printf("7 - Todas as anteriores\n");
        printf("\n\n");
        printf("O que você deseja alterar?\n");
        scanf("%d", &desejo);
        getchar();

            switch(desejo)
            {
                case 1:
                    printf("Digite o nome do funcionario:\n");
                    do
                    {
                        gets(cll.nome);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.nome,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
                        }
                    }while(strcmp(cll.nome,"\0")==0);
                    break;

                case 2:
                    printf("Digite o cpf do funcionario:\n");
                    do
                    {
                        gets(cll.cpf);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.cpf,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
                        }
                    }while(strcmp(cll.cpf,"\0")==0);
                    break;

                case 3:
                    printf("\nDigite a data de nascimento do funcionario (dd/mm/aa):\n");
                    do
                    {// laço para caso seja uma data inválida
                        fgets(data,11,stdin);
                        data[10]='\0';
                        setbuf(stdin,NULL);
                        getchar();
                        if((data[0]>='a' && data[0]<='z')||(data[0]>='A' && data[0]<='Z')||(data[1]>='a' && data[1]<='z')||(data[1]>='A' && data[1]<='Z')||data[2]!='/'||(data[3]>='a' && data[3]<='z')||(data[3]>='A' && data[3]<='Z')||(data[4]>='a' && data[4]<='z')||(data[4]>='A' && data[4]<='Z')||data[5]!='/'||(data[6]>='a' && data[6]<='z')||(data[6]>='A' && data[6]<='Z')||(data[7]>='a' && data[7]<='z')||(data[7]>='A' && data[7]<='Z')||(data[8]>='a' && data[8]<='z')||(data[8]>='A' && data[8]<='Z')||(data[9]>='a' && data[9]<='z')||(data[9]>='A' && data[9]<='Z')){

                            printf("%c\nData inválida\n", 7);
                            setbuf(stdin,NULL);
                        }

                        else
                        {
                            strcpy(cll.data,data);
                            setbuf(stdin,NULL);
                            break;
                        }

                    }while(z==3);

                    break;

                case 4:
                    getchar();
                    printf("Qual o endereco do funcionario?\n");
                    printf("Rua?\n");
                    do
                    {
                        gets(cll.end.rua);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.end.rua,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
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
                            setbuf(stdin,NULL);
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
                            setbuf(stdin,NULL);
                        }
                    }while(strcmp(cll.end.cidade,"\0")==0);

                    printf("Numero?\n");
                    do{
                    setbuf(stdin,NULL);
                    fgets(a,5,stdin);
                    setbuf(stdin,NULL);
                    if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')||(a[1]>='a' && a[1]<='z')||(a[1]>='A' && a[1]<='Z')||(a[2]>='a' && a[2]<='z')||(a[2]>='A' && a[2]<='Z')||(a[3]>='a' && a[3]<='z')||(a[3]>='A' && a[3]<='Z'))
                    {
                        printf("%c\nData inválida\n", 7);
                        setbuf(stdin,NULL);

                    }
                    else
                    {
                        cll.end.numero=atoi(a);
                        setbuf(stdin,NULL);
                        break;
                    }
                    }while(z==3);
                    break;

                case 5:
                    printf("Digite o cargo do funcionario:\n");
                    do
                    {
                        gets(cll.cargo);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.cargo,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
                        }
                    }while(strcmp(cll.cargo,"\0")==0);
                    break;

                case 6:
                    printf("Digite o salario do funcionario:\n");
                    do
                    {
                        gets(cll.salario);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.salario,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
                        }
                    }while(strcmp(cll.salario,"\0")==0);
                    break;

                case 7:
                    printf("Digite o nome do funcionario:\n");
                    do
                    {
                        gets(cll.nome);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.nome,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
                        }
                    }while(strcmp(cll.nome,"\0")==0);

                    printf("Digite o cpf do funcionario:\n");
                    do
                    {
                        gets(cll.cpf);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.cpf,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
                        }
                    }while(strcmp(cll.cpf,"\0")==0);

                    printf("\nDigite a data de nascimento do cliente (dd/mm/aa):\n");
                    do
                    {// laço para caso seja uma data inválida
                        fgets(data,11,stdin);
                        data[10]='\0';
                        setbuf(stdin,NULL);
                        getchar();
                        if((data[0]>='a' && data[0]<='z')||(data[0]>='A' && data[0]<='Z')||(data[1]>='a' && data[1]<='z')||(data[1]>='A' && data[1]<='Z')||data[2]!='/'||(data[3]>='a' && data[3]<='z')||(data[3]>='A' && data[3]<='Z')||(data[4]>='a' && data[4]<='z')||(data[4]>='A' && data[4]<='Z')||data[5]!='/'||(data[6]>='a' && data[6]<='z')||(data[6]>='A' && data[6]<='Z')||(data[7]>='a' && data[7]<='z')||(data[7]>='A' && data[7]<='Z')||(data[8]>='a' && data[8]<='z')||(data[8]>='A' && data[8]<='Z')||(data[9]>='a' && data[9]<='z')||(data[9]>='A' && data[9]<='Z')){

                            printf("%c\nData inválida\n", 7);
                            setbuf(stdin,NULL);
                        }

                        else
                        {
                            strcpy(cll.data,data);
                            setbuf(stdin,NULL);
                            break;
                        }

                    }while(z==3);
                    getchar();
                    printf("Qual o endereco do cliente?\n");
                    printf("Rua?\n");
                    do
                    {
                        gets(cll.end.rua);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.end.rua,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
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
                            setbuf(stdin,NULL);
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
                            setbuf(stdin,NULL);
                        }
                    }while(strcmp(cll.end.cidade,"\0")==0);

                    printf("Numero?\n");
                    do{
                        setbuf(stdin,NULL);
                        fgets(a,5,stdin);
                        setbuf(stdin,NULL);
                        if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')||(a[1]>='a' && a[1]<='z')||(a[1]>='A' && a[1]<='Z')||(a[2]>='a' && a[2]<='z')||(a[2]>='A' && a[2]<='Z')||(a[3]>='a' && a[3]<='z')||(a[3]>='A' && a[3]<='Z'))
                        {
                            printf("%c\nData inválida\n", 7);
                            setbuf(stdin,NULL);

                        }
                        else
                        {
                            cll.end.numero=atoi(a);
                            setbuf(stdin,NULL);
                            break;
                        }
                        }while(z==3);

                    printf("Digite o cargo do funcionario:\n");
                    do
                    {
                        gets(cll.cargo);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.cargo,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
                        }

                    }while(strcmp(cll.cargo,"\0")==0);

                    printf("Digite o salario do funcionario:\n");
                    do
                    {
                        gets(cll.salario);
                        setbuf(stdin,NULL);
                        if(strcmp(cll.salario,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                            setbuf(stdin,NULL);
                        }
                    }while(strcmp(cll.salario,"\0")==0);

                    break;

                default:
                    printf("\nOPÇÃO INVÁLIDA!!!\n");
                    system("pause");
                    system("cls");
        }
        fseek(arquivo,sizeof(FUNCIONARIO)*(regnum-1),SEEK_SET);
        fwrite(&cll,sizeof(FUNCIONARIO),1,arquivo);
        printf("\n\t****Cadastro atualizado com sucesso...!****");
        printf("\n");
        }
        system("pause");
        system("cls");
    }
    fclose(arquivo);

}


void menuFuncionarios()
{

    int opmenu;
    do
    {

        printf("\t\t\t************************\n");
        printf("\t\t\t*   Menu de Funcionarios   *");
        printf("\n\t\t\t************************\n");
        printf("\n\n");
        printf("1 - Cadastrar novo funcionario\n");
        printf("2 - Alterar Cadastro\n");
        printf("3 - Lista de funcionarios\n");
        printf("4 - Pesquisar cadastrados\n");
        printf("5 - Excluir cadastro\n");
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
                cadastroFuncionario();
                break;
            case 2:
                system("cls");
                alterarCadastro();
                break;
            case 3:
                system("cls");
                relatorioFuncionarios();
                break;
            case 4:
                system("cls");
                verFuncionarios();
                break;
            case 5:
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
    ADM cad;
    char c;
    int a=0,op=0;
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

    fwrite(&cad,sizeof(ADM),1,senha);
    fclose(senha);
    printf("\nCADASTRO DE ADM EFETUADO COM SUCESSO");
    system("pause");
    system("cls");
}
}

int verificartamanho()
{
    FILE *senha;
    senha = fopen("cadastro.dat", "rb");
    int tamanho;

    fseek(senha,0,SEEK_END);
    tamanho=ftell(senha);
    return tamanho;
}
void teladeLogin()
{
        FILE *senha;
        ADM cad;
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
        if(fread(&cad,sizeof(ADM),1,senha)==1&&!strcmp(cad.login,tentativalogin)&&!strcmp(cad.senha,tentativasenha))
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
    else if((verificartamanho()<=0))
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
                    menuFuncionarios();
                break;
            case 3:
                system("cls");
 //               menuClientes();
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
