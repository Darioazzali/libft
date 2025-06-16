/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:03:10 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/23 20:06:53 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/**
 * @brief Write a character to a file descriptor.
 *
 * This function writes the character c to the file descriptor fd using the write
 * system call.
 *
 * @param c The character to write.
 * @param fd The file descriptor to write to. If fd is invalid, the function will
 *           fail silently (write will return -1).
 * @note No error is reported if the write fails. The function does not check if
 *       fd is valid or open for writing.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
