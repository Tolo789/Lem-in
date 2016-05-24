/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:59:26 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/26 15:00:06 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char*)dst;
	str2 = (char*)src;
	while (i < n)
	{
		str1[i] = str2[i];
		if ((unsigned char)str2[i] == (unsigned char)c)
			return ((void*)&(str1[i + 1]));
		i++;
	}
	return (NULL);
}
