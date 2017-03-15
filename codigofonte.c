typedef struct
{
	char nome[200];	
	float preco;
	int estoque;
	int data[11];   //validade
	int ativo;
}Produto;


void cadastroProduto()// funçao de cadastro de clientes
{
    FILE *arquivo;
    PRODUTO cll;

    int opmenu, z=3;
    arquivo = fopen("produto.dat", "ab");
    char a[5], preço[60];
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
        printf("\t\t\t\t Cadastrar Produto ");
        printf("\n\t\t\t***********************************\n");

        printf("Digite o nome do produto:\n");
        do
        {
            gets(cll.nome);
            if(strcmp(cll.nome,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(cll.nome,"\0")==0);
        
        
        printf("Digite o preço do produto:\n");
                    do{
                    fgets(preço,60,stdin);
                    if((preço[0]>='a' && preço[0]<='z')||(preço[0]>='A' && preço[0]<='Z')||(preço[1]>='a' && preço[1]<='z')||(preço[1]>='A' && preço[1]<='Z')||(preço[2]>='a' && preço[2]<='z')||(preço[2]>='A' && preço[2]<='Z')||(preço[3]>='a' && preço[3]<='z')||(preço[3]>='A' && preço[3]<='Z'))
                    {
                        printf("%c\npreço invalido\n", 7);


                    }
                    else
                    {
                        cll.preço=atof(preço);
                        break;
                    }
                    }while(z==3);
        
		               
		printf("\nDigite a data de validade do produto(dd/mm/aaaa) :\n");
		        do
		        {// laço para caso seja uma data inválida
		            fgets(validade,11,stdin);
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
		        
		        
		        
		printf("Quantos profutos de %s deseja cadastrar?\n", &cll.nome);
        do{
        fgets(a,5,stdin);
        getchar();
        if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')||(a[1]>='a' && a[1]<='z')||(a[1]>='A' && a[1]<='Z')||(a[2]>='a' && a[2]<='z')||(a[2]>='A' && a[2]<='Z')||(a[3]>='a' && a[3]<='z')||(a[3]>='A' && a[3]<='Z'))
        {
            printf("%c\nNumero invalido\n", 7);

        }
        else
        {
            cll.estoque=atoi(a);
            break;
        }
        }while(z==3);



		 cll.ativo=1;
        fwrite(&cll, sizeof(FUNCIONARIO), 1, arquivo);


        printf("Deseja cadastrar um novo funcionario?(1-sim/ 0-nao)\n");
        scanf("%d", &opmenu);
        MrMusculo();
        getchar();
        system("cls");

    }while(opmenu!=0);// lembrar de colocar condição pelo menu.

    fclose(arquivo);
}

}


void excluirCadastro3()
{
    FILE *arquivo;
    PRODUTO cll;
    arquivo = fopen("produto.dat", "r+b");
    int posicao=0, regnum=0;
    char op, desejo,nome[60];
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
    else
    {
        printf("Digite o nome do produto a ser excluído:\n");
        do
        {
            gets(nome);
            if(strcmp(nome,"\n")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(nome,"\n")==0);



		while(fread(&cll,sizeof(PRODUTO),1,arquivo)==1){
		                if(strstr(strlwr(cll.nome),strlwr(nome))&&cll.ativo==1)
		                {
		                printf("\n");
		                printf("Nome: %s\n", cll.nome);
		                printf("Data de validade: %s\n", cll.data);
		                printf("Unidades do produto: %d\n", cll.estoque);
		                printf("Preço por unidade: %f\n", cll.preço);
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
            fseek(arquivo,sizeof(PRODUTO)*(regnum-1),SEEK_SET);
            fwrite(&cll,sizeof(PRODUTO),1,arquivo);
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



void relatorioProdutos()
{
    FILE *arquivo;
    PRODUTO cll;
    arquivo = fopen("produto.dat", "rb");
    int posicao=0, regnum=0;
    char op, desejo,nome[60];
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
	else{
            while(fread(&cll,sizeof(FUNCIONARIO), 1, arquivo)==1)
            {
                if(cll.ativo==1)
                {
					printf("\n");
	                printf("Nome: %s\n", cll.nome);
	                printf("Data de validade: %s\n", cll.data);
	                printf("Unidades do produto: %d\n", cll.estoque);
	                printf("Preço por unidade: %f\n", cll.preço);
	                printf("\n------------------------------------------------------------------\n");
	                
		    	}
     		}
		}
fclose(arquivo);
system("pause");
system("cls");
}


void verProdutos()
{
    FILE *arquivo;
    PRODUTO cll;
    char nome[200], c;
    arquivo = fopen("funcionario.dat", "rb");
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo, arquivo nulo!\n");
        exit(0);
    }
	else
    {
       printf("Digite o nome do produto a ser pesquisado:\n");
       do
        {
            gets(nome);
            if(strcmp(nome,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(nome,"\0")==0);
        
        
        
        while(!feof(arquivo)){
        if(fread(&cll,sizeof(PRODUTO),1,arquivo)==1){
        if(cll.ativo==1){
        if(strstr(strlwr(cll.nome),strlwr(nome))||strstr(strlwr(cll.cpf),strlwr(nome))||strstr(strlwr(cll.end.rua),strlwr(nome))||strstr(strlwr(cll.end.bairro),strlwr(nome))||strstr(strlwr(cll.end.cidade),strlwr(nome))||strstr(strlwr(cll.data),strlwr(nome)))
        {
					printf("\n");
	                printf("Nome: %s\n", cll.nome);
	                printf("Data de validade: %s\n", cll.data);
	                printf("Unidades do produto: %d\n", cll.estoque);
	                printf("Preço por unidade: %f\n", cll.preço);
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






void alterarCadastro3()// alterar cadastro
{
	FILE *arquivo;
    PRODUTO cll;

    int opmenu, z=3;
    arquivo = fopen("produto.dat", "ab");
    char a[5], preço[60];
    char data[11];
    if(arquivo==NULL)// condição de erro
	{
		printf("\nNão foi possível abrir o arquivo, arquivo nulo.");
		exit(0);
	}    
	else
    {
       printf("Digite o nome do produto a ser pesquisado:\n");
       do
        {
            gets(nome);
            if(strcmp(nome,"\0")==0)
            {
                printf("Desculpe mas você não digitou nada...\n");
            }
        }while(strcmp(nome,"\0")==0);
		
		
			
        while(!feof(arquivo)){
        if(fread(&cll,sizeof(PRODUTO),1,arquivo)==1){
		char op;
		        if(strstr(strlwr(cll.nome),strlwr(nome))&&cll.ativo==1)
		        {
					printf("\n");
	                printf("Nome: %s\n", cll.nome);
	                printf("Data de validade: %s\n", cll.data);
	                printf("Unidades do produto: %d\n", cll.estoque);
	                printf("Preço por unidade: %f\n", cll.preço);
	                printf("\n------------------------------------------------------------------\n");
	                printf("\n\nÉ este cadastro que estava procurando?(s/n)");
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
		printf("\n1 - Nome do produto\n");
        printf("2 - Preço do produto\n");
        printf("3 - Data de validade do produto\n");
        printf("4 - Numero de unidades do produto\n");
        printf("5 - Todas as anteriores\n");
		printf("\n\n");
        printf("O que você deseja alterar?\n");
        scanf("%d", &desejo);
        MrMusculo();
        getchar();

            switch(desejo)
            {
                case 1:
                    printf("Digite o nome do produto:\n");
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
                    printf("Digite o preço do produto:\n");
                    do{
                    fgets(preço,60,stdin);
                    if((preço[0]>='a' && preço[0]<='z')||(preço[0]>='A' && preço[0]<='Z')||(preço[1]>='a' && preço[1]<='z')||(preço[1]>='A' && preço[1]<='Z')||(preço[2]>='a' && preço[2]<='z')||(preço[2]>='A' && preço[2]<='Z')||(preço[3]>='a' && preço[3]<='z')||(preço[3]>='A' && preço[3]<='Z'))
                    {
                        printf("%c\npreço invalido\n", 7);


                    }
                    else
                    {
                        cll.preço=atof(preço);
                        break;
                    }
                    }while(z==3);
                    
                    break;

                case 3:
                    printf("\nDigite a data de validade do produto(dd/mm/aaaa) :\n");
		        do
		        {// laço para caso seja uma data inválida
		            fgets(validade,11,stdin);
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

                case 4:
                    printf("Quantos profutos de %s deseja cadastrar?\n", &cll.nome);
        do{
        fgets(a,5,stdin);
        getchar();
        if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')||(a[1]>='a' && a[1]<='z')||(a[1]>='A' && a[1]<='Z')||(a[2]>='a' && a[2]<='z')||(a[2]>='A' && a[2]<='Z')||(a[3]>='a' && a[3]<='z')||(a[3]>='A' && a[3]<='Z'))
        {
            printf("%c\nNumero invalido\n", 7);

        }
        else
        {
            cll.estoque=atoi(a);
            break;
        }
        }while(z==3);
        
        break;

                case 5:
                    printf("Digite o nome do produto:\n");
			        do
			        {
			            gets(cll.nome);
			            if(strcmp(cll.nome,"\0")==0)
			            {
			                printf("Desculpe mas você não digitou nada...\n");
			            }
			        }while(strcmp(cll.nome,"\0")==0);
			        
			        
			        printf("Digite o preço do produto:\n");
			                    do{
			                    fgets(preço,60,stdin);
			                    if((preço[0]>='a' && preço[0]<='z')||(preço[0]>='A' && preço[0]<='Z')||(preço[1]>='a' && preço[1]<='z')||(preço[1]>='A' && preço[1]<='Z')||(preço[2]>='a' && preço[2]<='z')||(preço[2]>='A' && preço[2]<='Z')||(preço[3]>='a' && preço[3]<='z')||(preço[3]>='A' && preço[3]<='Z'))
			                    {
			                        printf("%c\npreço invalido\n", 7);
			
			
			                    }
			                    else
			                    {
			                        cll.preço=atof(preço);
			                        break;
			                    }
			                    }while(z==3);
			        
					               
					printf("\nDigite a data de validade do produto(dd/mm/aaaa) :\n");
					        do
					        {// laço para caso seja uma data inválida
					            fgets(validade,11,stdin);
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
					        
					        
					        
					printf("Quantos profutos de %s deseja cadastrar?\n", &cll.nome);
			        do{
			        fgets(a,5,stdin);
			        getchar();
			        if((a[0]>='a' && a[0]<='z')||(a[0]>='A' && a[0]<='Z')||(a[1]>='a' && a[1]<='z')||(a[1]>='A' && a[1]<='Z')||(a[2]>='a' && a[2]<='z')||(a[2]>='A' && a[2]<='Z')||(a[3]>='a' && a[3]<='z')||(a[3]>='A' && a[3]<='Z'))
			        {
			            printf("%c\nNumero invalido\n", 7);
			
			        }
			        else
			        {
			            cll.estoque=atoi(a);
			            break;
			        }
			        }while(z==3);
			        
			        break;
			        
			        
			        default:
                    printf("\nOPÇÃO INVÁLIDA!!!\n");
                    system("pause");
                    system("cls");
        }
        fseek(arquivo,sizeof(PRODUTO)*(regnum-1),SEEK_SET);
        fwrite(&cll,sizeof(PRODUTO),1,arquivo);
        printf("\n\t****Cadastro atualizado com sucesso...!****");
        printf("\n");
        }
        system("pause");
        system("cls");
    }
    fclose(arquivo);

}




void menuProdutos()
{

    int opmenu;
    do
    {

        printf("\t\t\t************************\n");
        printf("\t\t\t* Menu de Produtos *");
        printf("\n\t\t\t************************\n");
        printf("\n\n");
        printf("1 - Cadastrar novo produto\n");
        printf("2 - Alterar Cadastro\n");
        printf("3 - Lista de produtos\n");
        printf("4 - Pesquisar cadastrados\n");
        printf("5 - Excluir cadastro\n");
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
                cadastroProduto();
                break;
            case 2:
                system("cls");
                alterarCadastro3();
                break;
            case 3:
                system("cls");
                relatorioProdutos();
                break;
            case 4:
                system("cls");
                verProdutos();
                break;
            case 5:
                system("cls");
                excluirCadastro3();
                break;
            default:
                printf("\nOpcao Inválida");
                system("pause");
                system("cls");
    }

    }while(opmenu!=0);
}


