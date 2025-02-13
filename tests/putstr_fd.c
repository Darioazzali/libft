#include <fcntl.h>
#include <assert.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	test(void);
void	test_null_string_no_crash(void);

int	main(void)
{
	test();
	// test_null_string_no_crash();
}

void	test(void)
{
	int		fd;
	char	buf[1024];

	fd = open("putstr_fd.txt",O_WRONLY | O_CREAT,0777);
	assert(fd > 0);
	ft_putstr_fd("test", fd);
	assert(close(fd) == 0);

	fd = open("putstr_fd.txt",O_RDONLY);
	assert(fd > 0);	
	while(!(read(fd, buf, sizeof(buf))));
	assert(strcmp(buf,"test") == 0);
}


// void	test_null_string_no_crash(void)
// {
// 	ft_putstr_fd(NULL, 1);
// }
