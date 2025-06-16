/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:27:45 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/28 23:18:25 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Add a new element to the end of a linked list.
 *
 * This function adds the element new to the end of the list pointed to by lst.
 * If lst or new is NULL, the function does nothing. If the list is empty, new
 * becomes the first element.
 *
 * @param lst A pointer to the pointer to the first element of the list.
 * @param new The new element to add to the list.
 * @note If lst or new is NULL, the function does nothing. If *lst is NULL, new
 *       becomes the first element.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
