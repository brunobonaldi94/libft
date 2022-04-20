/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:33:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/19 23:50:39 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char *tests_values = malloc(sizeof(char) * 128);
    create_ascii_arr(tests_values);
	loop_through_tests_memchr(tests_values, "ft_memchr", &ft_memchr, &memchr);
    free(tests_values);
	return (0);
}