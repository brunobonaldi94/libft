/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ascii_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:30:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/05 21:49:00 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*create_ascii_arr()
{
	char c;
	int	i;
	int	ascii_count = 127; 
	char *tests_values;

	c = 1;
	i = 0;
	tests_values = (char *)malloc(sizeof(char) * (ascii_count + 1));
	if (!tests_values)
		return (NULL);
	while (i < ascii_count)
	{
		tests_values[i] = c;
		i++;
		c++;
	}
	tests_values[i] = '\0';
	return (tests_values);
}