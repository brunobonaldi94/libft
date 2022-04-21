/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:30:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/20 23:39:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*print_function_name(char *test_file_name, char *function_name, size_t n)
{
	printf(BLUE"TEST NAME:"PURPLE" %s\n\n"RESET, function_name);
	ft_strlcpy(test_file_name,"test_results/",n);
	ft_strlcat(test_file_name, function_name, n);
	ft_strlcat(test_file_name, "_test_results", n);
	remove_file(test_file_name);
	return (test_file_name);
}

int    compare_results(char *file_name, int c, int index_test,int (*result)(int), int	(*expected)(int))
{
	int final_result = 1;
	int res = result(c);
	transform_to_one(&res);
	int exp = expected(c);
	transform_to_one(&exp);
	if (res != exp)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	
	create_results(file_name, index_test, c, exp, res);
	return (final_result);
}

void loop_through_tests_isxxx(char *tests_values, char *function_name, int (*result)(int), int	(*expected)(int))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}

int    compare_results_toupperlower(char *file_name, int c, int index_test,int (*result)(int), int (*expected)(int))
{
	int final_result = 1;
	int res = result(c);
	int exp = expected(c);
	if (res != exp)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	
	create_results_toupperlower(file_name, index_test, c, exp, res);
	return (final_result);
}

void loop_through_tests_toupperlower(char *tests_values, char *function_name, int (*result)(int), int	(*expected)(int))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_toupperlower(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}


int    compare_results_strlen(char *file_name, char *c, int index_test, size_t (*result)(const char *), size_t (*expected)(const char *))
{
	int final_result = 1;
	size_t res = result(c);
	size_t exp = expected(c);
	if (res != exp)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	
	create_results_strlen(file_name, index_test, c, exp, res);
	return (final_result);
}

void loop_through_tests_strlen(char **tests_values, char *function_name, size_t (*result)(const char *), size_t (*expected)(const char *))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_strlen(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}


int    compare_results_memset(char *file_name, char c, int index_test, void *(*result)(void *, int, size_t),  void *(*expected)(void *, int, size_t))
{
	int final_result = 1;
	char res[50] = "";
	char exp[50] = "";
	size_t n_bytes = generate_random_int(0, 50,index_test);
	result(res, c, n_bytes);
	expected(exp, c, n_bytes);
	if (memcmp(res, exp, 50) != 0)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	
	create_results_memset(file_name, index_test, c, exp, res, n_bytes);
	return (final_result);
}

void loop_through_tests_memset(char *tests_values, char *function_name, void *(*result)(void *, int, size_t),  void *(*expected)(void *, int, size_t))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_memset(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	i++;
	final_result += compare_results_memset(test_file_name,tests_values[i], i, result,expected);
	print_result_with_test(i, final_result);
}

int    compare_results_bzero(char *file_name, int c,int index_test, void (*result)(void *,  size_t),  void (*expected)(void *, size_t))
{
	int final_result = 1;
	char res[50] = "";
	char exp[50] = "";
	size_t n_bytes = generate_random_int(0, 50,index_test);
	result(res, n_bytes);
	expected(exp, n_bytes);
	if (memcmp(res, exp, 50) != 0)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	
	create_results_memset(file_name, index_test, c, exp, res, n_bytes);
	return (final_result);
}

void loop_through_tests_bzero(char *tests_values, char *function_name, void (*result)(void *,  size_t),  void (*expected)(void *, size_t))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_bzero(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	i++;
	final_result += compare_results_bzero(test_file_name,tests_values[i], i, result,expected);
	print_result_with_test(i, final_result);
}

int    compare_results_memcpy(char *file_name, char *c,int index_test, void *(*result)(void *, const void *,  size_t), void *(*expected)(void *, const void *,  size_t))
{
	int final_result = 1;
	char res[50] = "saf";
	char exp[50] = "saf";
	size_t n_bytes = generate_random_int(0, 50,index_test);
	result(res, c, n_bytes);
	expected(exp, c, n_bytes);
	if (memcmp(res, exp, 50) != 0)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	
	create_results_cpy(file_name, index_test, c, exp, res, n_bytes);
	return (final_result);
}

void loop_through_tests_memcpy(char **tests_values, char *function_name, void *(*result)(void *, const void *,  size_t), void *(*expected)(void *, const void *,  size_t))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_memcpy(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}

