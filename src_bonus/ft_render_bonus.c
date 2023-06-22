/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:28:45 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/20 11:28:59 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_render_player_down_or_left(t_list *e)
{
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerdown,
		e->cat_x, e->cat_y);
}

void	ft_render_player_up(t_list *e)
{
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerup,
		e->cat_x, e->cat_y);
}

void	ft_render_player_right(t_list *e)
{
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerright,
		e->cat_x, e->cat_y);
}

void	ft_render_floor(t_list *e)
{
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg,
		e->cat_x, e->cat_y);
}

void	ft_render_exit(t_list *e)
{
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg,
		e->cat_x, e->cat_y);
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->exitimg,
		e->cat_x, e->cat_y);
}
