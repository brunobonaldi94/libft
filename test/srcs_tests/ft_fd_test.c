/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:56:00 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 14:39:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void test_putchar(char c,  size_t *i,size_t *f)
{
	FILE *fp;
	fp = fopen("/tmp/test_putchar.txt", "w+");
	ft_putchar_fd(c, fileno(fp));
	fseek(fp, 0, SEEK_SET);
	check(fgetc(fp) == c, i, f);
}


void test_putstr(char *c, size_t *i,size_t *f)
{
	FILE *fp;
	char buf[255];
	fp = fopen("/tmp/test_putstr.txt", "w+");
	ft_putstr_fd(c, fileno(fp));
	fseek(fp, 0, SEEK_SET);
	fgets(buf, strlen(c) + 1, fp);
	check(strcmp(buf, c) == 0, i, f);
}

void test_putendl_fd(char *c, size_t *i,size_t *f)
{
	FILE *fp;
	char buf[255];
	char *c2 = malloc(sizeof(char) * (strlen(c) + 1) + 1);
	c2[(strlen(c) + 1)] = '\n';
	fp = fopen("/tmp/test_putendl.txt", "w+");
	ft_putendl_fd(c, fileno(fp));
	fseek(fp, 0, SEEK_SET);
	fgets(buf, strlen(c2) + 1, fp);
	check(strcmp(buf, c2) == 0, i, f);
	free(c2);
}

void test_putnbr(int n,size_t *i,size_t *f)
{
	FILE *fp;
	char buf[255];
	fp = fopen("/tmp/test_putnbr.txt", "w+");
	ft_putnbr_fd(n, fileno(fp));
	fseek(fp, 0, SEEK_SET);
	char *n1 = ft_itoa(n);
	fgets(buf, strlen(n1) + 1, fp);
	check(strcmp(buf, n1) == 0, i, f);
	free(n1);
}

int main()
{   
	//ft_putchar_fd
	char test_file_name[100] = {0};
	size_t i = 0 ;
	size_t final_result = 0;
	print_function_name(test_file_name, "ft_putchar_fd", 100);
	test_putchar('a', &i, &final_result);
	test_putchar('5', &i, &final_result);
	test_putchar('f', &i, &final_result);
	print_result_with_test(i, final_result);

	//ft_putstr_fd
	i = 0 ;
	final_result = 0;
	print_function_name(test_file_name, "ft_putstr_fd", 100);
	test_putstr("bruno", &i, &final_result);
	test_putstr("falcao", &i, &final_result);
	test_putstr("zinho   ", &i, &final_result);
	test_putstr("", &i, &final_result);
	print_result_with_test(i, final_result);

	//ft_putendl_fd
	i = 0;
	final_result = 0;
	print_function_name(test_file_name, "ft_putendl_fd", 100);
	test_putendl_fd("bruno", &i, &final_result);
	test_putendl_fd("falcao   ", &i, &final_result);
	test_putendl_fd("zinho", &i, &final_result);
	test_putendl_fd("", &i, &final_result);
	print_result_with_test(i, final_result);

	//ft_putnbr_fd
	i = 0;
	final_result = 0;
	print_function_name(test_file_name, "ft_putnbr_fd", 100);
	test_putnbr(400545, &i, &final_result);
	test_putnbr(-400545, &i, &final_result);
	test_putnbr(0, &i, &final_result);
	test_putnbr(256, &i, &final_result);
	test_putnbr(INT_MAX, &i, &final_result);
	test_putnbr(INT_MIN, &i, &final_result);
	print_result_with_test(i, final_result);

}