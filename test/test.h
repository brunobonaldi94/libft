/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:50:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/17 21:29:40 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H

# define TEST_STRING_QTY 10
# define ADDER_STRING 10
# define OK "OK"
# define KO "KO"
# define SUCCESS 1
# define FAILURE 0
# define RESET "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

#include <criterion/criterion.h>
#include <signal.h>
#include <ctype.h>
#include "../libft.h"
#include <string.h>
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

char	*create_ascii_arr(char *tests_values);
char	**random_string_generator(int qty);
int		generate_random_int(int min, int max, int seed);
void	free_string_generator(char **test_values);
void	transform_to_one(int *value);
void	print_result(int result);
void	remove_file(char *file_name);
void	create_results(char *file_name,int index_test, int c, int exp, int res);
void	create_results_toupperlower(char *file_name,int index_test, int c, int exp, int res);
void	create_results_strlen(char *file_name,int index_test, char *c, int exp, int res);
void	create_results_memset(char *file_name,int index_test, char c, void *exp, void *res, size_t n);
void	create_results_cpy(char *file_name,int index_test, char *c, void *exp, void *res, size_t n);
void	loop_through_tests_isxxx(char *tests_values, char *function_name, int (*result)(int), int (*expected)(int));
void	loop_through_tests_toupperlower(char *tests_values, char *function_name, int (*result)(int), int	(*expected)(int));
void	loop_through_tests_strlen(char **tests_values, char *function_name, size_t (*result)(const char *), size_t (*expected)(const char *));
void	loop_through_tests_memset(char *tests_values, char *function_name, void *(*result)(void *, int, size_t),  void *(*expected)(void *, int, size_t));
void 	loop_through_tests_bzero(char *tests_values, char *function_name, void (*result)(void *,  size_t),  void (*expected)(void *, size_t));
void	loop_through_tests_memcpy(char **tests_values, char *function_name, void *(*result)(void *, const void *,  size_t), void *(*expected)(void *, const void *,  size_t));
void	loop_through_tests_memmove(char **tests_values, char *function_name, void *(*result)(void *, const void *,  size_t), void *(*expected)(void *, const void *,  size_t));
void loop_through_tests_strl(char **tests_values, char *function_name, size_t(*result)(char *, const char *,  size_t), size_t(*expected)(char *, const char *,  size_t));
void	print_result_with_test(size_t total, size_t success_results);
#endif