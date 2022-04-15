/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_results_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:03:46 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/15 13:28:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void    remove_file(char *file_name)
{
    int fd;
    fd = open(file_name, O_CREAT|O_WRONLY|O_TRUNC);
    close(fd);
}

void	write_logs(char *file_name, char *message)
{
	int fd;

	fd = open(file_name, O_WRONLY|O_APPEND, 0644);
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