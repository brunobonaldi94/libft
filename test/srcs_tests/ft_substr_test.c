/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:00:12 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 10:48:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void loop_through_tests_substr(char *function_name, char *(*result)(const char *, unsigned int, size_t))
{
	size_t i = 0;
	size_t final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);

	char * s = result("bonaldi", 0, 42000);
	check(strcmp(s, "bonaldi") == 0, &i, &final_result);
	
	s = result("bonaldi", 1, 1);
 	check(strcmp(s, "o") == 0, &i, &final_result);
	free(s);

	s = result("bonaldi", 100, 1);
	check(strcmp(s, "") == 0, &i, &final_result);
	free(s);
	
	char * str = strdup("1");
	s = result(str, 42, 42000000);
	check(strcmp(s, "") == 0, &i, &final_result);
	free(s);
    free(str);
	
	str = strdup("0123456789");
	s = result(str, 9, 10);
	check(strcmp(s, "9") == 0, &i, &final_result);
	free(str);
    free(s);
	
	s = result("42", 0, 0);
	check(strcmp(s, "") == 0, &i, &final_result);
	free(s);
	
	s = result("BONJOUR LES HARICOTS !", 8, 14);
	check(strcmp(s, "LES HARICOTS !") == 0, &i, &final_result);
	free(s);
	
	s = result("test", 1, 2);
	check(strcmp(s, "es") == 0, &i, &final_result);
	free(s);
	print_result_with_test(i, final_result);
}

int	main()
{
	loop_through_tests_substr("ft_substr", &ft_substr);
	return (0);
}
 