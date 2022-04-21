/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_results_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:03:46 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/20 22:54:21 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void    remove_file(char *file_name)
{
    remove(file_name);

}

void	write_logs(char *file_name, char *message)
{
	int fd;

	fd = open(file_name, O_CREAT|O_WRONLY|O_APPEND, 0644);
	ft_putstr_fd(message, fd);
	close(fd);
}

void	create_results(char *file_name,int index_test, int c, int exp, int res)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char c_str[2] = {c, '\0'};
    char *condition_str = "\ncondition: ";
    char *result_str = "\nresult: ";
    char result[2] = {res + '0', '\0'};
    char *expected_str = "\nexpected: ";
    char expected[2] = {exp + '0', '\0'};
    char *final_result = res == exp ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) + 
    ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	free(test_index_str);
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	free(message);
}

void	create_results_toupperlower(char *file_name,int index_test, int c, int exp, int res)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	unsigned char c_str[2] = {c, '\0'};
    char *condition_str = "\ncondition: ";
    char *result_str = "\nresult: ";
    char result[2] = {res , '\0'};
    char *expected_str = "\nexpected: ";
    char expected[2] = {exp , '\0'};
    char *final_result = res == exp ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen((char *)c_str) +  ft_strlen(condition_str) + 
    ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	free(test_index_str);
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, (char *)c_str,message_len);
	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	free(message);
}



void	create_results_strlen(char *file_name,int index_test, char *c, int exp, int res)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char *c_str = c;
    char *condition_str = "\ncondition: ";
    char *result_str = "\nresult: ";
    char *result = ft_itoa(res); 
    char *expected_str = "\nexpected: ";
    char *expected = ft_itoa(exp);
    char *final_result = res == exp ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) + 
    ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(result);
    free(expected);
    free(test_index_str);
    free(message);
}

void	create_results_memset(char *file_name,int index_test, char c, void *exp, void *res, size_t n)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char c_str[2] = {c, '\0'};
    char *condition_str = "\ncondition: ";
    char *size_str = "\nsize: ";
    char *size = ft_itoa(n);
    char *result_str = "\nresult: ";
    char *result = res; 
    char *expected_str = "\nexpected: ";
    char *expected = exp;
    char *final_result = memcmp(res,exp,n) == 0 ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) + ft_strlen(size_str) + ft_strlen(size)
     + ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
    ft_strlcat(message, size_str, message_len);
    ft_strlcat(message, size, message_len);
	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(test_index_str);
    free(message);
    free(size);
}


void	create_results_cpy(char *file_name,int index_test, char *c, void *exp, void *res, size_t n)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char *c_str = c;
    char *condition_str = "\ncondition: ";
    char *size_str = "\nsize: ";
    char *size = ft_itoa(n);
    char *result_str = "\nresult: ";
    char *result = res; 
    char *expected_str = "\nexpected: ";
    char *expected = exp;
    char *final_result = memcmp(res,exp,n) == 0 ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) + ft_strlen(size_str) + ft_strlen(size)
     + ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
    ft_strlcat(message, size_str, message_len);
    ft_strlcat(message, size, message_len);
	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(test_index_str);
    free(message);
    free(size);
}


void	create_results_strchr(char *file_name,int index_test, char c, char *exp, char *res)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char c_str[2] = {c, '\0'};
    char *condition_str = "\ncondition: ";
    char *result_str = "\nresult: ";
    char *result = res; 
    char *expected_str = "\nexpected: ";
    char *expected = exp;
    char *final_result = strcmp(res,exp) == 0 ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) + 
     + ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(test_index_str);
    free(message);
}

void	create_results_strncmp(char *file_name,int index_test, char *c, char *c1, int exp, int res, size_t n)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
    char *n_bytes = "\nbytes: ";
	char *n_bytes_str = ft_itoa(n);
    char *condition_str = "\ncondition: ";
	char *c_str = (char *)c;
    char *condition1_str = "\ncondition1: ";
	char *c1_str = c1;
    char *result_str = "\nresult: ";
    char *result = res > 0 ? "1" : res < 0 ? "-1" : "0";
    char *expected_str = "\nexpected: ";
    char *expected = exp > 0 ? "1" : exp < 0 ? "-1" : "0";
    char *final_result = res == exp ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) + ft_strlen(c1_str) +  ft_strlen(condition_str) + ft_strlen(condition1_str) 
     + ft_strlen(result) + ft_strlen(n_bytes_str) + ft_strlen(n_bytes) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep) + 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
    ft_strlcat(message, n_bytes, message_len);
	ft_strlcat(message, n_bytes_str,message_len);
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
    ft_strlcat(message, condition1_str, message_len);
	ft_strlcat(message, c1_str,message_len);
	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(test_index_str);
    free(n_bytes_str);
    free(message);
}


