/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdlib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:30:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/08 19:29:23 by bbonaldi         ###   ########.fr       */
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

Test(test_stdlib, ft_calloc_test)
{
    void *p = ft_calloc(2,2);
    void *e = calloc(2,2);

    cr_expect(ft_memcmp(p,e, 4) == 0, "%d | %ld | %ld",ft_memcmp(p, e, 4) , sizeof(p) /sizeof(p[0]), sizeof(e) / sizeof(e[0]));
    free(p);
    free(e);
    void *p1= ft_calloc(4, 4);
    void *e1= calloc(4, 4);
    cr_expect(memcmp(p1, e1, 16) == 0);
    free(p1);
    free(e1);
    void *p2= ft_calloc(2, 2);
    char e2[] = {0,0,0,1};
    cr_expect(memcmp(p2, e2, 4) != 0);
    free(p2);
}