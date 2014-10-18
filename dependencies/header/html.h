/*
  Modulo responsavel por rasterizar o HTML
  
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

/* Define os valores booleanos */
#if !defined stdbool
  #include <stdbool.h>
#endif

#include "tamplates.h"

/*
	Substitui um trecho de uma string.
	
	Parametros:
		- const char * search: Pedaço da string que será subistituida;
		- const char * replace: String que será inserida no lugar de search;
		- const char * subject: String que será alterada;

	Retorno: char *: String resultante da troca de search por replace;
*/
char *strReplece(const char *search, const char *replace, const char *subject);

/*
	Gera o template basico de uma página HTML.
	
	Parametros:
		- const char * head: Elemento Head do HTML;
		- const char * body: Elemento Body do HTML;

	Retorno: char *: String que contem uma página HTML;
*/
char * getHtmlTpl(char *head, char *body);

/*
	Gera o template basico do elemento Head.

	Retorno: char *: String que contem o elemento Head;
*/
char * getHeadTpl();

/*
	Gera o template basico do elemento Body.
	
	Parametros:
		- const char * script: String contendo uma tag Script;

	Retorno: char *: String que contem o elemento Body;
*/
char * getBodyTpl(char *script);

/*
	Gera uma tag Script contento um techo de codigo javascript.

	Retorno: char *: String que contem uma tag Script;
*/
char* getScript();

/*
	Grava um tamplate HTML em uma arquivo
	
	Parametros:
		- const char * fileName: Nome do arquivo que será gravado;
		- const char * content: Conteudo do arquivo;
	
	Retorno: bool: True em caso de sucesso, false em caso de falha;
*/
bool exportHtmlToFile(const char *fileName, const char *content);
