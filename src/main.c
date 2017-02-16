#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include <util.h>

int main(void)
{
	char *username = get_username();
	char *hostname = get_hostname();

	printf("%s@%s $", username, hostname);

	free(username);
	free(hostname);

	return 0;
}
