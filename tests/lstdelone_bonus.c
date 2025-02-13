#include "libft.h"
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

static void test();
static void test_del_string(void *str)
{
	free(str);
}

int	main(void)
{
    test();
}

/** valgrind --leak-check=yes ./lstdelone */

static void test()
{
	t_list	*lst;
	t_list	*sec_node;

	lst = ft_lstnew(strdup("first"));
	sec_node = ft_lstnew(strdup("second"));
	ft_lstadd_back(&lst, sec_node);
	assert(strcmp(lst->content, "first") == 0);
	ft_lstdelone(lst, test_del_string);
	assert(strcmp(sec_node->content,"second") == 0);
	ft_lstdelone(sec_node, test_del_string);
}
