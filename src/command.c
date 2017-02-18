#include <sash/command.h>

#include <stdlib.h>

void free_command(struct command *c)
{
	free(c->args);
}
