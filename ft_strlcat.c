/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:45:38 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:55:26 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/**
 * @brief Concatenate two strings with size limitation.
 *
 * Appends the NUL-terminated string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 bytes,
 * NUL-terminating the result.
 *
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The total size of the destination buffer.
 * @return The total length of the string it tried to create:
 *         initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*original_dst;
	const char	*original_src;
	size_t		rem_bytes;
	size_t		occup_bytes;

	original_dst = dst;
	rem_bytes = size;
	while (*dst && rem_bytes-- != 0)
		dst++;
	occup_bytes = dst - original_dst;
	rem_bytes = size - occup_bytes;
	if (rem_bytes-- == 0)
		return (ft_strlen(src) + occup_bytes);
	original_src = src;
	while (*src)
	{
		if (rem_bytes != 0)
		{
			*dst++ = *src;
			rem_bytes--;
		}
		src++;
	}
	*dst = '\0';
	return (occup_bytes + src - original_src);
}
