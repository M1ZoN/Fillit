/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mislamov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:37:52 by mislamov          #+#    #+#             */
/*   Updated: 2019/07/25 23:37:53 by mislamov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s == c)
		s++;
	while (*s && *s++ != c)
		count++;
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dest;

	i = 0;
	j = 0;
	if (!s || !(dest = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	while (i < count_words(s, c))
	{
		k = 0;
		if (!(dest[i] = ft_strnew(word_len(&s[j], c) + 1)))
			dest[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			dest[i][k++] = s[j++];
		dest[i][k] = '\0';
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
