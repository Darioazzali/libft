#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

static void	test(void);
static void to_uppercase(void *str);
static void test_empty_list(void);

int	main(void)
{
	test();
	test_empty_list();
}

static void	test(void)
{
	t_list	*lst;
	char	**strings;

	strings = build_string_array(4,"one","two","three","four");
	lst = build_from_strings(strings);
	assert(strcmp(lst->content, "one") == 0);
	ft_lstiter(lst,to_uppercase);
	assert(strcmp(lst->content, "ONE") == 0);
	assert(strcmp(lst->next->content, "TWO") == 0);
	assert(strcmp(lst->next->next->content, "THREE") == 0);
	assert(strcmp(lst->next->next->next->content, "FOUR") == 0);
	assert(lst->next->next->next->next == NULL);
	ft_lstclear(&lst,free);
}

static void	test_empty_list(void)
{
	t_list	*lst;
	ft_lstiter(NULL, free);

	lst = ft_lstnew(ft_strdup("prova"));
	ft_lstiter(lst, NULL);
	ft_lstclear(&lst, free);
}

static void to_uppercase(void *str)
{
	char	*ptr;

	ptr = (char *) str;
	while (*ptr)
	{
		if (islower(*ptr))
			*ptr = toupper(*ptr);
		ptr++;
	}
}
