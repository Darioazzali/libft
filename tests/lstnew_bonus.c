#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*content;
	t_list	*list;

	content = strdup("content");
	list = ft_lstnew(content);
	assert(list->content == content);	
	assert(list->next == NULL);
	// printf("content: %s\n", (char *) list->content);
	free(content);
	free(list);
}
