#include <util.h>

#define __USE_POSIX
#include <limits.h>

#include <unistd.h>
#include <stdlib.h>

char *get_username()
{
	const int max_len = LOGIN_NAME_MAX + 1;
	char *buffer = malloc(max_len * sizeof(char));

	int status = getlogin_r(buffer, max_len);

	return buffer;
}

char *get_hostname()
{
	const int hostname_size = HOST_NAME_MAX + 1;
	char *hostname = malloc(hostname_size * sizeof(char));

	gethostname(hostname, HOST_NAME_MAX);

	return hostname;
}
