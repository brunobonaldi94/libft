/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:50:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/05 23:26:26 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H

# define TEST_STRING_QTY 10
# define ADDER_STRING 10
#include <criterion/criterion.h>
#include <signal.h>
#include <ctype.h>
#include "../libft.h"
//#include <string.h>
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char	*create_ascii_arr();
char    **random_string_generator(int qty);
void	free_string_generator(char **test_values);

#endif