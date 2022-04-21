/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:32:29 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 17:05:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
    char *result[] = {"test"};
    size_t i = 0;
    size_t final_result = 0;

    t_list *head;
    head = NULL;
	t_list *new;
    new = ft_lstnew("test");
    t_list *new1;
    new1 = ft_lstnew("test1");
    t_list *new2;
    new2 = ft_lstnew("test2");

    ft_lstadd_front(&head, new);
    ft_lstadd_front(&head, new1);
    ft_lstadd_front(&head, new2);
    t_list *last = ft_lstlast(head); 
    
    check_list(last, result, &i, &final_result, "ft_lst_last");
    
    free(new);
    free(new1);
    free(new2);
    return (0);
}
 