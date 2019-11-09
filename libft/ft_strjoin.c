/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:37:35 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/10 01:10:10 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (ft_strnew(0));
		else
			return ((char *)(s1 == NULL ? ft_strdup(s2) : ft_strdup(s1)));
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (res != NULL)
	{
		ft_strcpy(res, s1);
		ft_strcpy(res + len1, s2);
		res[len1 + len2] = '\0';
	}
	return (res);
}
