/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:13:00 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/20 20:26:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char *tests_values[] = {"<Q7e1l$cVn;wB*", "<Q7", "sox4KBj9*[ONtt}U{]",
     "dasd","YhUvOI7hs", " ", "qq", "\0", NULL};
	loop_through_tests_strnstr(tests_values, "ft_strnstr", &ft_strnstr, &strnstr);
	return (0);
}
 