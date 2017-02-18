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

	// break input into tokens
	token = strtok(input, SASH_TOKEN_DELIM);

	while(token != NULL)
	{
		// not enough memory; reallocate for more
		if(position == buffsize)
		{
			buffsize += SASH_BUFF_SIZE;
			tokens = realloc(tokens, sizeof(char *) * buffsize);
		}

		tokens[position] = token;
		position++;

		token = strtok(NULL, SASH_TOKEN_DELIM);
	}

	struct command *parsed_command = malloc(sizeof(struct command));

	parsed_command->num_args = position;
	parsed_command->args = tokens;
}
