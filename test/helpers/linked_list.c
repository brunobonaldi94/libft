/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:40:55 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 18:36:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	check_list(t_list *list, char **result_values, size_t *i, size_t *final_result, char *function_name)
{
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	size_t index = 0;
    if (list == NULL && result_values == NULL)
    {
        *i += 1;
        *final_result += 1;
        print_result_with_test(*i, *final_result);
        return ;
    }
	while(list)
	{
 		check(my_strcmp((char *)list->content, result_values[index]) == 0, i, final_result);
		list = list->next;
		index++;
	}
	print_result_with_test(*i, *final_result);
}