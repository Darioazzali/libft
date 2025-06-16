/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:44:50 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:54:57 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Concatenate two strings.
 *
 * This function concatenates the strings s1 and s2 into a new string.
 * If both s1 and s2 are empty strings, an empty string is returned.
 * If allocation fails, the function returns NULL.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the concatenated string, or NULL if allocation fails.
 * @note If both s1 and s2 are empty strings, an empty string is returned.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;		
	size_t	s2_len;		
	char	*res;

	if (!*s1 && !*s2)
		return (ft_strdup(""));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, s1_len + s2_len + 1);
	ft_strlcat(res, s2, s1_len + s2_len + 1);
	return (res);
}
