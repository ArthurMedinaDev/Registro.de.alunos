#include <stdio.h> //Biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //Biblioteca de aloc��o de empa�o em mem�ria 
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o 
#include <string.h> // Biblioteca respons�vel pela cria��o e organiza��o de strings 


int cadastro() // fun��o respons�vel por cadastrar novos usu�rios 
{
    char arquivo[40]; //cria��o ne vari�veis/strings 
	char id[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //final
	
	printf("Digite o ID que deseja cadastrar: "); //coletando informa��es do usu�rio
	scanf("%s", id);  //%s refere-se a strings, toda vez qeu precisamos salvar uma string
	
	strcpy(arquivo, id);  //Respons�vel por copiar valores das strings 
	
	FILE *file;  // criar um arquivo 
	file = fopen(arquivo, "w");  // abrir o arquivo criado e escrever "w"
	fprintf(file,id);  //salvar o valor da variavel 
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo arquivo criado no modo leitura "a"
	fprintf(file, ","); //Colocando um v�rgula como separa��o 
	fclose(file);  //Fechando o arquivo 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
		
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	char id[40]; //Criando variaveis/strings 
	char conteudo[200]; 
	char *token; //Final 
	
	printf("Digite o ID que seja consultar: ");  //Coletando informa�oes com do usu�rio 
	scanf("%s", id); //Armazenando uma string 
	
	FILE *file; //Criando um arquivo 
	file = fopen(id,"r");  //Abrindo o arquivo no modo leitura
	
	if(file == NULL) 
	{
		printf("Aluno n�o localizado, arquivo inexistente! ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nInforma��es relacionadas ao ID digitado: \n");
		
		token = strtok(conteudo, ",");  //variavel umtilizada para dividir a string em linhas a pertir de um caractere
		printf("ID: %s\n", token);      //informa�oes que vai aparecer antes dos dados coletados 
		
		token = strtok(NULL, ",");   
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n", token);
	}
	
    fclose(file);
	printf("\n\n");
		
	system("pause");	
}

int deletar()
{
	char id[40];
	
	printf("Digite ID do usu�rio que deseja deletar: "); //Coletando informa��es com o usu�rio 
	scanf("%s", id);  //Armazenando uma string 
	
	FILE *file;  //Criando um arquivo 
	file = fopen(id, "r"); //Abrindo o arquivo criado no modo leitura 
	fclose(file);
	
	
    if(file == NULL) //Caso o ID digitado n�o esteja no sistema aparecer� o printf 
	{
	    printf("\nUsu�rio n�o encontrado no sistema!! \n");
	    system("pause");
	}
	else  //Caso o ID digitado esteja no sistema ser� deletado e aparecer� o printf
	{
		remove(id);
		printf("\nUsu�rio deletado com sucesso! \n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao=0; //Definindo vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
	    system("cls"); //Respons�vel por limpar a tela 
	
        setlocale(LC_ALL, "Portuguese"); //Definindo linguagens 
	
	    printf("---- Registro de alunos EBAC ----\n\n");  //In�cio do menu 
 	    printf("Selecione a op��o desejada: \n\n");
	    printf("\t1 - Cadastrar aluno \n");
	    printf("\t2 - Consultar aluno \n");
	    printf("\t3 - Deletar aluno do sistema \n\n"); 
	    printf("Op��o: ");  //Fim do menu 
	
	    scanf("%d" , &opcao); //Armazenando escolha do usu�rio 
	
	    system("cls"); // Respons�vel por limpar a tela 
	    
	    switch(opcao) //Inicio da sele��o do menu
	    {
	    	case 1:
	    	cadastro(); //Chamada de fun��es 
            break;
            
            case 2:
            consulta(); //Chamada de fun��es 
			break;
			
			case 3:
			deletar(); //Chamada de fun��es 
			break;	
			
			default: //Caso o usu�rio digite uma op��o invalida 
		    printf("Op��o invalida!\n");
		    system("pause");      
			break;      
	    }
    }  
    
    return 0;
}
