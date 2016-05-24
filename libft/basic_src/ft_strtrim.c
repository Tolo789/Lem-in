/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:21:53 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/25 15:21:55 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	size_t	ft_get_lenght(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (!s[i])
		return (0);
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
	{
		j--;
		i++;
	}
	return (ft_strlen(s) - i);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = NULL;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		new = ft_strnew(ft_get_lenght(s));
		if (!new)
			return (NULL);
		while (j < ft_get_lenght(s))
		{
			new[j] = s[i];
			i++;
			j++;
		}
	}
	return (new);
}
