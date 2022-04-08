#include "test.h"

int generate_random_int(int min, int max, int seed)
{
    int random_nbr;

    srandom(seed * random());
    random_nbr = rand() % (max + 1 - min) + min;
    return (random_nbr);
}

void    populate_random_string(char *str, int desired_len)
{
    int index;

    index = 0;
    while (index < desired_len)
    {
        str[index] =  (char)generate_random_int(33,126,random());
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
        test_values[index] = (char *)malloc(sizeof(char *) * (random_value + 1));
        populate_random_string(test_values[index], random_value);
        index++;
    }
    test_values[index] = NULL;
    return (test_values);
}

void	free_string_generator(char **test_values)
{
	int	i;

	i = 0;
	while (test_values[i])
	{	
		free(test_values[i]);
		i++;
	}
	free(test_values);
}