#include "libft.h"
#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "helpers.h"
	
void	test_equal(void);
void	test_equal_first_n(void);
void	test_different(void);
void	test_zero_size_return_zero(void);
void	test_zero_size_return_zero_NULL(void);
void	test_one_byte(void);

int	main()
{
	test_equal();
	test_equal_first_n();
	test_different();
	test_zero_size_return_zero();
	test_zero_size_return_zero_NULL();
	test_one_byte();
}

void	test_equal()
{
	t_vector		*vector;	
	size_t			len;
	unsigned char	*dst;
	int				res;

	vector = generate_casual_bytes(1, 100);
	len = vector->len;
	dst = malloc(sizeof(unsigned char) * len);
	ft_memcpy(dst, vector->data, len);
	for (size_t i = 0; i < len ; i++)
	{
		assert(dst[i] == vector->data[i]);
	}
	res = ft_memcmp(dst, vector->data, len);
	assert(res == 0);
    free(dst);
    free_vector(vector);
}

void	test_equal_first_n(void)
{
	int				res;
	char 			block1[] = {0x80, 0xFF, 0x41};
	char 			block2[] = {0x80, 0xFF, 0x22};

	res =  ft_memcmp(block1, block2, 2);
	assert(res == 0);
}

void	test_different(void)
{
	int				res;
	char 			block1[] = {0x80, 0xFF, 0x41};
	char 			block2[] = {0x80, 0xFF, 0x22};
	int				expected = 0x1F;

	res =  ft_memcmp(block1, block2, 3);
	assert(res == expected);
}

void	test_zero_size_return_zero(void)
{
	int				res;
	char 			block1[] = {0x80, 0xFF, 0x41};
	char 			block2[] = {0x80, 0xFF, 0x22};

	res =  ft_memcmp(block1, block2, 0);
	assert(res == 0);
}

void	test_zero_size_return_zero_NULL(void)
{
	int				res;
	int				orig_res;
	char 			*block1;
	char 			block2[] = {0x80, 0xFF, 0x22};
	char 			*block3;

	block1 = NULL;
	res =  ft_memcmp(block1, block2, 0);
	orig_res = memcmp(block1, block2, 0);
	assert(res == orig_res);

	block3 = NULL;
	orig_res = memcmp(block1, block3, 0);
	res =  ft_memcmp(block1, block3, 0);

	assert(res == orig_res);

	res =  ft_memcmp(block2, block1, 0);
	orig_res =  memcmp(block2, block1, 0);
	assert(res == orig_res);
}

void	test_one_byte(void)
{
	int		res;
	int		orig_res;
	char 	block1[] = {0x80, 0xFF, 0x41};
	char 	block2[] = {0x80, 0xFF, 0x22};

	res =  ft_memcmp(block1, block2, 1);
	orig_res =  memcmp(block1, block2, 1);
	assert(res == orig_res);

	block1[0] = 0x20;
    res =  ft_memcmp(block1, block2, 1);
    orig_res =  memcmp(block1, block2, 1);
    assert(res == orig_res);
}
