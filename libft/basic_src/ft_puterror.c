/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:08:06 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/29 15:09:24 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft.h"

int		ft_puterror(int id)
{
	ft_putstr_fd("ERROR: ", 2);
	if (id == 1)
		ft_putstr_fd("Enter the path for a map file\n", 2);
	else if (id == 2)
		ft_putstr_fd("Problems creating the mlx pointer\n", 2);
	else if (id == 3)
		ft_putstr_fd("Problems creating the window\n", 2);
	else if (id == -1)
		ft_putstr_fd("The given path is not for a valid map\n", 2);
	else if (id == -2)
		ft_putstr_fd("Malloc error\n", 2);
	else if (id == -3)
		ft_putstr_fd("The image you are trying to create is too big\n", 2);
	return (id);
}
