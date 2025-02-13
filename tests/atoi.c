#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "helpers.h"

void	test(char *s)
{
	int	expected;
    int	result;

	printf("%-8s%-40s\t",__func__, *s?s:"");
	expected= atoi(s);
	result= ft_atoi(s);
	assert(expected == result);
	printf("%sOK%s\n",KGRN,KNRM);
}
int	main(void)
{
	format_title(__FILE_NAME__);
	test("1234");
	test("-1234");
	test(" 	1234");
	test(" 	12344jhkdahhkjkjagsfkljj#8800Flkjg");
	test("#$%9");
	test("  ");
	test("-a");
	test("- a");
	test("");
	test("+245");
	test("++245");
	test("+-245");
	test("-+245");
	test("000123");
	test("-000123");
	test("123   ");
	test("\t\n\r\v\f  469 \n");
}
