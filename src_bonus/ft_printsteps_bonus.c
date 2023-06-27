/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsteps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:26:06 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/22 15:26:18 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_printsteps(t_list *e)
{
	int	x;
	int	y;
	int	verif;

	verif = 0;
	y = 20;
	x = 20;
	while (y++ < 50)
	{
		while (x++ < 130)
			mlx_pixel_put(e->mlx, e->mlx_win, x, y, 0x00000);
		x = 20;
	}
	mlx_string_put(e->mlx, e->mlx_win, 25, 25, 0xFFFFFF, "STEPS:");
		e->steps_bns = ft_itoa(e->steps);
	mlx_string_put(e->mlx, e->mlx_win, 100, 25, 0xFFFFFF, e->steps_bns);
}
