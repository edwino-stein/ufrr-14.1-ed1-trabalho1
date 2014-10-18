/*
  Implementação do Modulo console 

  Edwino Stein - 1201324411
*/

#include "../header/console.h"

cmdList * initCommands(cmdsPrototype list[], int listSize){
	cmdList *cmdList = newCmdList();

	int i;
	for(i = 0; i < listSize; i++){
		addCmd(cmdList, newCmdNode(&list[i]));
	}

	return cmdList;
}

bool charIsPrintable(int c){
	return (c >= 20 && c <= 126);
}

inputCmd * identifyInput(const char * input, cmdList * cmds){
	int inputLen = strlen(input), i = 0;

	char * statement = (char *) malloc(inputLen);

	if(statement == NULL){
		perror("malloc");
		exit(1);
	}

	while(input[i] != ' ' && input[i] != NULL_CHAR){
		statement[i] = input[i];
		i++;
	}
	statement[i] = '\0';

	while(input[i] == ' '){
		if(input[i++] == '\0'){
			break;
		}
	}

	cmdNode * c = getFirstCmdNode(cmds);

	while(c != NULL){
		if(strcmp(statement, c->command->statement) == 0){
			break;
		}
		c = getNextCmdNode(c);
	}
	
	if(c == NULL){
		return NULL;
	}

	char * param = NULL;
	if(c->command->paramType != 'n'){

		param = (char *) malloc(inputLen - i + 1);
		if(param == NULL){
			perror("malloc");
    		exit(1);
		}

		int j = 0;

		while(input[i] != NULL_CHAR && input[i] !=  ' '){
			param[j++] = input[i++];
		}
		param[j] = '\0';

		if(strlen(param) <= 0){
			free(param);
			param = NULL;
		}
	}

	inputCmd * iCmd = (inputCmd *) malloc(sizeof(inputCmd));

	if(iCmd == NULL){
		perror("malloc");
    	exit(1);
	}

	iCmd->statement = c;
	iCmd->paramValue = param;

	return iCmd;
	
}

cmdList * getCmdHint(const char * input, cmdList * cmds){

	cmdNode * c = getFirstCmdNode(cmds);

	cmdList * hintCmds = newCmdList();

	char *p = NULL;

	while(c != NULL){

		if(c->command->cmdId >= 0){
			p = strstr(c->command->statement, input);

			if(p == &c->command->statement[0]){
				addCmd(hintCmds, newCmdNode(c->command));
			}
		}

		c = getNextCmdNode(c);
	}

	return hintCmds;
}

void printHintList(cmdList * cmds){
	cmdNode * c = getFirstCmdNode(cmds);
	int i = 0;
	printf("\n%sDica: ", CONSOLE_OUTPUT_SYMBLE);
	while(c != NULL){
		printf("%s, ", c->command->statement);
		i++;

		if(i >= 6){
			i = 0;
			printf("\n%s      ", CONSOLE_OUTPUT_SYMBLE);
		}
		c = getNextCmdNode(c);
	}
	puts("\b\b.\n");
}

inputCmd * getConsoleInput(cmdList * cmds, int bufferSize){
	if(bufferSize <= 0){
		bufferSize = 50;
	}

	int bufferPointer = 0;
	char buffer[bufferSize], key;

	strcpy(buffer, "");

	cmdList * hint = NULL;

	fputs(CONSOLE_INPUT_SYMBLE, stdout);

	while((key = getKey()) != KEY_RETURN){

		switch(key){

			case KEY_BSPACE :
				if(bufferPointer <= 0){
					continue;
				}

				buffer[--bufferPointer] = NULL_CHAR;
				fputs(CONSOLE_BRACKSPACE, stdout);
			break;

			case KEY_TAB:
				hint = getCmdHint(buffer, cmds);

				if(hint->total <= 0){
					continue;
				}

				if(hint->total > 1){
					printHintList(hint);

					fputs(CONSOLE_INPUT_SYMBLE, stdout);
					fputs(buffer, stdout);
				}
				else{
					strcpy(buffer, getFirstCmdNode(hint)->command->statement);
					bufferPointer = strlen(buffer);
					buffer[bufferPointer++] = ' ';
					buffer[bufferPointer] = '\0';

					
					if(getFirstCmdNode(hint)->command->paramType == 'i'){
						printf("\n\n%sDica: O \"%s\" comando exige um número positivo como parametro.\n", CONSOLE_OUTPUT_SYMBLE, getFirstCmdNode(hint)->command->statement);
					}

					printf("\n%s%s", CONSOLE_INPUT_SYMBLE, buffer);
				}

			break;

			default:
				if(bufferPointer >= bufferSize){
					continue;
				}

				if(charIsPrintable(key)){
					key = tolower(key);
					putchar(key);
					buffer[bufferPointer++] = key;
					buffer[bufferPointer] = NULL_CHAR;
				}
				
		}
	}

	if(bufferPointer <= 0){
		return identifyInput("null", cmds);
	}

	return identifyInput(buffer, cmds);
}
