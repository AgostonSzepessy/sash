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

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include <sash/input.h>
#include <sash/command.h>

START_TEST(test_input_parsing)
{
	char *input = malloc(sizeof("echo hello world"));
	strcpy(input, "echo hello world");

	struct command *parsed_input = parse_line(input);

	ck_assert_str_eq(parsed_input->args[0], "echo");
	ck_assert_str_eq(parsed_input->args[1], "hello");
	ck_assert_str_eq(parsed_input->args[2], "world");
}
END_TEST

Suite *input_suite(void)
{
	Suite *suite = suite_create("input");
	TCase *tc_input_parsing = tcase_create("input_parsing");

	tcase_add_test(tc_input_parsing, test_input_parsing);
	suite_add_tcase(suite, tc_input_parsing);

	return suite;
}

int main(int argc, char **argv)
{
	int number_failed;

	Suite *s = input_suite();
	SRunner *sr = srunner_create(s);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
