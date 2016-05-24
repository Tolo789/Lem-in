/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:02:23 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/26 15:02:25 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char*)dst;
	str2 = ft_strsub((char*)src, (unsigned int)0, len);
	if (!str2 && src)
		return (NULL);
	while (i < len)
	{
		str1[i] = str2[i];
		i++;
	}
	free(str2);
	dst = (void*)str1;
	return (dst);
}
