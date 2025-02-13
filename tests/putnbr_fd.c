#include "libft.h"
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

static void	test(int n, char * expected);
int	main(void)
{
	test(0, "0");
	test(1, "1");
	test(-1, "-1");
	test(INT_MIN, "-2147483648");
	test(11, "11");
}


static void	test(int n, char * expected)
{
	int		fd;
	char	buffer[65]={0};
	
	fd = open("test_nbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	assert(fd != -1);
	
	ft_putnbr_fd(n, fd);
    close(fd);

	fd = open("test_nbr.txt", O_RDONLY);
	assert(fd != -1);
	read(fd, buffer, 65);
	assert(strcmp(buffer, expected) == 0);
	close(fd);
}
