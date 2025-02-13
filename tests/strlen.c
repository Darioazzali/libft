#include "libft.h"
#include <assert.h>
#include <string.h>

void	test(char *word);

int	main()
{
	char	*words[] = {"prova", "", "@355", "99999999",
			"fda;skjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj", (char *)0};
	int		i;

	i = 0;
	while (*(words + i))
	{
		test(*(words + i));
		i++;
	}
}

void	test(char *word)
{
	int	expected;
	int	output;

	expected = strlen(word);
	output = ft_strlen(word);
	assert(expected == output);
}
