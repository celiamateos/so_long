/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:08 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/16 17:38:34 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_print_floor(t_list *e)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < e->height_win)
	{
		while (x < e->width_win)
		{
			mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, x, y);
			x += e->whimg;
		}
		x = 0;
		y += e->htimg;
	}
}

void	ft_print_object(t_list *e, int i, int j)
{
	if (e->map[i][j] == '1')
		mlx_put_image_to_window(e->mlx, e->mlx_win, e->wallimg,
			e->position.x, e->position.y);
	if (e->map[i][j] == 'P')
	{
		mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerup,
			e->position.x, e->position.y);
		e->cat_y = e->position.y;
		e->cat_x = e->position.x;
		e->i = i;
		e->j = j;
	}
	if (e->map[i][j] == 'C')
		mlx_put_image_to_window(e->mlx, e->mlx_win, e->collectimg,
			e->position.x, e->position.y);
	if (e->map[i][j] == 'E')
		mlx_put_image_to_window(e->mlx, e->mlx_win, e->exitimg,
			e->position.x, e->position.y);
}

void	ft_print_map(t_list *e)
{
	int	i;
	int	j;

	ft_print_floor(e);
	i = 0;
	j = 0;
	while (e->position.y < e->height_win)
	{
		while (e->position.x < e->width_win)
		{
			ft_print_object(e, i, j);
			j++;
			e->position.x += e->whimg;
		}
		j = 0;
		e->position.x = 0;
		i++;
		e->position.y += e->htimg;
	}
}
