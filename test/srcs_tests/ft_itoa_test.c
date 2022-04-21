/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:37:55 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 13:07:00 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
void swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
char* reverse(char *buffer, int i, int j)
{
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }
 
    return buffer;
}
char* itoa(int value, int base)
{
	char *buffer =  malloc(sizeof(char) * 12);
    // invalid input
    if (base < 2 || base > 32) {
        return buffer;
    }
 
    // consider the absolute value of the number
	long int nvalue = value;
    long int n = nvalue < 0 ? -nvalue : nvalue;
 
    int i = 0;
    while (n)
    {
        int r = n % base;
 
        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        }
        else {
            buffer[i++] = 48 + r;
        }
 
        n = n / base;
    }
 
    // if the number is 0
    if (i == 0) {
        buffer[i++] = '0';
    }
 
    // If the base is 10 and the value is negative, the resulting string
    // is preceded with a minus sign (-)
    // With any other base, value is always considered unsigned
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }
 
    buffer[i] = '\0'; // null terminate string
 
    // reverse the string and return it
    return reverse(buffer, 0, i - 1);
}

void loop_through_tests_itoa(int tests_values[], char *function_name, char *(*result)(int n), char *(*expected)(int n,int ), size_t size)
{
	size_t i = 0;
	size_t final_result;
	final_result = 0;
	char test_file_name[100] = {0};
	print_function_name(test_file_name, function_name, 100);
	while (i < size)
	{
		char *res = result(tests_values[i]);
		char *exp = expected(tests_values[i], 10);
		check(my_strcmp(res, exp) == 0,&i, &final_result);
		free(exp);
		free(res);
	}
	print_result_with_test(i, final_result);
}


int	main()
{
	int tests_values[] = {100, 430, 323123124, -1, 0, INT_MIN, INT_MAX, -323123124, 0};
	loop_through_tests_itoa(tests_values, "ft_itoa", &ft_itoa, &itoa, 9);
	return (0);
}
 