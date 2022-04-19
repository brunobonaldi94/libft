/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:33:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/18 22:58:16 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char *tests_values = malloc(sizeof(char) * 128);
    create_ascii_arr(tests_values);
	loop_through_tests_strchr(tests_values, "ft_strrchr", &ft_strrchr, &strrchr);
    free(tests_values);
	return (0);
}