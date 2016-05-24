/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:43:45 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/26 15:43:47 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	while (dst[start] && start < size)
		start++;
	if (start < size)
	{
		while (start + i + 1 < size && src[i])
		{
			dst[start + i] = (char)src[i];
			i++;
		}
		dst[start + i] = '\0';
	}
	return (start + ft_strlen(src));
}
