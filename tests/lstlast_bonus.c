#include "libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdarg.h>
#include "helpers.h"
#include <assert.h>
#include <string.h>

int	main(void)
{
	char	**strings;
	t_list	*lst;
	t_list	*last;

	strings = build_string_array(3, "first", "second", "third");
    lst = build_from_strings(strings);
	last = ft_lstlast(lst);
	assert(strcmp((char *) lst->content, "first") == 0);
	assert(strcmp((char *) last->content, "third") == 0);

    return (0);
}
