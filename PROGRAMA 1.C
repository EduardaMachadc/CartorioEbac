#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema

{	
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w"(write) significa "escrever"
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,","); //Cria v�rgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadatrado: "); //Coletando informa��es do usu�rio
	scanf("%s", nome); //Salva na vari�vel string "nome"
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,nome); //Armazenar no arquivo "nome"
	fclose(file); //Fechar arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,","); //Cria v�rgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //Coletando informa��es do usu�rio
	scanf("%s", sobrenome); //Salva na vari�vel string "sobrenome"
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,sobrenome); //Armazenar no arquivo "sobrenome"
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");  //Abre o arquivo e "a" significa atualizar
	fprintf(file,","); //Cria v�rgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cargo); //Salva na vari�vel string "cargo"
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,cargo); //Armazenar no arquivo "cargo"
	fclose(file); //Fecha o arquivo
	
	
	system("pause"); //Comando de pausa
	
}

int consultar() //Fun��o respons�vel por consultar usu�rio no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//In�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser consultado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //Abre o arquivo 
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" (read) significa "ler"
	
	if(file == NULL) //Se o resultado for nulo = n�o encontrado
 	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas s�o as informa��s do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause"); //Comando de pausa
	}
	
	
}

int deletar()
{	
	//In�cio da cria��o de vari�veis/string
	char cpf[40];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��es oo usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	remove(cpf); //Deletar usu�rio
	
	FILE *file; //Abre o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" (read) significa "ler"
	
	if(file == NULL) //Se o resultado for nulo = n�o encontrado
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
	{		
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //Criando la�o de repeti��o
	{
	
	system("cls"); //Respons�vel por limpar a tela
		
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\tCART�RIO DA EBAC\t \n\n");
		printf("Escolha a op��o desejada a seguir:\n\n");
		printf("\t1 - Cadastrar\n");
		printf("\t2 - Consultar\n");
		printf("\t3 - Excluir\n\n\n\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d",&opcao); //Armazenando a escolha do usuario
	
		system("cls"); //Respons�vel por limpar a tela
		
		
		switch (opcao) //Inic�o da sele��o do menu
		{
				case 1:
				registro(); //Chamada de fun��es
				break;	
				
				case 2:
				consultar(); //Chamada de fun��es
				break;
				
				case 3:
				deletar(); //Chamada de fun��es
				break;
				
				case 4:
				printf("Obrigada por utilizar o sistema!\n"); 
				return 0;
				break;
				
				default:
				printf("Essa opcao n�o est� dispon�vel\n");
				system("pause");
				break;
		} //Fim da sele��o
	
	
	}
}
