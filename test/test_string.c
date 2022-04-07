/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:19:52 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/06 23:31:53 by bbonaldi         ###   ########.fr       */
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

	int	i = 0;
	int	j = 0;
	int	result;
	int	expect;
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
				result = ft_strncmp(s1s[i],s2s[j],s_max);
				transform_to_one(&result);
				expect = strncmp(s1s[i],s2s[j],s_max);
				transform_to_one(&expect);
				cr_expect( result == expect, 
				"s1:%s | s2:%s | s_max:%ld - ft_strncmp: %d != strncmp: %d"
				,s1s[i],s2s[j],s_max,result,expect);
				s_max--;
			}
			j++;
		}
		i++;
	}
	
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

Test(test_string, ft_strnstr_test)
{
	char *src[] = {"42 SCHOOL - SP", "Olá, meu nome é Bruno", "Brasil", "", NULL};
	char *subs[] = {"2 SCHOOL", "nome ", "Br", "Teste", NULL}; 
	int i = 0;
	int j = -2;
	while (src[i] != NULL)
	{
		int slen = (int)(ft_strlen(src[i]) + 20);
		while (j < slen)
		{	
			cr_expect(my_strcmp(ft_strnstr(src[i],subs[i],j),strnstr(src[i],subs[i],j)) == 0, "ft:%s | ori:%s -- index %d",
			ft_strnstr(src[i],subs[i],j),strnstr(src[i],subs[i],j), j);
			j++;
		}
		i++;
	}
}

Test(test_string, ft_strlcpy_test)
{
	char **src = random_string_generator(20);
	
	int i = 0;
	while (src[i])
	{	
		int random_int = generate_random_int(0,100,i);
		char dst[random_int];
		char dst1[random_int];
	
		cr_expect(ft_strlcpy(dst,src[i],sizeof(dst)) == strlcpy(dst1,src[i],sizeof(dst1)) && my_strcmp(dst,dst1) == 0,
		"ft=%d dst=%s| ori = %d dst1=%s", (int)ft_strlcpy(dst,src[i],sizeof(dst)), dst,(int)strlcpy(dst1,src[i],sizeof(dst1)), dst1);
		i++;
	}
	free_string_generator(src);

}

// Test(test_string, ft_strlcat_test)
// {
// 	char **src = random_string_generator(5);
// 	int random_int = generate_random_int(2500,2500,i);
// 	char dst[random_int];

// 	char dst1[random_int];

// 	int i = 0;
// 	while (src[i])
// 	{	
		

// 		cr_expect(ft_strlcat(dst,src[i],sizeof(dst)) == strlcat(dst1,src[i],sizeof(dst1)) && my_strcmp(dst1,dst) == 0,
// 		"ft_cat=%d dst=%s| ori_cat = %d dst1=%s", (int)ft_strlcat(dst,src[i],sizeof(dst)), dst,(int)strlcat(dst1,src[i],sizeof(dst1)), dst1);
// 		memset(dst1,0,random_int);
// 		memset(dst,0,random_int);
// 		i++;
// 	}
// 	free_string_generator(src);
	
// }