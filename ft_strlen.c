/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:37:32 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/25 18:41:43 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

/**
 * @brief Calculate the length of a string.
 *
 * @param str The string whose length is to be calculated.
 * @return The number of characters in the string, excluding the null terminator.
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
