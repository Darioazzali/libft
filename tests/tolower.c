#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

void	test(int c)
{
	int	expected;
	int	output;

	// printf("Testing char '%c'\n", c);
	expected = tolower(c);
	// printf("expected %c\n", expected);
	output = ft_tolower(c);
	// printf("output %c\n", output);
	assert(expected == output);
}
int	main(void)
{
	for (int i = 1; i <= 127; i++)
		test(i);
}
