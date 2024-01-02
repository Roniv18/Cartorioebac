#include <stdio.h> // biblioteca de entrada e saída padrão
#include <stdlib.h> // biblioteca de alocação de memória dinâmica
#include <locale.h> // biblioteca para configuração de região
#include <string.h> // biblioteca responsável por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o cpf a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
    FILE *file; //Criar o arquivo no computador
    file = fopen(arquivo, "w"); // Criar o arquivo na pasta
    fprintf(file, "%s", cpf);  // Salvo o valor da variável (// Salva o valor no arquivo)
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
    printf ("Não foi possível abrir o arquivo, não localizado!.\n");	
    }
 
 	while(fgets(conteudo, 200, file) != NULL) 
	{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
	}

	system("pause");
	
	
}

int deletar()
{
	printf("Você escolheu deletar nomes!\n");
}



int main()
{
    int opcao = 0; // Definindo variáveis
    int laco = 1;
    for (laco = 1; laco == 1;)
    {

        setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

        printf("### Cartório da EBAC ###\n\n"); // início do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("opção:"); // fim do menu

        scanf("%d", &opcao); // armazenando a escolha do usuário
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
            printf("Essa opção não está disponível!\n");
            system("pause");
            break;
        }
    }
}
