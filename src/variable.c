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

#include <sash/variable.h>
#include <sash/uthash.h>

#include <stdlib.h>

/* Important! Must be initialized to NULL for the hash map to work */
struct variable *variables = NULL;

void set_variable(struct variable *v)
{

}

struct variable *get_variable(char *name)
{
	struct variable *var;

	HASH_FIND_STR(variables, name, var);

	return var;
}

bool delete_variable(char *name)
{
	return true;
}
