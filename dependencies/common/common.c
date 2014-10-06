/*
  Funções de utilidade genericas
  
  Edwino Stein - 1201324411
*/

#include "common.h"

/**
 * Funcao responsavel por ler uma cadeia de caracteres
 * Parametros:
 *    - int length : Caso seja um numero positivo diferente de zero,
 *             define o tamanho maximo da string, caso contrario,
 *             define 256 o tamanho maximo da string;

 *  Retorno: char * - Ponteiro de char apontando para string lida;
 */
char *getString(int length) {
  //Caso o length seja menor ou igual a zero, define como sendo 256
  if (length <= 0)
    length = 256;

    char *string;

    //Aloca espaco para a string
  string = malloc(length);
    
  if(!string)
    perror("malloc");
  else{
    flushInput();
    fgets (string, length, stdin);
  }
    
    //tira o caractere enter do final da string
    string[strlen(string)-1] = '\0';


  return string;
}

/**
 * Deixa uma string toda em maiuscula
 * Parametros:
 *    - string s : String que será transformada
 */
void strToUpper(string s){
  int i = 0;
  while(s[i] != '\0'){
    s[i] = toupper(s[i]);
    i++;
  }
}

/**
 * Deixa uma string toda em minuscula
 * Parametros:
 *    - string s : String que será transformada
 */
void strToLower(string s){
  int i = 0;
  while(s[i] != '\0'){
    s[i] = tolower(s[i]);
    i++;
  }
}

/*
  Remove todos os espacos de uma string

  Parametros:
     - string s: String que tera seus espacos removidos
*/
void removeSpaces(string s){
  char temp[strlen(s)+1];

  strcpy(temp, s);

  int i = 0, j = 0;

  while(temp[i] != '\0'){
    if(temp[i] != ' '){
      
      s[j++] = temp[i];

    }
    i++;
  }

  s[j] = '\0';
}

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
bool getBool(char *forTrue, char *forFalse, char *error, int defaultVal){
    char *input;
    
    while(true){
        input = getString(0);
        
        if(strcmp(input, forTrue) == 0){
            return true;
        }
        if(strcmp(input, forFalse) == 0){
            return false;
        }
        
        if(defaultVal == 1){
            return true;
        }
        
        if(defaultVal == 0){
            return false;
        }
        
        printf(error, forTrue, forFalse);
    }
}

/*
  Gera um numero inteiro aleatoriamente maior que zero

  Parametros:
     - int maxValue: Maior valor possivel a ser gerado, em caso de valer zero, não existira limite;

  Retorno: int: numero aleatorio
*/
int randInt (int maxValue){
  static unsigned int currentSeed;

  unsigned int seed = (unsigned) time(NULL);

  //Assegura que a seed não sera igual a ultima seed utilizada
  if(currentSeed ==  seed){
    seed += (rand() % seed) * 2 ;
  }
  else{
    currentSeed = seed;
  }
  
  srand(seed);

  if(maxValue <= 0){
    return rand();
  }

  return rand() % (maxValue + 1);
}

/*
  Gera um caractere aleatoriamente

  Parametros:
     - char maxChar: Maior valor da tabela ASCII do caractere possivel a ser gerado,
                     em caso de valer zero, o limite sera 126 (~);
     - bool printableOnly: Em caso de true, define apenas caracteres imprimiveis;

  Retorno: char: caractere aleatorio
*/
char randChar(char maxChar, bool printableOnly){

  char c;

  char minChar = 0;

  if(printableOnly){
    minChar = 33;
  }

  if((maxChar <= minChar) || (maxChar >= 127)){
    maxChar = 126;
  }

  do{
    c = randInt(maxChar);
  }while(c < minChar || c > maxChar);

  return c;
}

/*
  Gera um numero double aleatoriamente

  Retorno: double: double aleatorio
*/
double randDouble(){
  int i, j;

  do{
    i = randInt(100);
    j = randInt(200);
  }while( (i == j) || (j == 0) );

  return ((double) i)/((double) j);
}

/*
  Gera um valor booleano aleatoriamente

  Retorno: bool: booleano aleatorio
*/
bool randBool(){
  return (randInt(99) % 2 == 0);
}

/*
  Define qual o sistema operacional que o programa sera compilado para poder incluir seus
  respectivos arquivos utilitarios para serem linckadados durante a compilação.

  OBS: Para facilitar a compilação manual, as implementacoes das funcoes sao injetadas neste neste arquivo.
*/

#if defined WIN32
  #include "utilWin.c"
#else
   #include "utilUnix.c"
#endif

