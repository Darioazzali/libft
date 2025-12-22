/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:45:06 by dazzali           #+#    #+#             */
/*   Updated: 2025/12/22 03:06:43 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **split);

/**
 * Convert ASCII string to float
 * @param str String to convert
 * @return Float value
 */
float	ft_atof(char *str)
{
	float	result;
	float	decimal;
	int		sign;
	int		len;
	char	**parts;

	sign = 1;
	if (*str == '-' && ++str)
		sign = -1;
	parts = ft_split(str, '.');
	result = (float)ft_atoi(parts[0]);
	if (parts[1])
	{
		decimal = (float)ft_atoi(parts[1]);
		len = ft_strlen(parts[1]);
		while (len--)
			decimal /= 10.0;
		result += decimal;
	}
	free_split(parts);
	return (result * sign);
}

static void	free_split(char **split)
{
	int i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}