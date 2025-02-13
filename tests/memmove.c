#include "libft.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "helpers.h"

static void	test_overlap(void);
static void	test_cpy_no_overlap(void);
static void	test_shift_right(void);
static void	test_shift_left(void);
static void test_both_inputs_null_size_0();
static void	test_src_null_size_0();
static void test_dst_null_size_0();

int	main()
{
	format_title(__FILE_NAME__);
	test_cpy_no_overlap();
	test_overlap();
	test_shift_right();
	test_shift_left();
	test_both_inputs_null_size_0();
	test_src_null_size_0();
	test_dst_null_size_0();
}

static void	test_overlap(void)
{
	char	input[6]={'a','b','c','d','e','\0'};
	char	*expected;
	char	*dest;
	int		byte_nr;
	char	*result;

	printf("%-30s ", __func__);
	byte_nr = 2;
	dest = (input + byte_nr);
	expected = (char *) malloc(sizeof(input));
	expected = memcpy(expected, input, 6);
	result = (char *) ft_memmove(dest, input, byte_nr);
	memmove((expected + byte_nr), expected, byte_nr);
	for (unsigned long i = 0; i < sizeof(input); i++)
	{
		assert(input[i] ==  expected[i]);
	}
	assert(result == dest);
	printf("%sOK\n%s", KGRN, KNRM);
}
static void	test_cpy_no_overlap(void)
{
	char	*input;
	char	*tocopy;

	printf("%-30s ", __func__);
	tocopy = "outpu";
	input = strdup( "input");
	ft_memmove(input, tocopy, 5);
	assert(strcmp(input, tocopy) == 0);
	printf("%sOK\n%s", KGRN, KNRM);
}


/* Shift right.*/
static void	test_shift_right(void)
{
    char	*dst;
    char	*dst2;

	printf("%-30s ", __func__);
	char	src2[] = "lorem ipsum dolor sit amet";
	dst2 = src2 + 1;
	memmove(dst2, src2, 8);

	char	src[] = "lorem ipsum dolor sit amet";
	dst = src + 1;
	ft_memmove(dst, src, 8);
	assert(strcmp(dst,dst2) == 0);
	assert(strcmp(src,src2) == 0);
	printf("%sOK\n%s", KGRN, KNRM);
}

/* Shift the bytes to the left.*/
static void	test_shift_left(void)
{
    char	*dst;
    char	*dst2;

	printf("%-30s ", __func__);
	char	src[] = "lorem ipsum dolor sit amet";
	dst = src + 1;
	ft_memmove(src, dst, 8);

	char	src2[] = "lorem ipsum dolor sit amet";
	dst2 = src2 + 1;
	memmove(src2, dst2, 8);
	
	assert(!strcmp(src2,src));
	assert(!strcmp(dst2,dst));
	printf("%sOK\n%s", KGRN, KNRM);
}


static void test_both_inputs_null_size_0()
{
	char	*src;
	char	*dst;

	printf("%-30s ", __func__);
	src = NULL;
	dst = NULL;
	ft_memmove(src, dst, 0);
	assert(dst == dst);
	printf("%sOK\n%s", KGRN, KNRM);
}

static void test_src_null_size_0()
{
	char	*src;
	char	*dst;

	printf("%-30s ", __func__);
	src = NULL;
	dst = malloc(10);
	dst = ft_memmove(src, dst, 0);
	assert(dst == dst);
	printf("%sOK\n%s", KGRN, KNRM);
	free(dst);
}

static void test_dst_null_size_0()
{
	char	*src;
	char	*dst;

	printf("%-30s ", __func__);
	src = "prova";
	dst = NULL;
	dst = ft_memmove(src, dst, 0);
	assert(dst == dst);
	printf("%sOK\n%s", KGRN, KNRM);
}
