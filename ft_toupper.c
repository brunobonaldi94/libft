/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:25:15 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/04 19:19:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	to_upper_constant;

	to_upper_constant = 'a' - 'A';
	if (c >= 'a' && c <= 'z')
		c -= to_upper_constant;
	return (c);
}
