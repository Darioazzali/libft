/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:25:34 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:54:15 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Locate the first occurrence of a character in a string.
 *
 * @param haystack The string to be searched.
 * @param needle The character to search for (interpreted as unsigned char).
 * @return A pointer to the first occurrence of the character in the string,
 *         or NULL if not found.
 */
char	*ft_strchr(const char *haystack, int needle)
{
	while (*haystack != (unsigned char) needle)
	{
		if (*haystack == '\0')
			return ((char *) 0);
		haystack++;
	}
	return ((char *)haystack);
}
