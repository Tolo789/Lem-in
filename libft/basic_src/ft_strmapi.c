/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 12:31:16 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/19 12:31:21 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	new = NULL;
	if (s && f)
	{
		if (*s)
		{
			if (!(new = ft_strnew(ft_strlen(s))))
				return (NULL);
			i = ft_strlen(s) - 1;
			while (i > 0)
			{
				new[i] = f(i, (char)s[i]);
				i--;
			}
			new[i] = f(i, (char)s[i]);
		}
		else if (!(new = ft_strnew(0)))
			return (NULL);
	}
	return (new);
}
