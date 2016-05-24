/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:04:02 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/24 19:04:04 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && s2[j] && i + j < n)
				j++;
			if (s2[j] == 0)
				return ((char*)&s1[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
