#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"

static void	test(char *haystack, int needle);
static void	test_no_res(char *haystack, char needle);
static void test_unsigned_char(char *haystack);


int	main()
{
	format_title(__FILE_NAME__);
	char	*haystack;

	haystack = "a  dst to finD definly";
	test(haystack, 'd');
	test(haystack, 'a');
	test(haystack, 'y');
	test_unsigned_char(haystack);
	test("prova\0", '\0');
	test("\0\0\0", '\0');
	test("", '\0');
	test_no_res(haystack, 'h');
}
void	test(char *haystack, int needle)
{
	char	*expected;
	char	*output;

	char formatted[50];  // Adjust size based on your needs
	if (haystack[0] == '\0') 
	{
		strcpy(formatted, "\"\"");
	}
	else 
	{
		sprintf(formatted, "\"%s\"", haystack);
	}
	printf("%-14s%-28s%-4c%4d\t", __func__, formatted, needle? needle : ' ',needle);
	expected = strrchr(haystack, needle);
	output = ft_strrchr(haystack, needle);
	assert(output == expected);
	assert(*output == (unsigned char) needle);
	printf("%sOK%s\n", KGRN, KNRM);

}

/**
 *	Value is passed as an int(integer promotion).
 *	Check if handle the conversion 
 *	to unsigned char correctly
*/
static void test_unsigned_char(char *haystack)
{

	test(haystack, 'e' + 256);
}

void	test_no_res(char *haystack, char needle)
{
	char	*expected;
	char	*output;

	expected = (char *)0;
	output = ft_strrchr(haystack, needle);
	assert(output == expected);
}

