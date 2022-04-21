#include "test.h"

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

void    remove_file(char *file_name)
{
    remove(file_name);

}