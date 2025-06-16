/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:22:54 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/30 11:15:18 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/**
 * @brief Write a string followed by a newline to a file descriptor.
 *
 * This function writes the string s to the file descriptor fd, followed by a
 * newline character. It uses the write system call.
 *
 * @param s The string to write. If s is NULL, the function will likely cause a
 *          segmentation fault.
 * @param fd The file descriptor to write to. If fd is invalid, the function will
 *           fail silently (write will return -1).
 * @note No error is reported if the write fails. The function does not check if
 *       fd is valid or open for writing.
 */
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
