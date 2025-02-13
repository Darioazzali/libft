#include <fcntl.h>
#include "libft.h"
#include <unistd.h>
#include <assert.h>

int	main(void)
{
	char	buffer[2];
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT, 0777);
    ft_putchar_fd('a', fd);
	close(fd);

	fd = open("test.txt", O_RDONLY);
	assert(fd);
	if(! read(fd, buffer, 2))
		return (1);
	assert(buffer[0] == 'a');
}
