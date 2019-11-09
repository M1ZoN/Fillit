/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:37:11 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/08 17:16:39 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	res;

	if (!s1 || !s2)
		return (0);
	res = ft_strcmp(s1, s2);
	if (res == 0)
		return (1);
	else
		return (0);
}
