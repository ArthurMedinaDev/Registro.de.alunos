#include <stdio.h> //Biblioteca de comunicação com o usuário 
#include <stdlib.h> //Biblioteca de alocção de empaço em memória 
#include <locale.h> //Biblioteca de alocação de texto por região 
#include <string.h> // Biblioteca responsável pela criação e organização de strings 


int cadastro() // função responsável por cadastrar novos usuários 
{
    char arquivo[40]; //criação ne variáveis/strings 
	char id[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //final
	
	printf("Digite o ID que deseja cadastrar: "); //coletando informações do usuário
	scanf("%s", id);  //%s refere-se a strings, toda vez qeu precisamos salvar uma string
	
	strcpy(arquivo, id);  //Responsável por copiar valores das strings 
	
	FILE *file;  // criar um arquivo 
	file = fopen(arquivo, "w");  // abrir o arquivo criado e escrever "w"
	fprintf(file,id);  //salvar o valor da variavel 
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo arquivo criado no modo leitura "a"
	fprintf(file, ","); //Colocando um vírgula como separação 
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
	
	printf("Digite o ID que seja consultar: ");  //Coletando informaçoes com do usuário 
	scanf("%s", id); //Armazenando uma string 
	
	FILE *file; //Criando um arquivo 
	file = fopen(id,"r");  //Abrindo o arquivo no modo leitura
	
	if(file == NULL) 
	{
		printf("Aluno não localizado, arquivo inexistente! ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nInformações relacionadas ao ID digitado: \n");
		
		token = strtok(conteudo, ",");  //variavel umtilizada para dividir a string em linhas a pertir de um caractere
		printf("ID: %s\n", token);      //informaçoes que vai aparecer antes dos dados coletados 
		
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
	
	printf("Digite ID do usuário que deseja deletar: "); //Coletando informações com o usuário 
	scanf("%s", id);  //Armazenando uma string 
	
	FILE *file;  //Criando um arquivo 
	file = fopen(id, "r"); //Abrindo o arquivo criado no modo leitura 
	fclose(file);
	
	
    if(file == NULL) //Caso o ID digitado não esteja no sistema aparecerá o printf 
	{
	    printf("\nUsuário não encontrado no sistema!! \n");
	    system("pause");
	}
	else  //Caso o ID digitado esteja no sistema será deletado e aparecerá o printf
	{
		remove(id);
		printf("\nUsuário deletado com sucesso! \n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao=0; //Definindo variáveis 
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
	    system("cls"); //Responsável por limpar a tela 
	
        setlocale(LC_ALL, "Portuguese"); //Definindo linguagens 
	
	    printf("---- Registro de alunos EBAC ----\n\n");  //Início do menu 
 	    printf("Selecione a opção desejada: \n\n");
	    printf("\t1 - Cadastrar aluno \n");
	    printf("\t2 - Consultar aluno \n");
	    printf("\t3 - Deletar aluno do sistema \n\n"); 
	    printf("Opção: ");  //Fim do menu 
	
	    scanf("%d" , &opcao); //Armazenando escolha do usuário 
	
	    system("cls"); // Responsável por limpar a tela 
	    
	    switch(opcao) //Inicio da seleção do menu
	    {
	    	case 1:
	    	cadastro(); //Chamada de funções 
            break;
            
            case 2:
            consulta(); //Chamada de funções 
			break;
			
			case 3:
			deletar(); //Chamada de funções 
			break;	
			
			default: //Caso o usuário digite uma opção invalida 
		    printf("Opção invalida!\n");
		    system("pause");      
			break;      
	    }
    }  
    
    return 0;
}
