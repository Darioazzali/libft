/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:00:17 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/25 23:42:26 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Convert a lowercase letter to uppercase.
 *
 * This function converts the lowercase letter c to its uppercase equivalent. If
 * c is not a lowercase letter, it is returned unchanged.
 *
 * @param c The character to convert.
 * @return The uppercase equivalent if c is a lowercase letter, otherwise c.
 */

static int	ft_is_lower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_is_lower(c))
		return (c - ('a' - 'A'));
	return (c);
}
