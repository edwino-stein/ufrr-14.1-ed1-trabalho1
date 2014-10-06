/*
  TAD Stack (Pilha) utilizando lista encadiada
  
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

/* Define os valores booleanos */
#if !defined stdbool
  #include <stdbool.h>
#endif


// Define o node (no) da lista encadiada que sera utilizada na pilha
typedef struct sNode {
	//Proximo elemento da lista
	struct sNode *next;

	//Valor do elemento
	void *value;
}stackNode;

//Define a estrutura da pilha
typedef struct {
	//Referencia do elemento que esta no topo da pilha
	stackNode * top;

	//Tamanho do tipo de dado que a pilha ira receber
	size_t dataSize;

	//Tamanho maximo da pilha
	unsigned int maxSize;

	//Tamanho atual da pilha
	unsigned int currentSize;
} stack;


/*

  ====================== Funcoes ======================
  
*/

/*
	Instancia e inicializa uma pilha.
	Parametros:
	    size_t dataSize: Tamanho em bytes de um elemento da pilha;
	    unsigned int maxSize: Maximo de itens que a pilha ira receber,
	    					  nao havera limite caso seja definido 0 (zero);

	Retorno: stack * - Retorna uma refenrencia da pilha recem criada;
*/
stack * _newStack(size_t dataSize, unsigned int maxSize);

/*
	Aloca e empilha um elemento vazio na pilha.
	Parametros:
	    stack *s: Pilha onde o referencia será colocada;

	Retorno: bool - True para sucesso, false para fracasso;
*/
bool _pushVoidStack(stack *s);

/*
	Aloca e empilha um elemento com valor definido na pilha.
	Parametros:
	    stack *s: Pilha onde o referencia será colocada;
	    void *data: Referencia onde o valor esta armazenado;

	Retorno: bool - True para sucesso, false para fracasso;
*/
bool _pushStack(stack *s, void *data);

/*
	Desempilha um elemento da pilha e o desaloca da memoria.
	Parametros:
	    stack *s: Pilha onde o elemento sera retirado;

	Retorno: bool - True para sucesso, false para fracasso;
*/
bool _popStack(stack *s);

/*
	Retorna a referencia do elemento no topo da pilha.
	Parametros:
	    stack *s: Pilha onde o elemento sera recuperado;

	Retorno: stackNode * - Referencia do elemento. Em caso de erro, retorna uma referencia NULL;
*/
stackNode * _top(stack *s);

/*
	Verifica se a pilha esta cheia.

	OBS.: Esta funcao so tera utilidade se existir um tamanho maximo definido para a pilha,
	caso contrario sempre ira retornar false.

	Parametros:
	    stack *s: Pilha que sera verificada;

	Retorno: bool;
*/
bool stackIsFull(stack *s);


/*
	Verifica se a pilha esta vazia.

	Parametros:
	    stack *s: Pilha que sera verificada;

	Retorno: bool;
*/
bool stackIsEmpy(stack *s);

/*
	Desempilha todos os elementos da pilha.
	Parametros:
	    stack *s: Pilha que sera limpa;
*/
void cleanStack(stack *s);

/*
	Limpa e destroi a pilha.
	Parametros:
	    stack *s: Pilha que será destruida;
*/
void destroyStack(stack *s);


/*
	Imprime uma representacao da pilha na tela.

	Parametros:
	    stack *s: Pilha que sera imprimida;
	    const char type: Caractere que define o tipo de dado que será imprimido na tela.
	    				 OBS.:Segue o mesmo padrão de simbulos do printf/scanf;
*/
void printStack(stack *s, const char type);


/*

  ====================== Macros ======================
  
  OBS.: Estas macros servem para complementar e automatizar a interface com as pilhas.
*/

/*
	Está macro automatiza e simplifica o processo de empilhar elementos na pilha

	Parametros:
	    stack * stack: Pilha onde o elemento sera empilhado;
	    _value_: Elemento que sera empilhado. OBS: não existe restrições a tipos de
	    	     dados que serão empilhados, porem e aconcelhavel que sejam emplilados
	    	     sempre dados do mesmo tipo em cada pilha, devido aos castings automaticos
	    	     que sao realizado durante as operacoes.

	Retorno: bool - True para sucesso, false para fracasso;
*/
#define pushStack(stack, _value) ((_pushVoidStack(stack)) ? ((_top(stack) != NULL) ? ((*( ( typeof( _value )* ) _top(stack)->value) = _value ) ? true : false ) : false ): false )

/*
	Desempilha o elemento do topo. Simplificação da função _popStack().

	Parametros:
	    stack * stack: Pilha onde o elemento sera desempilhado;

    Retorno: bool - True para sucesso, false para fracasso;
*/
#define popStack(stack) _popStack(stack)

/*
	Retorna o valor do primeiro elemento da pilha.

	Parametros:
	    stack * stack: Pilha onde o elemento esta empilhado;
	    type: Tipo referente ao tipo de dado esperado, para que
	    	  seja realizado um casting antes do valor ser retornado.
	    	  Exemplo: int i = getTop(foo, int);.

	Retorno: Valor do elemento que esta no topo da pilha, em caso de erro, retorna o resultado de: (<tipo>) 0.
*/
#define getTop(stack, type) ( (_top(stack) != NULL) ? ( * ( (type *) _top(stack)->value ) ) : ( (type) 0 ) )

/*
	Instancia e inicializa uma pilha. Simplificação da função _newStack().

	Parametros:
		type: Tipo de dado que sera armazenado na pilha.
	    unsigned int maxSize: Tamanho maximo da pilha;
	    
    Exemplo: stack *s = newStack(int, 10);.

	Retorno: stack * - Retorna uma refenrencia da pilha criada;
*/
#define newStack(type, maxSize) _newStack(sizeof(type), maxSize)
