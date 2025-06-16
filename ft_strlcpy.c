/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:45:51 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:55:40 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief Copy a string to a buffer with size limitation.
 *
 * Copies up to size - 1 characters from the NUL-terminated string src to dst,
 * NUL-terminating the result.
 *
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create: the length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	len;

	len = ft_strlen((char *) src);
	if (size == 0)
		return (len);
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size --;
	}
	*dst = '\0';
	return (len);
}
