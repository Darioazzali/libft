#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/**	One simple character in the set.*/
static void	test_one_set()
{
	char	*set;	
	char	*str;
	char	*expected;
	char	*output;

	set = " ";
	str = "  holahola  h   ";
	expected = "holahola  h";
	output = ft_strtrim(str, set);
	assert(strcmp(expected, output) == 0);
	free(output);
}

/** More character in set. */
static void	test_more_set()
{
	char	*set;	
	char	*str;
	char	*expected;
	char	*output;

	set = " i";
	str = "  holahola  h i ";
	expected = "holahola  h";
	output = ft_strtrim(str, set);
	assert(strcmp(expected, output) == 0);
	free(output);
	
	str = "i holaihiiii";
	expected = "holaih";
	output = ft_strtrim(str, set);
	assert(strcmp(expected, output) == 0);
	free(output);
}

/**	Set is empty. Should return str. */
static void	test_empty_set()
{
	char	*set;	
	char	*str;
	char	*expected;
	char	*output;

	set = "";
	str = "  holahola  h   ";
	expected = str;
	output = ft_strtrim(str, set);
	assert(strcmp(expected, output) == 0);
	free(output);
}

/**	All the set characters are in str.
 * 	Should return empty string.
*/
static void	test_all_in_set()
{
	char	*set;	
	char	*str;
	char	*expected;
	char	*output;

	set = " hola";
	str = "  holahola  h   ";
	expected = "";
	output = ft_strtrim(str, set);
	assert(strcmp(expected, output) == 0);
	free(output);
}

/**If the given set is null, return str*/
// static void	test_null_set()
// {
// 	char	*set;	
// 	char	*str;
// 	char	*expected;
// 	char	*output;
//
// 	set = NULL;
// 	str = "  holahola  h   ";
// 	expected = str;
// 	output = ft_strtrim(str, set);
// 	assert(strcmp(expected, output) == 0);
// 	free(output);
// }

/** If string is null return null */
// static void	test_NULL_str()
// {
// 	char	*set;	
// 	char	*str;
// 	char	*output;
//
// 	set = " dsd&*504-F";
// 	str = NULL;
// 	output = ft_strtrim(str, set);
// 	assert(output == NULL);
// }

static void	test_not_found()
{
	char	*set;	
	char	*str;
	char	*output;

	set = "@#";
	str = "hola como estas  _";
	output = ft_strtrim(str, set);
	assert(strcmp(output, str) == 0);
}

int	main(void)
{
	test_one_set();
	test_empty_set();
	// test_null_set();
	test_more_set();
	// test_NULL_str();
	test_not_found();
	test_all_in_set();
}
