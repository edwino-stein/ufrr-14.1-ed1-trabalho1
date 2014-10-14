/*
  Implementação da API de manipulação do teclado
  
  Edwino Stein - 1201324411
*/

#include "../header/keyboard.h"

/*
	Implementação desta função teve base a implementação feita pela GNU da função fpurge() na GLIBC.
	Disponivel em <http://www.gnu.org/software/gnulib/coverage/gllib/fpurge.c.gcov.frameset.html> acessado 10/10/14 as 11:23.
*/
bool stdinIsEmpty(){
# if defined _IO_ftrylockfile || __GNU_LIBRARY__ == 1
	/* Compatibilidade com: GNU libc, BeOS, Haiku, Linux libc5 */
	return strlen(stdin->_IO_read_ptr) == strlen(stdin->_IO_read_end);
	
# elif defined __sferror || defined __DragonFly__
	/* Compatibilidade com: FreeBSD, NetBSD, OpenBSD, DragonFly, MacOS X, Cygwin */
	return stdin->_r <= 0;

#else
	/* Caso não haja compatibilidade com os citados acima */
	closeConsole();
	puts("O porte da LIBC do seu sistema operacional não é compativel com este programa :(\n");
	exit(1);
#endif
}

void rawConsole(){
	system("/bin/stty raw");
	system("/bin/stty -echo");
}

void cookedConsole(){
	system("/bin/stty cooked");
	system("/bin/stty echo");
}

int getKey(){
	int key;

	rawConsole();

	key = getchar();
	while(!stdinIsEmpty()){
		key = getchar() * (-1);
	}

	cookedConsole();
	return key;
}
