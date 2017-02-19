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

#ifndef BUILTINS_H_459DC012_DB5D_4D11_91FC_78ABC4E46E7F
#define BUILTINS_H_459DC012_DB5D_4D11_91FC_78ABC4E46E7F

struct command;

int sash_cd(struct command *cmd);
int sash_help(struct command *cmd);
int sash_exit(struct command *cmd);
int sash_clear(struct command *cmd);
int sash_pwd(struct command *cmd);

int sash_num_builtins();

#endif // BUILTINS_H_459DC012_DB5D_4D11_91FC_78ABC4E46E7F
