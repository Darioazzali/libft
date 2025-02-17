#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static int	test();

int	main(void)
{
	printf("Testing with buffer size %u\n", GNL_BUFFER_SIZE);
	test();
}

static int	test()
{

	int		fd;	
	char	path[1024];
	char	*line;

	if (getcwd(path, 1024) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	strcat(path, "../input/");
	strcat(path,"no_allowed.txt");
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	assert(line == NULL);
	printf("Return NULL if no read permission \e[032m\u2713\e[0m\n");
	return (0);
}
