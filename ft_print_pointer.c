/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:36:28 by dazzali           #+#    #+#             */
/*   Updated: 2025/07/28 07:15:59 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_print_pointer(int fd, void *ptr)
{
	uintptr_t	ptr_value;
	int			res;

	if (ptr == NULL)
		return (write(fd, "(nil)", 5));
	ptr_value = (uintptr_t) ptr;
	if (write(fd, "0x", 2) == -1)
		return (-1);
	res = ft_putnbr_base_fd(fd, ptr_value, "0123456789abcdef");
	if (res == -1)
		return (-1);
	return (res + 2);
}
