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

char	*create_ascii_arr()
{
	char c;
	int	i;
	int	ascii_count = 127; 
	char *tests_values;

	c = 0;
	i = 0;
	tests_values = (char *)malloc(sizeof(char) * (ascii_count + 1));
	if (!tests_values)
		return (NULL);
	while (i < ascii_count)
	{
		tests_values[i] = c;
		i++;
		c++;
	}
	tests_values[i] = '\0';
	return (tests_values);
}

Test(test_ctype, ft_isalpha_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_isalpha, &isalpha);
}

Test(test_ctype, ft_isdigit_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_isdigit, &isdigit);
}

Test(test_ctype, ft_isascii_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_isascii, &isascii);
}

Test(test_ctype, ft_isprint_test)
{
	char *tests_values;

	tests_values = create_ascii_arr();
	run_test_ctype_char(tests_values, &ft_isprint, &isprint);
}

