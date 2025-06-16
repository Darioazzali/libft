/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:27:17 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/23 18:51:50 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

static	size_t	ft_digit_n(int n)
{
	size_t	digits;

	digits = 1;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		digits++;
		if (n == INT_MIN)
		{
			digits++;
			n /= 10;
		}
		n = -n;
	}
	while (n)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

/**
 * @brief Convert an integer to a string.
 *
 * This function converts the integer n to a string representation. It handles
 * negative numbers and the special case of INT_MIN. If allocation fails, the
 * function returns NULL.
 *
 * @param n The integer to convert.
 * @return A pointer to the resulting string, or NULL if allocation fails.
 * @note The function handles negative numbers and the special case of INT_MIN.
 */
char	*ft_itoa(int n)
{
	char	*res;
	char	*ptr;

	res = (char *) malloc(sizeof(char) * ft_digit_n(n));
	if (!res)
		return (NULL);
	if (n < 0)
		*res = '-';
	ptr = res + ft_digit_n(n) - 1;
	*ptr-- = '\0';
	if (n == INT_MIN)
	{
		*ptr-- = - (n % 10) + '0';
		n = n / 10;
	}
	if (n < 0)
		n = -n;
	while (n / 10)
	{
		*ptr-- = (n % 10) + '0';
		n /= 10;
	}
	*ptr = (n % 10) + '0';
	return (res);
}
