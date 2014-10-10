/*
  Implementação da API de manipulação do teclado
  
  Edwino Stein - 1201324411
*/

#include "../header/keyboard.h"

bool stdinIsEmpty(){
	return stdin->_r <= 0;
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
