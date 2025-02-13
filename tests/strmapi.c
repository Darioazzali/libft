#include "libft.h"
#include <string.h>
#include <assert.h>

char	to_upper(unsigned int i, char c)
{
	char	res;

	(void) i;
	res = 'A' + c - 'a';
	return (res);
}

char	odd_uppercase(unsigned int i, char c)
{
	if ((i % 2) == 0)
		return ('A' + c - 'a');
	return (c);
}

int	main(void)
{
	char	*res;
	
	res = ft_strmapi("prova", to_upper);
	assert(strcmp(res, "PROVA") == 0);
	res = ft_strmapi("prova", odd_uppercase);
	assert(strcmp(res, "PrOvA") == 0);
}
