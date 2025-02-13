#include <stddef.h>
#include <assert.h>
#include <stdio.h>

static	size_t	count_words(char const *str, char sep)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == sep)
		{
			while (*str && *str == sep)
				str++;
			continue;
		}
		while(*str && *str != sep)
			str++;
		i++;
	}
	return (i);
}

void test()
{
	char	*input;
	char	sep;

	input = "  1 2 3   4  ";
	sep = ' ';
	assert(count_words(input, sep) ==  4);

	input = "1 2 3   4";
	sep = ' ';
	assert(count_words(input, sep) ==  4);

	input = "1 2 3   4   ";
	sep = ' ';
	assert(count_words(input, sep) ==  4);

	input = "   ";
	sep = ' ';
	assert(count_words(input, sep) ==  0);
}

int	main(void)
{
	test();
}
