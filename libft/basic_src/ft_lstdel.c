/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:57:50 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/27 12:57:52 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	if (alst && *alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			next = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = next;
		}
		*alst = NULL;
	}
}
