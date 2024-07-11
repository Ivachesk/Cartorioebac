#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocação de texto por região
#include <string.h>   //bliblioteca responsável por cuidar das string

int Registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio criação de variaveis/string
	char Arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	//Final criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", CPF); // %s refere-se a string
	
	strcpy(Arquivo, CPF);  //Responsável por copiar os valores das string
	
	FILE *file;  //Cria o arquivo
	file = fopen(Arquivo, "w"); //Cria o arquivo e o "w " significa escrever	
	fprintf(file, CPF); // Salvo o valor da váriavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(Arquivo,"a"); // cria o arquivo e o "a" significa abrir para gravação no fim do arquivo
	fprintf(file,","); // Salvo valor da váriavel
	fclose(file); // fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",Nome);// %s refere-se a string
	
	file = fopen(Arquivo, "a"); // cria o arquivo e o "a" significa abrir para gravação no fim do arquivo
	fprintf(file,Nome); // Salvo valor da váriavel
	fclose(file); // fecha o arquivo 
	
	file = fopen(Arquivo,"a"); // cria o arquivo e o "a" significa abrir para gravação no fim do arquivo
	fprintf(file,",");// Salvo valor da váriavel
	fclose(file);// fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", Sobrenome); // %s refere-se a string
	
	file = fopen(Arquivo, "a"); // cria o arquivo e o "a" significa abrir para gravação no fim do arquivo
	fprintf(file, Sobrenome);// Salvo valor da váriavel
	fclose(file);// fecha o arquivo 
	
	file = fopen(Arquivo,"a"); // cria o arquivo e o "a" significa abrir para gravação no fim do arquivo
	fprintf(file,","); // Salvo valor da váriavel
	fclose(file);// fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando informação do usuário
	scanf("%s", Cargo); // %s refere-se a string
	
	file = fopen(Arquivo, "a"); // cria o arquivo e o "a" significa abrir para gravação no fim do arquivo
	fprintf(file, Cargo); // Salvo valor da váriavel
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
		printf("Não foi possivel abri o arquivo, não localizado!. \n");
	}
	
	while(fgets(Conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}	
int main()
	{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	char senhadigitada[20]="a";  // Supondo que senhadigitada seja uma string de tamanho suficiente	
	int comparacao;
	
	printf("### Cartório da EBAC ### \n\n");
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
	
			printf("### Cartório da EBAC ### \n \n");  //Inicio do menu 
    		printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1- Resgitrar nomes \n");
			printf("\t2- Consultar nomes \n");
    		printf("\t3- Deletar nomes \n\n"); 
    		printf("\t4- Sair do sistema\n\n");
    		printf("Opção:");  //Fim do menu 
	
    		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
			system("cls"); //responsavel por limpar a tela
		
		
			switch(opcao) // inicio da seleção do menu
			{
				case 1:
				Registro(); // chamada de funções
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
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;	
			
	
			 	}// fim da seleção		
		 }		 
    }
    
    else
    printf("Senha Incorreta!");
    
}
