/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:21:07 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/13 20:21:37 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_move_down(t_list *e)
{
	if (e->map[e->i + 1][e->j] != '1')
	{
		e->steps++;
		if (!ft_end_game(e))
			ft_printsteps(e);
		if (e->map[e->i][e->j] != 'E')
			ft_render_floor(e);
		if (e->map[e->i][e->j] == 'E' && !ft_open_exit(e))
			ft_render_exit(e);
		e->cat_y += HEIGHT_IMG;
		ft_render_player_down_or_left(e);
		e->i = e->i + 1;
		if (e->map[e->i][e->j] == 'X')
			ft_error(e, 2);
		if (e->map[e->i][e->j] == 'E' && ft_open_exit(e))
			ft_error(e, 2);
		if (e->map[e->i][e->j] == 'C')
		{
			e->map[e->i][e->j] = '0';
			ft_render_floor(e);
			ft_render_player_down_or_left(e);
			e->collected += 1;
		}
	}
}

void	ft_move_up(t_list *e)
{
	if (e->map[e->i - 1][e->j] != '1')
	{
		e->steps++;
		if (!ft_end_game(e))
			ft_printsteps(e);
		if (e->map[e->i][e->j] != 'E')
			ft_render_floor(e);
		if (e->map[e->i][e->j] == 'E' && !ft_open_exit(e))
			ft_render_exit(e);
		e->cat_y -= HEIGHT_IMG;
		ft_render_player_up(e);
		e->i = e->i - 1;
		if (e->map[e->i][e->j] == 'X')
			ft_error(e, 2);
		if (e->map[e->i][e->j] == 'E' && ft_open_exit(e))
			ft_error(e, 2);
		if (e->map[e->i][e->j] == 'C')
		{
			e->map[e->i][e->j] = '0';
			ft_render_floor(e);
			ft_render_player_up(e);
			e->collected += 1;
		}
	}
}

void	ft_move_left(t_list *e)
{
	if (e->map[e->i][e->j - 1] != '1')
	{
		e->steps++;
		if (!ft_end_game(e))
			ft_printsteps(e);
		if (e->map[e->i][e->j] != 'E')
			ft_render_floor(e);
		if (e->map[e->i][e->j] == 'E' && !ft_open_exit(e))
			ft_render_exit(e);
		e->cat_x -= WIDTH_IMG;
		ft_render_player_down_or_left(e);
		e->j = e->j - 1;
		if (e->map[e->i][e->j] == 'X')
			ft_error(e, 2);
		if (e->map[e->i][e->j] == 'E' && ft_open_exit(e))
			ft_error(e, 2);
		if (e->map[e->i][e->j] == 'C')
		{
			e->map[e->i][e->j] = '0';
			ft_render_floor(e);
			ft_render_player_down_or_left(e);
			e->collected += 1;
		}
	}
}

void	ft_move_right(t_list *e)
{
	if (e->map[e->i][e->j + 1] != '1')
	{
		e->steps++;
		if (!ft_end_game(e))
			ft_printsteps(e);
		if (e->map[e->i][e->j] != 'E')
			ft_render_floor(e);
		if (e->map[e->i][e->j] == 'E' && !ft_open_exit(e))
			ft_render_exit(e);
		e->cat_x += WIDTH_IMG;
		ft_render_player_right(e);
		e->j = e->j + 1;
		if (e->map[e->i][e->j] == 'X')
			ft_error(e, 2);
		if (e->map[e->i][e->j] == 'E' && ft_open_exit(e))
			ft_error(e, 2);
		if (e->map[e->i][e->j] == 'C')
		{
			e->map[e->i][e->j] = '0';
			ft_render_floor(e);
			ft_render_player_right(e);
			e->collected += 1;
		}
	}
}

int	ft_press_key(int keycode, t_list *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e ->mlx_win);
		exit(1);
	}
	if (keycode == S || keycode == DOWN)
		ft_move_down(e);
	if (keycode == W || keycode == UP)
		ft_move_up(e);
	if (keycode == A || keycode == LEFT)
		ft_move_left(e);
	if (keycode == D || keycode == RIGHT)
		ft_move_right(e);
	if (e->collected == e->collectable)
		ft_open_exit(e);
	return (0);
}
