/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:19:52 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 18:14:10 by bbonaldi         ###   ########.fr       */
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
    char *start = find_c;
	while (string_test[index])
	{
        find_c = start;
		while(*find_c)
		{
			result = result_function(string_test[index], *find_c);
			expected = expected_function(string_test[index], *find_c);
			cr_expect(my_strcmp(result, expected) == 0,
				"arg value: %s, should_find: %c , result:%d != expect:%d",
				*string_test, *find_c, result, expected);
			find_c++;
		}
		index++;
	}
	cr_expect(my_strcmp(result, expected) == 0,
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
		int random_int = generate_random_int(1,100,i);
		char dst[random_int];
		char dst1[random_int];
	
		cr_expect(ft_strlcpy(dst,src[i],sizeof(dst)) == strlcpy(dst1,src[i],sizeof(dst1)) && my_strcmp(dst,dst1) == 0,
		"ft=%d dst=%s| ori = %d dst1=%s", (int)ft_strlcpy(dst,src[i],sizeof(dst)), dst,(int)strlcpy(dst1,src[i],sizeof(dst1)), dst1);
		i++;
	}
	free_string_generator(src);

}



Test(test_string, ft_strlcat_test)
{
	//char **src = random_string_generator(10);


	// int i = 0;
	// while (src[i])
	// {	
	// 	int random_int = generate_random_int(strlen(src[i]),strlen(src[i]) + 100,i);
	// 	char dst[random_int];
	// 	int int_other_random = generate_random_int(32,126,i);
	// 	memset(dst, int_other_random,random_int / 2);
 	// 	char dst1[random_int];
	// 	memset(dst1,int_other_random,random_int / 2);
 	// 	cr_expect(ft_strlcat(dst,src[i],sizeof(dst)) == strlcat(dst1,src[i],sizeof(dst1)) && my_strcmp(dst1,dst) == 0,
	// 	"src=%s\ni=%d\nft_cat=%d dst=%s\nori_cat=%d dst1=%s", src[i],i,
	// 	(int)ft_strlcat(dst,src[i],sizeof(dst)), 
	// 	dst,
	// 	(int)strlcat(dst1,src[i],sizeof(dst1)), dst1);
	// 	i++;
	// }
	//free_string_generator(src);

	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";
	dest[0] = 'B';
	/* 1 */ cr_expect(ft_strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "B"));
	dest[0] = 'B';
	/* 2 */ cr_expect(ft_strlcat(dest, src, 1) == 10 && !strcmp(dest, "B"));
	memset(dest, 'B', 4);
	/* 3 */ cr_expect(ft_strlcat(dest, src, 3) == 3 + strlen(src) && !strcmp(dest, "BBBB"));
	/* 4 */ cr_expect(ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA"));
	memset(dest, 'C', 5);
	/* 5 */ cr_expect(ft_strlcat(dest, src, -1) == 14 && !strcmp(dest, "CCCCCAAAAAAAAA"));
	memset(dest, 'C', 15);
	/* 6 */ cr_expect(ft_strlcat(dest, src, 17) == 24 && !strcmp(dest, "CCCCCCCCCCCCCCCA"));
	memset(dest, 0, 30);
	/* 7 */ cr_expect(ft_strlcat(dest, src, 1) == strlen(src) && !strcmp(dest, ""));
	memset(dest, 0, 30); memset(dest, '1', 10);
	/* 8 */ cr_expect(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30); memset(dest, '1', 10);
	/* 9 */ cr_expect(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30); memset(dest, '1', 10);
	/* 10 */ cr_expect(ft_strlcat(dest, "", 15) == 10 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30);
	/* 11 */ cr_expect(ft_strlcat(dest, "", 42) == 0 && !strcmp(dest, ""));
	memset(dest, 0, 30);
	/* 12 */ cr_expect(ft_strlcat(dest, "", 0) == 0 && !strcmp(dest, ""));
	memset(dest, 0, 30);
	/* 13 */ cr_expect(ft_strlcat(dest, "123", 1) == 3 && !strcmp(dest, ""));
	memset(dest, 0, 30);
	/* 14 */ cr_expect(ft_strlcat(dest, "123", 2) == 3 && !strcmp(dest, "1"));
	memset(dest, 0, 30);
	/* 15 */ cr_expect(ft_strlcat(dest, "123", 3) == 3 && !strcmp(dest, "12"));
	memset(dest, 0, 30);
	/* 16 */ cr_expect(ft_strlcat(dest, "123", 4) == 3 && !strcmp(dest, "123"));
	memset(dest, 0, 30);
	size_t i = strlcat(dest, "123", 0);
	//printf("%ld | %s", i, dest);
	/* 17 */ cr_expect(i == 3 && !strcmp(dest, ""), "%d | %s", i, dest);
	
}

Test(test_string, ft_strdup_test)
{
	char **src = random_string_generator(TEST_STRING_QTY);
	int i = 0;
	while (src[i])
	{
		char	*result = ft_strdup(src[i]);
		char	*expected = strdup(src[i]);
		cr_expect(my_strcmp(result,expected) == 0,"src=%s\nresult=%s\nexpected:%s", src[i], result, expected);
		i++;
		free(result);
		free(expected);
	}
	free_string_generator(src);
}

