/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:33:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/17 21:03:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char *tests_values[] = {"abcdefabcdef", "jasddkoaso", "djadkada12     ", "", " ", "\0", NULL};
	loop_through_tests_strl(tests_values, "ft_strlcpy", &ft_strlcpy, &strlcpy);
	return (0);
}
 