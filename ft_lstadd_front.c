/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:08:32 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/27 15:40:33 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Add a new element to the beginning of a linked list.
 *
 * This function adds the element new to the beginning of the list pointed to by
 * lst. If lst or new is NULL, the function does nothing. If the list is empty,
 * new becomes the first element.
 *
 * @param lst A pointer to the pointer to the first element of the list.
 * @param new The new element to add to the list.
 * @note If lst or new is NULL, the function does nothing. If *lst is NULL, new
 *       becomes the first element.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
