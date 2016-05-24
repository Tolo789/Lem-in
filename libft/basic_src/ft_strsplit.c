/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:04:09 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/25 16:04:13 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static size_t	ft_getwords(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			return (words);
		words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static char		*ft_cutword(char const *s, int c, size_t *start)
{
	size_t	j;
	char	*newword;

	j = *start;
	newword = 0;
	while (s[j] != c)
		j++;
	newword = ft_strsub(s, *start, j - *start);
	*start = j;
	return (newword);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	size;

	if (s)
	{
		i = -1;
		size = ft_getwords(s, c);
		tab = (char**)ft_memalloc(sizeof(*tab) * (size + 1));
		if (!tab)
			return (NULL);
		tab[size] = (char*)'\0';
		j = 0;
		while (++i < size)
		{
			while (s[j] == c)
				j++;
			tab[i] = ft_cutword(s, c, &j);
			if (!tab[i])
				return (NULL);
		}
		return (tab);
	}
	return (NULL);
}