void loop_through_tests_memmove(char **tests_values, char *function_name, void *(*result)(void *, const void *,  size_t), void *(*expected)(void *, const void *,  size_t))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_memcpy(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	i++;

	char res[50] = "testing_overlap";
	char exp[50] = "testing_overlap";
	size_t n_bytes = generate_random_int(0, 50,i);
	expected(&res[2], &res[0],n_bytes);
	result(&exp[2], &exp[0],n_bytes);
	if (memcmp(res, exp, 50) != 0)
	{
		printf(WHITE" #"BLUE"%ld-"RED"%s"RESET, i,KO);
		final_result = 0;
	}
	else
	{
		printf(WHITE" #"BLUE"%ld-"GREEN"%s"RESET, i,OK);
		final_result++;
	}
	
	create_results_cpy(test_file_name, i,"testing_overlap", exp, res, n_bytes);
	print_result_with_test(i, final_result);
}


int    compare_results_strl(char *file_name, char *c,int index_test, size_t(*result)(char *, const char *,  size_t), size_t(*expected)(char *, const char *,  size_t))
{
	int final_result = 1;
	char res[50] = "saf";
	char exp[50] = "saf";
	size_t n_bytes = generate_random_int(0, 50,index_test);
	result(res, c, n_bytes);
	expected(exp, c, n_bytes);
	if (strcmp(res, exp) != 0)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	
	create_results_cpy(file_name, index_test, c, exp, res, n_bytes);
	return (final_result);
}

void loop_through_tests_strl(char **tests_values, char *function_name, size_t(*result)(char *, const char *,  size_t), size_t(*expected)(char *, const char *,  size_t))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_strl(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	i++;

	char res[50] = "ac";
	char exp[50] = "ac";
	char src[6] = "abcas";
	result(res, src,sizeof(res));
	result(exp, src,sizeof(exp));
	if (strcmp(res, exp) != 0)
	{
		printf(WHITE" #"BLUE"%ld-"RED"%s"RESET, i,KO);
		final_result = 0;
	}
	else
	{
		printf(WHITE" #"BLUE"%ld-"GREEN"%s"RESET, i,OK);
		final_result++;
	}
	
	create_results_cpy(test_file_name, i,res, exp, res, sizeof(res));
	print_result_with_test(i, final_result);
}


int	my_strcmp(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	if ((s1 == NULL && s2 != NULL) || (s2 == NULL && s1 != NULL))
		return (-1);
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}

int    compare_results_strchr(char *file_name, char c,int index_test, char *(*result)(const char *, int c), char *(*expected)(const char *, int c))
{
	int final_result = 1;
	char *res = "<Q7e1l$cVn;wB*;m&4H]0tjqM5s!Dz)YhUvOI7hs<$ju*56@6s^L?3C{sox4KBj9*[ONtt}U{]";
	char *exp_ = expected(res, c);
	char *res_ = result(res, c);
	if (my_strcmp(res_, exp_) != 0)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	if (res_ == NULL)
		res_ = "NULL";
	if (exp_ == NULL)
		exp_ = "NULL";
	create_results_strchr(file_name, index_test, c, res_, exp_);

	return (final_result);
}

void loop_through_tests_strchr(char *tests_values, char *function_name, char *(*result)(const char *, int c), char *(*expected)(const char *, int c))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_strchr(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}

int    compare_results_strncmp(char *file_name, char **c,size_t *index_test, size_t *final_result,int (*result)(const char *, const char *, size_t n), int (*expected)(const char *, const char *, size_t n))
{

	size_t i = 0;
	size_t j = 0;
	size_t len = 0;
	while (c[len])
		len++;
	while (c[i])
	{
		j = i;
		while (c[j] && j < len)
		{
			int n = generate_random_int(0, strlen(c[i]),*index_test);
			int res = result(c[i], c[j], n);
			transform_to_one(&res);
			int exp = expected(c[i], c[j], n);
			transform_to_one(&exp);
			if (res != exp)
			{
				printf(WHITE" #"BLUE"%d-"RED"%s"RESET, (int)(*index_test),KO);
				create_results_strncmp(file_name, i, c[i], c[j], res, exp, n);
				
			}
			else
			{
				printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET,(int)(*index_test),OK);
				*final_result = *final_result + 1;
				create_results_strncmp(file_name, i, c[i], c[j], res, exp, n);
			}
			j++;
			*index_test = *index_test + 1;
		}
		i++;
	}
	return (int)(*final_result);
}

