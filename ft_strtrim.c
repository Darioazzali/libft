/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:39:18 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:49:53 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

/**
 * @brief Trim characters from the beginning and end of a string.
 *
 * Removes all characters in set from the beginning and end of s1.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to trim.
 * @return A new string with the specified characters 
 * 			removed from the start and end.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*start;
	char	*end;
	char	*res;

	if (!*set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = (char *) s1;
	while (*start && ft_strchr(set, *start))
		start++;
	if (!*start)
		return (ft_strdup(""));
	end = (char *) s1 + len - 1;
	while (*end && ft_strchr(set, *end))
		end--;
	res = ft_substr(s1, start - s1, end - start + 1);
	return (res);
}
