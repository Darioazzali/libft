/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:14:10 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/28 23:21:48 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a function to each element of a linked list.
 *
 * This function iterates over the list lst and applies the function f to the
 * content of each element. If lst or f is NULL, the function does nothing.
 *
 * @param lst The beginning of the list.
 * @param f The function to apply to each element's content.
 * @note If lst or f is NULL, the function does nothing.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
