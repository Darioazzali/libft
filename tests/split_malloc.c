#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

static int free_call_count = 0;
static int malloc_call_count = 0;
static int malloc_fail_on_n = 0;

void* test_malloc(size_t size) {
    malloc_call_count++;
	if(malloc_call_count == malloc_fail_on_n)
		return (NULL);
    return malloc(size);
}

void test_free(void* ptr) {
	free(ptr);
	free_call_count++;
}

void reset_counters(void) {
	free_call_count = 0;
	malloc_call_count = 0;
	malloc_fail_on_n = 200;
}

#define free test_free
#define malloc test_malloc

#include "../ft_strlen.c"
#include "../ft_calloc.c"
#include "../ft_bzero.c"
#include "../ft_memset.c"
#include "../ft_strlcpy.c"
#include "../ft_memcpy.c"
#include "../ft_split.c"
#include "../ft_strdup.c"
#include "../ft_strchr.c"
#include "../ft_substr.c"
#include "../ft_strtrim.c"

/** Free does get called at all since no allocation succeded*/
void	test_alloc_fail_on_res_allocation()
{
	char	*input;
	char	**split;

	reset_counters();
	input = "  test  t";
	malloc_fail_on_n = 1;
	split = ft_split(input, ' ');
	assert(split == NULL);
	assert(free_call_count == 0);
}

void test_alloc_fail_on_first_allocation()
{

	char	*input;
	input = "  test  t";
	reset_counters();
	malloc_fail_on_n = 2;
	ft_split(input, ' ');
	
	assert(free_call_count == 1);
	assert(malloc_call_count == 2);
}

void test_alloc_fail_on_last_allocation()
{

	char	*input;
	input = "  test  t";
	reset_counters();
	malloc_fail_on_n = 3;
	ft_split(input, ' ');
	
	assert(free_call_count == 2);
	assert(malloc_call_count == 3);
}

void test_alloc_fail_on_second_allocation()
{

	char	*input;
	input = "  test t t";
	reset_counters();
	malloc_fail_on_n = 3;
	ft_split(input, ' ');
	
	assert(free_call_count == 2);
	assert(malloc_call_count == 2);
}

void test_multiple_words_cleanup()
{
	char *input = "one two three four five";
	reset_counters();
	malloc_fail_on_n = 4;
	ft_split(input, ' ');
	
	assert(free_call_count == 3);
	assert(malloc_call_count == 4);
}

int	main(void)
{
	test_alloc_fail_on_res_allocation();
	test_alloc_fail_on_res_allocation();
	test_alloc_fail_on_last_allocation();
}
