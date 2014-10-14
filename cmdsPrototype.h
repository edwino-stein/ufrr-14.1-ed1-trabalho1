/*
  Prototipos dos comandos
  
  Edwino Stein - 1201324411
*/

#if !defined _commands_
  #include "../dependencies/header/commands.h"
#endif


cmdsPrototype commands[] = {
	{
		.statement = "null",
		.paramType = 'n',
		.cmdId = -1,
		.stackable = false,
		.desc = "",
	},
	{
		.statement = "desligar",
		.paramType = 'n',
		.cmdId = 0,
		.stackable = true,
		.desc = "Desliga o rastro do pincel.",
	},
	{
		.statement = "ligar",
		.paramType = 'n',
		.cmdId = 1,
		.stackable = true,
		.desc = "Liga o rastro do pincel.\n\t      O rastro do pincel é ativado por padrão.",
	},
	{
		.statement = "pfrente",
		.paramType = 'i',
		.cmdId = 2,
		.stackable = true,
		.desc = "Move um número de unidades para frente.",
	},
	{
		.statement = "ptras",
		.paramType = 'i',
		.cmdId = 3,
		.stackable = true,
		.desc = "Move um número de unidades para trás.",
	},
	{
		.statement = "gdireita",
		.paramType = 'i',
		.cmdId = 4,
		.stackable = true,
		.desc = "Gira um número de graus para a direita.",
	},
	{
		.statement = "gesquerda",
		.paramType = 'i',
		.cmdId = 5,
		.stackable = true,
		.desc = "Gira um número de graus para a esquerda.",
	},
	{
		.statement = "desfazer",
		.paramType = 'n',
		.cmdId = 6,
		.stackable = false,
		.desc = "Desfaz o ultimo comando realizado.",
	},
	{
		.statement = "sair",
		.paramType = 'n',
		.cmdId = 7,
		.stackable = false,
		.desc = "Encerra o console.",
	},
	{
		.statement = "ajuda",
		.paramType = 'n',
		.cmdId = 8,
		.stackable = false,
		.desc = "Exibe essa tela.",
	},
	{
		.statement = "limpatela",
		.paramType = 'n',
		.cmdId = 9,
		.stackable = false,
		.desc = "Limpa a tela do console",
	},
};