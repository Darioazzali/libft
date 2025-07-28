/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:37:23 by dazzali           #+#    #+#             */
/*   Updated: 2025/07/28 07:16:38 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(int fd, unsigned int nbr, bool upper)
{
	char	*base_lower;
	char	*base_upper;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (upper)
	{
		return (ft_putnbr_base_fd(fd, nbr, base_upper));
	}
	return (ft_putnbr_base_fd(fd, nbr, base_lower));
}
