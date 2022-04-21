/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:26:28 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 18:47:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


void change_first_letter(void *content)
{
    char *str = (char *)content;
    str[0] = 'c';
}

int	main()
{
	char *result[] = {"cest", "cest1"};
	t_list *head = NULL;
	
    t_list *new;
    char *c = malloc(sizeof(char) * 5);
    strcpy(c, "test");
	new = ft_lstnew(c);
	
    char *c1 = malloc(sizeof(char) * 6);
    strcpy(c1, "test1");
    t_list *new1;
	new1 = ft_lstnew(c1);

	ft_lstadd_back(&head, new);
	ft_lstadd_back(&head, new1);
	ft_lstiter(head, &change_first_letter);
	size_t i = 0;
	size_t final_result = 0;
	check_list(head, result, &i, &final_result, "ft_lstiter");
	return (0);
}
 