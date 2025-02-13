#include "libft.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"


static void	test_overlap(void);
static void	test_str();
static void	test_non_str();
static void	test_no_corrupt_memory();
static void	test_zero_bytes_unchanged();

int	main()
{
	test_str();
	test_overlap();
	test_non_str();
	test_no_corrupt_memory();
	test_zero_bytes_unchanged();
}


void	test_str(void)
{
	char	*input;
	char	*tocopy;

	tocopy = "output";
	input = strdup("input");
	ft_memcpy(input, tocopy, 5);
	assert(ft_strncmp(input, tocopy, 5) == 0);
	free(input);
}

static void	test_non_str()
{
	char	input[5]={0xFF, 0X12, 0X34, 0X56, 0X78};
	char	*dest;
	char	*expected;

	dest = malloc((sizeof(char) * 5));
	expected = ft_memcpy(dest, input, 5);
	printf("%-30s\t","Copying 5 bytes to dest");
    assert(expected == dest);
	for(size_t i = 0; i < 5; i++)
		assert(dest[i] == input[i]);
	printf("%sOK%s\n",KGRN, KNRM);
    free(dest);
}

static void	test_no_corrupt_memory()
{
	char	input[5]={0xFF, 0X12, 0X34, 0X56, 0X78};
	char	dest[6]={'0','0','0','0','0', 'a'};
	char	*expected;

	expected = ft_memcpy(dest, input, 5);
	printf("%-30s\t",__func__);
    assert(expected == dest);
	for(size_t i = 0; i < 5; i++)
		assert(dest[i] == input[i]);
	assert(dest[5] == 'a');
	printf("%sOK%s\n",KGRN, KNRM);
}


/** 
 *	When the data overlaps the behaviour is memory corruption.
*/
void	test_overlap(void)
{
	char	input[5]={'a','b','c','d','e'};
	char	expected[5]={'a','a','a','a','e'};
	char	*dest;

	printf("%-30s\t",__func__);
	dest = (input + 1);
	ft_memcpy(dest, input, 3);
	for (int i = 0; i < 5; i++)
	{
		assert(input[i] ==  expected[i]);
	}
	printf("%sOK%s\n",KGRN, KNRM);
}

static void test_zero_bytes_unchanged()
{

	char	input[5]={0xFF, 0X12, 0X34, 0X56, 0X78};
	char	dest[6]={'0','0','0','0','0', 'a'};
	char	dest_orig[6]={'0','0','0','0','0', 'a'};
	char	*expected;

    printf("%s\t",__func__);
	expected = ft_memcpy(dest, input, 0);
	assert(expected == dest);
	for(size_t i = 0; i < 5; i++)
        assert(dest[i] == dest_orig[i]);
    printf("%sOK%s\n",KGRN, KNRM);
}
