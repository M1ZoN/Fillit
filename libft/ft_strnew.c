/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:35:55 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/08 18:26:56 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i <= size)
		res[i++] = '\0';
	res[0] = '\0';
	return (res);
}
