#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

void	test(int c)
{
	int	expected;
	int	output;

	// printf("Testing %d\n", c);
	expected = isdigit(c) && true;
	output = ft_isdigit(c) && true;
	// printf("expected %d\n", expected);
	// printf("output %d\n", output);
	assert(expected == output);
}
int	main()
{
	for (int i = 0; i <= 127; i++)
		test(i);
}