Test(test_string, ft_memset)
{
	char **src = random_string_generator(TEST_STRING_QTY);
	size_t i = 0;
	while (src[i])
	{
		void *cp_src = strdup(src[i]);
		size_t n = generate_random_int(1,strlen(src[i]),i);
		int c = generate_random_int(32,126,i);
 		ft_memset(cp_src, c , n);
		void *cp_src2 = strdup(src[i]);
		memset(cp_src2, c, n);
		cr_expect(ft_memcmp(cp_src,cp_src2, strlen(cp_src2)) == 0,"i=%d\nsrc=%.*s\nresult=%.*s\nexpected=%s\n",i, src[i], cp_src, cp_src2);
		i++;
		free(cp_src);
		free(cp_src2);
	}
	free_string_generator(src);
}

Test(test_string, ft_bzero)
{
	char **src = random_string_generator(TEST_STRING_QTY);
	size_t i = 0;
	while (src[i])
	{
		void *cp_src = strdup(src[i]);
		void *cp_src2 = strdup(src[i]);
        void *cp_src3 = strdup(src[i]);
		ft_bzero(cp_src, (size_t)generate_random_int(1,20,i));
		bzero(cp_src2, (size_t)generate_random_int(1,20,i));
		cr_expect(ft_memcmp(cp_src,cp_src2, strlen(cp_src)) == 0,"i=%d\nsrc=%s\nresult=%.*s\nexpected=%.*s\n",i, cp_src3, cp_src, cp_src2);
		i++;
		free(cp_src);
		free(cp_src2);
        free(cp_src3);
	}
	free_string_generator(src);
}

Test(test_string, ft_memcpy)
{
	char dest[100];
	memset(dest, 'A', 100);
	ft_memcpy(dest, "coucou", 0);
	/* 1 */ cr_expect(dest[0] == 'A');
	char src[] = {0, 0};
	ft_memcpy(dest, src, 2);
	int i = 0;
	for (; i < 100 && dest[i] == 0; ++i)
		;
	/* 2 */ cr_expect(i == 2 && dest[2] == 'A', "%d | %c", i  , dest[2] );
}



Test(test_string, ft_memmove)
{

	
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	/* 1 */ cr_expect(ft_memmove(s0, s, 7) == s0 && !memcmp(s, s0, 7));  //Post 0
	/* 2 */ cr_expect(ft_memmove(s, s + 2, 0) && !memcmp(s, sCpy, 7));  //0 move
	/* 3 */ cr_expect(ft_memmove(s, s + 2, 2) == s && !memcmp(s, sResult, 7));  //forward
	/* 4 */ cr_expect(ft_memmove(sResult + 1, sResult, 2) == sResult + 1 && !memcmp(sResult, sResult2, 7));  //reverse
}


void	run_test_string_memchr(char **string_test,  char  *find_c, void *(*result_function)(const void *, int, size_t),
						void *(*expected_function)(const void *, int, size_t))
{
	void	*result;
	void	*expected;
	int index;

	index = 0;
    char *start = find_c;
	while (string_test[index])
	{
        find_c = start;
		while(*find_c)
		{
            size_t random_int = generate_random_int(0, ft_strlen(string_test[index]), index);
			result = result_function(string_test[index], *find_c, random_int);
			expected = expected_function(string_test[index], *find_c, random_int);
			cr_expect(result == expected,
				"arg value: %s, should_find: %c , result:%d != expect:%d",
				*string_test, *find_c, result, expected);
			find_c++;
		}
		index++;
	}
	cr_expect(result == expected,
			"arg value: %s, should_find: %c , result:%d != expect:%d",
			string_test[index], '\0', result, expected);
}

Test(test_string, ft_memchr_teste)
{
	char **tests_values = random_string_generator(TEST_STRING_QTY);   
	char *find_chars = create_ascii_arr();
	run_test_string_memchr(tests_values, find_chars, &ft_memchr, &memchr);
	free(find_chars);
	free_string_generator(tests_values);
}


Test(test_string, ft_memcmp_test)
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	/* 1 */ cr_expect(ft_memcmp(s, sCpy, 4) == memcmp(s, sCpy, 4) ,"%d | %d", ft_memcmp(s, sCpy, 4),memcmp(s, sCpy, 4)); 
	/* 2 */ cr_expect(ft_memcmp(s, s2, 0) == memcmp(s, s2, 0) ,"%d | %d", ft_memcmp(s, s2, 0),  memcmp(s, s2, 0)); 
	/* 3 */ cr_expect(ft_memcmp(s, s2, 1)  == memcmp(s, s2, 1) ,"%d | %d", ft_memcmp(s, s2, 1) ,  memcmp(s, s2, 1)); 
	/* 4 */ cr_expect(ft_memcmp(s2, s, 1)  == memcmp(s2, s, 1) ,"%d | %d", ft_memcmp(s2, s, 1) ,  memcmp(s2, s, 1));
	/* 5 */ cr_expect(ft_memcmp(s2, s3, 4) > 0 && memcmp(s2, s3, 4) > 0 ,"%d | %d", ft_memcmp(s2, s3, 4)  , memcmp(s2, s3, 4));
}

