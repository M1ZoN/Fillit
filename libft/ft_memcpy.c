/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:17:21 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/08 18:46:14 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *restrict str1, const void *restrict str2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = 0;
	if (n == 0 || str1 == str2)
		return (str1);
	ptr = (unsigned char*)str1;
	ptr2 = (unsigned char*)str2;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (str1);
}
