/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:30:08 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/27 15:40:49 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Check for alphanumeric character.
 *
 * This function checks if the character c is alphanumeric (A-Z, a-z, 0-9).
 * It returns a non-zero value if c is alphanumeric, and zero otherwise.
 *
 * @param c The character to check.
 * @return Non-zero if c is an alphanumeric character, zero otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
