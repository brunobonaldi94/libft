/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:50:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/06 22:11:24 by bbonaldi         ###   ########.fr       */
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
#include <string.h>
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char	*create_ascii_arr();
char	**random_string_generator(int qty);
int		generate_random_int(int min, int max, int seed);
void	free_string_generator(char **test_values);
void	transform_to_one(int *value);

#endif