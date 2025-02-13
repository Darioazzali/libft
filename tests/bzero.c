#include "libft.h"
#include <assert.h>
#include <stdbool.h>
#include "helpers.h"
#include <stdio.h>
#include <string.h>

static void	test();
static void	test_no_override_memory(void);
static void	test_no_change_if_zero(void);

int	main(void)
{
	format_title(__FILE_NAME__);
	test();
	test_no_override_memory();
	test_no_change_if_zero();
}


static void	test()
{
	size_t	n;

	printf("%-26s",__func__);
	n = 6;
	char	input[] = {'a', 'l', 'l', 'o', 'r', 'a'};
	ft_bzero(input, n);
	for (size_t i = 0; i < n; i++)
		assert(input[i] == 0);
	printf("%sOK%s\n",KGRN, KNRM);
}


static void	test_no_override_memory()
{
	char	input[10]="123456789";

	printf("%-26s",__func__);
    ft_bzero(input, 8);
	for (size_t i = 0; i < 8; i++)
		assert(input[i] == '\0');
	assert(input[8] == '9');
	printf("%sOK%s\n",KGRN, KNRM);
}

/** If the size of the zeroing is zero, 
 * 	buffer remains unchanged.
*/
static void	test_no_change_if_zero(void)
{
	char	input[10]="123456789";

	printf("%-26s",__func__);
    ft_bzero(input, 0);
	assert(strncmp(input, "123456789",9) == 0);
	bzero(input, 0);
	assert(strncmp(input, "123456789",9) == 0);
	printf("%sOK%s\n",KGRN, KNRM);
}

