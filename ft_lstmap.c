/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:14:12 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:52:50 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/**
 * @brief Create a new list by applying a function to each element of an existing
 *        list.
 *
 * This function iterates over the list lst and applies the function f to the
 * content of each element, creating a new list with the results. If allocation
 * fails for any element, the function uses del to free the content of all new
 * elements and returns NULL.
 *
 * @param lst The beginning of the list to map over. Can be NULL.
 * @param f The function to apply to each element's content. Must not be NULL.
 * @param del The function to delete the content of each element in case of
 *            failure. Can be NULL if no cleanup is needed.
 * @return A new list resulting from the successive applications of f, or NULL if
 *         allocation fails or if lst or f is NULL.
 * @note If allocation fails, all allocated nodes are freed using del.
 *       If lst or f is NULL, the function returns NULL.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
