#include "libft.h"
#include <assert.h>
#include <string.h>


static void test_1();
static void test_empty_strings();
static void test_size_0();
static void test_negative_n();

int	main()
{

	test_1();
	test_negative_n();
	test_size_0();
	test_empty_strings();
}

static void	test(char *str1, char *str2, int n)
{
	int		expected;
	int		output;

	expected = strncmp(str1, str2, n);
	output = ft_strncmp(str1, str2, n);
	assert(output == expected);
}

static void test_1()
{
	test("ABC", "AB", 3);
	test("ABC", "ABCDEFGH", 11);
    test("AB", "A", 2);
    test("A", "A", 1);
    test("A", "B", 1);
}

static void test_negative_n()
{
	test("ABC", "AB", -1);
	test("A", "ABCDFF", -1);
}

static void test_size_0()
{
	test("ABC", "AB", 0);
	test("AB", "ABCD", 0);
	test("AGFLKSD", "434324", 0);
}

static void test_empty_strings()
{
	test("", "AB", 10);
	test("ABFLKD", "", 12);
	test("", "", 1);
}
