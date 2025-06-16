/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:28:43 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/27 15:38:20 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Split a string into an array of strings based on a delimiter.
 *
 * This function splits the string s into an array of strings using the delimiter
 * c. If s is NULL, the function returns NULL. The function handles multiple
 * consecutive delimiters and trims leading and trailing delimiters.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return An array of strings, or NULL if allocation fails.
 * @note If s is NULL, the function returns NULL. The function handles multiple
 *       consecutive delimiters and trims leading and trailing delimiters.
 */

static	size_t	count_words(char const *str, char sep)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == sep)
		{
			while (*str && *str == sep)
				str++;
			continue ;
		}
		while (*str && *str != sep)
			str++;
		i++;
	}
	return (i);
}

static	void	*free_all(char **ptr, int count)
{
	int	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (ptr[i])
			free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static char	*ft_split_word(char	**res, char *str, char sep, size_t *i)
{
	char	*next_separator;

	while (*str && *str == sep)
		str++;
	next_separator = ft_strchr(str, sep);
	if (!next_separator)
	{
		res[*i] = ft_strdup(str);
		if (!res[*i])
			return (NULL);
		(*i)++;
		return (str);
	}
	res[*i] = ft_substr(str, 0, (next_separator - str));
	if (!res[*i])
		return (NULL);
	(*i)++;
	str = next_separator + 1;
	while (*str == sep)
		str++;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		words_count;	

	if (s == NULL)
		return (NULL);
	words_count = count_words(s, c);
	res = (char **) malloc((words_count + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	ft_bzero(res, (words_count + 1) * sizeof(char *));
	i = 0;
	while (words_count > 0)
	{
		s = ft_split_word(res, (char *) s, c, &i);
		if (!s)
			return (free_all(res, i));
		words_count--;
	}
	res[i] = NULL;
	return (res);
}
