/*
  Modulo responsavel por simular um console Unix
  
  Edwino Stein - 1201324411
*/
  
#if !defined stdlib
  #include <stdlib.h>
#endif

#if !defined stdio
  #include <stdio.h>
#endif

#if !defined string
  #include <string.h>
#endif

#if !defined ctype
  #include <ctype.h>
#endif

/* Define os valores booleanos */
#if !defined stdbool
  #include <stdbool.h>
#endif

#include "commands.h"
#include "keyboard.h"

#define CONSOLE_INPUT_SYMBLE " #> "
#define CONSOLE_OUTPUT_SYMBLE "   "
#define CONSOLE_BRACKSPACE "\b \b"
#define NULL_CHAR '\0'

/*
	Definição da estrutura da saida de cada inseção de comando no console
*/
typedef struct input_cmd{
	//Referencia ao nó do comando que está presente na lista de comandos
	cmdNode * statement;

	//Valor do parametro passado junto ao comando
	char * paramValue;
} inputCmd;

/*
	Cria uma lista de comandos que será utilizada na entrada de dados.
	
	Parametros:
		- cmdsPrototype list[]: Array contendo os prototipos dos comandos;
		- int listSize: Tamanho do array de prototipos;

	Retorno: cmdList *: Lista encadeada contendo os comandos prontos para serem utilizados;
*/
cmdList * initCommands(cmdsPrototype list[], int listSize);

/*
	Verifica se um caractere ASCII é imprimivel.

	Parametros:
		- int c: Código ASCII do caractere;

	Retorno: bool: True para quando for imprimivel, false para não imprimivel;
*/
bool charIsPrintable(int c);

/*
	Indentifica o comando e seu parametro apartir de uma string.
	
	Parametros:
		- const char * input: String de entrada;
		- cmdList * cmds: Lista contendo os comandos conhecidos;

	Retorno: inputCmd *: Referencia de um inputCmd, contendo o comando identificado e
						 seu parametro, caso haja.

 	OBS: Um ponteiro NULL será retornado caso o comando não seja indentificado dentro da
 		 lista de comandos.

*/
inputCmd * identifyInput(const char * input, cmdList * cmds);

/*
	Busca comandos que comecem com a string de entrada.
	
	Parametros:
		- const char * input: String de entrada;
		- cmdList * cmds: Lista contendo os comandos conhecidos;

	Retorno: cmdList *: Lista que contem os comandos que começam com a string de entrada.
*/
cmdList * getCmdHint(const char * input, cmdList * cmds);

/*
	Imprime na tela uma Lista de comandos.
	
	Parametros:
		- cmdList * cmds: Lista contendo que será impressa;
*/
void printHintList(cmdList * cmds);

/*
	Ler um comando do usuário e retorna uma referencia de comando e seu parametro, caso seja conhecido.
	
	Parametros:
		- cmdList * cmds: Lista de comando conhecidos;
		- int bufferSize: Tamanho do buffer do teclado;

	Retorno: inputCmd *: Referencia do comando informado e seu parametro, caso haja.

	OBS: Um ponteiro NULL será retornado caso o comando não seja indentificado dentro da
 		 lista de comandos.
*/
inputCmd * getConsoleInput(cmdList * cmds, int bufferSize);
