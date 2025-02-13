#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "helpers.h"

void	test(int c)
{
	int	expected;
	int	output;

	// printf("Testing %d\n", c);
	expected = isalnum(c) && true;
	output = ft_isalnum(c) && true;
	// printf("expected %d\n", expected);
	// printf("output %d\n", output);
	assert(expected == output);
}
int	main()
{
	format_title(__FILE_NAME__);
	for (int i = 0; i <= 127; i++)
		test(i);
	printf("all ascii\t%sOK%s\n", KGRN, KNRM);
}
