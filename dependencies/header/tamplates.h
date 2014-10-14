/*
  Tamplates base para gerar o código HTML
  
  Edwino Stein - 1201324411
*/

#include "style.h"
#include "script.h"

//Valor da tag <title>
#define TITLE "Trabalho de Estrutura de Dados"

//Codificação do arquivo HTML
#define CHARSET "UTF-8"

//Tamplate Basico HTML
#define HTML_TPL "<!DOCTYPE html>\n\
<html>\n\
	*HEAD*\n\
	*BODY*\n\
</html>"

//Tamplate basico HEAD
#define HEAD_TPL "\n\
<head>\n\
	<title>*TITLE*</title>\n\
	<meta charset=\"*CHARSET*\">\n\
	*STYLE*\n\
</head>"

//Tamplate basico BODY
#define BODY_TPL "\n\
<body>\n\
	<div class=\"top\"><span>1º Trabalho de Estrutura de Dados</span></div>\n\
	<div class=\"container\">\n\
        <div class=\"container-head\">Resultado</div>\n\
        <div class=\"container-body\"><canvas width=\"500\" height=\"500\"></canvas></div>\n\
    </div>\n\
    <div class=\"footer\">\n\
        <p>Desenvolvido por <b>Edwino Stein</b> - 1201324411</p>Boa Vista, Roraima - 2014\n\
    </div>\n\
	*SCRIPT*\n\
</body>"

