#include "libft.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** MEMORY LEAKS
 * valgrind --leak-check=yes ./lstclear 
 *
 * */

static void test();
static void test_no_list();
static void	del(void *content) 
{
	free(content);
}

int	main(void)
{
    test();
	test_no_list();
}


static void test()
{
	t_list	*lst;
	t_list	*sec_node;
	t_list	*third_node;

	lst = ft_lstnew(strdup("first"));
	sec_node = ft_lstnew(strdup("second"));
	third_node = ft_lstnew(strdup("third"));
	ft_lstadd_back(&lst, sec_node);
	ft_lstadd_back(&lst, third_node);
	assert(strcmp(lst->content, "first") == 0);
	assert(strcmp(lst->next->content, "second") == 0);
	assert(strcmp(lst->next->next->content, "third") == 0);
	assert(lst->next->next->next == NULL);
	ft_lstclear(&lst, del);
}

/** Doesn't crash on NULL list ot null function */
static void test_no_list()
{
	t_list	*lst;
	ft_lstclear(NULL, del);
	lst = ft_lstnew(ft_strdup("prova"));
	ft_lstclear(&lst, NULL);

	/** Clear for valgrind*/
	ft_lstclear(&lst, del);
}
