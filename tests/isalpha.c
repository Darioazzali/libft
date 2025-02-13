/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario </var/spool/mail/dario>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:41:18 by dario             #+#    #+#             */
/*   Updated: 2024/12/30 21:01:49 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "helpers.h"

void	test(int c)
{
	int	expected;
	int	output;

	expected = isalpha(c) && true;
	output = ft_isalpha(c) && true;
	assert(expected == output);
}
int	main()
{
	format_title(__FILE_NAME__);
	for (int i = 0; i <= 127; i++)
		test(i);
	printf("All ascii\t%sOK%s\n", KGRN, KGRN);
}
