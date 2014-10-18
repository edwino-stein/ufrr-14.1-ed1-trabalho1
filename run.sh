 #!/bin/sh

#  run.sh
#  
#  Shellscript para compilar e executar o trabalho 1 de estrutura de dados.
#
#  Versao 1.0
#
#  Created by Edwino Stein on 18/10/14.
#

# ************** Incoações **************

compiler="./compile.sh";

invocation="Trabalho1.c \
dependencies/src/commands.c \
dependencies/src/console.c \
dependencies/src/html.c \
dependencies/src/keyboard.c \
dependencies/src/stack.c";

# ************** Sub-rotinas **************

chmod +x $compiler;
invocation="$compiler $invocation";

echo "********************************************************";
echo "*                                                      *";
echo "*          COMPILANDO E INICIANDO O PROGRAMA           *";
echo "*                                                      *";
echo "********************************************************";
echo "";

rm -R "build/";

bash -c "$invocation";

exit 0