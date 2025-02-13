#include "libft.h"
#include "helpers.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static void	test_found();
static void	test_not_found();

int	main(void)
{
	size_t	times;

	srand((unsigned int)time(NULL));
	times = 200;
	for(size_t i=0; i < times; i++)
		test_found();
	test_not_found();
}

static void	test_found()
{
	char			*expected;
	char			*output;
	t_vector		*input;
	size_t			casual_index;
	size_t			casual_len;

	input = generate_casual_bytes(5,200);
	casual_index = generate_random_size(5, 200);
	casual_len = generate_random_size(5, 200);
	printf("Searching at index %zu for %zu bytes \t",casual_index, casual_len);
	expected = memchr(input->data, input->data[casual_index], casual_len);
	output = ft_memchr(input->data, input->data[casual_index], casual_len);
	assert(output == expected);
	printf("%sOK%s\n", KGRN, KNRM);
	free(input->data);
	free(input);
}

static void	test_not_found()
{
	char			*expected;
	char			*output;
	t_vector		*input;
	char			not_included;

	input = generate_casual_bytes(1,2);
	do {
		not_included = generate_random_char();
	} while (is_in_array(input->data, not_included ,input->len));
	
	expected = memchr(input, not_included, input->len);
	output = ft_memchr(input, not_included, input->len);
	assert(output == expected);
}
