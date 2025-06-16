/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazzali <dazzali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:14:01 by dazzali           #+#    #+#             */
/*   Updated: 2025/06/16 13:53:10 by dazzali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Create a new list element.
 *
 * This function allocates and returns a new list element. The member variable
 * content is initialized with the value of the parameter content. The variable
 * next is initialized to NULL. If allocation fails, the function returns NULL.
 *
 * @param content The content to store in the new element. Can be NULL.
 * @return A pointer to the new element, or NULL if allocation fails.
 * @note If allocation fails, NULL is returned.
 *       The content pointer is stored as-is and not copied.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *) malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
