/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:45:06 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/30 10:48:55 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	ft_iswhitespace(const char *s)
{
	return ((*s >= '\t' && *s <= '\r') || *s == ' ');
}

/**
 * @brief Convert a string to an integer.
 *
 * This function converts the string nptr to an integer. It skips leading
 * whitespace, handles an optional sign, and stops at the first non-digit
 * character.
 *
 * @param nptr The string to convert.
 * @return The converted integer value.
 * @note The function skips leading whitespace, handles an optional sign, and
 *       stops at the first non-digit character.
 */
int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr && ft_iswhitespace(nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		nptr++;
		sign = -1;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}
