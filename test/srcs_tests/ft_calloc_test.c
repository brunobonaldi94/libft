/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:53:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/20 22:39:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	size_t tests_values[] = {1, 200, 100, 4, 1, 32, 3,4, ULLONG_MAX, ULLONG_MAX, 0};
	loop_through_tests_calloc(tests_values, "ft_calloc", &ft_calloc, &calloc);
	return (0);
}
 