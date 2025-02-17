#include "libft.h"
#include <stdio.h>
#include <assert.h>

static int	test();

int	main(void)
{
	printf("Testing with buffer size %u\n", GNL_BUFFER_SIZE);
	test();
}

static int	test()
{
	char	*line;
	while((line = get_next_line(0)))
	{
		printf("Output: %s", line);
	}
	free(line);
	return (0);
}
