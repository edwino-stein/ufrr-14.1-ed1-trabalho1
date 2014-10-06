/*
  Funções de utilidade para Sistemas Unix
  
  Edwino Stein - 1201324411
*/

#if !defined stdio
  #include <stdio.h>
#endif
  
#if !defined stdlib
  #include <stdlib.h>
#endif

/* Verifica se o sistema nao for o OSX */
#if !defined __APPLE__
  #if !defined __fpurge
    #include <stdio_ext.h>
    #define fpurge(stream) __fpurge(stream)
  #endif
#endif

/**
 * Função usada para limpar a tela
 */

void sysClear(){
    //Limpa o buffer para IO
    fflush(stdout);
    
    //Imprime caractere que limpa o terminal
    printf("\033c");    
}

/**
 * Função usada para esperar que o usuario aperte alguma tecla 
 * para continuar a execução do programa
 */

void sysPause(){
  printf("Pressione qualquer tecla para continuar...");
  
    //Limpa o buffer para IO
    fflush(stdout);
    
    //Aguarda uma tecla ser precionada no terminal
    system("read KEYPRESS");
    
}

/*
    Limpa o buffer de Input
*/
void flushInput(){
    fpurge(stdin);
}


/*
  Procedimento que posiciona o cursor na tela
  
  Parametros:
    int x: Coluna do terminal
    int y: Linha do terminal
*/
void gotoxy(int x, int y){
  printf("\033[%d;%dH",y,x);
}
