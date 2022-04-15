/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:43:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/15 12:49:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_result(int result)
{
	char *res= result ? OK : KO;
	char *color = result ? GREEN : RED;
	(void)result;
	printf("\n%s%s\n"RESET,color,res);
}