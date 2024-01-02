#include <stdio.h> // biblioteca de entrada e saída padrão
#include <stdlib.h> // biblioteca de alocação de memória dinâmica
#include <locale.h> // biblioteca para configuração de região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/strings
	
	printf("digite o cpf a ser cadastrado:"); // coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string, scanf=scanf=abre funções(armazenamento de informação que o usuário digitou dentro de uma variável ou de uma string)
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
    FILE *file; //Criar o arquivo no computador
    file = fopen(arquivo, "w"); // Criar o arquivo na pasta e "w" significa escrever
    fprintf(file, "%s", cpf);  // Salvo o valor da variável (Salva o valor no arquivo, fprint=file)
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); //abriu o arquivo,"a" é de atualização de informação, não quero abrir um novo arquivo
    fprintf(file, ","); // a vírgula dentro "," é para dá espaço na informação, ex.: 10RonivaldoMartinsAluno ou seja não tem espaço das informações.
    fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string, scanf=scanf=abre funções(armazenamento de informação que o usuário digitou dentro de uma variável ou de uma string)
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); //%s refere-se a string, scanf=scanf=abre funções(armazenamento de informação que o usuário digitou dentro de uma variável ou de uma string)

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); //%s refere-se a string, scanf=abre funções (armazenamento de informação que o usuário digitou dentro de uma variável ou de uma string)

    file = fopen(arquivo, "a"); //Quando você utiliza fopen(arquivo, "a");, está abrindo um arquivo chamado arquivo no modo "append" (acréscimo), pronto para realizar operações de escrita no final do arquivo
    fprintf(file,  cargo); //Escreve o conteúdo da variável cargo no final do arquivo.
    fclose(file); // fechar um arquivo previamente aberto(Fecha o arquivo após as operações de escrita terem sido concluídas.)
    
    file = fopen(arquivo, "a"); //Quando você utiliza fopen(arquivo, "a");, está abrindo um arquivo chamado arquivo no modo "append" (acréscimo), pronto para realizar operações de escrita no final do arquivo
    fprintf(file, ","); //Escreve o conteúdo da variável cargo no final do arquivo.
    fclose(file); // fechar um arquivo previamente aberto(Fecha o arquivo após as operações de escrita terem sido concluídas.)
	
	system("pause"); // o usuário consegue ler as informações (quando você dá enter, as informações fica na tela para que ocê consiga ler)	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];
    
    printf("digite o cpf a ser consultado: ");
    scanf("%s" , cpf); //%s refere-se a string, scanf=abre funções(armazenamento/salva de informação que o usuário digitou dentro de uma variável ou de uma string)
    
    FILE *file; // declaração de uma variável
    file = fopen(cpf, "r"); // abrir o arquivo e ler o que lá está
    
    if(file ==NULL) // comparação, se o que está dentro do arquivo file é igual ou nulo, (comparação), Portanto, ao fazer if (file == NULL), você está verificando se a variável file contém o valor NULL, o que indicaria que houve algum problema ao tentar abrir o arquivo especificado.
	{
    printf ("Não foi possível abrir o arquivo, não localizado!.\n");	
    }
 	while(fgets(conteudo, 200, file) != NULL) //enquanto os 200 caracteres estiver dentro do arquivo filevai, vai buscar o conteudo no arquivo; Esse trecho de código está usando a função fgets() para ler linhas de um arquivo apontado por file e armazená-las na variável conteudo.
	{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo); //%s refere-se a string, scanf=abre funções(armazenamento/salva de informação que o usuário digitou dentro de uma variável ou de uma string)
	printf("\n\n"); //significa que serão impressas duas quebras de linha consecutivas, deixando duas linhas em branco no console quando executado.
	}
	system("pause"); // o usuário consegue ler as informações (quando você dá enter, as informações fica na tela para que ocê consiga ler)
		
}
int deletar() // variável do tipo inteiro
{
	
	char cpf[40];   // variável e a quantidade de caracteres
    
	printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf); //%s refere-se a string, scanf=abre funções(armazenamento/salva de informação que o usuário digitou dentro de uma variável ou de uma string)
    
    remove(cpf); // deletar/romover
    
    FILE *file; //declaração de uma variável
    file = fopen(cpf, "r"); // abrir o arquivo e ler o que lá está
    
    if(file ==NULL) //se o arquivo file é igual ou nulo(comparação), Portanto, ao fazer if (file == NULL), você está verificando se a variável file contém o valor NULL, o que indicaria que houve algum problema ao tentar abrir o arquivo especificado.
    {
    	printf("O usuário não se encontra no sistema, foi deletado com sucesso!.\n"); //\n é para pular linha
    	system ("pause"); // o usuário consegue ler as informações (quando você dá enter, as informações fica na tela para que ocê consiga ler)
	}
}

int main() // função tipo inteiro
{

    int opcao = 0; // Definindo variáveis do tipo inteiro(opção)
    int laco = 1;
    for (laco = 1; laco == 1;)
    {

        setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

        printf("### Cartório da EBAC ###\n\n"); // início do menu
        printf("Escolha a opção desejada do menu:\n\n"); //imprimir o resultado(mostrar o resultado)
        printf("\t1 - Registrar nomes\n"); //imprimir o resultado(mostrar o resultado)
        printf("\t2 - Consultar nomes\n"); //imprimir o resultado(mostrar o resultado)
        printf("\t3 - Deletar nomes\n\n"); //imprimir o resultado(mostrar o resultado)
        printf("\t4 - sair do sistema\n\n");
        printf("opção:"); // fim do menu

        scanf("%d", &opcao); // scanear o que o usuário escreve/pausa o programa, armazenando a variável do tipo ineiro é %d (escolha do usuário)
        
        system("cls"); // responsável por limpar a tela (todos os dados t1, t2, t3...)
        
        switch (opcao) // inicio da seleção do menu (opção é a variável)
        {

        case 1: // os dois(:) pontos é como se fosse abertura de uma chave
            registro(); // chamada de funções
            break; // fechamento de função/chaves, é a quebra do case 1,O break é usado para interromper a execução do loop ou sair de um bloco de controle de fluxo (como um switch-case) e continuar a execução do programa fora desse bloco.

        case 2:
            consulta();
            break; // fechamento de função/chaves, é a quebra do case 2, O break é usado para interromper a execução do loop ou sair de um bloco de controle de fluxo (como um switch-case) e continuar a execução do programa fora desse bloco.

        case 3:
            deletar();
            break; // fechamento de função/chaves, é a quebra do case 3, O break é usado para interromper a execução do loop ou sair de um bloco de controle de fluxo (como um switch-case) e continuar a execução do programa fora desse bloco.
			
			case 4:
			printf("obrigado por utilizar o sistema!\n"); // agradecimento.
			return 0; // quebra laços, funções, quebra tudo, ele sai do sistema.
			break;
			
        default: // é else, é uma resposta para o usário se a variável testada no switch não corresponder a nenhum dos valores especificados nos case anteriores, será exibida a mensagem"Essa opção não está disponível!"
        
            printf("Essa opção não está disponível!\n"); // \n, é para pular linha
            system("pause");// o usuário consegue ler as informações (quando você dá enter, as informações fica na tela para que ocê consiga ler)
            break; //fechamento de função, O break é usado para interromper a execução do loop ou sair de um bloco de controle de fluxo (como um switch-case) e continuar a execução do programa fora desse bloco.
        }
    }
}
