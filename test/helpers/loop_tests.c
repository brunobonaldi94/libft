/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:30:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/15 13:32:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int    compare_results(char *file_name, int c, int index_test,int (*result)(int), int	(*expected)(int))
{
	int final_result = 1;
	int res = result(c);
	transform_to_one(&res);
	int exp = expected(c);
	transform_to_one(&exp);
	if (res != exp)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	
	create_results(file_name, index_test, c, exp, res);
	return (final_result);
}

void loop_through_tests_isxxx(char *tests_values, char *function_name, int (*result)(int), int	(*expected)(int))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	printf(BLUE"TEST NAME:"PURPLE" %s\n"RESET, function_name);
	char test_file_name[100] = "srcs_tests/";
	ft_strlcat(test_file_name, function_name, sizeof(test_file_name));
	ft_strlcat(test_file_name, "_test_results", sizeof(test_file_name));
	remove_file(test_file_name);
	while (tests_values[i])
	{
		final_result += compare_results(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	if (final_result == i)
		print_result(SUCCESS);
	else
		print_result(FAILURE);
}