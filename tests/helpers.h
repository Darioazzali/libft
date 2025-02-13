/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:47:55 by dazzali           #+#    #+#             */
/*   Updated: 2025/01/02 09:23:06 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPERS_H

# define FT_HELPERS_H
# include <stddef.h>
# include <stdbool.h>
# include "../libft.h"
# define KGRN  "\x1B[32m"
# define KBLUE	"\x1B[34m"
# define KNRM  "\x1B[0m"

typedef struct Vector
{
	unsigned char	*data;
	size_t 			len;
} t_vector;

size_t			generate_random_size(size_t min_size, size_t max_size) ;
unsigned char	generate_random_char(void); 
t_vector		*generate_casual_bytes(int min, int max);
void			free_vector(t_vector *v);
bool			is_in_array(unsigned char *array, unsigned char c, size_t len);
t_list			*build_from_strings(char **strings);
char			**build_string_array(size_t count, ...);

char	char_title(unsigned int i, char s);
void	format_title(char *title);
#endif
