/*
	PROGRAMA PRINCIPAL

	Edwino Stein - 1201324411 
*/

#include "dependencies/common/common.h"

#include "dependencies/header/console.h"
#include "dependencies/header/stack.h"
#include "dependencies/header/html.h"
#include "cmdsPrototype.h"

#define LINUX_INVOCATION "sensible-browser > /dev/null %s &"
#define OSX_INVOCATION "open %s"

/*
	Imprime a tela de ajuda
*/
void printHelpScreen(cmdList * cmds);

/*
	Transforma uma pilha de comandos em um array javascript ao estilo json.
*/
char * cmdStackJsonEncode(stack * cmdStack);

/*
	Abre o navegador padrão defininido no Sistema operacional
*/
void openDefaultBrowser(char *fileName);


int main (){
	sysClear();

	/* TODO: Colocar uma mensagem de boas vindas */

	cmdList * cmdsList = initCommands(commands, (int) sizeof(commands)/sizeof(*commands));
	stack * cmdStack = newStack(inputCmd*, 0);
	inputCmd * input = NULL;

	//Laço principal do programa
	while(true){
		input = getConsoleInput(cmdsList, 50);
		putchar('\n');

		if(input == NULL){
			fputs(CONSOLE_OUTPUT_SYMBLE, stdout);
			puts("Comando não encontrado! Tente o comando \"ajuda\" para mais comandos.\n");
			continue;
		}

		if(input->statement->command->cmdId == 7){
			fputs(CONSOLE_OUTPUT_SYMBLE, stdout);
			puts("Console encerrado.\n");
			break;
		}

		if(input->statement->command->cmdId == -1){
			continue;
		}

		if(input->statement->command->cmdId == 6){
			fputs(CONSOLE_OUTPUT_SYMBLE, stdout);

			if(stackIsEmpy(cmdStack)){
				puts("Não existe comando para ser desfeito!\n");
				continue;
			}
			
			printf("O ultimo comando (\"%s\") foi desfeito.\n\n", getTop(cmdStack, inputCmd*)->statement->command->statement);
			popStack(cmdStack);
			continue;
		}

		if(input->statement->command->cmdId == 8){
			printHelpScreen(cmdsList);
		}

		if(input->statement->command->cmdId == 9){
			sysClear();
			continue;
		}

		if(input->statement->command->paramType == 'i'){
			if(input->paramValue == NULL){
				fputs(CONSOLE_OUTPUT_SYMBLE, stdout);
				puts("ERRO: O comando espera um número positivo como parametro!\n");
				continue;
			}

			if(atoi(input->paramValue) <= 0){
				fputs(CONSOLE_OUTPUT_SYMBLE, stdout);
				puts("ERRO: O comando espera um número positivo como parametro!\n");
				continue;
			}
		}

		if(input->statement->command->stackable){
			pushStack(cmdStack, input);
		}
	}

	sysClear();
	char * fileName;
	readString(fileName, "Informe o nome do arquivo html que será gerado: ");
	sprintf(fileName, "%s.html", fileName);
	printf("\nGerando arquivo \"%s\"...", fileName);
	exportHtmlToFile(fileName, getHtmlTpl(getHeadTpl(), getBodyTpl(getScript(cmdStackJsonEncode(cmdStack)))));
	printf("Ok\n\n");
	
	printf("Deseja abrir o arquivo \"%s\" em seu navegador padrão? (sim ou nao): ", fileName);

	if(getBool("sim", "nao", "Sim ou Nao", 0)){
		openDefaultBrowser(fileName);
	}
	sysClear();

	sysPause();
	return 0;
}


/* Implementações */

void printHelpScreen(cmdList * cmds){

	printf("\t***********************************************\n");
	printf("\t*                Tela de Ajuda                *\n");
	printf("\t***********************************************\n");

	cmdNode * c = getFirstCmdNode(cmds);
	puts("\n * Comandos disponiveis:\n");
	while(c != NULL){
		if(c->command->cmdId >= 0){
			printf("\t* %s:\n\t    - Parametro: ", c->command->statement);

			if(c->command->paramType == 'i'){
				printf("Número inteiro positivo.\n");
			}
			else{
				printf("Não exige um parametro.\n");
			}
			printf("\t    - Descrição: %s\n\n", c->command->desc);
		}
		c = getNextCmdNode(c);
	}
	puts("\n * Dica: Pressone a tecla TAB para fornecer dicas e completar os comandos.\n");
}

char * cmdStackJsonEncode(stack * cmdStack){
	int size = 0;

	stack * temp = newStack(inputCmd*, 0);

	while(!stackIsEmpy(cmdStack)){
		size += 23 + (int) strlen(getTop(cmdStack, inputCmd*)->statement->command->statement);
		
		if(getTop(cmdStack, inputCmd*)->statement->command->paramType == 'i'){
			size += (int) strlen(getTop(cmdStack, inputCmd*)->paramValue);
		}
		else{
			size += 4;
		}

		pushStack(temp, getTop(cmdStack, inputCmd*));

		popStack(cmdStack);
	}

	char * json = (char *) malloc(size + 1);

	while(!stackIsEmpy(temp)){
		if(getTop(temp, inputCmd*)->statement->command->paramType == 'i'){
			sprintf(json, "%s{statement:'%s',param:%s},\n", json, getTop(temp, inputCmd*)->statement->command->statement, getTop(temp, inputCmd*)->paramValue);
		}
		else{
			sprintf(json, "%s{statement:'%s',param:null},\n", json, getTop(temp, inputCmd*)->statement->command->statement);
		}

		popStack(temp);
	}

	return json;
}

void openDefaultBrowser(char *fileName){
	char * invocation = NULL;

	#if defined __APPLE__
	//Abre o navegador no mac
	invocation = (char *) malloc(strlen(OSX_INVOCATION) + strlen(fileName) + 1);
	sprintf(invocation, OSX_INVOCATION, fileName);
	#else
	//Abre o navegador em distriuições derivadas do debian
	invocation = malloc(strlen(LINUX_INVOCATION) + strlen(fileName) + 1);
	sprintf(invocation, LINUX_INVOCATION, fileName);
	#endif

	system(invocation);
	free(invocation);
}
