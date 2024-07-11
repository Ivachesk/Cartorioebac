#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��o de texto por regi�o
#include <string.h>   //bliblioteca respons�vel por cuidar das string

int Registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de variaveis/string
	char Arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	//Final cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", CPF); // %s refere-se a string
	
	strcpy(Arquivo, CPF);  //Respons�vel por copiar os valores das string
	
	FILE *file;  //Cria o arquivo
	file = fopen(Arquivo, "w"); //Cria o arquivo e o "w " significa escrever	
	fprintf(file, CPF); // Salvo o valor da v�riavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(Arquivo,"a"); // cria o arquivo e o "a" significa abrir para grava��o no fim do arquivo
	fprintf(file,","); // Salvo valor da v�riavel
	fclose(file); // fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",Nome);// %s refere-se a string
	
	file = fopen(Arquivo, "a"); // cria o arquivo e o "a" significa abrir para grava��o no fim do arquivo
	fprintf(file,Nome); // Salvo valor da v�riavel
	fclose(file); // fecha o arquivo 
	
	file = fopen(Arquivo,"a"); // cria o arquivo e o "a" significa abrir para grava��o no fim do arquivo
	fprintf(file,",");// Salvo valor da v�riavel
	fclose(file);// fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", Sobrenome); // %s refere-se a string
	
	file = fopen(Arquivo, "a"); // cria o arquivo e o "a" significa abrir para grava��o no fim do arquivo
	fprintf(file, Sobrenome);// Salvo valor da v�riavel
	fclose(file);// fecha o arquivo 
	
	file = fopen(Arquivo,"a"); // cria o arquivo e o "a" significa abrir para grava��o no fim do arquivo
	fprintf(file,","); // Salvo valor da v�riavel
	fclose(file);// fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando informa��o do usu�rio
	scanf("%s", Cargo); // %s refere-se a string
	
	file = fopen(Arquivo, "a"); // cria o arquivo e o "a" significa abrir para grava��o no fim do arquivo
	fprintf(file, Cargo); // Salvo valor da v�riavel
	fclose(file); // fecha o arquivo
	
	system("pause");
	
	
	
		
}

int Consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem 
	
	char CPF[40];
	char Conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abri o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(Conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", Conteudo);
		printf("\n\n");
	}	

	system("pause");
}

int Deletar()
{

	char CPF[40];
	
	printf("Digite o CPF a ser Deletado: ");
	scanf("%s" ,CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}	
int main()
	{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	char senhadigitada[20]="a";  // Supondo que senhadigitada seja uma string de tamanho suficiente	
	int comparacao;
	
	printf("### Cart�rio da EBAC ### \n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
	
	system("cls");
	for(laco=1;laco=1;)
	{
	
			system("cls"); //responsavel por limpar a tela
	
	
	
    		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem 
	
			printf("### Cart�rio da EBAC ### \n \n");  //Inicio do menu 
    		printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1- Resgitrar nomes \n");
			printf("\t2- Consultar nomes \n");
    		printf("\t3- Deletar nomes \n\n"); 
    		printf("\t4- Sair do sistema\n\n");
    		printf("Op��o:");  //Fim do menu 
	
    		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system("cls"); //responsavel por limpar a tela
		
		
			switch(opcao) // inicio da sele��o do menu
			{
				case 1:
				Registro(); // chamada de fun��es
				break;
			
				case 2:
				Consulta();
				break;
			
				case 3:
				Deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;	
			
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;	
			
	
			 	}// fim da sele��o		
		 }		 
    }
    
    else
    printf("Senha Incorreta!");
    
}
