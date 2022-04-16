/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:40:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/15 22:58:37 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char tests_values[] = {'A', 'B', 'z', 'Z', '0', '9', ' ', 
	'\t', '\n', '\v', '\f', '\r', 129,'\0'};
	loop_through_tests_isxxx(tests_values, "ft_isdigit", &ft_isdigit, &isdigit);
    return (0);
}