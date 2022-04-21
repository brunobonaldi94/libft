/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:26:28 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 18:38:24 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char **result = NULL;
	t_list *head = NULL;
	t_list *new;
	char *c = malloc(sizeof(char) * 6);
	strcpy(c, "test");
	new = ft_lstnew(c);
	t_list *new1;
	char *c1= malloc(sizeof(char) * 6);
	strcpy(c1, "test1");
	new1 = ft_lstnew(c1);
	ft_lstadd_back(&head, new);
	ft_lstadd_back(&head, new1);
	ft_lstclear(&head, &free);
	size_t i = 0;
	size_t final_result = 0;
	check_list(head, result, &i, &final_result, "ft_lstclear");
	return (0);
}
 