/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:09:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/07 23:57:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_uc;
	const unsigned char	*src_uc;

	if (!dest && !src)
		return (NULL);
	dest_uc = (unsigned char *)dest;
	src_uc = (unsigned char *)src;
	while (n)
	{
		*dest_uc = *src_uc;
		dest_uc++;
		src_uc++;
		n--;
	}
	return (dest);
}
