#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

static void	test(void);
static char *to_uppercase(void *str);
static void *identity(void *content);
static void test_empty_list(void);
static void test_no_alloc_del_empty(void);


int	main(void)
{
	test();
	test_empty_list();
	test_no_alloc_del_empty();
}

static void	test(void)
{
	t_list	*lst;
	t_list	*mapped_list;
	char	**strings;

	strings = build_string_array(4,"one","two","three","four");
	lst = build_from_strings(strings);
	assert(strcmp(lst->content, "one") == 0);
	mapped_list = ft_lstmap(lst,(void *) to_uppercase,free);
	assert(strcmp(mapped_list->content, "ONE") == 0);
	assert(strcmp(mapped_list->next->content, "TWO") == 0);
	assert(strcmp(mapped_list->next->next->content, "THREE") == 0);
	assert(strcmp(mapped_list->next->next->next->content, "FOUR") == 0);
	assert(mapped_list->next->next->next->next == NULL);
	ft_lstclear(&lst,free);
	ft_lstclear(&mapped_list,free);
}

static void	test_empty_list(void)
{
	t_list	*lst;
	t_list	*mapped_list;
	ft_lstiter(NULL, free);

	lst = ft_lstnew(ft_strdup("prova"));
	mapped_list = ft_lstmap(lst, NULL,NULL);
	ft_lstclear(&lst, free);
	if (mapped_list)
		ft_lstclear(&mapped_list, free);
}

/** This test cover the edge case where 
 *	the function f is not allocating new
 *	memory, so del is not needed.
 *	Still the node should be freed if
 *	the allocation of a new node fails
 *	for some reason.
 * */
static void test_no_alloc_del_empty(void)
{
	t_list	*lst;
	t_list	*mapped_lst;

	lst = ft_lstnew("Prova");
	ft_lstadd_back(&lst, ft_lstnew("Prova2"));
    mapped_lst = ft_lstmap(lst, identity, NULL);
    ft_lstclear(&lst, NULL);
    ft_lstclear(&mapped_lst, NULL);
}

static char *to_uppercase(void *str)
{
	char	*upper_str;
	char	*ptr;

	upper_str = ft_strdup(str);
	if (!upper_str)
		return (NULL);
	ptr = upper_str;
	while (*ptr)
	{
		if (islower(*ptr))
            *ptr = toupper(*ptr);
        ptr++;
    }
	return upper_str;
}

static void *identity(void *content)
{
	return (content);
}
