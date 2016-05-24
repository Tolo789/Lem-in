/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:50:20 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/27 12:50:21 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)ft_memalloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = (void*)NULL;
		new->content_size = content_size;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		if (!new->content)
		{
			free(new);
			return (NULL);
		}
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = (t_list*)NULL;
	return (new);
}
