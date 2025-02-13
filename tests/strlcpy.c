#include <assert.h>
#include <stdio.h>
#include <bsd/string.h>
#include <libft.h>
#include "helpers.h"

static void test(char *src,char *dst, size_t size);
// static void test_substr();
static void test_truncates();
static void	test_size_0();
static void	test_size_1();
static void	test_normal_cpy();

/**
 *	Behavior of the original strlcpy.
 *	If the size is major than the buffer size is UB.
 *	
*/

int	main(void)
{
	format_title(__FILE_NAME__);
	test_size_0();
	test_size_1();
	test_truncates();
	test_normal_cpy();
}

static void	test_normal_cpy()
{
	char	dest[22];
	char	*src;

	printf("%-30s\t",__func__);
	src = "a very long string";
	test(src, dest, strlen(src) + 1);
	printf("%sOK%s\n", KGRN, KNRM);
}

/** When the size is zero dst remain untouched */
static void	test_size_0()
{
	printf("%-30s\t",__func__);
	char	dest[]="prova";
	test("test", dest, 0);
	printf("%sOK%s\n", KGRN, KNRM);
}

static void test_truncates()
{
	char	dest[]="prova";

	printf("%-30s\t",__func__);
	test("test", dest, 4);
	printf("%sOK%s\n", KGRN, KNRM);
}

static void	test_size_1()
{
	char	dest[]="prova";

	printf("%-30s\t",__func__);
	test("test a long string", dest, 1);
	printf("%sOK%s\n", KGRN, KNRM);
}

static void test(char *src,char *dst, size_t size)
{
	char	*orig_src;
	char	*orig_dst;
	size_t	orig_res;
	size_t	res;

	orig_src = src;
	orig_dst = dst;
	size = 4;
	res = ft_strlcpy(dst, src, size);
	orig_res = strlcpy(orig_dst, orig_src, size);
	assert(strcmp(dst , orig_dst) == 0);
	assert(res == orig_res);
}

/**
*	Behavior of the original strlcpy.
*	If the size is less, truncates the result
*	but return the len of the original string.
*	static void original_truncates()
*	{
*		char	*src;
*		char	dest[12];
*		size_t	res;
*	
*		src = "a long string with little size";
*	    res = strlcpy(dest, src, 2);
*	    assert(strcmp(dest, "a") == 0);
*	    assert(res == strlen(src));
*	}
*/

/** Original strlcpy. 
*	static void	original_strlcpy()
*	{
*		char	dest[5];
*		char	*src;
*		size_t	size;
*		size_t	bytes_copied;
*	
*		src = "test";
*		size = sizeof(dest) / sizeof(char);
*		assert(size == 5);
*		bytes_copied = strlcpy(dest, src, size);
*		assert(strcmp(dest, src) == 0);
*		assert(dest[size -1] == '\0');
*		assert(bytes_copied == size - 1);
*	}
*/

// static void test_substr()
// {
// 	char	*original;
// 	char	dest[4];
//
// 	original="test";
// 	ft_strlcpy(dest, (original + 2),3);
// 	assert(strcmp(dest, "st") ==  0);
// }
