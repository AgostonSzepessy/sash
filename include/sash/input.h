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

#ifndef INPUT_H_2C6A9CFE_83FE_4419_BEFD_E4B888681E1D
#define INPUT_H_2C6A9CFE_83FE_4419_BEFD_E4B888681E1D

struct command;

/**
 * @brief read_line Reads a line from stdin
 * @return char array containing line read
 */
char *read_line(void);

/**
 * @brief parse_line Parses a line read from stdin
 * @param input char array containing text to parse
 * @return array of inputs split by whitespace
 */
struct command *parse_line(char *input);

#endif // INPUT_H_2C6A9CFE_83FE_4419_BEFD_E4B888681E1D
