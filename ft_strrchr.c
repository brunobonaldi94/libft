/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:47:10 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/06 17:59:59 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		s_len;
	const char	*ptr_s;

	s_len = ft_strlen(s);
	ptr_s = s + s_len;
	while (ptr_s != s && s != NULL)
	{
		if (*ptr_s == c)
			return ((char *)ptr_s);
		ptr_s--;
	}
	return (NULL);
}
