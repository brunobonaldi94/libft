/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:15:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/05 23:21:51 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
    size_t	s2_len;
    size_t	size;
	size = n;
    if (!*s2)
        return ((char *)(s1));
    s2_len = ft_strlen(s2);
    while (*s1 && size)
    {
        if ((*s1 == *s2) && (ft_strncmp(s1, s2, s2_len) == 0) && n > s2_len)
            return ((char *)(s1));
        s1++;
		size--;
    }
	return (NULL);
}