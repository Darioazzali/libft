#include <assert.h>
#include "libft.h"
#include <string.h>

static	void base_test(void)
{
	t_list 	link_1;
	t_list 	link_2;
	t_list 	link_3;
	t_list	*list;
	t_list	*new_node;

	link_1.content = "link_1";
    link_1.next = &link_2;

	link_2.content = "link_2";
	link_2.next = &link_3;

	link_3.content = "link_3";
	link_3.next = NULL;

	list = &link_1;
	assert(strcmp(list->content, "link_1") == 0 );
	assert(strcmp(list->next->content, "link_2") == 0 );

	new_node = ft_lstnew("new_node");
    ft_lstadd_front(&list, new_node);
	assert(strcmp(list->content, "new_node") == 0 );
	assert(strcmp(list->next->content, "link_1") == 0 );
	assert(strcmp(list->next->next->content, "link_2") == 0 );
	assert(strcmp(list->next->next->next->content, "link_3") == 0 );
	assert(list->next->next->next->next == NULL );
}

static void	new_test(void)
{
	t_list	*list;
	t_list	*lnk_2;
	t_list	*lnk_3;

	list = ft_lstnew("el1");
	lnk_2 = ft_lstnew("el2");
	lnk_3 = ft_lstnew("el3");
	list->next = lnk_2;
	lnk_2->next = lnk_3;

	assert(strcmp(list->content, "el1") == 0 );
	assert(strcmp(list->next->content, "el2") == 0 );
	assert(strcmp(list->next->next->content, "el3") == 0 );
	assert(list->next->next->next == NULL );
	ft_lstadd_front(&list, ft_lstnew("el0"));

	assert(strcmp(list->content, "el0") == 0 );
	assert(strcmp(list->next->content, "el1") == 0 );
	assert(strcmp(list->next->next->content, "el2") == 0 );
	assert(list->next->next->next == lnk_3 );
}

static void	test_empty_list()
{
	t_list	*empty;

	empty = NULL;
	ft_lstadd_front(&empty, ft_lstnew("prova"));
	assert(empty != NULL);
	assert(strcmp(empty->content, "prova") == 0);
}

int	main(void)
{
	base_test();
	new_test();
	test_empty_list();
}
