/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:47:38 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/30 18:16:24 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief Locate a substring in a string, limited by length.
 *
 * This function locates the first occurrence of the substring little in the
 * string big, searching within the first len characters. If little is an empty
 * string, big is returned. If len is 0, NULL is returned.
 *
 * @param big The string to be searched.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search in big.
 * @return A pointer to the first occurrence of little in big, or NULL if not
 *         found.
 * @note If little is an empty string, big is returned. If len is 0, NULL is
 *       returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	if (!len)
		return (NULL);
	while (*big && len > 0)
	{
		if (ft_strlen(little) > len)
			return (NULL);
		if (ft_strncmp(big, little, ft_strlen(little)) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
