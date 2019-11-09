/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:16:49 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/08 19:51:04 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*node_ptr;

	if (!f || !lst)
		return ;
	node_ptr = lst;
	while (node_ptr)
	{
		f(node_ptr);
		node_ptr = node_ptr->next;
	}
}
