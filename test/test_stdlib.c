/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdlib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:30:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/06 19:49:54 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

Test(test_stdlib, ft_atoi_test)
{   
    char *test_values[] = {"1", "  -1", "0", "  a1", "   41564561", "-41564561", "+41564561"
    ,"+61" ,"-+61", "++61", "-1451650 a121" , "-1451650 121", "" ," " ," +14516\t50121", NULL};
    int i = 0;
    while (test_values[i])
    {
        cr_expect(ft_atoi(test_values[i]) == atoi(test_values[i]),
        "arg value: %s | ft_atoi = %d != atoi = %d",test_values[i],
        ft_atoi(test_values[i]), atoi(test_values[i])
        );
        i++;
    }
}