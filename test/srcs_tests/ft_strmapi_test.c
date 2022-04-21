/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:10:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 13:21:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void loop_through_tests_strmapi(char *tests_values[], char *result_values[], char *function_name, char *(*result)(char const *, char (*f)(unsigned int, char)), char (*f_aux)(unsigned int, char))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		char *res = result(tests_values[i], f_aux);
		check(my_strcmp(res, result_values[i]) == 0,&i, &final_result);
 		free(res);
	}
	print_result_with_test(i, final_result);
}

char add_index(unsigned int index, char c)
{
    return (c + index);
}

int	main()
{
	char *tests_values[] = {"abcdef", "012", 0};
    char *result_values[] = {"acegik", "024"};
	loop_through_tests_strmapi(tests_values, result_values,"ft_strmapi", &ft_strmapi, &add_index);
	return (0);
}
 