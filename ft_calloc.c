/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:14:20 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/08 19:04:42 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc_result;

	if (nmemb == 0 || size == 0)
		return (NULL);
	calloc_result = malloc(nmemb * size);
	if (calloc_result == NULL)
		return (NULL);
	ft_bzero(calloc_result, nmemb * size);
	return (calloc_result);
}
