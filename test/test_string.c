/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:19:52 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/05 23:32:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	run_test_string_string(char **string_test, size_t (*result_function)(const char *),
						size_t (*expected_function)(const char *))
{
	int	result;
	int	expected;
	int index;

	index = 0;
	while(string_test[index])
	{
		result = result_function(string_test[index]);
		expected = expected_function(string_test[index]);
		cr_expect(result == expected,
			"arg value: %s, result:%d != expect:%d",
			string_test[index], result, expected);
		index++;
	}
}

void	run_test_string_strchr(char **string_test,  char  *find_c, char *(*result_function)(const char *, int),
						char *(*expected_function)(const char *, int))
{
	char	*result;
	char	*expected;
	int index;

	index = 0;
	while (string_test[index])
	{
		while(*find_c)
		{
			result = result_function(string_test[index], *find_c);
			expected = expected_function(string_test[index], *find_c);
			cr_expect(result == expected,
				"arg value: %s, should_find: %c , result:%d != expect:%d",
				*string_test, *find_c, result, expected);
			find_c++;
		}
		string_test++;
	}
	cr_expect(result == expected,
			"arg value: %s, should_find: %c , result:%d != expect:%d",
			string_test[index], '\0', result, expected);
}

Test(test_string, ft_strlen_test)
{
	char **tests_values = random_string_generator(TEST_STRING_QTY);   
	run_test_string_string(tests_values, &ft_strlen, &strlen);
	free_string_generator(tests_values);
}

Test(test_string, ft_strchr_test)
{
	char **tests_values = random_string_generator(TEST_STRING_QTY);   
	char *find_chars = create_ascii_arr();
	run_test_string_strchr(tests_values, find_chars, &ft_strchr, &strchr);
	free(find_chars);
	free_string_generator(tests_values);
}

Test(test_string, ft_strrchr_test)
{
	char **tests_values = random_string_generator(TEST_STRING_QTY);  
	char *find_chars = create_ascii_arr();
	run_test_string_strchr(tests_values, find_chars, &ft_strrchr, &strrchr);
	free(find_chars);
	free_string_generator(tests_values);
}

Test(test_string, ft_strncmp_test)
{
	char	*s1s[] = {"", "Brun", "bru", "bonalDisadada", "ABCDEF", NULL};
	char	*s2s[] = {"", "Bru", "bru", "bonalDi", "ABCDEFeeeee", NULL};

	int i = 0;
	int j = 0;
	while(s1s[i])
	{
		j = 0;
		size_t s1_len = ft_strlen(s1s[i]);
		while (s2s[j])
		{
			size_t s2_len = ft_strlen(s2s[j]);
			size_t s_max = s1_len > s2_len ? s1_len : s2_len;
			while (s_max)
			{
				cr_expect(ft_strncmp(s1s[i],s2s[j],s_max) == strncmp(s1s[i],s2s[j],s_max), 
				"s1:%s | s2:%s | s_max:%ld - ft_strncmp: %d != strncmp: %d"
				,s1s[i],s2s[j],s_max,
				ft_strncmp(s1s[i],s2s[j],s_max),
				strncmp(s1s[i],s2s[j],s_max));
				s_max--;
			}
			j++;
		}
		i++;
	}
	
}


Test(test_string, ft_strnstr_test)
{
	char *src = "42 SCHOOL - SP";
	char *subs = "2 SCH"; 
	int i = 0;
	while (i < 10)
	{

		cr_expect(strcmp(ft_strnstr(src,subs,i),strnstr(src,subs,i)) == 0, "ft:%s | ori:%s",
		 ft_strnstr(src,subs,i),strnstr(src,subs,i));
		i++;
	}
	
}