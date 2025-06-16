/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:57:51 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/19 17:57:52 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check for a digit (0 through 9).
 *
 * This function checks if the character c is a digit (0-9). It returns a
 * non-zero value if c is a digit, and zero otherwise.
 *
 * @param c The character to check.
 * @return Non-zero if c is a digit, zero otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
