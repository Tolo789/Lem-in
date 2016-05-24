/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:24:45 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/25 12:24:47 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_apllyf(char *new, char *str, char (*f)(char))
{
	size_t	i;

	i = ft_strlen(str);
	new[i] = '\0';
	while (--i > 0)
		new[i] = f(str[i]);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*str;

	new = NULL;
	if (s && f)
	{
		if (*s)
		{
			str = (char*)s;
			new = ft_strnew(ft_strlen(str));
			if (!new)
				return (NULL);
			ft_apllyf(new, str, f);
			new[0] = f(str[0]);
		}
		else if (!(new = ft_strnew(0)))
			return (NULL);
	}
	return (new);
}
