#include "libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "helpers.h"


void	free_vector(t_vector *vector) {
	free(vector->data);
	free(vector);
}

size_t	generate_random_size(size_t min_size, size_t max_size) {
    return (min_size + (rand() % (max_size - min_size + 1)));
}

unsigned char	generate_random_char(void) {
    return ((unsigned char)(rand() % 256));
}

t_vector	*generate_casual_bytes(int min, int max)
{
	size_t				generated_size;
	unsigned char		*array;
	t_vector			*vector;

	// srand((unsigned int)time(NULL));
	generated_size = generate_random_size(min, max);
	array = (unsigned char*)malloc(generated_size * sizeof(unsigned char));
	if (array == NULL) 
	{
        fprintf(stderr, "Malloc failed\n");
        exit(1);
    }
	for (size_t i = 0; i < generated_size; i++) 
	{
        array[i] = generate_random_char();
    }
	vector = malloc(sizeof(t_vector));
	vector->data = array;
	vector->len = generated_size;
	return (vector);
}


bool	is_in_array(unsigned char *array, unsigned char c, size_t len) 
{
    for (size_t i = 0; i < len; i++) 
	{
        if (array[i] == c)
            return true;
    }
    return (false);
}

/** Build a list from a series of strings. Free the strings after */
t_list	*build_from_strings(char **strings)
{
	t_list	*lst;
	size_t	i;

	lst = ft_lstnew(strdup(*strings));
	i = 1;
	while (strings[i])
	{
		ft_lstadd_back(&lst,ft_lstnew(ft_strdup(strings[i])));
		i++;
	}
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (lst);
}

char	**build_string_array(size_t count, ...)
{
	va_list	args;
    char	**strings;
	size_t	i;

	strings = calloc(count + 1, sizeof(char *));
	va_start(args, count);
	i = 0;
	while (i < count)
	{
		strings[i] = strdup(va_arg(args, char *));
		i++;
	}
	va_end(args);
	strings[i]= 0;
	return (strings);
}

char	char_title(unsigned int i, char s)
{
	(void) i;
	if ((unsigned char)s == '.')
		return (0);
	return ((unsigned char) s - 32);
}

void	format_title(char *title)
{
	int width = 80;
    int padding = (width - strlen(title)) / 2;
    printf("%s%s%*s%s%*s%s\n\n","\x1b[4m",KBLUE, padding, "", ft_strmapi(title, char_title), padding, "",KNRM);
}
