/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:44:30 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/27 15:44:37 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

static bool	is_overflow(size_t nmemb, size_t size)
{
	size_t	total_bytes;

	total_bytes = nmemb * size;
	if (total_bytes < nmemb || total_bytes < size)
		return (true);
	return (false);
}

/**
 * @brief Allocate memory for an array of elements and initialize it to zero.
 *
 * This function allocates memory for an array of nmemb elements, each of size
 * bytes, and initializes all bytes to zero. If allocation fails or if the total
 * size exceeds PTRDIFF_MAX, the function returns NULL.
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element.
 * @return A pointer to the allocated memory, or NULL if allocation fails or if
 *         the total size exceeds PTRDIFF_MAX.
 * @note If nmemb or size is 0, the function returns a pointer to a zero-sized
 *       block of memory.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	if (total_bytes >= PTRDIFF_MAX)
		return (NULL);
	if (!total_bytes)
		return (malloc(0));
	if (is_overflow(nmemb, size))
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_bytes);
	return (ptr);
}
