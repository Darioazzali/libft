/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:22:38 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:52:19 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Delete and free a single element of a linked list.
 *
 * This function deletes and frees the given list element, using the function del
 * to free its content. If lst or del is NULL, the function does nothing.
 *
 * @param lst The element to delete.
 * @param del The function to delete the content of the element. If del is NULL,
 *            the function does nothing.
 * @note If lst or del is NULL, the function does nothing.
 * If lst->content is NULL, del is not called.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->content)
		del(lst->content);
	free(lst);
}
