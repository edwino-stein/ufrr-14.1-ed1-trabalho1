/*
  Implementacao da API para TAD Comandos

  Edwino Stein - 1201324411
*/

#include "../../header/tads/commands.h"

cmdList * newCmdList(){
	cmdList * list = malloc(sizeof(cmdList));

	if(list == NULL){
		perror("malloc");
    	exit(1);
	}

	list->first = NULL;
	list->last = NULL;
	list->total = 0;

	return list;
}

cmdNode * newCmdNode(cmdsPrototype * cmd){
	cmdNode * c = (cmdNode *) malloc(sizeof(cmdNode));

	if(c == NULL){
		perror("malloc");
    	exit(1);
	}

	c->next = NULL;
	c->index = 0;

	c->command = cmd;

	return c;
}

void addCmd(cmdList * list, cmdNode * cmd){
	cmd->index = list->total;

	if(list->total <= 0){		
		list->first = cmd;
		list->last = cmd;
		list->total++;
	}
	else{
		list->last->next = cmd;
		list->last = cmd;
		list->total++;
	}
}

cmdNode * getFirstCmdNode(cmdList * list){
	return list->first;
}

cmdNode * getLastCmdNode(cmdList * list){
	return list->last;
}

cmdNode * getNextCmdNode (cmdNode * cmd){
	return cmd->next;
}

cmdNode * getCmdNodeByIndex(cmdList * list, int index){
	if(list->total <= 0){
		return NULL;
	}

	cmdNode *c = getFirstCmdNode(list);

	while(c != NULL){

		if(c == NULL){
			return NULL;
		}

		if(c->index == index){
			return c;
		}

		c = getNextCmdNode(c);
	}

	return NULL;
}

void destroyCmdList(cmdList * list){
	cmdNode *c = getFirstCmdNode(list);

	while(c != NULL){

		if(c == NULL){
			break;
		}

		list->first = getNextCmdNode(c);

		free(c->command);
		free(c);

		c = getFirstCmdNode(list);
	}

	free(list);
}
