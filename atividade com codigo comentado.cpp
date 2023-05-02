#include <stdio.h> //Biblioteca de comunic, com usuario	
#include <stdlib.h> //biblioteca de aloca��o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()  //corpo do programa referente ao registro
{
	setlocale(LC_ALL, "portuguese"); //idioma usado
	char arquivo[10];       
	char cpf[10];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //caixa de texto a definir o cpf
	
	strcpy(arquivo, cpf); //iguala o valor das strings arquivo e cpf
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //acessa o arquivo criado
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //caixa de texto a definir o nome
	
	file = fopen(arquivo, "a"); //acessa o arquivo criado
	fprintf(file,nome); //acessa o arquivo criado e valor inserido 
	fclose(file);
	
	file = fopen(arquivo,"a"); //acessa o arquivo criado
	fprintf(file,","); //acessa o arquivo criado e valor inseriro
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //caixa de texto a definir o sobrenome
	
	file = fopen(arquivo, "a"); //acessa o arquivo criado
	fprintf(file,sobrenome); //acessa o arquivo criado e valor inseriro
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //acessa o arquivo criado
	fprintf(file,","); //acessa o arquivo criado e valor inseriro
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //caixa de texto a definir o cargo
	
	file = fopen(arquivo, "a"); //acessa o arquivo criado
	fprintf(file,cargo); //acessa o arquivo criado e valor inseriro
	fclose(file); //fecha o arquivo
	
	system("pause");
}


int consulta() //corpo do programa referente a consulta
{
	setlocale(LC_ALL, "portuguese");
		char cpf[10];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
				printf("N�o foi possivel abrir o arquivo.\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
				printf("\nEstas s�o as informa��es do usuario:   ");
				printf("%s", conteudo);
				printf("\n\n");
		}
		
		system("pause");
}


int deleta() //corpo do programa referente ao ato de deletar
{
	char cpf[10];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario n�o encontrado!\n");
		system("pause");
	}
	
	if(file != NULL)
	{
		printf("Usuario deletado com sucesso\n");
		system("pause");
	}
}


int main()  //corpo do programa referente a fun��o a ser exercida pelo usuario de acordo com as escolhas do menu
{
	int opcao=0; //Variavel de valor inicial
	int x=1;
	
			for (x=1;x=1;)
	{
		system("cls");
							
				setlocale(LC_ALL, "portuguese"); //Idioma
			
					printf("   Cart�rio da EBAC   \n\n");  //corpo do menu
					printf("Escolha a op��o desejada:\n");
					printf("\t1 - Registrar nome\n");
					printf("\t2 - Consultar nome\n");
					printf("\t3 - Deletar nome\n\n"); //Fim do menu
					printf("Op��o: "); //corpo para inserir texto
			
						scanf("%d", &opcao); //caixa de texto referente a op��o
			
		system("cls");
			
		    	switch(opcao)   //Op�oes e seus valores
			{
			    case 1:
				    registro();
				break;
						
			    case 2:
					consulta();
				break;	
			
			    case 3:
					deleta();	
				break;
				
			    default:
					printf("Voc� escolheu uma ob��o n�o existente!\n");
					system("pause");
				break;
			}
	}
}

