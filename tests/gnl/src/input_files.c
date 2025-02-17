#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "helpers.h"

static int	test(char *filename);
static void free_all(char **ptr, size_t count);
char** read_lines(const char* filename, size_t* num_lines);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "%sPlease provide a file name\n%s", CRED, CNORM);
		exit(EXIT_FAILURE);
	}
	printf("Testing with buffer size %u\n", GNL_BUFFER_SIZE);
	test(argv[1]);
}

static int	test(char *filename)
{

	int		fd;	
	char	path[1024];
	char	*line;
	char	**expected;
	size_t	count;
	char	*res;

	if (getcwd(path, 1024) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	strcat(path, "/../input/");
	strcat(path, filename);
	expected = read_lines(filename, &count);
	printf("Expected count %zu\n", count);
	if (!expected)
		exit(1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "\e[031mError while opening file %s\e[0m\n", "path");
		perror(path);
		exit(EXIT_FAILURE);
	}
	for(size_t i=0; i < count; i++)
    {
		printf("Expected\n%s", expected[i]);
		line = get_next_line(fd);
		printf("Output: \n%s", line);
		assert(strcmp(line, expected[i]) == 0);
		free(line);
		printf("Line %zu \e[032m\u2713\e[0m\n", i);
	}
	res = get_next_line(fd);
	assert(res == NULL);
	res = get_next_line(fd);
	assert(res == NULL);
	printf("After last line return NULL \e[032m\u2713\e[0m\n");
	free_all(expected, count);
	return (0);
}

static void free_all(char **ptr, size_t count)
{
    if (!ptr) return;
    
    for (size_t i = 0; i < count; i++) {
        free(ptr[i]);
    }
    free(ptr);
}

char** read_lines(const char* filename, size_t* num_lines) 
{
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    *num_lines = 0;
    size_t capacity = 16;
    char** lines = malloc(capacity * sizeof(char*));
    char buffer[1024];

    if (!lines) {
        fclose(file);
        return NULL;
    }
    while (fgets(buffer, sizeof(buffer), file)) {
		if (*num_lines >= capacity) {
        capacity *= 2;
        char** temp = realloc(lines, capacity * sizeof(char*));
        if (!temp) {
            for (size_t i = 0; i < *num_lines; i++) {
                free(lines[i]);
            }
            free(lines);
            fclose(file);
            return NULL;
        }
        lines = temp;  // Only update lines after successful realloc
    }
        lines[*num_lines] = strdup(buffer);
        if (!lines[*num_lines]) {
            for (size_t i = 0; i < *num_lines; i++) {
                free(lines[i]);
            }
            free(lines);
            fclose(file);
            return NULL;
        }
        (*num_lines)++;
    }
	if (capacity > *num_lines)
	{
    char** temp = realloc(lines, *num_lines * sizeof(char*));
    if (temp)
        lines = temp;
	}
    fclose(file);
    return lines;
}
