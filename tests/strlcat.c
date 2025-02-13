#include <assert.h>
#include <stdio.h>
#include <bsd/string.h>
#include <libft.h>
#include <execinfo.h>
#include "helpers.h"

static void	test_original_strlcat();
static void	test_empty_string(size_t (*f)(char *,const char *,size_t));
static void	test(size_t (*f)(char *, const char *, size_t));
static void test_edge_cases_unchanged();
static void	test_truncate(size_t (*f)(char *, const char *, size_t));

int	main(void)
{
	test_original_strlcat();
	test(strlcat);
	test(ft_strlcat);
	test_empty_string(strlcat);
	test_empty_string(ft_strlcat);
	test_edge_cases_unchanged();
	test_truncate(strlcat);
	test_truncate(ft_strlcat);
}

static void	test_original_strlcat()
{
	char	dest[10]={'t','e','s','t','\0'};
	char	*src;
	size_t	size;
	size_t	total_len;
	char	*expected;
	size_t	expected_len;

	expected = "test ok";
	expected_len = strlen(expected);
	src = " ok";
	size = sizeof(dest) / sizeof(char);
	assert(size == 10);
	total_len = strlcat(dest, src, size);
	/** Assertions */
	assert(total_len == expected_len);
	assert(strcmp(dest, expected) == 0);
}

static void  test_truncate(size_t (*f)(char *, const char *, size_t))
{
	size_t size;
	char dst[8] = "Hi";
	char src[] = "World";
	size = (*f)(dst, src, 3);
	assert(size == 7);
	assert(strcmp(dst,"Hi") == 0);
}

static void	test_edge_case_unchanged(size_t (*f) (char *, const char *, size_t), size_t given_size, char *expected)
{
	size_t size;
	char dst[8] = "Hi";
	char src[] = "World";

	size = (*f)(dst, src, given_size);
	assert(size == 7);
	assert(strcmp(dst, expected) == 0);

}

static void	test_edge_case_unchanged_size_changes(size_t (*f) (char *, const char *, size_t), size_t given_size, char *expected, size_t expected_size)
{
	size_t size;
	char dst[8] = "Hi";
	char src[] = "World";

	size = (*f)(dst, src, given_size);
	assert(size == expected_size);
	assert(strcmp(dst, expected) == 0);

}

static void test_edge_cases_unchanged()
{
	/** Remains unchanged  and return the sum of the lengths*/
	for (size_t i=2; i <= 3; i++)
	{
		test_edge_case_unchanged(strlcat, i, "Hi");
		test_edge_case_unchanged(ft_strlcat, i, "Hi");
	}

	/** Remains unchanged  and return the size + src_len*/

	for (size_t i=0; i <= 1; i++)
	{
		test_edge_case_unchanged_size_changes(strlcat, i, "Hi",5 + i);
		test_edge_case_unchanged_size_changes(ft_strlcat, i, "Hi",5 + i);
	}
}

static void	test(size_t (*f)(char *, const char *, size_t))
{
	char	dest[10]={'t','e','s','t','\0'};
	char	*src;
	size_t	size;
	size_t	total_len;
	char	*expected;
	size_t	expected_len;

	expected = "test ok";
	expected_len = strlen(expected);
	src = " ok";
	printf("%-30s%-20s\t", src, expected);
	size = sizeof(dest) / sizeof(char);
	assert(size == 10);
	total_len = (*f)(dest, src, size);
	/** Assertions */
	assert(total_len == expected_len);
	assert(strcmp(dest, expected) == 0);
	printf("%sOK%s\n",KGRN, KNRM);
}

static void	test_empty_string(size_t (*f)(char *,const char *,size_t))
{
	char	dst[10]={'\0'};
	char	src[] = "World";
	size_t	total_len;

	total_len = (*f)(dst, src, 4);

	assert(total_len == 5);
    assert(strcmp(dst,"Wor") == 0);
}
