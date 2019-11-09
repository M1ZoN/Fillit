/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:28:12 by mislamov          #+#    #+#             */
/*   Updated: 2019/07/24 17:28:13 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i] == str2[i]) && str1[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
