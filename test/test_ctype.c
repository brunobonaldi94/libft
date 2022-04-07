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
						int (*expected_function)(int), int convert_to_one)
{
	int	result;
	int	expected;
	int index = 0;

	while (string_test[index])
	{
		result = result_function(string_test[index]);
		expected = expected_function(string_test[index]);
		if (convert_to_one)
		{
			transform_to_one(&result);
			transform_to_one(&expected);
		}
		cr_expect(result == expected,
			"arg value: %c %d, result:%d != expect:%d",
			string_test[index],string_test[index], result, expected);
		index++;
	}
}

Test(test_ctype, ft_isalpha_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_isalpha, &isalpha,1);
	free(tests_values);
}

Test(test_ctype, ft_isdigit_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_isdigit, &isdigit,1);
	free(tests_values);
}

Test(test_ctype, ft_isascii_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_isascii, &isascii,1);
	free(tests_values);
}

Test(test_ctype, ft_isprint_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_isprint, &isprint,1);
	free(tests_values);
}

Test(test_ctype, ft_to_upper_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_toupper, &toupper,0);
	free(tests_values);
}

Test(test_ctype, ft_to_lower_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_tolower, &tolower,0);
	free(tests_values);
}