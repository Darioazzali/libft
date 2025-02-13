#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "helpers.h"


static void test_2(void);
static void test(void);

int	main(void)
{
	format_title(__FILE_NAME__);
	test();
	test_2();
}

static void test_2()
{
	char	*str;
	char	*output;
	int		start;
	size_t	len;

	printf("%s%-32s%6s%8s%s\n","\x1b[1m","string", "start", "len",KNRM);
	str = "a not so long string";
	start = 2;
	len = 3;
	printf("%-32s%6d%8zu\t",str, start, len);
	output = ft_substr(str, start, len);
	assert(strcmp(output,"not") == 0);
	printf("%sOK%s\n", KGRN, KNRM);

	start = 2;
	len = 100;
	printf("%-32s%6d%8zu\t",str, start, len);
	output = ft_substr(str, start, len);
	assert(strcmp(output,"not so long string") == 0);
	printf("%sOK%s\n", KGRN, KNRM);

	start = ft_strlen(str) - 1;
	len = 100;
	printf("%-32s%6d%8zu\t",str, start, len);
	output = ft_substr(str, start, len);
	assert(strcmp(output,"g") == 0);
	printf("%sOK%s\n", KGRN, KNRM);

	start = ft_strlen(str) + 10;
	len = 5;
	printf("%-32s%6d%8zu\t",str, start, len);
	output = ft_substr(str, start, len);
	assert(strcmp(output,"") == 0);
	printf("%sOK%s\n", KGRN, KNRM);
}

static void	test()
{
	char	*str;
	char	*output;

	str = "test";
	output = ft_substr(str, 2,10);
	assert(output != NULL);
	assert(strcmp(output, "st") == 0);
	free(output);

	output = ft_substr(str, 2,1);
	assert(output != NULL);
	assert(strcmp(output, "s") == 0);
	free(output);

	output = ft_substr(str, 10,5);
	assert(output != NULL);
	assert(strcmp(output, "") == 0);
	free(output);

	output = ft_substr(str, 10,5);
	assert(output != NULL);
	assert(strcmp(output, "") == 0);
	free(output);

	output = ft_substr(str, 0,20);
	assert(output != NULL);
	assert(strcmp(output, "test") == 0);
	free(output);
}

