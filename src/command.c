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

#include <sash/command.h>
#include <sash/builtins.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/wait.h>

extern int (*builtin_func[]) (struct command *cmd);
extern char *builtin_str[];

int launch_process(struct command *cmd)
{
	pid_t pid, wpid;
	int status;

	pid = fork();

	if(pid == 0)
	{
		// child process
		if(execvp(cmd->cmd, cmd->args) == -1)
		{
			perror("sash");
		}
		exit(EXIT_FAILURE);
	}

	else if(pid < 0)
	{
		perror("sash:");
	}
	else
	{
		// parent process
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}

int execute_cmd(struct command *cmd)
{
	if(cmd->cmd == NULL)
	{
		return 1;
	}

	for(int i = 0; i < sash_num_builtins(); ++i)
	{
		if(strcmp(cmd->cmd, builtin_str[i]) == 0)
		{
			return (*builtin_func[i])(cmd);
		}
	}

	return launch_process(cmd);
}

void free_command(struct command *c)
{
	free(c->args);
	free(c);
}
