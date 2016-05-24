/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:16:35 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/22 10:16:38 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_mod(const char *s1)
{
	char	*new;

	if (!s1)
		return (ft_strdup_mod("(null)"));
	new = ft_strsub(s1, 0, ft_strlen(s1));
	return (new);
}
