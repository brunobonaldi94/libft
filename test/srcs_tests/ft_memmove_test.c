/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:33:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/16 16:59:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char *tests_values[] = {"abc", "ABC", "123", "123456789", "", " ", NULL};
	loop_through_tests_memmove(tests_values, "ft_memmove", &ft_memmove, &memmove);
	return (0);
}