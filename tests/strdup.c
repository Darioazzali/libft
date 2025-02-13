#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void test()
{
	char	*str1;
	char	*copied;

	str1 = "test";
	copied = ft_strdup(str1);	
	assert(copied != NULL);
	assert(strcmp(str1, copied) == 0);
	free(copied);
}

static void test_empty_string()
{
    char	*str1;
    char	*copied;

	str1 = "";
	copied = ft_strdup(str1);
	assert(copied != NULL);
	assert(strcmp("", copied) == 0);
	free(copied);
}

int	main(void)
{
	test();
	test_empty_string();
}
