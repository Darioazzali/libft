#include "libft.h"
#include <assert.h>
#include <bsd/string.h>
#include <stdio.h>
#include "helpers.h"


static void	test_little_empty(void);
static void test_null_haystack_0_char();
static void test_found();
static void test_found2();
static void test_found3();
static void test_found4();
static void test_little_too_big();
static void test_strnstr(const char *big, const char *little, size_t len);

int	main()
{
	test_null_haystack_0_char();
	test_little_empty();
	test_found();
	test_found2();
	test_found3();
	test_found4();
	test_little_too_big();

	test_strnstr("hello world", "hello", 11);
	test_strnstr("world hello there", "hello", 16);
	test_strnstr("world there", "hello", 11);
	test_strnstr("hello world", "hello", 3);
	test_strnstr("hello", "hello", 5);
	test_strnstr("hello world hello", "hello", 8);
	test_strnstr("", "hello", 0);
	test_strnstr("hello hello hello", "hello", 17);
	test_strnstr("hel hello", "hello", 17);
	test_strnstr("helhello", "hello", 8);
	test_strnstr("mississippi", "issi", 11);
	test_strnstr("hello", "hello", 0);
	test_strnstr("hello", "hello", 4);
   	test_strnstr("lorem ipsum dolor sit amet", "sit", 10);
   	test_strnstr("MZIRIBMZIRIBMZE123","MZIRIBMZE", 22);
}

static void	test_found()
{
	char	*haystack;	
	char	*needle;
	char	*expected;
	char	*output;

	haystack = "prova";
	needle = "pro";
	expected = strnstr(haystack, needle, 3);
	output = ft_strnstr(haystack, needle, 3);
	assert(expected == haystack);
	assert(output == haystack);
}

static void test_found2()
{
	char	*haystack;	
	char	*needle;
	char	*expected;
	char	*output;

	haystack = "unaprova";
	needle = "pro";
	expected = strnstr(haystack, needle, 6);
	output = ft_strnstr(haystack, needle, 6);
	assert(expected == (haystack + 3));
	assert(output == (haystack + 3));
}


static void test_found3()
{
	char	*haystack;	
	char	*needle;
	char	*expected;
	char	*output;

	haystack = "unaprova";
	needle = "pro";
	expected = strnstr(haystack, needle, 3);
	output = ft_strnstr(haystack, needle, 3);
	assert(expected == NULL);
	assert(output == NULL);
}

static void test_found4()
{
	char	*haystack;	
	char	*needle;
	char	*expected;
	char	*output;

	haystack = "unaprova";
	needle = "va";
	expected = strnstr(haystack, needle, 8);
	output = ft_strnstr(haystack, needle, 8);
	assert(expected == (haystack + 6));
	assert(output == (haystack + 6));
}

static void	test_null_haystack_0_char()
{
	char	*haystack;	
	char	*needle;
	char	*expected;
	char	*output;

	haystack = NULL;
	needle = "prova";
	expected = strnstr(haystack, needle, 0);
	output = ft_strnstr(haystack, needle, 0);
	assert(expected == NULL);
	assert(output == NULL);
}
static void	test_little_empty()
{
	test_strnstr("hello", "", 5);
}


static void test_little_too_big()
{
    char	*little;
    char	*big;
	char	*expected;
	char	*output;

	big = "allora come fdfkadf;";
	little = "come";
	expected = strnstr(big, little, 3);
	output = ft_strnstr(big, little, 3);
	assert(expected == output);
}

static void test_strnstr(const char *big, const char *little, size_t len) {
	printf("%-30s%-12s%-2zu\t", *big ? big : "\"\"", *little ? little : "\"\"", len);
    char *expected = strnstr(big, little, len);
    char *result = ft_strnstr(big, little, len);

    assert(result == expected);
	printf("%sOK%s\n",KGRN, KNRM);
}
