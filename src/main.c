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

#include <util.h>
#include <input.h>
#include <command.h>

int main(void)
{
	char *username = get_username();
	char *hostname = get_hostname();

	printf("%s@%s $", username, hostname);

	char *input = read_line();

	struct command *parsed_command = parse_line(input);

	for(int i = 0; i < parsed_command->num_args; ++i)
	{
		printf("%s, ", parsed_command->args[i]);
	}

	printf("\n");

	free_command(parsed_command);
	free(input);
	free(username);
	free(hostname);

	return 0;
}
