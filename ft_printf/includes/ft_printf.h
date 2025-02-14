/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:33:47 by dazzali           #+#    #+#             */
/*   Updated: 2025/02/04 12:58:36 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include "libft.h"

int	ft_print_cursor(char **cursor, const char **fmt, int *b_pr, va_list args);
int	ft_printf(const char *fmt, ...);
int	ft_print_pointer(void *ptr);
int	ft_print_int(int i);
int	ft_putnbr_base(unsigned long long nbr, char *base);
int	ft_print_hex(unsigned int nbr, bool upper);
int	ft_print_unsigned(unsigned int i);
int	ft_print_str(char *s);
int	ft_print_char(char c);
int	ft_print_int(int i);
int	print_formatted_argument(va_list args, char fmt);
#endif
