/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:19:52 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/03 22:59:47 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	run_test_ctype_string(char **string_test, size_t (*result_function)(const char *),
						size_t (*expected_function)(const char *))
{
	int	result;
	int	expected;

	while(*string_test)
	{
		result = result_function(*string_test);
		expected = expected_function(*string_test);
		cr_expect(result == expected,
			"arg value: %s, result:%d != expect:%d",
			*string_test, result, expected);
		string_test++;
	}
}

int generate_random_int(int min, int max, int seed)
{
    int random_nbr;

    srandom(seed * random());
    random_nbr = min + (random() % (max - min +1));
    return (random_nbr);
}

void    populate_random_string(char *str, int desired_len)
{
    int index;

    index = 0;
    while (index < desired_len)
    {
        str[index] =  (char)generate_random_int(32,126,random());
        index++;
    }
    str[index] = '\0';
}

char    **random_string_generator(int qty)
{
    int index;
    char **test_values;
    int random_value;

    index = 0;
    test_values = (char **)malloc(sizeof(char *) * (qty + 1));
    
    while (index < qty)
    {
        random_value = generate_random_int(1,100, index);
        test_values[index] = (char *)malloc(sizeof(char *) * (random_value +1));
        populate_random_string(test_values[index], random_value);
        index++;
    }
    test_values[index] = NULL;
    return (test_values);
}



Test(test_ctype, ft_strlen_test)
{
	// char *tests_values[] = {"DNAKLDLA313131r532K 12DNAK 3\n\t"
	// , "dmakd", "qwsx \tvwq", "MAKLMCAS", "ASDNAS", NULL};
    char **tests_values = random_string_generator(5);
    // int i = 0;
    // while (tests_values[i])
    // {
    //     printf("%s\n",tests_values[i]);
    //     i++;
    // }
        
	run_test_ctype_string(tests_values, &ft_strlen, &strlen);
}
