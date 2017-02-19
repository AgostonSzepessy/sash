/*
	Sash is a basic Unix shell written in C.
	Copyright (C) 2017  Agoston Szepessy

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <sash/builtins.h>
#include <sash/command.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

int (*builtin_func[]) (struct command *cmd) = {
	&sash_cd,
	&sash_help,
	&sash_exit,
	&sash_clear,
	&sash_pwd
};

char *builtin_str[] = {
	"cd",
	"help",
	"exit",
	"clear",
	"pwd"
};

int sash_num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

int sash_cd(struct command *cmd)
{
	if(cmd->args[1] == NULL)
	{
		if(chdir(getenv("HOME")) != 0)
		{
			perror("sash");
		}
	}
	else
	{
		if(chdir(cmd->args[1]) != 0)
		{
			perror("sash");
		}
	}

	return 1;
}

int sash_help(struct command *cmd)
{
	printf("         ZOOOOOOOOOOOOOOOO8ZOOOOOOOOOOOO.\n");
	printf("        ZOOOOOOOOOOOOOOOOOO8OOOOOO8OOOOO.\n");
	printf("        OOOOOOOOOOOOOOOOO8O88OOOOONOOOOOI\n");
	printf("       8OOOOOOOOOOOOOOO8O88D88OOOONOOOOO8.\n");
	printf("       888D88OOOOOOOOOO8O88D88OOOO8O8OOOZ.\n");
	printf("       ODDDDDDDDDDD888=:. .?$OO888$88OOD.\n");
	printf("        N8888D88888888OON.  88888?IOOOO,\n");
	printf("          =8888888888O88888D8888D,D8888.\n");
	printf("            .N88888888888D888888:+888O:.\n");
	printf("                $O888888D888888888O8OO.\n");
	printf("                  .N888D88888888D88OO..\n");
	printf("                     .D88888D88888OO8\n");
	printf("                      D88OO8888D888O.\n");
	printf("                    $D88,..~D88D8OO.\n");
	printf("                  .8OO8,.  ..:?D88.\n");
	printf("                 ?88OOO..  .,D8O8.\n");
	printf("                N8DO8D.  ..,888ZO.\n");
	printf("               8ODD8~..  .:NND8D.\n");
	printf("              888O8D.  .,8N8DND.\n");
	printf("            .7D8DDN?...,DODN88\n");
	printf("            +DD8N8D...,8DDONO8.\n");
	printf("           ODOD8DZ,..,8D8DD8O.\n");
	printf("     8$ ..888N8DD:.,MDD8NDDO.\n");
	printf("     ?O88ODNDN88~~DDDMND88D.\n");
	printf("      O8D8DDN88++8D88N8D8D.\n");
	printf("       888DDDN=8NDNN888DDO.\n");
	printf("       ..DDD8I..NONDN8ONO?.\n");
	printf("         ..DZ.  .?I88DOD8.\n");
	printf("                   ,8D8I.\n");
	printf("                    ....\n");
	printf("\n");
	printf("\n");
	printf("         ___  __ _ ___| |__\n");
	printf("        / __|/ _` / __| '_ \\\n");
	printf("        \\__ \\ (_| \\__ \\ | | |\n");
	printf("        |___/\\__,_|___/_| |_|\n");
	printf("\n");
	printf("sash is Szepessy Agoston's shell\n");
	printf("If you're not sure what a command does type man command_name. If you don't know what man does, type man man.\n");
	printf("\n");
	printf("The following are builtin commands:\n");

	for(int i = 0; i < sash_num_builtins(); ++i)
	{
		printf("%s\n", builtin_str[i]);
	}

	return 1;
}

int sash_exit(struct command *cmd)
{
	return 0;
}

int sash_clear(struct command *cmd)
{
	return 1;
}

int sash_pwd(struct command *cmd)
{
	char *path = malloc(sizeof(char *) * PATH_MAX + 1);

	path = getcwd(path, PATH_MAX + 1);

	printf("%s\n", path);

	free(path);

	return 1;
}
