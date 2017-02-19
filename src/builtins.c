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

	return 1;
}
