/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:32:29 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 18:26:23 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main()
{
	char *result[] = {"test"};
	t_list *head = NULL;
	t_list *new;
	new = ft_lstnew("test");
	t_list *new1;
	char *c = malloc(sizeof(char) * 6);
	strcpy(c, "test1");
	new1 = ft_lstnew(c);
	ft_lstadd_back(&head, new);
	ft_lstadd_back(&head, new1);
	ft_lstdelone(new1, &free);
	new->next = NULL;
	size_t i = 0;
	size_t final_result = 0;
	check_list(head, result, &i, &final_result, "ft_lstdelone");
	free(new);
	return (0);
}
 