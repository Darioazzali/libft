/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:16:08 by dazzali           #+#    #+#             */
/*   Updated: 2025/07/28 11:40:58 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_init_sm(t_print_sm *sm, const char *fmt);

int	ft_printf(const char *fmt, ...)
{
	return (ft_fprintf(1, fmt));
}

int	ft_fprintf(int fd, const char *fmt, ...)
{
	va_list		args;
	t_print_sm	sm;
	int			res;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	_init_sm(&sm, fmt);
	while (*sm.fmt != '\0')
	{
		if (*sm.fmt == '%')
		{
			res = ft_print_cursor(fd, &sm, args);
			if (res == -1)
				return (-1);
		}
		else
			++(sm.fmt);
	}
	res = write(fd, sm.cursor, sm.fmt - sm.cursor);
	if (res == -1)
		return (-1);
	va_end(args);
	return (sm.printed + res);
}

static void	_init_sm(t_print_sm *sm, const char *fmt)
{
	sm->fmt = fmt;
	sm->cursor = (char *) fmt;
	sm->printed = 0;
}
