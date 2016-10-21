#include<stdio.h>
#include<stdlib.h>   // comentar o codigo faz bem! :D
#include<time.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>


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
             // A PARTIR DAQUI   COMEÇA O MEU CÓDIGO!!!
  
  typedef struct
{

    char nome[200];
    int dia, mes, ano;
    char predileto[30];
    char clientevip[200];

}Cliente;

	Cliente cliente[255];
        void cadastroCliente()
		{
            int i=0, vip, opmenu;
			
			do
			{
		  	printf("\t\t\t***********************************\n");
			printf("\t\t\t\t Cadastrar clientes ");
			printf("\n\t\t\t***********************************\n");
			
            		while(strlen(cliente[i].nome)>0){
                        
                        i++;
                        
                    	}
                                            
                	NOME:   printf("Digite o nome do cliente:\n");
                        		gets(cliente[i].nome);
                        
                      

             		NASCIMENTO: printf("Digite a data de nascimento do cliente (dd/mm/aa):\n");
                       	 		scanf("%d/%d/%d", &cliente[i].dia, &cliente[i].mes, &cliente[i].ano);
                        				setbuf(stdin,NULL);
                        
                        	if(isalpha(cliente[i].dia) || isalpha(cliente[i].mes) || isalpha(cliente[i].ano)){
                        		printf("\nData de nascimento inválida, por favor digite novamente.\n");
                        			
                        		goto NASCIMENTO; 
							}
							else if(cliente[i].dia>31|| cliente[i].mes>12 || cliente[i].mes==0 || cliente[i].ano>3500){
								printf("\nData de nascimento inválida, por favor digite novamente.\n");
                        			
                        		goto NASCIMENTO;
							}
                        	
					
                	printf("Digite qual o prato predileto do cliente:\n");
                        		gets(cliente[i].predileto);

            		printf("%s é cliente VIP?(1-sim/ 2-nao)\n", cliente[i].nome);
                        		scanf("%d", &vip);
                    	if(vip==1)
		    	{	
                        	strcpy(cliente[i].clientevip,cliente[i].nome);
		    	}
						
					
            	        printf("Deseja cadastrar um novo cliente?(1-sim/ 2-nao)\n");
            	  			scanf("%d", &opmenu);
            	  			setbuf(stdin,NULL);
          			if(opmenu==1){
					  
                        		system("pause");
                        		system("cls");
                  }	
							
						
        		}while(opmenu!=2);// lembrar de colocar condição pelo menu.
                		system("cls");        	
				menuprincipal();
				
		}
        
            // menu de opções
   
        	void menuprincipal(){
			int opmenu;
                        
            printf("\t\t\t***********************************\n");
			      printf("\t\t\t\t Menu de Cadastro ");
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
			  	case 0: system("cls"); break;
			  	case 1: system("cls"); cadastroCliente(); break;
			  	
			  }
		
        }
        
        main(){
        	menuprincipal();
		}
