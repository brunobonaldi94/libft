/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:39:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 10:59:26 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

void loop_through_tests_strtrim(char *function_name, char *(*result)(const char *,const char *))
{
	size_t i = 0;
	size_t final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);

	char * s = result("bonaldi", "ib");
	check(strcmp(s, "onald") == 0, &i, &final_result);
	
	s = result("1 - ","- 1 ");
 	check(strcmp(s, "") == 0, &i, &final_result);
	free(s);

	s = result("cccbbbbaaa", "caaac");
	check(strcmp(s, "bbbb") == 0, &i, &final_result);
	free(s);
	
	
	s = result("aadweqabcdewww", "qdaabww");
	check(strcmp(s, "eqabcde") == 0, &i, &final_result);
	free(s);
    
    s = result("libft", "");
	check(strcmp(s, "libft") == 0, &i, &final_result);
	free(s);
	print_result_with_test(i, final_result);
}

int	main()
{
	loop_through_tests_strtrim("ft_strtrim", &ft_strtrim);
	return (0);
}
 