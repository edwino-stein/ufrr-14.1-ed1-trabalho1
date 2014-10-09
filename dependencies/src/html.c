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


char * getHtmlTpl(const char *head, const char *body){

	char *html = strReplece("*HEAD*", head, HTML_TPL);
	html = strReplece("*BODY*", body, html);

	return html;
}

char * getHeadTpl(){

	char *head = strReplece("*TITLE*", TITLE, HEAD_TPL);
	head = strReplece("*CHARSET*", CHARSET, head);
	head = strReplece("*STYLE*", STYLE, head);

	return head;
}

char * getBodyTpl(const char *script){
	char *body = strReplece("*SCRIPT*", script, BODY_TPL);

	return body;
}

/*TODO: Pegar os comandos que foram inseridos pelo usuario*/
char* getScript(){
	return strReplece("*CMDS*", " ", SCRIPT);
}

bool exportHtmlToFile(const char *fileName, const char *content){
	FILE * pFile = fopen(fileName, "w");

	fputs(content, pFile);

	fclose(pFile);

	return true;
}