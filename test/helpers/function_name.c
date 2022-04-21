/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:49:52 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 18:53:13 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*print_function_name(char *test_file_name, char *function_name, size_t n)
{
	printf(BLUE"TEST NAME:"PURPLE" %s\n\n"RESET, function_name);
	strlcpy(test_file_name,"test_results/",n);
	strlcat(test_file_name, function_name, n);
	strlcat(test_file_name, "_test_results", n);
	remove_file(test_file_name);
	return (test_file_name);
}