/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:39:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 12:10:24 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

void    adjust_index(size_t *i, size_t *final_result,size_t len)
{
	if (*i == *final_result)
	{
		*i -= len - 1;
		*final_result -= len - 1;
	}
}

void check_result(char **s, char *res[],size_t *i, size_t *final_result, size_t result_len)
{
	size_t index = 0;
	size_t my_result_len = 0;
	while (s[my_result_len])
		my_result_len++;
	
	if (my_result_len + 1 != result_len)
	{
		check (0, i, final_result);
		return;		
	}
	while (*s)
	{
		if (my_strcmp(*s, res[index]) == 0)
			*final_result+=1;
		*i+=1;
		free(*s);
		s++;
		index++;
	}
	adjust_index(i, final_result, result_len);
	check(*i == *final_result, i, final_result);
	free(s - index);
}

void loop_through_tests_split(char *function_name, char **(*result)(const char *,char))
{
	size_t i = 0;
	size_t final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);

	char **s = result("bonaldi", 'b');
	char *res[] = {"onaldi", 0};
	check_result(s, res, &i, &final_result, sizeof(res) / sizeof(res[0]));
	
	s = result("bonaldi,bruno,silva" , ',');
	char *res1[] = {"bonaldi","bruno","silva", 0};
	check_result(s, res1, &i, &final_result, sizeof(res1) / sizeof(res1[0]));
	
	s = result("bonaldi,bruno silva" , ',');
	char *res2[] = {"bonaldi","bruno silva", 0};
	check_result(s, res2, &i, &final_result, sizeof(res2) / sizeof(res2[0]));
	
	s = result("bonaldi bruno silva ramos" , ' ');
	char *res3[] = {"bonaldi", "bruno", "silva", "ramos", 0};
	check_result(s, res3, &i, &final_result, sizeof(res3) / sizeof(res3[0]));
	

	s = result("" , ' ');
	char *res4[] = {0};
	check_result(s, res4, &i, &final_result, sizeof(res4) / sizeof(res4[0]));
	
	s = result("bonaldi bruno silva ramos" , ',');
	char *res5[] = {"bonaldi bruno silva ramos", 0};
	check_result(s, res5, &i, &final_result, sizeof(res5) / sizeof(res5[0]));
	

	print_result_with_test(i, final_result);
}

int	main()
{
	loop_through_tests_split("ft_split", &ft_split);
	return (0);
}
 