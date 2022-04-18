/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:40:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/17 21:32:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char tests_values[] = {'a', 'B', 'z', 'Z', '0', '9', ' ', 
	'\t', '\n', '\v', '\f', '\r', 127,'\0'};
	loop_through_tests_toupperlower(tests_values, "ft_toupper", &ft_toupper, &toupper);
	return (0);
}
 