/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:59:23 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:53:35 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Count the number of elements in a linked list.
 *
 * This function counts and returns the number of elements
 * in the list starting at lst. If lst is NULL, the function returns 0.
 *
 * @param lst The beginning of the list. Can be NULL.
 * @return The number of elements in the list, or 0 if
 *         the list is empty or lst is NULL.
 * @note If lst is NULL, the function returns 0.
 */
int	ft_lstsize(t_list *lst)
{
	t_list	*next_node;
	size_t	len;

	if (!lst)
		return (0);
	len = 1;
	next_node = lst->next;
	while (next_node)
	{
		next_node = next_node->next;
		len++;
	}
	return (len);
}
