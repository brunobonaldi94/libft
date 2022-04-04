/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:43:11 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/04 19:19:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	to_lower_constant;

	to_lower_constant = 'a' - 'A';
	if (c >= 'A' && c <= 'Z')
		c += to_lower_constant;
	return (c);
}
