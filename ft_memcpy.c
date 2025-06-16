/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:45:31 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:55:57 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Copy memory area.
 *
 * Copies n bytes from memory area src to memory area dst.
 * The memory areas must not overlap.
 *
 * @param dst Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory area dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	while (i < n)
	{
		*(dst_ptr + i) = *(src_ptr + i);
		i++;
	}
	return (dst);
}
