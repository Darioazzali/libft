#include "libft.h"
#include <assert.h>
#include <stdarg.h>
#include "helpers.h"

static void test();
static void test_one_element();
static void test_no_elements();

int	main(void)
{
    test();
	test_one_element();
	test_no_elements();
}

static void test()
{
	char	**strings;
	t_list	*lst;
	strings = build_string_array(3, "first", "second", "third");
    lst = build_from_strings(strings);
	assert(ft_lstsize(lst) == 3);
}

static void test_one_element()
{
	char	**strings;
	t_list	*lst;
	strings = build_string_array(1, "first");
    lst = build_from_strings(strings);
	assert(ft_lstsize(lst) == 1);
}

static void test_no_elements()
{
	t_list	*lst;

    lst = NULL;
	assert(ft_lstsize(lst) == 0);
}

