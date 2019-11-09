/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:27:58 by mislamov          #+#    #+#             */
/*   Updated: 2019/07/24 17:27:59 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*l))
		return ((char *)b);
	while (b[i] && len > i)
	{
		j = 0;
		while (b[i] && b[j] &&
				i < len && b[i] == l[j])
		{
			i++;
			j++;
		}
		if (l[j] == '\0')
			return ((char*)b + i - j);
		i = i - j;
		++i;
	}
	return (NULL);
}
