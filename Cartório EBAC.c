#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
	//Inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo 
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo e o ''a'' significa atualizar
	fprintf(file,","); //salva o valor da variavel
	fclose(file); //fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuario
	scanf("%s", nome); //salvando a informação do usuario ''nome'' na string
	
	file = fopen(arquivo, "a"); //abrir arquivo
	fprintf(file,nome); //salva o valor da variavel "nome"
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file,","); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //Coletando informação do usuario
	scanf("%s",sobrenome); //salvando a informação do usuario "sobrenome" na string
	
	file = fopen(arquivo, "a"); //abrir arquivo
	fprintf(file,sobrenome); //salva o valor da variavel "sobrenome"
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo e atualizar
	fprintf(file,","); //salvar o valor da variavel
	fclose(file); //fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // //Coletando informação do usuario
	scanf("%s",cargo); //salvando a informação do usuario "cargo" na string
	
	file = fopen(arquivo, "a"); //abrir arquivo
	fprintf(file,cargo); //salvar o valor da variavel 
	fclose(file); //fechar o arquivo
	
	system("pause"); //pausar o sistema 
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem em portugues
	
	char cpf[40]; //criando e armazenando o valor da variavel "cpf"
	char conteudo[200]; //criando e armazenando o valor da variavel
	
	printf("Digite o cpf a ser consultado: ");  //Coletando informação do usuario
	scanf("%s",cpf); //salvando a informação do usuario
	
	FILE *file; //abre o arquivo e procura
	file =  fopen(cpf,"r"); //abrir o arquivo e ler "cpf"
	
	if(file == NULL) //SE o resultado for nulo
	{
		printf("Nao localizado!.\n"); //falando pro usuario o cadastro dele nao foi encontrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //ENQUANTO 
	{
		printf("\nEssas sao as informações do usuario: "); //mostrando as informações do usuario
		printf("%s", conteudo); //
		printf("\n\n");
	}
	
	system("pause");

	
		
}

int deletar()
{
	char cpf[40]; //criando o valor da variavel e armazenando ela
	
	printf("Digite o CPF do usuario a ser deletado: "); //Coletando informação do usuario
	scanf("%s", cpf); //salvando as informações do usuario na string
	
	remove(cpf); //removendo o usuario do banco de dados/sistema
	
	FILE *file; //abrir o arquivo e procurar
	file = fopen(cpf, "r"); //abrir o arquivo e ler o cpf
	
	if(file == NULL) //SE o resultado for igual ou nulo
	{
		printf("o usuario nao se encontra no sistema!. \n"); //Falando para o usuario que o "cpf" dele nao foi encontrado no sistema
		system("pause"); //pausa o sistema para o usuario
	}


}






int main()
{
	int opcao=0; //Definindo variaveis 
	int x=1; //variavel x=1
	
	for(x=1;x=1;) //valor inicial da variavel é 1 e o valor final dela é 1 (ou seja, vai ficar repetindo o menu sem ter um limite para o usuario)
	{
		
		system("cls"); //responsavel por limpar a tela
	
      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	 printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	 printf("Escolha a opção desejada do menu: \n\n"); //falando para o usuario escolher a opção 
	 printf("\t1 - Registrar nomes\n"); //opção 1
	 printf("\t2 - Consultar nomes\n"); //opção 2
	 printf("\t3 - Deletar nomes\n\n"); //opção 3
	 printf("\t4 - Sair do Sistema\n");
	 printf("Opção: "); //Fim do menu
	
	scanf("%d" , &opcao); //Armazenando a escolha do usuario
	
	system("cls"); //responsavel por limpar a tela
	
	
    switch(opcao) //incio da seleção do menu
    {
    	case 1:	//caso 1: caso a opção do usuario for a 1 (Registrar Nomes)
    	registro(); //chamada de funções (Registro de Nomes)
		break; //finalizar o case 1
		
		case 2: //caso 2: caso a opção do usuario for a 2 (Consultar Nomes)
		consulta(); //chamada de funções (Consultar Nomes)
    	break; //finalizar o case 2
    	
    	case 3: //caso 3: caso a opção do usuario for a 3 (Deletar Nomes)
    	deletar(); //chamada de funções (Deletar Nomes)
    	break; //finalizar o case 3
    	
    	case 4:
    	printf("Obrigado, até mais!");
    	return 0;
    	
    	default:
    	printf("Os numeros disponiveis para escolha sao os numeros 1, 2 ou 3, a opção escolhida por voce nao esta disponivel");
    	system("pause");
    	break; 
   	}
	



    }
 }
