/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:57:31 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/25 09:57:32 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new;

	new = (void*)malloc(size);
	if (!new)
		return (NULL);
	new = ft_memset(new, 0, size);
	return (new);
}
