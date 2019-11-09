/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:27:45 by mislamov          #+#    #+#             */
/*   Updated: 2019/07/24 17:27:47 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0 && str[i] != (char)c)
	{
		i--;
	}
	if (str[i] == (char)c)
		return (&((char*)str)[i]);
	return (NULL);
}