void loop_through_tests_strncmp(char **tests_values, char *function_name, int (*result)(const char *, const char *, size_t n), int (*expected)(const char *, const char *, size_t n))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	compare_results_strncmp(test_file_name,tests_values, &i,&final_result, result,expected);
	print_result_with_test(i, final_result);
}


int    compare_results_memcmp(char *file_name, char **c,size_t *index_test, size_t *final_result,int (*result)(const void *, const void *, size_t n), int (*expected)(const void *, const void *, size_t n))
{

	size_t i = 0;
	size_t j = 0;
	size_t len = 0;
	while (c[len])
		len++;
	while (c[i])
	{
		j = i;
		while (c[j] && j < len)
		{
			int n = generate_random_int(0, strlen(c[i]),*index_test);
			int res = result(c[i], c[j], n);
			transform_to_one(&res);
			int exp = expected(c[i], c[j], n);
			transform_to_one(&exp);
			if (res != exp)
			{
				printf(WHITE" #"BLUE"%d-"RED"%s"RESET, (int)(*index_test),KO);
				create_results_strncmp(file_name, i, c[i], c[j], res, exp, n);
				
			}
			else
			{
				printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET,(int)(*index_test),OK);
				*final_result = *final_result + 1;
				create_results_strncmp(file_name, i, c[i], c[j], res, exp, n);
			}
			j++;
			*index_test = *index_test + 1;
		}
		i++;
	}
	return (int)(*final_result);
}


void loop_through_tests_memcmp(char **tests_values, char *function_name, int (*result)(const void *, const void *, size_t n), int (*expected)(const void *, const void *, size_t n))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	compare_results_memcmp(test_file_name,tests_values, &i,&final_result, result,expected);
	print_result_with_test(i, final_result);
}


int    compare_results_memchr(char *file_name, char c,int index_test, void *(*result)(const void *, int c, size_t), void *(*expected)(const void *, int c, size_t))
{
	int final_result = 1;
	char *res = "<Q7e1l$cVn;wB*;m&4H]0tjqM5s!Dz)YhUvOI7hs<$ju*56@6s^L?3C{sox4KBj9*[ONtt}U{]";
	size_t i = generate_random_int(0, strlen(res),index_test);
	char *exp_ = expected(res, c, i);
	char *res_ = result(res, c, i);
	if (my_strcmp(res_, exp_) != 0)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	if (res_ == NULL)
		res_ = "NULL";
	if (exp_ == NULL)
		exp_ = "NULL";
	create_results_memchr(file_name, index_test, c, res_, exp_, i);

	return (final_result);
}

void loop_through_tests_memchr(char *tests_values, char *function_name, void *(*result)(const void *, int c, size_t), void *(*expected)(const void *, int c,size_t))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_memchr(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}

int    compare_results_strnstr(char *file_name, char *c,int index_test, char *(*result)(const char *, const char *, size_t), char *(*expected)(const char *, const char *, size_t))
{
	int final_result = 1;
	char *res = "<Q7e1l$cVn;wB*;m&4H]0tjqM5s!Dz)YhUvOI7hs<$ju*56@6s^L?3C{sox4KBj9*[ONtt}U{]e1l$cVn;wB*;m&4H]0tjqM5s!Dz)YhUvOI7hs<$";
	size_t i = generate_random_int(0, strlen(res),index_test);
	char *exp_ = expected(res, c, i);
	char *res_ = result(res, c, i);
	if (my_strcmp(res_, exp_) != 0)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	if (res_ == NULL)
		res_ = "NULL";
	if (exp_ == NULL)
		exp_ = "NULL";
	create_results_strnstr(file_name, index_test, c, res_, exp_, i);

	return (final_result);
}

void loop_through_tests_strnstr(char **tests_values, char *function_name, char *(*result)(const char *, const char *, size_t), char *(*expected)(const char *, const char *, size_t))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_strnstr(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}


int    compare_results_atoi(char *file_name, const char *c,int index_test, int (*result)(const char *), int (*expected)(const char *))
{
	int final_result = 1;
 	int exp_ = expected(c);
	int res_ = result(c);
	if (res_ != exp_)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	create_results_atoi(file_name, index_test, c, res_, exp_);

	return (final_result);
}

