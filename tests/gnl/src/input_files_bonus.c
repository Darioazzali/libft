#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "helpers.h"

int	main(int argc, char **argv)
{

	int		fd[1024];	
	size_t	count;
	char	*line;
	if (argc < 2)
	{
		fprintf(stderr, "%sPlease provide at least a file name\n%s", CRED, CNORM);
		exit(EXIT_FAILURE);
	}
	printf("Testing with buffer size %u\n", BUFFER_SIZE);
	count = 0;
	for (size_t i = 1; i < (size_t) argc; i++)
	{
		fd[i] = open(argv[i], O_RDONLY);
		count++;
	}

	do 
	{
		for (size_t i = 1; i <= count; i++)
		{
			line = get_next_line(fd[i]);
			if(line)
			{
				if (line[strlen(line) -1 ] == '\n')
					printf("Reading from fd %d, got:\n%s", fd[i], line);
				else
					printf("Last line on %d, got:\n%s\x1b[47m\x1b[30m%%\e[0m\n", fd[i], line);
			}
		}
	}
	while(line);
	while ((line=get_next_line(0))!= 0)
		printf("%s", line);
}
