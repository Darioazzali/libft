#include "libft.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"
#define COLOR_BOLD  "\e[1m"
#define COLOR_OFF   "\e[m"

void	test(int input, char *expected)
{
	char	*output;

	output = ft_itoa(input);
	printf("%-8s%-14d%-14s\t", __func__, input, output);
	assert(strcmp(output,expected) == 0);
	printf("%sOK%s\n", KGRN, KNRM);
}
int	main(void)
{
	format_title(__FILE_NAME__);
	printf("%s%-8s%-14s%-14s%s\n", COLOR_BOLD, "Name", "input", "OUTPUT", COLOR_OFF);
	char	int_max[14];
	test(1234,"1234");
	test(-1234,"-1234");
	sprintf(int_max, "%d", INT_MIN);
	test(INT_MIN, int_max);
	sprintf(int_max,"%d", INT_MAX);
	test(INT_MAX, int_max);
	test(0, "0");
	test(1, "1");
	test(-1, "-1");
	test(-0, "0");
}
