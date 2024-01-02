#include <stdio.h> // biblioteca de entrada e sa�da padr�o
#include <stdlib.h> // biblioteca de aloca��o de mem�ria din�mica
#include <locale.h> // biblioteca para configura��o de regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/strings
	
	printf("digite o cpf a ser cadastrado:"); // coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string, scanf=scanf=abre fun��es(armazenamento de informa��o que o usu�rio digitou dentro de uma vari�vel ou de uma string)
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
    FILE *file; //Criar o arquivo no computador
    file = fopen(arquivo, "w"); // Criar o arquivo na pasta e "w" significa escrever
    fprintf(file, "%s", cpf);  // Salvo o valor da vari�vel (Salva o valor no arquivo, fprint=file)
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); //abriu o arquivo,"a" � de atualiza��o de informa��o, n�o quero abrir um novo arquivo
    fprintf(file, ","); // a v�rgula dentro "," � para d� espa�o na informa��o, ex.: 10RonivaldoMartinsAluno ou seja n�o tem espa�o das informa��es.
    fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string, scanf=scanf=abre fun��es(armazenamento de informa��o que o usu�rio digitou dentro de uma vari�vel ou de uma string)
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); //%s refere-se a string, scanf=scanf=abre fun��es(armazenamento de informa��o que o usu�rio digitou dentro de uma vari�vel ou de uma string)

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); //%s refere-se a string, scanf=abre fun��es (armazenamento de informa��o que o usu�rio digitou dentro de uma vari�vel ou de uma string)

    file = fopen(arquivo, "a"); //Quando voc� utiliza fopen(arquivo, "a");, est� abrindo um arquivo chamado arquivo no modo "append" (acr�scimo), pronto para realizar opera��es de escrita no final do arquivo
    fprintf(file,  cargo); //Escreve o conte�do da vari�vel cargo no final do arquivo.
    fclose(file); // fechar um arquivo previamente aberto(Fecha o arquivo ap�s as opera��es de escrita terem sido conclu�das.)
    
    file = fopen(arquivo, "a"); //Quando voc� utiliza fopen(arquivo, "a");, est� abrindo um arquivo chamado arquivo no modo "append" (acr�scimo), pronto para realizar opera��es de escrita no final do arquivo
    fprintf(file, ","); //Escreve o conte�do da vari�vel cargo no final do arquivo.
    fclose(file); // fechar um arquivo previamente aberto(Fecha o arquivo ap�s as opera��es de escrita terem sido conclu�das.)
	
	system("pause"); // o usu�rio consegue ler as informa��es (quando voc� d� enter, as informa��es fica na tela para que oc� consiga ler)	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];
    
    printf("digite o cpf a ser consultado: ");
    scanf("%s" , cpf); //%s refere-se a string, scanf=abre fun��es(armazenamento/salva de informa��o que o usu�rio digitou dentro de uma vari�vel ou de uma string)
    
    FILE *file; // declara��o de uma vari�vel
    file = fopen(cpf, "r"); // abrir o arquivo e ler o que l� est�
    
    if(file ==NULL) // compara��o, se o que est� dentro do arquivo file � igual ou nulo, (compara��o), Portanto, ao fazer if (file == NULL), voc� est� verificando se a vari�vel file cont�m o valor NULL, o que indicaria que houve algum problema ao tentar abrir o arquivo especificado.
	{
    printf ("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");	
    }
 	while(fgets(conteudo, 200, file) != NULL) //enquanto os 200 caracteres estiver dentro do arquivo filevai, vai buscar o conteudo no arquivo; Esse trecho de c�digo est� usando a fun��o fgets() para ler linhas de um arquivo apontado por file e armazen�-las na vari�vel conteudo.
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo); //%s refere-se a string, scanf=abre fun��es(armazenamento/salva de informa��o que o usu�rio digitou dentro de uma vari�vel ou de uma string)
	printf("\n\n"); //significa que ser�o impressas duas quebras de linha consecutivas, deixando duas linhas em branco no console quando executado.
	}
	system("pause"); // o usu�rio consegue ler as informa��es (quando voc� d� enter, as informa��es fica na tela para que oc� consiga ler)
		
}
int deletar() // vari�vel do tipo inteiro
{
	
	char cpf[40];   // vari�vel e a quantidade de caracteres
    
	printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf); //%s refere-se a string, scanf=abre fun��es(armazenamento/salva de informa��o que o usu�rio digitou dentro de uma vari�vel ou de uma string)
    
    remove(cpf); // deletar/romover
    
    FILE *file; //declara��o de uma vari�vel
    file = fopen(cpf, "r"); // abrir o arquivo e ler o que l� est�
    
    if(file ==NULL) //se o arquivo file � igual ou nulo(compara��o), Portanto, ao fazer if (file == NULL), voc� est� verificando se a vari�vel file cont�m o valor NULL, o que indicaria que houve algum problema ao tentar abrir o arquivo especificado.
    {
    	printf("O usu�rio n�o se encontra no sistema, foi deletado com sucesso!.\n"); //\n � para pular linha
    	system ("pause"); // o usu�rio consegue ler as informa��es (quando voc� d� enter, as informa��es fica na tela para que oc� consiga ler)
	}
}

