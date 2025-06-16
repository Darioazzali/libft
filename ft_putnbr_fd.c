/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:31:29 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/27 15:38:06 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/**
 * @brief Write an integer to a file descriptor as a string.
 *
 * This function writes the integer n to the file descriptor fd as a string of
 * characters. Handles negative numbers and the INT_MIN edge case.
 *
 * @param n The integer to write.
 * @param fd The file descriptor to write to. If fd is invalid, the function will
 *           fail silently (write will return -1).
 * @note No error is reported if the write fails. The function does not check if
 *       fd is valid or open for writing. Handles INT_MIN by recursive calls.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(-(n % 10), fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n % 10 + '0', fd);
}
