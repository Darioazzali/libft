/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:44:08 by dazzali           #+#    #+#             */
/*   Updated: 2025/07/28 07:17:10 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_cursor(int fd, t_print_sm *sm, va_list args)
{
	int	res;

	write(fd, sm->cursor, (sm->fmt - sm->cursor));
	sm->printed += (sm->fmt)++ - sm->cursor;
	res = print_formatted_argument(fd, args, *(sm->fmt));
	if (res == -1)
		return (-1);
	sm->printed += res;
	sm->cursor = (char *)sm->fmt + 1;
	return (res);
}

int	print_formatted_argument(int fd, va_list args, char fmt)
{
	if (fmt == 'd' || fmt == 'i')
		return (ft_print_int(fd, va_arg(args, int)));
	else if (fmt == 'c')
		return (ft_print_char(fd, va_arg(args, int)));
	else if (fmt == 'u')
		return (ft_print_unsigned(fd, va_arg(args, unsigned int)));
	else if (fmt == 's')
		return (ft_print_str(fd, va_arg(args, char *)));
	else if (fmt == 'p')
		return (ft_print_pointer(fd, va_arg(args, char *)));
	else if (fmt == 'x')
		return (ft_print_hex(fd, va_arg(args, unsigned int), false));
	else if (fmt == 'X')
		return (ft_print_hex(fd, va_arg(args, unsigned int), true));
	else if (fmt == '%')
		return (ft_print_char(fd, '%'));
	return (-1);
}

int	ft_print_str(int fd, char *s)
{
	size_t	len;
	int		w_res;

	if (!s)
		return (write(fd, "(null)", 6));
	len = ft_strlen(s);
	w_res = write(fd, s, len);
	if ((w_res) != (int) len)
		return (-1);
	return (len);
}

int	ft_print_char(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	ft_print_int(int fd, int i)
{
	int		b_written;
	char	*res;

	res = ft_itoa(i);
	if (res == NULL)
		return (-1);
	b_written = ft_print_str(fd, res);
	free(res);
	return (b_written);
}
