#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

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
    char data[11];
    char predileto[60];
    int clientevip;
    int ativo;//1=ativo/0=excluído.
    float gasto;
    ENDERECO end;
};
typedef struct ran RAN;
struct ran{
    char nome[200];
    float gasto;
};

typedef struct adm ADM;// STRUCT DE CADASTRO DE USUÁRIO ADM, DO PROGRAMA.
struct adm
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
        printf("\t\t\t\t Cadastrar clientes ");
        printf("\n\t\t\t***********************************\n");

         printf("Digite o nome do cliente:\n");
        do
        {
            gets(cll.nome);
            if(strcmp(cll.nome,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.nome,"\0")==0);

        printf("\nDigite a data de nascimento do cliente(dd/mm/aaaa) :\n");
        do
        {// laço para caso seja uma data inválida
            fgets(data,11,stdin);
            data[10]='\0';
            if((data[0]>='a' && data[0]<='z')||(data[0]>='A' && data[0]<='Z')||(data[1]>='a' && data[1]<='z')||(data[1]>='A' && data[1]<='Z')||data[2]!='/'||(data[3]>='a' && data[3]<='z')||(data[3]>='A' && data[3]<='Z')||(data[4]>='a' && data[4]<='z')||(data[4]>='A' && data[4]<='Z')||data[5]!='/'||(data[6]>='a' && data[6]<='z')||(data[6]>='A' && data[6]<='Z')||(data[7]>='a' && data[7]<='z')||(data[7]>='A' && data[7]<='Z')||(data[8]>='a' && data[8]<='z')||(data[8]>='A' && data[8]<='Z')||(data[9]>='a' && data[9]<='z')||(data[9]>='A' && data[9]<='Z')){

                printf("%c\nData inválida\n", 7);
            }

            else
            {
                strcpy(cll.data,data);
                break;
            }

        }while(z==3);
        getchar();
        printf("Qual o endereco do cliente?\n");
        printf("Rua?\n");

        do
        {
            gets(cll.end.rua);
            if(strcmp(cll.end.rua,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.end.rua,"\0")==0);

        printf("Bairro?\n");
        do
        {
            gets(cll.end.bairro);
            if(strcmp(cll.end.bairro,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.end.bairro,"\0")==0);

        printf("Cidade?\n");
        do
        {
            gets(cll.end.cidade);
            if(strcmp(cll.end.cidade,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.end.cidade,"\0")==0);

		printf("Numero?\n");
        do{
        fgets(a,5,stdin);
        if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')||(a[1]>='a' && a[1]<='z')||(a[1]>='A' && a[1]<='Z')||(a[2]>='a' && a[2]<='z')||(a[2]>='A' && a[2]<='Z')||(a[3]>='a' && a[3]<='z')||(a[3]>='A' && a[3]<='Z'))
        {
            printf("%c\nData inválida\n", 7);

        }
        else
        {
            cll.end.numero=atoi(a);
            break;
        }
        }while(z==3);
        printf("Digite qual o prato predileto do cliente:\n");
        do
        {
            gets(cll.predileto);
            if(strcmp(cll.predileto,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }

        }while(strcmp(cll.predileto,"\0")==0);

		printf("%s é cliente VIP?(1-sim/ 0-nao)\n", cll.nome);
        scanf("%d", &vip);
        MrMusculo();
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
        MrMusculo();
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
        printf("Digite o nome do cadastrado a ser excluído:\n");
        do
        {
            gets(nome);
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
                printf("Data de nascimento: %s\n", cll.data);
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
                printf("Data de nascimento: %s\n", cll.data);
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

       printf("Digite uma informação a respeito do cadastrado a ser pesquisada:\n");
       do
        {
            gets(nome);
            if(strcmp(nome,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(nome,"\0")==0);
        while(!feof(arquivo)){
        if(fread(&cll,sizeof(CLIENTE),1,arquivo)==1){
        if(cll.ativo==1){
        if(strstr(strlwr(cll.nome),strlwr(nome))||strstr(strlwr(cll.predileto),strlwr(nome))||strstr(strlwr(cll.end.rua),strlwr(nome))||strstr(strlwr(cll.end.bairro),strlwr(nome))||strstr(strlwr(cll.end.cidade),strlwr(nome))||strstr(strlwr(cll.data),strlwr(nome)))
        {
                printf("\n");
                printf("Nome: %s\n", cll.nome);
                printf("Data de nascimento: %s\n", cll.data);
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
    char c, a[5], data[11];
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
                printf("Data de nascimento: %s\n", cll.data);
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
                        fgets(data,11,stdin);
                        data[10]='\0';
                        if((data[0]>='a' && data[0]<='z')||(data[0]>='A' && data[0]<='Z')||(data[1]>='a' && data[1]<='z')||(data[1]>='A' && data[1]<='Z')||data[2]!='/'||(data[3]>='a' && data[3]<='z')||(data[3]>='A' && data[3]<='Z')||(data[4]>='a' && data[4]<='z')||(data[4]>='A' && data[4]<='Z')||data[5]!='/'||(data[6]>='a' && data[6]<='z')||(data[6]>='A' && data[6]<='Z')||(data[7]>='a' && data[7]<='z')||(data[7]>='A' && data[7]<='Z')||(data[8]>='a' && data[8]<='z')||(data[8]>='A' && data[8]<='Z')||(data[9]>='a' && data[9]<='z')||(data[9]>='A' && data[9]<='Z')){

                            printf("%c\nData inválida\n", 7);
                        }

                        else
                        {
                            strcpy(cll.data,data);
                            break;
                        }

                    }while(z==3);

                    break;

                case 3:
                    getchar();
                    printf("Qual o endereco do cliente?\n");
                    printf("Rua?\n");
                    do
                    {
                        gets(cll.end.rua);
                        if(strcmp(cll.end.rua,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.rua,"\0")==0);

                    printf("Bairro?\n");
                    do
                    {
                        gets(cll.end.bairro);
                        if(strcmp(cll.end.bairro,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.bairro,"\0")==0);


                    printf("Cidade?\n");
                    do
                    {
                        gets(cll.end.cidade);
                        if(strcmp(cll.end.cidade,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.cidade,"\0")==0);

                    printf("Numero?\n");
                    do{
                    fgets(a,5,stdin);
                    if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')||(a[1]>='a' && a[1]<='z')||(a[1]>='A' && a[1]<='Z')||(a[2]>='a' && a[2]<='z')||(a[2]>='A' && a[2]<='Z')||(a[3]>='a' && a[3]<='z')||(a[3]>='A' && a[3]<='Z'))
                    {
                        printf("%c\nData inválida\n", 7);

                    }
                    else
                    {
                        cll.end.numero=atoi(a);
                        break;
                    }
                    }while(z==3);
                    break;
                case 4:
                    getchar();
                    printf("Digite qual o prato predileto do cliente:\n");
                    do
                    {
                        gets(cll.predileto);
                        if(strcmp(cll.predileto,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.predileto,"\0")==0);
                    break;

                case 5:
                    printf("%s é cliente VIP?(1-sim/ 0-nao)\n", cll.nome);
                    scanf("%d", &vip);
                    MrMusculo();
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
                        if(strcmp(cll.nome,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");;
                        }
                    }while(strcmp(cll.nome,"\0")==0);

                    printf("\nDigite a data de nascimento do cliente (dd/mm/aa):\n");
                    do
                    {// laço para caso seja uma data inválida
                        fgets(data,11,stdin);
                        data[10]='\0';
                        if((data[0]>='a' && data[0]<='z')||(data[0]>='A' && data[0]<='Z')||(data[1]>='a' && data[1]<='z')||(data[1]>='A' && data[1]<='Z')||data[2]!='/'||(data[3]>='a' && data[3]<='z')||(data[3]>='A' && data[3]<='Z')||(data[4]>='a' && data[4]<='z')||(data[4]>='A' && data[4]<='Z')||data[5]!='/'||(data[6]>='a' && data[6]<='z')||(data[6]>='A' && data[6]<='Z')||(data[7]>='a' && data[7]<='z')||(data[7]>='A' && data[7]<='Z')||(data[8]>='a' && data[8]<='z')||(data[8]>='A' && data[8]<='Z')||(data[9]>='a' && data[9]<='z')||(data[9]>='A' && data[9]<='Z')){

                            printf("%c\nData inválida\n", 7);
                        }

                        else
                        {
                            strcpy(cll.data,data);
                            break;
                        }

                    }while(z==3);
                    getchar();
                    printf("Qual o endereco do cliente?\n");
                    printf("Rua?\n");
                    do
                    {
                        gets(cll.end.rua);
                        if(strcmp(cll.end.rua,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.rua,"\0")==0);

                    printf("Bairro?\n");
                    do
                    {
                    gets(cll.end.bairro);
                        if(strcmp(cll.end.bairro,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.bairro,"\0")==0);

                    printf("Cidade?\n");
                    do
                    {
                        gets(cll.end.cidade);
                        if(strcmp(cll.end.cidade,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }
                    }while(strcmp(cll.end.cidade,"\0")==0);

                    printf("Numero?\n");
                    do{
                        fgets(a,5,stdin);
                        if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')||(a[1]>='a' && a[1]<='z')||(a[1]>='A' && a[1]<='Z')||(a[2]>='a' && a[2]<='z')||(a[2]>='A' && a[2]<='Z')||(a[3]>='a' && a[3]<='z')||(a[3]>='A' && a[3]<='Z'))
                        {
                            printf("%c\nData inválida\n", 7);

                        }
                        else
                        {
                            cll.end.numero=atoi(a);
                            break;
                        }
                        }while(z==3);
                    printf("Digite qual o prato predileto do cliente:\n");
                    do
                    {
                        gets(cll.predileto);
                        if(strcmp(cll.predileto,"\0")==0)
                        {
                            printf("Desculpe mas você não digitou nada...\n");
                        }

                    }while(strcmp(cll.predileto,"\0")==0);

                    printf("%s é cliente VIP?(1-sim/ 0-nao)\n", cll.nome);
                    scanf("%d", &vip);
                    MrMusculo();
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
    char mes[3];
    arquivo = fopen("cliente.dat", "rb");
    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
    else{
        printf("De qual mês deseja saber os aniversariantes? [00-12]\n");
        fgets(mes,3,stdin);
        system("cls");
        printf("Aniversariantes:\n");
        while(fread(&cll,sizeof(CLIENTE),1,arquivo)==1){
            if(cll.data[3]==mes[0]&&cll.data[4]==mes[1]&&cll.ativo==1){
                printf("%s\n", cll.nome);
                printf("%s", cll.data);
                printf("\n--------------------------------------\n");
            }
            else if(cll.data[4]==mes[0]&&cll.ativo==1){
                printf("%s\n", cll.nome);
                printf("%s", cll.data);
                printf("\n--------------------------------------\n");
            }
        }
        fclose(arquivo);
        system("pause");
        system("cls");
    }
}

int criarR()
{
    FILE *arquivo;
    arquivo = fopen("cliente.dat", "rb");
    CLIENTE cll;
    int contador=0;
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(1);
    }

    while(fread(&cll,sizeof(CLIENTE),1,arquivo)==1)
    {
        contador++;
    }
    return contador;
    fclose(arquivo);
}
void setarNULL(CLIENTE cliente[criarR()], RAN ran[criarR()])
{
    int i;
    for(i=0;i<criarR();i++)
        {
            strcpy(cliente[i].nome,"\0");
            strcpy(cliente[i].data,"\0");
            strcpy(cliente[i].predileto,"\0");
            cliente[i].clientevip=0;
            cliente[i].ativo=0;
            cliente[i].gasto=0;
            strcpy(ran[i].nome,"\0");
            ran[i].gasto=0;
        }
}
void criar2(CLIENTE cliente[criarR()], RAN ran[criarR()])
{
    setarNULL(cliente, ran);
    FILE *arquivo;
    arquivo = fopen("cliente.dat", "rb");
    CLIENTE cll;
    int contador=0;
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }

    while(fread(&cll,sizeof(CLIENTE),1,arquivo)==1)
    {
        strcpy(cliente[contador].nome,cll.nome);
        strcpy(cliente[contador].data,cll.data);
        strcpy(cliente[contador].predileto,cll.predileto);
        cliente[contador].clientevip=cll.clientevip;
        cliente[contador].ativo=cll.ativo;
        cliente[contador].gasto=cll.gasto;
        contador++;
    }
    fclose(arquivo);
}


void ranking(CLIENTE cliente[criarR()],RAN ran[criarR()])
{
    int i, j, salvo, maior=0;
    for(j=0;j<criarR()&&strcmp(cliente[j].nome,"\0")!=0;j++)
    {
        for(i=0;i<criarR();i++)
        {
            if(maior<cliente[i].gasto&&(strcmp(cliente[i].nome,ran[i].nome)!=0))
            {
                maior=cliente[i].gasto;
                salvo = i;
            }

    }
    printf("\n%dº colocado\n", j+1);
    printf("\nNome: %s\n", cliente[salvo].nome);
    printf("Gasto: %f", cliente[salvo].gasto);
    printf("\n-----------------------\n");
    strcpy(ran[salvo].nome, cliente[salvo].nome);
    ran[salvo].gasto= cliente[salvo].gasto;

    maior = 0;
    }
    printf("\n");
    system("pause");
    system("cls");

}


            // menu de opções de clientes

void menuClientes()
{
    FILE *arquivo;
    arquivo = fopen("cliente.dat", "rb");
    if(arquivo==NULL)
    {
        FILE *arq;
        arq = fopen("cliente.dat", "wb");
        fclose(arq);
    }
    fclose(arquivo);

    int opmenu;
    do
    {
        criarR();
        CLIENTE cliente[criarR()];
        RAN ran[criarR()];

        printf("\t\t\t************************\n");
        printf("\t\t\t*   Menu de Clientes   *");
        printf("\n\t\t\t************************\n");
        printf("\n\n");
        printf("1 - Cadastrar novo cliente\n");
        printf("2 - Alterar Cadastro\n");
        printf("3 - Lista de Clientes\n");
        printf("4 - Pesquisar cadastrados\n");
        printf("5 - Aniversariantes do mês\n");
        printf("6 - Excluir cadastro\n");
        printf("7 - Ranking de consumo\n");
        printf("0 - Para sair dessa opcao\n");
        printf("\nQual operação deseja realizar?\n");
        scanf("%d", &opmenu);
        MrMusculo();

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
            case 7:
                system("cls");
                criar2(cliente, ran);
                ranking(cliente, ran);
                break;

            default:
                printf("\nOpcao Inválida");
                system("pause");
                system("cls");
    }

    }while(opmenu!=0);
}

#endif // CLIENTES_H_INCLUDED
