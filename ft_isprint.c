/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:30:08 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/19 19:01:01 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check for any printable character including space.
 *
 * This function checks if the character c is a printable character, including
 * space. It returns a non-zero value if c is printable, and zero otherwise.
 *
 * @param c The character to check.
 * @return Non-zero if c is a printable character, zero otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
