/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:47:23 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:54:38 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Duplicate a string.
 *
 * This function duplicates the string s into a new string. It allocates memory
 * for the new string and copies the original string into it.
 * If allocation fails, the function returns NULL.
 *
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string, or NULL if allocation fails.
 * @note The function allocates memory for the new string and copies the original
 *       string into it.
 */
char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *) malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}
