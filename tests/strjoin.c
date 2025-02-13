#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

void test_lorem(void);
static void	test_1(void);
static void	test_empty_str(void);

int	main(void)
{
	format_title(__FILE_NAME__);
	test_1();
	test_empty_str();
	test_lorem();
}

static void	test_empty_str()
{
	char	*s1;
    char	*s2;
	char	*output;
	char	*expected;

	printf("%s\t",__func__);
	s1="";
	s2=" di scrittura";
	expected=" di scrittura";
	output = ft_strjoin(s1, s2);
	assert(strcmp(expected,output) == 0);
	free(output);

	s1="prova";
	s2="";
	expected="prova";
	output = ft_strjoin(s1, s2);
	assert(strcmp(expected,output) == 0);
	free(output);

	s1="";
	s2="";
	expected="";
	output = ft_strjoin(s1, s2);
	assert(strcmp(expected,output) == 0);
	free(output);
	printf("%sOK%s\n",KGRN, KNRM);
}

void test_lorem()
{

	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	char 	*strjoin;
	printf("%s\t",__func__);

	strjoin = ft_strjoin(s1, s2);
	assert(strcmp(strjoin,"lorem ipsumdolor sit amet") == 0);
	printf("%sOK%s\n",KGRN, KNRM);
}
// static void	test_null_string()
// {
// 	char	*s1;
//     char	*s2;
// 	char	*output;
//
// 	s1=NULL;
// 	s2=" di scrittura";
// 	output = ft_strjoin(s1, s2);
// 	assert(output == NULL);
//
// 	s1="prova";
// 	s2=NULL;
// 	output = ft_strjoin(s1, s2);
// 	assert(output == NULL);
//
// 	s1=NULL;
// 	s2=NULL;
// 	output = ft_strjoin(s1, s2);
// 	assert(output == NULL);
// }


static void	test_1()
{
	char	*s1;
    char	*s2;
	char	*output;
	char	*expected;

	s1="prova";
	s2=" di scrittura";
	expected="prova di scrittura";
	output = ft_strjoin(s1, s2);
	assert(strcmp(expected,output) == 0);
	free(output);
}
