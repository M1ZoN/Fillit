/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:16:57 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/09 17:48:49 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*node_ptr;

	if (!lst || !f)
		return (NULL);
	node_ptr = f(lst);
	head = node_ptr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(node_ptr->next = f(lst)))
		{
			free(node_ptr->next);
			return (NULL);
		}
		node_ptr = node_ptr->next;
	}
	return (head);
}
