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
		.statement = "ajuda",
		.paramType = 'n',
		.cmdId = 8,
		.stackable = false,
		.desc = "Exibe este menu de ajuda.",
	},
	{
		.statement = "desfazer",
		.paramType = 'n',
		.cmdId = 6,
		.stackable = false,
		.desc = "Desfaz o último comando realizado.",
	},
	{
		.statement = "desligar",
		.paramType = 'n',
		.cmdId = 0,
		.stackable = true,
		.desc = "Desliga o rastro do pincel.",
	},
	{
		.statement = "gantihorario",
		.paramType = 'i',
		.cmdId = 5,
		.stackable = true,
		.desc = "Gira um número de graus em sentido anti-horário.",
	},
	{
		.statement = "ghorario",
		.paramType = 'i',
		.cmdId = 4,
		.stackable = true,
		.desc = "Gira um número de graus em sentido horário.",
	},
	{
		.statement = "ligar",
		.paramType = 'n',
		.cmdId = 1,
		.stackable = true,
		.desc = "Liga o rastro do pincel.\n\t      O rastro do pincel é ativado por padrão.",
	},
	{
		.statement = "limpatela",
		.paramType = 'n',
		.cmdId = 9,
		.stackable = false,
		.desc = "Limpa a tela do console de comandos.",
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
		.statement = "sair",
		.paramType = 'n',
		.cmdId = 7,
		.stackable = false,
		.desc = "Encerra o console de comandos.",
	},
};