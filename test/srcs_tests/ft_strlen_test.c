/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:33:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/16 12:46:10 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char *tests_values[] = {"abcdef", "jasddkoaso", "djadkada12     ", "", " ", "\0", NULL};
	loop_through_tests_strlen(tests_values, "ft_strlen", &ft_strlen, &strlen);
	return (0);
}
 