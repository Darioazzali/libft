/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:13:34 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/25 23:44:17 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Convert an uppercase letter to lowercase.
 *
 * This function converts the uppercase letter c to its lowercase equivalent. If
 * c is not an uppercase letter, it is returned unchanged.
 *
 * @param c The character to convert.
 * @return The lowercase equivalent if c is an uppercase letter, otherwise c.
 */

static int	ft_is_upper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_is_upper(c))
		return (c + ('a' - 'A'));
	return (c);
}