void	create_results_memchr(char *file_name,int index_test, char c, void *exp, void *res, size_t i)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char c_str[2] = {c, '\0'};
    char *condition_str = "\ncondition: ";
    char *i_str = "\nbytes: ";
    char *i_size = ft_itoa(i);
    char *result_str = "\nresult: ";
    char *result = res; 
    char *expected_str = "\nexpected: ";
    char *expected = exp;
    char *final_result = strcmp(res,exp) == 0 ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) +  ft_strlen(i_str) +  ft_strlen(i_size) + 
     + ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
    ft_strlcat(message, i_str, message_len);
	ft_strlcat(message, i_size,message_len);
	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(test_index_str);
    free(i_size);
    free(message);
}


void	create_results_strnstr(char *file_name,int index_test, char *c, char *exp, char *res, size_t i)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char *c_str = c;
    char *condition_str = "\ncondition: ";
    char *i_str = "\nbytes: ";
    char *i_size = ft_itoa(i);
    char *result_str = "\nresult: ";
    char *result = res; 
    char *expected_str = "\nexpected: ";
    char *expected = exp;
    char *final_result = strcmp(res,exp) == 0 ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) +  ft_strlen(i_str) +  ft_strlen(i_size) + 
     + ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
    ft_strlcat(message, i_str, message_len);
	ft_strlcat(message, i_size,message_len);
	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(test_index_str);
    free(i_size);
    free(message);
}

void	create_results_atoi(char *file_name,int index_test, const char *c, int exp, int res)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char *c_str = (char *)c;
    char *condition_str = "\ncondition: ";
    char *result_str = "\nresult: ";
    char *result = ft_itoa(res); 
    char *expected_str = "\nexpected: ";
    char *expected = ft_itoa(exp);
    char *final_result = res == exp ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) + 
     + ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
 	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(test_index_str);
    free(result);
    free(expected);
    free(message);
}


void	create_results_calloc(char *file_name,int index_test, size_t c, size_t c1, size_t exp, size_t res)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char *c_str = ft_itoa(c);
    char *condition_str = "\ncondition0: ";
    char *c1_str = ft_itoa(c1);
    char *condition1_str = "\ncondition1: ";
    char *result_str = "\nresult: ";
    char *result = ft_itoa(res); 
    char *expected_str = "\nexpected: ";
    char *expected = ft_itoa(exp);
    char *final_result = res == exp ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) + ft_strlen(c1_str) +  ft_strlen(condition1_str) + 
     + ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
    ft_strlcat(message, condition1_str, message_len);
	ft_strlcat(message, c1_str,message_len);
 	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(test_index_str);
    free(c_str);
    free(c1_str);
    free(result);
    free(expected);
    free(message);
}

void	create_results_strdup(char *file_name,int index_test, const char *c, char *exp, char *res)
{
    char sep[] = "-----------------------------------------------------\n";
	char *test_index_str = ft_itoa(index_test);
	char *c_str = (char *)c;
    char *condition_str = "\ncondition0: ";
    char *result_str = "\nresult: ";
    char *result = res; 
    char *expected_str = "\nexpected: ";
    char *expected = exp;
    char *final_result = strcmp(res, exp) ? "\nOK\n" : "\nKO\n";
    size_t message_len = (ft_strlen(sep) + ft_strlen(test_index_str) + ft_strlen(c_str) +  ft_strlen(condition_str) 
     + ft_strlen(result) +ft_strlen(result_str) + ft_strlen(expected)+ft_strlen(expected_str) + ft_strlen(final_result) + ft_strlen(sep)+ 1);
	char *message = (char *)malloc(sizeof(char) * message_len);
    
    ft_strlcpy(message, sep, message_len);
	ft_strlcat(message, test_index_str, message_len);
	
	ft_strlcat(message, condition_str, message_len);
	ft_strlcat(message, c_str,message_len);
 	ft_strlcat(message, result_str, message_len);
    ft_strlcat(message, result, message_len);
	ft_strlcat(message, expected_str,message_len);
    ft_strlcat(message, expected, message_len);
	ft_strlcat(message, final_result, message_len);
    ft_strlcat(message, sep, message_len);
    
	write_logs(file_name,message);
	
    free(test_index_str);
    free(message);
}