#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "libft.h"

static void free_strings(char ** strings);
static void	test(void);
static void	test_no_split(void);
static void	test_no_initial_sep(void);
static void test_empty_string(void);
static void	only_separator(void);
static void	test_no_separator(void);
static void	test_NULL_input(void);
static void	test_final_sep(void);


int	main(void)
{
	test();
	test_no_split();
	test_no_initial_sep();
	test_final_sep();
	test_NULL_input();
	test_no_separator();
	only_separator();
	test_empty_string();
}


static void	test()
{
	char	input[] = "hello world";
    char	**split;
	char	**orig_split;
	char	*expected[] = {"hello", "world", NULL};
	int		i;
	
	i = 0;
	split = ft_split(input, ' ');
	orig_split = split;
	assert(split != NULL);
	while(*split)
	{
		assert(strcmp(*(split), expected[i]) == 0);
		split++;
		i++;
	}
	assert(i == 2);
	i = 0;
	free_strings(orig_split);
}

static void	test_no_split()
{
	char	input[] = "hello world";
    char	**split;
	char	**orig_split;
	char	*expected[] = {"hello world", "\0"};
	int		i;
	
	i = 0;
	split = ft_split(input, 'z');
	orig_split = split;
	assert(split != NULL);
	while(*split)
	{
		assert(strcmp(*(split), expected[i]) == 0);
		split++;
		i++;
	}
	assert(i == 1);
	free_strings(orig_split);
}

static void	test_no_initial_sep()
{
	char	*input;
    char	**split;
	char	**orig_split;
	char	*expected[] = {"hello", "world", "\0"};
	int		i;
	
	i = 0;
 	input = "@@hello@world";
	split = ft_split(input, '@');
	orig_split = split;
	assert(split != NULL);
	while(*split)
	{
		assert(strcmp(*(split), expected[i]) == 0);
		split++;
		i++;
	}
	assert(i == 2);
	free_strings(orig_split);
}

static void	test_final_sep()
{
	char	*input;
    char	**split;
	char	**orig_split;
	char	*expected[] = {"hello", "world", "\0"};
	int		i;
	
	i = 0;
 	input = "hello###world####";
	split = ft_split(input, '#');
	orig_split = split;
	assert(split != NULL);
	while(*split)
	{
		assert(strcmp(*(split), expected[i]) == 0);
		split++;
		i++;
	}
	assert(i == 2);
	free_strings(orig_split);
}

static void	test_NULL_input()
{
	char	*input;
    char	**split;
	
 	input = NULL;
	split = ft_split(input, '#');
	assert(split == NULL);
}

static void	test_no_separator()
{
	char	*input;
    char	**split;
	
 	input = NULL;
	split = ft_split(input, (char ) 0);
	assert(split == NULL);
}

static void	only_separator()
{
	char	*input;
    char	**split;
	
 	input = "          ";
	split = ft_split(input, ' ');
	assert(*split == NULL);
	free(split);
}

static void test_empty_string()
{
	char *input = "";
	char **split = ft_split(input, ' ');
	assert(split != NULL);
	assert(*split == NULL);
	free(split);
}


static	void free_strings(char ** strings)
{
	char	**ptr;

	ptr = strings;
	while (*ptr)
		free(*ptr++);
	free(strings);
}
