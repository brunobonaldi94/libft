/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:39:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 10:57:32 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

void loop_through_tests_strjoin(char *function_name, char *(*result)(const char *,const char *))
{
	size_t i = 0;
	size_t final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);

	char * s = result("bonaldi", "bruno");
	check(strcmp(s, "bonaldibruno") == 0, &i, &final_result);
	
	s = result("1 - ","bbonaldi");
 	check(strcmp(s, "1 - bbonaldi") == 0, &i, &final_result);
	free(s);

	s = result("course", "42");
	check(strcmp(s, "course42") == 0, &i, &final_result);
	free(s);
	
	
	s = result("libft", "");
	check(strcmp(s, "libft") == 0, &i, &final_result);
	free(s);
    
    s = result("", "libft");
	check(strcmp(s, "libft") == 0, &i, &final_result);
	free(s);
	print_result_with_test(i, final_result);
}

int	main()
{
	loop_through_tests_strjoin("ft_strjoin", &ft_strjoin);
	return (0);
}
 