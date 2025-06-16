/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:30:08 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/25 18:32:54 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check for an ASCII character.
 *
 * This function checks if the character c is an ASCII character (0 to 127).
 * It returns a non-zero value if c is ASCII, and zero otherwise.
 *
 * @param c The character to check.
 * @return Non-zero if c is an ASCII character (0 to 127), zero otherwise.
 */
int	ft_isascii(int c)
{
	return (!(c & ~127));
}
