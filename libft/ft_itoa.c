/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:38:01 by mislamov          #+#    #+#             */
/*   Updated: 2019/07/25 23:38:02 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	int				num;
	int				num_len;
	unsigned int	temp;
	char			*res;

	num_len = (n < 0) ? 1 : 0;
	num = n;
	temp = (n < 0) ? (-n) : n;
	while (n >= 10 || n <= -10)
	{
		num_len++;
		n /= 10;
	}
	if (!(res = (char *)malloc(sizeof(char) * (num_len + 2))))
		return (NULL);
	res[num_len + 1] = '\0';
	while (num_len >= 0)
	{
		res[num_len--] = (temp % 10) + '0';
		temp /= 10;
	}
	res[0] = num < 0 ? '-' : res[0];
	return (res);
}
