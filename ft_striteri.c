/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:44:44 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/27 15:38:33 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a function to each character of a string, passing its index.
 *
 * This function iterates over the string s and applies the function f to each
 * character, passing the index and a pointer to the character. The function does
 * nothing if s or f is NULL.
 *
 * @param s The string to iterate over. Must be modifiable.
 * @param f The function to apply to each character and its index.
 * @note If s or f is NULL, the function does nothing.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
		f(i++, s++);
}
