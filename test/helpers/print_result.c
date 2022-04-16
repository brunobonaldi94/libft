/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:43:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/16 11:55:34 by bbonaldi         ###   ########.fr       */
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

void    print_result_with_test(size_t total, size_t success_results)
{
	printf(WHITE"\n\nTOTAL TESTS: %ld"WHITE" (SUCCESS:"GREEN"%ld,"WHITE" FAILED:"RED"%ld"WHITE")\n", total, success_results, total - success_results);
	if (success_results == total)
		print_result(SUCCESS);
	else
		print_result(FAILURE);
}