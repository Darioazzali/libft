#include "libft.h"
#include <assert.h>
#include <linux/limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "helpers.h"


static void	test_ok(void);
static void	test_unique_pointer_on_0(void);
static void	test_overflow(void);
static void	test_MAX_PTR(void);

int	main(void)
{
	test_ok();
	test_unique_pointer_on_0();
	test_MAX_PTR();
	test_overflow();
}

static void	test_ok()
{
	char	*result;	
	int		*result2;	
	int		*orig_result2;	

	printf("%-40s\t",__func__);
	result = (char *) ft_calloc(1, 1);
	assert(*result == 0);

	result2 = (int *) ft_calloc(100, sizeof(int));
	for (size_t i = 0; i < 100; i++)
	{
		assert(result2[i] == 0);
	}

	orig_result2 = (int *) calloc(100, sizeof(int));
	for (size_t i = 0; i < 100; i++)
	{
		assert(result2[i] == orig_result2[i]);
	}
	printf("%sOK%s\n",KGRN,KNRM);
}

static void	test_unique_pointer_on_0()
{
	char	*result;	

	printf("%-40s\t",__func__);
	result = (char *) ft_calloc(0, 1);
	assert(result != NULL);

	result = (char *) ft_calloc(1, 0);
	assert(result != NULL);

	result = (char *) ft_calloc(0, 0);
	assert(result != NULL);

	printf("%sOK%s\n",KGRN,KNRM);
}

/* This will fails in every case 
* On a normal pc there is no such memory available
* */
static void	test_MAX_PTR()
{
	char	*result;

	printf("%-40s\t",__func__);
	result = (char *) ft_calloc(1, (PTRDIFF_MAX));
	assert(result == NULL);

	printf("%sOK%s\n",KGRN,KNRM);
}

static void	test_overflow()
{
	char	*result;
	size_t	size;

	printf("%-40s\t",__func__);
	size = -1;
	result = (char *) ft_calloc(2, size);
	assert(result == NULL);
	printf("%sOK%s\n",KGRN,KNRM);
}

