/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:32:29 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 00:19:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
    t_list *head;
    head = NULL;
	t_list *new;
    new = ft_lstnew("test");
    ft_lstadd_front(&head, new);
    t_list *new2;
    new2 = ft_lstnew("test2");
    ft_lstadd_front(&head, new2);
    t_list *new3;
    new3 = ft_lstnew("test3");
    
    ft_lstadd_back(&head, new3);
    while (head)
    {
        printf(WHITE"%s\n", (char *)head->content);
        head = head->next;
    }
	return (0);
}
 