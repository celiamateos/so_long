/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:33:05 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/21 20:33:20 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_print_blackhole(t_list *e, int x, int y)
{
	if (!ft_end_game(e))
		e->loops++;
	if (e->loops < 50)
	{
		mlx_put_image_to_window(e->mlx, e->mlx_win, e->blackhole1, x, y);
	}
	else if (e->loops < 100)
	{
		mlx_put_image_to_window(e->mlx, e->mlx_win, e->blackhole2, x, y);
	}
	else if (e->loops < 150)
	{
		mlx_put_image_to_window(e->mlx, e->mlx_win, e->blackhole3, x, y);
	}
	if (e->loops == 200)
		e->loops = 0;
}

int	ft_animation(t_list *e)
{
	int	i;
	int	j;

	e->position.x = 0;
	e->position.y = 0;
	i = 0;
	j = 0;
	while (e->position.y < e->height_win)
	{
		while (e->position.x < e->width_win)
		{
			if (e->map[i][j] == 'X')
				ft_print_blackhole(e, e->position.x, e->position.y);
			j++;
			e->position.x += e->whimg;
		}
		j = 0;
		e->position.x = 0;
		i++;
		e->position.y += e->htimg;
	}
	return (0);
}
