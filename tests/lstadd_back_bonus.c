#include "libft.h"
#include <assert.h>
#include <stdarg.h>
#include <string.h>

static void test();
static void	test_null_pointers();
static void	test_empty_list();

int	main(void)
{
    test();
	test_null_pointers();
	test_empty_list();
}

static void test()
{
	t_list	*lst;

	lst = ft_lstnew("first");
	assert(ft_lstsize(lst) == 1);
	ft_lstadd_back(&lst, ft_lstnew("second"));
	assert(ft_lstsize(lst) == 2);
	assert(strcmp(lst->content , "first") == 0);
	assert(strcmp(lst->next->content , "second") == 0);
}

static void	test_null_pointers()
{
	t_list	**lst;
	t_list	*element;

	/** Element on NULL list */
	lst = NULL;
	ft_lstadd_back(lst, ft_lstnew("prova"));
	assert(lst == NULL);

	/** Null Element on empty list doesn't change list*/
	element = ft_lstnew("prova");
	lst = &element;
	ft_lstadd_back(lst, NULL);
	assert(strcmp((*lst)->content, "prova") == 0);

}

/** Element on empty list*/
static void	test_empty_list()
{
	t_list	**lst;
	t_list	*element;
	t_list	*new_element;

	element = NULL;
	lst = &element;
	new_element = ft_lstnew("prova");
	ft_lstadd_back(lst, new_element);
	assert(strcmp((*lst)->content, "prova") == 0);

}
