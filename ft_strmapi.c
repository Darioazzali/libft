/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:57:59 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:51:26 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/**
 * @brief Apply a function to each character of a string.
 *
 * This function applies the function f to each character of the string s,
 * passing the index and the character as arguments.
 * It returns a new string with the results.
 * If allocation fails, the function returns NULL.
 *
 * @param s The string to process.
 * @param f The function to apply to each character.
 * @return A pointer to the resulting string, or NULL if allocation fails.
 * @note The function applies f to each character of s, passing the index and the
 *       character as arguments.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*res;
	size_t	idx;

	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		res[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
