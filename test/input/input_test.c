#include <check.h>
#include <stdlib.h>

#include <sash/input.h>
#include <sash/command.h>

START_TEST(test_input_parsing)
{
	char *input = "echo hello world";

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
