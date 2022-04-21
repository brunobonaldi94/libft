/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:32:29 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 16:56:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
    char *result[] = {"test1","test"};
    size_t i = 0;
    size_t final_result = 0;

    t_list *head;
    head = NULL;
	t_list *new;
    new = ft_lstnew("test");
    t_list *new1;
    new1 = ft_lstnew("test1");

    ft_lstadd_front(&head, new);
    ft_lstadd_front(&head, new1);
    check_list(head, result, &i, &final_result, "ft_lstadd_front");
    
    free(new);
    free(new1);
    return (0);
}
 