int main() // fun��o tipo inteiro
{

    int opcao = 0; // Definindo vari�veis do tipo inteiro(op��o)
    int laco = 1;
    for (laco = 1; laco == 1;)
    {

        setlocale(LC_ALL, "portuguese"); // Definindo a linguagem

        printf("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
        printf("Escolha a op��o desejada do menu:\n\n"); //imprimir o resultado(mostrar o resultado)
        printf("\t1 - Registrar nomes\n"); //imprimir o resultado(mostrar o resultado)
        printf("\t2 - Consultar nomes\n"); //imprimir o resultado(mostrar o resultado)
        printf("\t3 - Deletar nomes\n\n"); //imprimir o resultado(mostrar o resultado)
        printf("\t4 - sair do sistema\n\n");
        printf("op��o:"); // fim do menu

        scanf("%d", &opcao); // scanear o que o usu�rio escreve/pausa o programa, armazenando a vari�vel do tipo ineiro � %d (escolha do usu�rio)
        
        system("cls"); // respons�vel por limpar a tela (todos os dados t1, t2, t3...)
        
        switch (opcao) // inicio da sele��o do menu (op��o � a vari�vel)
        {

        case 1: // os dois(:) pontos � como se fosse abertura de uma chave
            registro(); // chamada de fun��es
            break; // fechamento de fun��o/chaves, � a quebra do case 1,O break � usado para interromper a execu��o do loop ou sair de um bloco de controle de fluxo (como um switch-case) e continuar a execu��o do programa fora desse bloco.

        case 2:
            consulta();
            break; // fechamento de fun��o/chaves, � a quebra do case 2, O break � usado para interromper a execu��o do loop ou sair de um bloco de controle de fluxo (como um switch-case) e continuar a execu��o do programa fora desse bloco.

        case 3:
            deletar();
            break; // fechamento de fun��o/chaves, � a quebra do case 3, O break � usado para interromper a execu��o do loop ou sair de um bloco de controle de fluxo (como um switch-case) e continuar a execu��o do programa fora desse bloco.
			
			case 4:
			printf("obrigado por utilizar o sistema!\n"); // agradecimento.
			return 0; // quebra la�os, fun��es, quebra tudo, ele sai do sistema.
			break;
			
        default: // � else, � uma resposta para o us�rio se a vari�vel testada no switch n�o corresponder a nenhum dos valores especificados nos case anteriores, ser� exibida a mensagem"Essa op��o n�o est� dispon�vel!"
        
            printf("Essa op��o n�o est� dispon�vel!\n"); // \n, � para pular linha
            system("pause");// o usu�rio consegue ler as informa��es (quando voc� d� enter, as informa��es fica na tela para que oc� consiga ler)
            break; //fechamento de fun��o, O break � usado para interromper a execu��o do loop ou sair de um bloco de controle de fluxo (como um switch-case) e continuar a execu��o do programa fora desse bloco.
        }
    }
}
