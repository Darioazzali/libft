/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:31:13 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/19 18:45:10 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check for an alphabetic character.
 *
 * This function checks if the character c is an alphabetic character (A-Z or
 * a-z). It returns a non-zero value if c is alphabetic, and zero otherwise.
 *
 * @param c The character to check.
 * @return Non-zero if c is an alphabetic character, zero otherwise.
 */

static int	isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int c)
{
	return (isupper(c) || islower(c));
}
