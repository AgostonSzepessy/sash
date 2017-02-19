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

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <sash/util.h>
#include <sash/input.h>
#include <sash/command.h>

int main(void)
{
	char *username = get_username();
	char *hostname = get_hostname();

	int status = 1;

	char *input;
	struct command *parsed_command;

	do
	{
		printf("%s@%s $ ", username, hostname);

		input = read_line();

		int input_length = strlen(input);

		parsed_command = parse_line(input);

		status = execute_cmd(parsed_command);

		free_command(parsed_command);
		parsed_command = NULL;

		free(input);
		input = NULL;
	} while(status);

	free(username);
	free(hostname);

	return 0;
}
