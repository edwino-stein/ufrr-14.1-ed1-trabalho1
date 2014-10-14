/*
  Interface da API de manipulação do teclado
  
  Edwino Stein - 1201324411
*/

#if !defined stdio
  #include <stdio.h>
#endif
  
#if !defined stdlib
  #include <stdlib.h>
#endif

/* Define os valores booleanos */
#if !defined stdbool
  #include <stdbool.h>
#endif

# if defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1
	#if !defined string
	  #include <string.h>
	#endif
#endif

/*
	Define apelidos para algumas teclas utilizando a numeração do padrão ASCII
*/
#define KEY_CTRL_C 3
#define KEY_TAB 9
#define KEY_NLINE 10
#define KEY_RETURN 13
#define KEY_ESC 27
#define KEY_BSPACE 127
#define KEY_UP (-65)
#define KEY_DOWN (-66)
#define KEY_RIGHT (-67)
#define KEY_LEFT (-68)
#define KEY_DEL (-126)

/*
	Muda o comportamento de um terminal Unix para ler caractere por caractere
	e não imprimi-lo diretamente.
*/
void rawConsole();

/*
	Restaura o comportamento de um terminal Unix para travar a leitura e imprimir
	diretamente os caracteres digitados.
*/
void cookedConsole();

/*
	Verifica se existe conteúdo dentro do stream STDIN.

	Retorno: bool - Retorna true para vazio, falso para não vazio;
*/
bool stdinIsEmpty();

/*
	Ler uma tecla pressionada pelo usuário.
	
	OBS: O simbolo referente a tecla não será exibida na saida padrão;
	OBS: Teclas não ASCII terão seus valores negativos, para evitar conflitos;

	Retorno: int - Indentificador ASCII da tecla;
*/
int getKey();
