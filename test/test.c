/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             ::      ::    ::   */
/*                                                    : :         :     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    #  :       #        */
/*                                                #####   #           */
/*   Created: 2022/04/02 03:54:40 by bbonaldi          ##    ##             */
/*   Updated: 2022/04/01 23:58:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	run_test_ctype_char(char *string_test, int (*result_function)(int),
						int (*expected_function)(int))
{
	int	result;
	int	expected;

	while (*string_test)
	{
		result = result_function(*string_test);
		if ((expected_function(*string_test) == 0))
		{
			expected = 0;
		}
		else
		{
			expected = 1;
		}
		cr_expect(result == expected,
			"arg value: %c, result:%d != expect:%d",
			*string_test, result, expected);
		string_test++;
	}
}

void	run_test_ctype_string(char **string_test, size_t (*result_function)(const char *),
						size_t (*expected_function)(const char *))
{
	int	result;
	int	expected;

	while(*string_test)
	{
		result = result_function(*string_test);
		expected = expected_function(*string_test);
		cr_expect(result == expected,
			"arg value: %s, result:%d != expect:%d",
			*string_test, result, expected);
		string_test++;
	}
}

Test(test_ctype, ft_isalpha_test)
{
	char *tests_values;

	tests_values = "DNAKLDLAK 12DNAK 3\n\t";
	run_test_ctype_char(tests_values, &ft_isalpha, &isalpha);
}

Test(test_ctype, ft_isdigit_test)
{
	char *tests_values;

	tests_values = "DNAKLDLA313131r532K 12DNAK 3\n\t";
	run_test_ctype_char(tests_values, &ft_isdigit, &isdigit);
}

Test(test_ctype, ft_isascii_test)
{
	char *tests_values;

	tests_values = "DNAKLDLA313131r532K 12DNAK 3\n\t";
	run_test_ctype_char(tests_values, &ft_isascii, &isascii);
}

Test(test_ctype, ft_isprint_test)
{
	char *tests_values;

	tests_values = "DNAKLDLA313131r532K 12DNAK 3\n\t";
	run_test_ctype_char(tests_values, &ft_isprint, &isprint);
}

Test(test_ctype, ft_strlen_test)
{
	char *tests_values[] = {"DNAKLDLA313131r532K 12DNAK 3\n\t"
	, "dmakd", "qwsx \tvwq", "MAKLMCAS", "ASDNAS", NULL};
	run_test_ctype_string(tests_values, &ft_strlen, &strlen);
}
