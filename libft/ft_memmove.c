/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <mislamov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:25:01 by mislamov          #+#    #+#             */
/*   Updated: 2019/08/08 19:12:38 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			i;

	if (str1 == str2)
		return (str1);
	i = 0;
	ptr = (unsigned char*)str1;
	ptr2 = (unsigned char*)str2;
	if (ptr2 < ptr)
		while (++i <= n)
			ptr[n - i] = ptr2[n - i];
	else
		while (n-- > 0)
			*(ptr++) = *(ptr2++);
	return (str1);
}
