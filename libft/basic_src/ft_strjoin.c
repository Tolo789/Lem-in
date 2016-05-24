/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:57:27 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/25 14:57:29 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_add(char *newelem, char const *str)
{
	newelem = ft_strnew(ft_strlen(str));
	if (!newelem)
		return (NULL);
	newelem = ft_strcat(newelem, (char*)str);
	return (newelem);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	new = NULL;
	if (s1 && s2)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (!new)
			return (NULL);
		new = ft_strcat(new, (char*)s1);
		new = ft_strcat(new, (char*)s2);
		return (new);
	}
	if (s1)
		return (ft_add(new, s1));
	if (s2)
		return (ft_add(new, s2));
	return (new);
}
