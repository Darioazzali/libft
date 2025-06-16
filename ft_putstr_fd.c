/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:45:54 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/30 11:12:36 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <unistd.h>

/**
 * @brief Write a string to a file descriptor.
 *
 * This function writes the string s to the file descriptor fd using the write
 * system call.
 *
 * @param s The string to write. If s is NULL, the function will likely cause a
 *          segmentation fault.
 * @param fd The file descriptor to write to. If fd is invalid, the function will
 *           fail silently (write will return -1).
 * @note No error is reported if the write fails. The function does not check if
 *       fd is valid or open for writing.
 */
void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}
