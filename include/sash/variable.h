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

#ifndef VARIABLE_H_7B3504F3_3BB4_45CA_94B4_25D80DC17635
#define VARIABLE_H_7B3504F3_3BB4_45CA_94B4_25D80DC17635

#include <sash/uthash.h>
#include <stdbool.h>

struct variable
{
	/**
	 * @brief name The name of the variable and also the key into the
	 * hashmap that stores the variables.
	 */
	char *name;

	/**
	 * @brief value The value of the variable.
	 */
	char *value;

	/**
	 * @brief hh Makes this structure hashable.
	 */
	UT_hash_handle hh;
};

/**
 * @brief set_variable Sets the value of an existing {@code variable}, or adds a new
 * one if a {@code variable} with that name doesn't exist yet.
 * @param v {@code variable} to add or set
 */
void set_variable(struct variable *v);

/**
 * @brief get_variable Retrieves the specified {@code variable}, or returns a
 * {@code variable} with {@code name} and @code{value} set to {@code ""}.
 * @param name Name of the @code{variable} to retrieve.
 * @return Specified {@code variable} or a {@code variable} that has {@code name}
 * and {@code value} set to {@code ""}.
 */
struct variable *get_variable(char *name);

/**
 * @brief delete_variable Tries to remove the {@code variable} from the hash map.
 * @param name Name of {@code variable} to remove.
 * @return {@code true} if successful, {@code false} otherwise.
 */
bool delete_variable(char *name);

#endif // VARIABLE_H_7B3504F3_3BB4_45CA_94B4_25D80DC17635
