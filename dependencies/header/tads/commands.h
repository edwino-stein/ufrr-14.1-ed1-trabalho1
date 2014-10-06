/*
  TAD utilizado definição dos Comandos suportados pela aplicação
  
  Edwino Stein - 1201324411
*/
  
#if !defined stdlib
  #include <stdlib.h>
#endif

#if !defined string
  #include <string.h>
#endif

/* Definição do tipo cmdNode */
typedef struct cmdnode{
	//Indice do node na lista
	int index;

	//Proximo node da lista
	struct cmdnode * next;

	//Statement do comando
	char * command;

	//Tipo de parametro esperado pelo parametro
	char paramType;
} cmdNode;

/* Definição do tipo cmdlist */
typedef struct cmdlist{
	//Primeiro node da lista
	cmdNode * first;

	//Ultimo node da lista
	cmdNode * last;

	//Numero de nodes na lista
	int total;
} cmdList;

/*
	Cria uma lista de comandos

	Retorno: cmdList *: Referencia para uma lista de comandos vazia
*/
cmdList * newCmdList();

/*
	Define um novo comando
	
	Parametros:
		- const char * cmd: Statement do comando;
		- const char paramType: Tipo de parametro esperado pelo comando

	Retorno: cmdNode *: Referencia do novo comando

*/
cmdNode * newCmdNode(const char * cmd, const char paramType);

/*
	Adiciona um comando em uma lista de comandos
	
	Parametros:
		- cmdList * list: Lista do comando;
		- cmdNode * cmd: Comando;
*/
void addCmd(cmdList * list, cmdNode * cmd);

/*
	Pega o primeiro node de uma lista de comandos
	
	Parametros:
		- cmdList * list: Lista do comando;

	Retorno: cmdNode *: Referencia do primeiro node da lista
*/
cmdNode * getFirstCmdNode(cmdList * list);

/*
	Pega o ultimo node de uma lista de comandos
	
	Parametros:
		- cmdList * list: Lista do comando;

	Retorno: cmdNode *: Referencia do ultimo node da lista
*/
cmdNode * getLastCmdNode(cmdList * list);

/*
	Pega o proximo node de uma lista de comandos apartir de um node conhecido
	
	Parametros:
		- cmdNode * cmd: Node de um comando conhecido;

	Retorno: cmdNode *: Referencia do priximo node
*/
cmdNode * getNextCmdNode (cmdNode * cmd);

/*
	Pega um node especifico da lista de comandos atraves de seu indice
	
	Parametros:
		- cmdList * list: Lista do comando;
		- int index: Indice do node na lista de comando;

	Retorno: cmdNode *: Referencia do node referente ao index informado.
*/
cmdNode * getCmdNodeByIndex(cmdList * list, int index);

/*
	Destroi uma lista de comando por completo
	Parametros:
		- cmdList * list: Lista do comando que será destruida;
*/
void destroyCmdList(cmdList * list);
