/*
  Implementacao da API para Stack (Pilha) utilizando lista encadiada

  Edwino Stein - 1201324411
*/

#include "../../header/tads/stack.h"

stack * _newStack(size_t dataSize, unsigned int maxSize){

	stack * s = (stack *) malloc(sizeof(stack));

	if(s == NULL){
		perror("malloc");
    	exit(1);
	}

	s->top = NULL;
	s->dataSize = dataSize;
	s->maxSize = maxSize;
	s->currentSize = 0;

	return s;
}

bool _pushVoidStack(stack *s){

	if(stackIsFull(s)){
		return false;
	}

	stackNode * node = (stackNode *) malloc(sizeof(stackNode));
	if(node == NULL){
		perror("malloc");
    	return false;
	}

	node->value = malloc(s->dataSize);
	if(node->value == NULL){
		perror("malloc");
    	return false;
	}

	node->next = s->top;

	s->top = node;

	s->currentSize++;

	return true;
}

bool _pushStack(stack *s, void *data){

	if(!_pushVoidStack(s)){
		return false;
	}

	memcpy(_top(s)->value, data, s->dataSize);

	return true;
}

bool _popStack(stack *s){
	if(stackIsEmpy(s)){
		return false;
	}

	stackNode * nodeTop = _top(s);

	s->top = nodeTop->next;
	s->currentSize--;

	free(nodeTop->value);
	free(nodeTop);

	return true;
}

stackNode * _top(stack *s){
	return s->top;
}

bool stackIsFull(stack *s){

	if(s->maxSize <= 0){
		return false;
	}

	return (bool) (s->currentSize >= s->maxSize);
}

bool stackIsEmpy(stack *s){
	return (bool) (s->currentSize <= 0);
}

void cleanStack(stack *s){
	while(!stackIsEmpy(s)){
		_popStack(s);
	}
}

void destroyStack(stack *s){
	cleanStack(s);
	free(s);
}

void printStack(stack *s, const char type){

	printf("\n\n\t|      TOPO  \t|\n");
	printf("\t+---------------+\n");


	stackNode * node = _top(s);

	while(node != NULL){
		switch(type){
			case 'd':
			case 'i':

				if(*((int *) node->value) == 0){
					printf("\t|             0 |");
				}
				else{
					printf("\t|%14.d |", *((int *) node->value));
				}
			break;
			case 'f':
				printf("\t|\t%f|", *((double *) node->value));
			break;
			case 'c':
				printf("\t|\t%c\t|", *((char *) node->value));
			break;
		}

		printf("\n\t+---------------+\n");
		node = node->next;
	}
}
