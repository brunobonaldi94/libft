/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:33:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/18 23:44:56 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char *tests_values[] = {"abcdefabcdef", "abcdefabcdef", "djadkada12     ",
     "djadka","djadkada12", "abcdef", "\0", NULL};
	loop_through_tests_memcmp(tests_values, "ft_memcmp", &ft_memcmp, &memcmp);
	return (0);
}
 