void loop_through_tests_atoi(char **tests_values, char *function_name, int (*result)(const char *), int (*expected)(const char *))
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_atoi(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}

int    compare_results_calloc(char *file_name, size_t c, size_t c1,int index_test, void *(*result)(size_t, size_t), void * (*expected)(size_t, size_t))
{
	int final_result = 1;
 	void *exp_ = expected(c, c1);
	void *res_ = result(c,c1);
	size_t result_times = c * c1;
	if (c1 != 0 && result_times / c1 != c)
	{
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
		create_results_calloc(file_name, index_test, c, c1, malloc_usable_size(res_), malloc_usable_size(exp_));
		free(res_);
		free(exp_);
		return (1);
	}
	if (malloc_usable_size(res_) != malloc_usable_size(exp_))
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	create_results_calloc(file_name, index_test, c, c1, malloc_usable_size(res_), malloc_usable_size(exp_));
	free(res_);
	free(exp_);
	return (final_result);
}

void loop_through_tests_calloc(size_t tests_values[], char *function_name, void *(*result)(size_t, size_t), void * (*expected)(size_t, size_t))
{
	size_t i = 1;
	size_t final_result;
	final_result = 1;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_calloc(test_file_name,tests_values[i - 1],tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}

int    compare_results_strdup(char *file_name, const char *c,int index_test, char *(*result)(const char *), char * (*expected)(const char *))
{
	int final_result = 1;
 	char *exp_ = expected(c);
	char *res_ = result(c);
	if (my_strcmp(res_,exp_) != 0)
	{
		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
		final_result = 0;
	}
	else
		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
	create_results_strdup(file_name, index_test, c, res_, exp_);
	free(res_);
	free(exp_);
	return (final_result);
}

void loop_through_tests_strdup(char **tests_values, char *function_name, char *(*result)(const char *), char * (*expected)(const char *))
{
	size_t i = 1;
	size_t final_result;
	final_result = 1;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (tests_values[i])
	{
		final_result += compare_results_strdup(test_file_name,tests_values[i], i, result,expected);
		i++;
	}
	print_result_with_test(i, final_result);
}

// int    compare_results_substr(char *file_name, const char *c,int index_test, char *(*result)(const char *, size_t, size_t))
// {
// 	int final_result = 1;
// 	char *res_ = result(c);
// 	if (my_strcmp(res_,exp_) != 0)
// 	{
// 		printf(WHITE" #"BLUE"%d-"RED"%s"RESET, index_test,KO);
// 		final_result = 0;
// 	}
// 	else
// 		printf(WHITE" #"BLUE"%d-"GREEN"%s"RESET, index_test,OK);
// 	create_results_strdup(file_name, index_test, c, res_);
// 	free(res_);
// 	free(exp_);
// 	return (final_result);
// }

void	check(int test, size_t *index, size_t *final_result)
{
	if (test == 0)
		printf(WHITE" #"BLUE"%ld-"RED"%s"RESET, *index,KO);
	else
	{
		*final_result += 1;
		printf(WHITE" #"BLUE"%ld-"GREEN"%s"RESET, *index,OK);
	}
	*index += 1;
}

void loop_through_tests_substr(char *function_name, char *(*result)(const char *, unsigned int, size_t))
{
	size_t i = 0;
	size_t final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);

	char * s = result("tripouille", 0, 42000);
	check(strcmp(s, "tripouille") == 0, &i, &final_result);
	
	s = result("tripouille", 1, 1);
 	check(strcmp(s, "r") == 0, &i, &final_result);
	free(s);

	s = result("tripouille", 100, 1);
	check(strcmp(s, "") == 0, &i, &final_result);
	free(s);
	
	char * str = strdup("1");
	s = result(str, 42, 42000000);
	check(strcmp(s, "") == 0, &i, &final_result);
	free(s);
	
	str = strdup("0123456789");
	s = result(str, 9, 10);
	check(strcmp(s, "9") == 0, &i, &final_result);
	free(str);
    free(s);
	
	s = result("42", 0, 0);
	check(strcmp(s, "") == 0, &i, &final_result);
	free(s);
	
	s = result("BONJOUR LES HARICOTS !", 8, 14);
	check(strcmp(s, "LES HARICOTS !") == 0, &i, &final_result);
	free(s);
	
	s = result("test", 1, 2);
	check(strcmp(s, "es") == 0, &i, &final_result);
	free(s);
	print_result_with_test(i, final_result);
}