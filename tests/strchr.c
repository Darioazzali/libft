#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"

static void	test(char *haystack, int needle);
static void	test_not_found_gives_NULL(char *haystack, char needle);
static void	test(char *haystack, int needle);
static void	test_empty_string();

int	main()
{
	format_title(__FILE_NAME__);
	printf("%-30s%-24s%-8s%4s\n","Test name", "Haystack", "Needle", "UChar");
	test( "a  st to find definly", 'd');
	test( "a  st to find definly", 'a');
	test( "a  st to find definly", '\0');
	test( "a  st to find definly", 'a' + 256); // Integer promotion.
	test( "aaaabbb", 'a');
	test_not_found_gives_NULL( "a  st to finD definly", 'h');
	test_empty_string();
}

static void	test(char *haystack, int needle)
{
	char	*expected;
	char	*output;
	
	printf("%-30s%-24s%-8c%4d\t",__func__, haystack, needle, needle);
	expected = strchr(haystack, needle);
	output = ft_strchr(haystack, needle);
	assert(output == expected);
	assert(*output == (unsigned char) needle);
	printf("%sOK%s\n",KGRN,KNRM);
}

static void	test_not_found_gives_NULL(char *haystack, char needle)
{
	char	*expected;
	char	*output;

	printf("%-30s%-24s%-8c%4d\t",__func__, haystack, needle? needle : ' ', needle);
	expected = strchr(haystack, needle);
	output = ft_strchr(haystack, needle);
	assert(output == expected);
	printf("%sOK%s\n",KGRN,KNRM);
}

static void	test_empty_string()
{
	char	*expected;
	char	*output;

	printf("%-30s%-24s%-8c%4d\t",__func__, "\"\"", 'a', 'a');
	expected = strchr("", 'a');
	output = ft_strchr("", 'a');
	assert(output == expected);
	printf("%sOK%s\n",KGRN,KNRM);
}

