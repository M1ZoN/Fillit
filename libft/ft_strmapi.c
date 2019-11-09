/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:36:44 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/08 18:36:50 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*new_str;
	size_t	i;

	i = -1;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	new_str = ft_strnew(size);
	if (!new_str)
		return (NULL);
	while (s[++i])
		new_str[i] = f(i, s[i]);
	return (new_str);
}
