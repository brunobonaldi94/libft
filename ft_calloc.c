/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:14:20 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/11 23:31:10 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void					*calloc_result;
	long long unsigned int	result;

	if ((nmemb + size) < nmemb)
		return (NULL);
	result = nmemb * size;
	calloc_result = malloc(result);
	if (calloc_result == NULL)
		return (NULL);
	ft_bzero(calloc_result, result);
	return (calloc_result);
}
