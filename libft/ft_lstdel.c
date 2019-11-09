/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:16:25 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/08 19:55:12 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node_ptr;
	t_list	*next_ptr;

	node_ptr = *alst;
	while (node_ptr)
	{
		next_ptr = node_ptr->next;
		ft_lstdelone(&node_ptr, del);
		node_ptr = next_ptr;
	}
	*alst = NULL;
}
