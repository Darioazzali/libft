/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:04:43 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:52:31 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last element of a singly linked list.
 *
 * This function traverses the list starting from lst and returns
 * a pointer to the last element. If lst is NULL, the function returns NULL.
 *
 * @param lst The beginning of the list. Can be NULL.
 * @return The last element of the list, or NULL if the list is empty or lst is
 *         NULL.
 * @note If lst is NULL, the function returns NULL.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
