/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 01:20:34 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/10 01:35:31 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **alst, void const *c, size_t n)
{
	t_list	*node_ptr;

	node_ptr = *alst;
	while (node_ptr->next)
		node_ptr = node_ptr->next;
	node_ptr->next = ft_lstnew(c, n);
}
