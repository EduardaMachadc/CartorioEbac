#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema

{	
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w"(write) significa "escrever"
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,","); //Cria vírgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadatrado: "); //Coletando informações do usuário
	scanf("%s", nome); //Salva na variável string "nome"
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,nome); //Armazenar no arquivo "nome"
	fclose(file); //Fechar arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,","); //Cria vírgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //Coletando informações do usuário
	scanf("%s", sobrenome); //Salva na variável string "sobrenome"
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,sobrenome); //Armazenar no arquivo "sobrenome"
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");  //Abre o arquivo e "a" significa atualizar
	fprintf(file,","); //Cria vírgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cargo); //Salva na variável string "cargo"
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa atualizar
	fprintf(file,cargo); //Armazenar no arquivo "cargo"
	fclose(file); //Fecha o arquivo
	
	
	system("pause"); //Comando de pausa
	
}

int consultar() //Função responsável por consultar usuário no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Fim da criação de variáveis/string
	
	printf("Digite o cpf a ser consultado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //Abre o arquivo 
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" (read) significa "ler"
	
	if(file == NULL) //Se o resultado for nulo = não encontrado
 	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas são as informaçõs do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause"); //Comando de pausa
	}
	
	
}

int deletar()
{	
	//Início da criação de variáveis/string
	char cpf[40];
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informações oo usuário
	scanf("%s", cpf); // %s refere-se a string
	
	remove(cpf); //Deletar usuário
	
	FILE *file; //Abre o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" (read) significa "ler"
	
	if(file == NULL) //Se o resultado for nulo = não encontrado
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
	{		
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //Criando laço de repetição
	{
	
	system("cls"); //Responsável por limpar a tela
		
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\tCARTÓRIO DA EBAC\t \n\n");
		printf("Escolha a opção desejada a seguir:\n\n");
		printf("\t1 - Cadastrar\n");
		printf("\t2 - Consultar\n");
		printf("\t3 - Excluir\n\n\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d",&opcao); //Armazenando a escolha do usuario
	
		system("cls"); //Responsável por limpar a tela
		
		
		switch (opcao) //Inicío da seleção do menu
		{
				case 1:
				registro(); //Chamada de funções
				break;	
				
				case 2:
				consultar(); //Chamada de funções
				break;
				
				case 3:
				deletar(); //Chamada de funções
				break;
				
				default:
				printf("Essa opcao não está disponível\n");
				system("pause");
				break;
		} //Fim da seleção
	
	
	}
}
