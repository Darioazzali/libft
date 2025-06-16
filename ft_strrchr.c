/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:25:34 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:50:44 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate the last occurrence of a character in a string.
 *
 * @param haystack The string to be searched.
 * @param needle The character to search for (interpreted as unsigned char).
 * @return A pointer to the last occurrence of the character in the string,
 *         or NULL if not found.
 */
char	*ft_strrchr(const char *haystack, int needle)
{
	int				len;
	const char		*end;

	len = ft_strlen(haystack);
	end = haystack + len;
	while (end >= haystack)
	{
		if (*end == (unsigned char) needle)
			return ((char *) end);
		end--;
	}
	return ((char *)0);
}
