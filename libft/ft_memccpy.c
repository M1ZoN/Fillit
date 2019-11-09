/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:15:52 by mislamov          #+#    #+#             */
/*   Updated: 2019/07/22 17:16:16 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *str1, void *str2, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char*)str1;
	ptr2 = (unsigned char*)str2;
	while (n > 0)
	{
		*(ptr) = *(ptr2);
		if (*(ptr2) == (unsigned char)c)
			return ((void *)&(*(ptr + 1)));
		ptr++;
		ptr2++;
		n--;
	}
	return (NULL);
}
