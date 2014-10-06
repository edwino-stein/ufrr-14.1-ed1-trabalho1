/*
  Macro e funcoes de utilidade geral
  
  Revisao: 0012

  Edwino Stein - 1201324411
*/

#if !defined stdio
  #include <stdio.h>
#endif
  
#if !defined stdlib
  #include <stdlib.h>
#endif

#if !defined string
  #include <string.h>
#endif

#if !defined ctype
  #include <ctype.h>
#endif

#if !defined time
  #include <time.h>
#endif

/* Define os valores booleanos */
#if !defined stdbool
  #include <stdbool.h>
#endif


/* Define um tipo para strings */
typedef char * string;

/*

  ====================== Funcoes ======================
  
*/

/**
 * Função usada para limpar a tela
 */
void sysClear();

/**
 * Função usada para esperar que o usuario aperte alguma tecla 
 * para continuar a execução do programa
 */
void sysPause();

/*
    Limpa o buffer de Input
*/
void flushInput();

/*
  Procedimento que posiciona o cursor na tela
  
  Parametros:
    int x: Coluna do terminal
    int y: Linha do terminal
*/
void gotoxy(int x, int y);

/**
 * Funcao responsavel por ler uma cadeia de caracteres
 * Parametros:
 *    - int length : Caso seja um numero positivo diferente de zero,
 *             define o tamanho maximo da string, caso contrario,
 *             define 256 o tamanho maximo da string;

 *  Retorno: char * - Ponteiro de char apontando para string lida;
 */
char *getString(int length);

/**
 * Deixa uma string toda em maiuscula
 * Parametros:
 *    - string s : String que será transformada
 */
void strToUpper(string s);

/**
 * Deixa uma string toda em minuscula
 * Parametros:
 *    - string s : String que será transformada
 */
void strToLower(string s);

/*
  Remove todos os espacos de uma string

  Parametros:
     - string s: String que tera seus espacos removidos
*/
void removeSpaces(string s);

/**
 * Funcao responsavel por ler um valor booleano.
 * O valor booleano sera retornado de acordo com seu respectivo significado
 * Parametros:
 *    - char *forTrue: String para quando o valor for veradeiro
 *      - char *forFalse: String para quando o valor for falso
 *      - char *erro: String que sera mostrada caso o valor informado não seja igual a forTrue ou forFalse
 *      - int defaultVal: Define se sera retornado true(caso seja definido 1) ou false(caso seja definido 0) 
 *                        caso o valor informado nao seja igual a forTrue ou forFalse. 
 *                        Se for diferente de 1 ou 0, nao existira valor padrao.
 *                        
 *  Retorno: bool - Valor booleano que e representado por forTrue ou forFalse
 */
bool getBool(char *forTrue, char *forFalse, char *error, int defaultVal);

/*
  Gera um numero inteiro aleatoriamente maior que zero

  Parametros:
     - int maxValue: Maior valor possivel a ser gerado, em caso de valer zero, não existira limite;

  Retorno: int: numero aleatorio
*/
int randInt (int maxValue);

/*
  Gera um caractere aleatoriamente

  Parametros:
     - char maxChar: Maior valor da tabela ASCII do caractere possivel a ser gerado,
                     em caso de valer zero, o limite sera 126 (~);
     - bool printableOnly: Em caso de true, define apenas caracteres imprimiveis;

  Retorno: char: caractere aleatorio
*/
char randChar(char maxChar, bool printableOnly);

/*
  Gera um numero double aleatoriamente

  Retorno: double: double aleatorio
*/
double randDouble();

/*
  Gera um valor booleano aleatoriamente

  Retorno: bool: booleano aleatorio
*/
bool randBool();

/*

  ====================== Macros ======================

*/

/**
 *	Macro usada para mostrar uma mensagem na tela e em seguida realizar a leitura de um valor inteiro.
 *  Parametros:
 *		- int var : variavel onde o valor ira ser armazenado;
 *		- char *stringFormat : string a ser exibida antes da leitura;
 *		- ... : parametros que serao concatenados a *stringFormat;
 */
#define readInt(var, stringFormat, ...)\
		printf(stringFormat, ##__VA_ARGS__);\
		flushInput();\
		scanf("%d", &var)

/**
 *	Macro usada para mostrar uma mensagem na tela e em seguida realizar a leitura de um valor de ponto flutuante.
 *  Parametros:
 *		- float var : variavel onde o valor ira ser armazenado;
 *		- char *stringFormat : string a ser exibida antes da leitura;
 *		- ... : parametros que serao concatenados a *stringFormat;
 */
#define readFloat(var, stringFormat, ...)\
		printf(stringFormat, ##__VA_ARGS__);\
		flushInput();\
		scanf("%f", &var)

/**
 *	Macro usada para mostrar uma mensagem na tela e em seguida realizar a leitura de um valor caracterer.
 *  Parametros:
 *		- char var : variavel onde o valor ira ser armazenado;
 *		- char *stringFormat : string a ser exibida antes da leitura;
 *		- ... : parametros que serao concatenados a *stringFormat;
 */
#define readChar(var, stringFormat, ...)\
		printf(stringFormat, ##__VA_ARGS__);\
		flushInput();\
		scanf("%c", &var)

/**
 *	Macro usada para mostrar uma mensagem na tela e em seguida realizar a leitura de um valor de cadeia de caracterer.
 *  Parametros:
 *		- char *var : variavel onde o valor ira ser armazenado;
 *		- char *stringFormat : string a ser exibida antes da leitura;
 *		- ... : parametros que serao concatenados a *stringFormat;
 */
#define readString(var, stringFormat, ...)\
		printf(stringFormat, ##__VA_ARGS__);\
		var = getString(0)
