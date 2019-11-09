/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:28:31 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/08 19:36:27 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	num;
	int			i;
	int			sign;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' ' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == '\n'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
