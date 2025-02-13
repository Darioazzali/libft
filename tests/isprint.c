#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void	test(int c);

int	main()
{
	for (int i = 0; i <= 127; i++)
		test(i);
}

void	test(int c)
{
	int	expected;
	int	output;

	expected = isprint(c) && true;
	output = ft_isprint(c) && true;
	printf("Original %d\n", isprint(c));
	printf("Mine %d\n", ft_isprint(c));
	assert(expected == output);
}
