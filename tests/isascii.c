#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "helpers.h"

void	test(int);

int	main()
{
	format_title(__FILE_NAME__);
	for (int i = 0; i <= 255; i++)
		test(i);
	printf("Test all char\t%sOK%s\n", KGRN, KNRM);
}

void	test(int c)
{
	int	expected;
	int	output;

	expected = isascii(c) && true;
	output = ft_isascii(c) && true;
	assert(expected == output);
}
