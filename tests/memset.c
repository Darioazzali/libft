#include <assert.h>
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"

static void	test(void);

int	main()
{
	format_title(__FILE_NAME__);
	test();
}

void	test(void)
{
	char	test[16];
	char	*output;

	memset(test, 'a', 16);
	output = ft_memset((void *)test, '#', 6);
	printf("Set 6 bytes with '#'\t");
	for (int i = 0; i < 6; i++)
		assert(*(output + i) == '#');
	printf("%sOK%s\n", KGRN, KNRM);
	printf("Other bytes unchanged\t");
	for (int i = 6; i < 16; i++)
		assert(*(output + i) == 'a');
	printf("%sOK%s\n", KGRN, KNRM);

}
