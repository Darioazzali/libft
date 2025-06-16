/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:45:23 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/27 19:08:33 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Locate a byte in a block of memory.
 *
 * This function locates the first occurrence of the byte c in the memory area
 * pointed to by s, searching within the first n bytes. If n is 0, the function
 * returns NULL.
 *
 * @param s Pointer to the memory area to search.
 * @param c The byte to search for (interpreted as unsigned char).
 * @param n Number of bytes to search.
 * @return A pointer to the first occurrence of the byte in the memory area, or
 *         NULL if not found.
 * @note If n is 0, the function returns NULL.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	c = (unsigned char) c;
	ptr = (unsigned char *)s;
	while (n)
	{
		if (*ptr == c)
			return ((void *) ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
