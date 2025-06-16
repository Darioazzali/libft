/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:01:26 by dazzali           #+#    #+#             */
/*   Updated: 2024/12/27 15:40:29 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Delete and free all elements of a linked list.
 *
 * This function deletes and frees all elements of the list pointed to by lst,
 * using the function del to free the content of each element. The pointer to the
 * list is set to NULL after the operation. If lst or *lst is NULL, the function
 * does nothing.
 *
 * @param lst A pointer to the pointer to the first element of the list.
 * @param del The function to delete the content of each element. If del is NULL,
 *            the content is not freed.
 * @note If lst or *lst is NULL, the function does nothing. If del is NULL, only
 *       the nodes are freed, not their content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;

	if (!lst || !*lst)
		return ;
	current_node = *lst;
	if (current_node->next)
		ft_lstclear(&(current_node)->next, del);
	if (del)
		del(current_node->content);
	free(current_node);
	*lst = NULL;
}
