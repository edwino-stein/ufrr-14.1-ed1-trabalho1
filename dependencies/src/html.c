/*
  Implementacao da API para a rasterização de uma página HTML

  Edwino Stein - 1201324411
*/

#include "../header/html.h"

char *strReplece(const char *search, const char *replace, const char *subject){

	char * occurrence = strstr(subject, search);
	if(occurrence == NULL){
		return NULL;
	}

	char * result = (char *) malloc(strlen(subject) + strlen(replace) - strlen(search) + 1);
	if(result == NULL){
		return NULL;
	}

	int i = 0, j = 0;

	while(subject != occurrence){
		result[i] = *subject;
		subject++;
		i++;
	}

	while(replace[j] != '\0'){
		result[i++] = replace[j++];
	}

	subject += strlen(search);

	while (*subject != '\0'){
		result[i++] = *subject;
		subject++;
	}

	result[i] = '\0';

	return result;
}


char * getHtmlTpl(char *head, char *body){

	char *html = strReplece("*HEAD*", head, HTML_TPL);
	char * temp = html;

	html = strReplece("*BODY*", body, html);

	//Limpa a memoria das strings que foram utilizadas na concatenação
	free(temp);
	free(head);
	free(body);
	temp = NULL;
	head = NULL;
	body = NULL;

	return html;
}

char * getHeadTpl(){

	char *head = strReplece("*TITLE*", TITLE, HEAD_TPL);
	char * temp = head;

	head = strReplece("*CHARSET*", CHARSET, head);
	//Limpa a memoria do head de antes do CHARSET ser concatenado
	free(temp);
	temp = head;

	head = strReplece("*STYLE*", STYLE, head);
	//Limpa a memoria do head de antes do STYLE ser concatenado
	free(temp);
	temp = NULL;

	return head;
}

char * getBodyTpl(char *script){
	char *body = strReplece("*SCRIPT*", script, BODY_TPL);

	//Limpa a memoria da strig do script
	free(script);

	return body;
}

char* getScript(char *cmdsJson){
	char *script = strReplece("*CMDS*", cmdsJson, SCRIPT);

	//Limpa a memoria do json
	free(cmdsJson);

	return script;
}

bool exportHtmlToFile(const char *fileName, const char *content){
	FILE * pFile = fopen(fileName, "w");

	fputs(content, pFile);

	fclose(pFile);

	return true;
}