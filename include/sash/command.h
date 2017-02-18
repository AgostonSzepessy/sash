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

#ifndef COMMAND_H_DB4A3D34_5F1A_4C25_AAC5_B80866690FE7
#define COMMAND_H_DB4A3D34_5F1A_4C25_AAC5_B80866690FE7

struct command
{
	int num_args;
	char **args;
};

/**
 * @brief free_command Frees the allocated memory that the command struct
 * uses
 * @param c struct to free
 */
void free_command(struct command *c);

#endif // COMMAND_H_DB4A3D34_5F1A_4C25_AAC5_B80866690FE7
