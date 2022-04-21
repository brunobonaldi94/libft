/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:10:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 13:48:10 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void loop_through_tests_striteri(char *tests_values[], char *result_values[], char *function_name, void (*result)(char *, void (*f)(unsigned int, char *)), void (*f_aux)(unsigned int, char *))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		result(tests_values[i], f_aux);
		check(my_strcmp(tests_values[i], result_values[i]) == 0,&i, &final_result);
	}
	print_result_with_test(i, final_result);
}

void check_odd(unsigned int index, char *c)
{
	//P = Par
	//I = Impar
    index = index % 2;
	if (ft_isdigit(*c))
	{
		int c_int = *c - '0';
		if (c_int % 2 == 0)
			c[0] = 'P';
		else
			c[0] = 'I';
	}
}
void populate_array(char *s[], char c[], int index)
{
    if (*c == '\0')
    {
        s[index] = NULL;
        return ;
    }
    char *c1 = strdup(c);
   s[index] = c1;
   free(c1);
}

int	main()
{
	char *tests_values[3];
	char *result_values[3];
    populate_array(tests_values, "123456789", 0);
    populate_array(tests_values, "abcdef", 1);
    populate_array(tests_values, "", 2);
    populate_array(result_values, "IPIPIPIPI", 0);
    populate_array(result_values, "abcdef", 1);
    populate_array(result_values, "", 2);
	loop_through_tests_striteri(tests_values, result_values,"ft_striteri", &ft_striteri, &check_odd);
	return (0);
}
 