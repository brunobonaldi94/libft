/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:32:29 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 18:01:57 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char *result[] = {"test", "test1", "test2", "test3"};
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
	t_list *new3;
	new3 = ft_lstnew("test3");

	ft_lstadd_back(&head, new);
	ft_lstadd_back(&head, new1);
	ft_lstadd_back(&head, new2);
	ft_lstadd_back(&head, new3);
	
	
	check_list(head, result, &i, &final_result, "ft_lstadd_back");
	
	free(new);
	free(new1);
	free(new2);
	free(new3);
	return (0);
}
 