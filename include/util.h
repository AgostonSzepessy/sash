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

#ifndef UTIL_H_70F35D73_713A_4829_B884_0C27C325FE24
#define UTIL_H_70F35D73_713A_4829_B884_0C27C325FE24

/**
 * @brief get_username Returns a dynamically allocated char array which
 * contains the username of the logged in user.
 * @return dynamically allocated array containing username
 */
char *get_username();

/**
 * @brief get_hostname Returns a dynamically allocated char array which
 * contains the hostname of the machine.
 * @return dynamically allocated array containing hostname
 */
char *get_hostname();

#endif // UTIL_H_70F35D73_713A_4829_B884_0C27C325FE24
