/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:39:43 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:50:31 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/**
 * @brief Extract a substring from a string.
 *
 * This function extracts a substring from the string s, starting at index start
 * and with a maximum length of len. If start is greater than the length of s, an
 * empty string is returned. 
 * If start + len exceeds the length of s, the substring
 * will be truncated.
 *
 * @param s The string from which to extract the substring.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return A pointer to the extracted substring, or NULL if allocation fails.
 * @note If start is greater than the length of s, an empty string is returned.
 * 		 If start + len exceeds the length of s, the substring will be truncated.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len >= s_len)
		len = s_len - start;
	res = (char *) ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, (s + start), len + 1);
	return (res);
}
