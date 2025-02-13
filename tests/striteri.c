#include <assert.h>
#include <ctype.h>
#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void	make_upper(unsigned int idx, char *c)
{
	(void) idx;
	if (islower(*c))
		*c = 'A' + *c - 'a';
}

void	make_upper_odds(unsigned int idx, char *c)
{
	if ((idx % 2) == 0 && islower(*c))
		*c = 'A' + *c - 'a';
}

int	main(void)
{
	char	*input;

	input = ft_strdup("prova");
	ft_striteri(input, make_upper);
	assert(strcmp(input, "PROVA") == 0);

	input = ft_strdup("prova");
	ft_striteri(input, make_upper_odds);
	assert(strcmp(input, "PrOvA") == 0);

	input = NULL;
	ft_striteri(input, make_upper_odds);
	assert(input == NULL);
}
