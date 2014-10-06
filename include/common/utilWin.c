/*
  Funções de utilidade para Sistemas Windows
  
  Edwino Stein - 1201324411
*/

#if !defined stdlib
  #include <stdlib.h>
#endif

#include <windows.h>

/**
 * Função usada para limpar a tela
 */

void sysClear(){
    //Limpa o buffer para IO
    fflush(stdout);
    //Aguarda uma tecla ser precionada no terminal
    system("cls");
    
}

/**
 * Função usada para esperar que o usuario aperte alguma tecla 
 * para continuar a execução do programa
 */

void sysPause(){
    //Limpa o buffer para IO
    fflush(stdout);
    
    //Aguarda uma tecla ser precionada no terminal
    system("pause");
    
}

/*
 * Limpa o buffer do teclado
 */
void flushInput(){
     fflush(stdin);
}

/*
  Procedimento que posiciona o cursor na tela
  
  Parametros:
    int x: Coluna do terminal
    int y: Linha do terminal
*/
void gotoxy(int x, int y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
