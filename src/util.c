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

#include <sash/util.h>

#define __USE_POSIX
#include <limits.h>

#include <unistd.h>
#include <stdlib.h>

char *get_username()
{
	// allocate enough space for the longest possible POSIX username plus 1 for
	// null terminator
	const int max_len = LOGIN_NAME_MAX + 1;
	char *buffer = malloc(max_len * sizeof(char));

	int status = getlogin_r(buffer, max_len);

	return buffer;
}

char *get_hostname()
{
	// allocate enough space for the longest possible POSIX username plus 1 for
	// null terminator
	const int hostname_size = HOST_NAME_MAX + 1;
	char *hostname = malloc(hostname_size * sizeof(char));

	gethostname(hostname, HOST_NAME_MAX);

	return hostname;
}
