#include <stdio.h> // biblioteca de entrada e sa�da padr�o
#include <stdlib.h> // biblioteca de aloca��o de mem�ria din�mica
#include <locale.h> // biblioteca para configura��o de regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o cpf a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
    FILE *file; //Criar o arquivo no computador
    file = fopen(arquivo, "w"); // Criar o arquivo na pasta
    fprintf(file, "%s", cpf);  // Salvo o valor da vari�vel (// Salva o valor no arquivo)
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
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
    fprintf(file,  cargo);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];
    
    printf("digite o cpf a ser consultado: ");
    scanf("%s" , cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file ==NULL)
	{
    printf ("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");	
    }
 
 	while(fgets(conteudo, 200, file) != NULL) 
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	}

	system("pause");
	
	
}

int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
}



int main()
{
    int opcao = 0; // Definindo vari�veis
    int laco = 1;
    for (laco = 1; laco == 1;)
    {

        setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

        printf("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("op��o:"); // fim do menu

        scanf("%d", &opcao); // armazenando a escolha do usu�rio
        system("cls");

        switch (opcao)
        {

        case 1:
            registro();
            break;

        case 2:
            consulta();
            break;

        case 3:
            deletar();
            break;

        default:
            printf("Essa op��o n�o est� dispon�vel!\n");
            system("pause");
            break;
        }
    }
}
