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

#include <sash/input.h>
#include <sash/command.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SASH_BUFF_SIZE 64
#define SASH_TOKEN_DELIM " \r\n\t"

char *read_line(void)
{
	char *input = NULL;
	size_t size = 0;

	getline(&input, &size, stdin);

	return input;
}

static void *realloc_memory(void *mem, size_t size)
{
	mem = realloc(mem, sizeof(char *) * size);

	if(!mem)
	{
		fprintf(stderr, "sash: allocation error");
		exit(1);
	}

	return mem;
}

struct command *parse_line(char *input)
{
	int buffsize = SASH_BUFF_SIZE;
	int position = 0;

	char **tokens = malloc(SASH_BUFF_SIZE * sizeof(char *));
	char *token = NULL;

	if(!tokens)
	{
		fprintf(stderr, "sash: failed to allocate memory for parsing");
		exit(1);
	}

	struct command *parsed_command = malloc(sizeof(struct command));

	// break input into tokens
	token = strtok(input, SASH_TOKEN_DELIM);
	parsed_command->cmd = token;

	while(token != NULL)
	{
		// not enough memory; reallocate for more
		if(position >= buffsize)
		{
			buffsize += SASH_BUFF_SIZE;
			tokens = realloc_memory(tokens, buffsize);
		}

		tokens[position] = token;
		position++;

		token = strtok(NULL, SASH_TOKEN_DELIM);
	}

	if(position >= buffsize)
	{
		buffsize += 1;
		tokens = realloc_memory(tokens, buffsize);
	}

	tokens[position] = NULL;

	parsed_command->num_args = position;
	parsed_command->args = tokens;
}
