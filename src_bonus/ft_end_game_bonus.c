/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:40:31 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/19 21:41:43 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

void	ft_win(t_list *e)
{
	int	y_message1;
	int	x_message1;
	int	y_message2;
	int	x_message2;

	y_message1 = e->height_win / 2 - 80;
	x_message1 = e->width_win / 2 - 60 ;
	y_message2 = e->height_win / 2 - 40;
	x_message2 = e->width_win / 2 - 80;
	mlx_clear_window(e->mlx, e->mlx_win);
	mlx_string_put(e->mlx, e->mlx_win, x_message1, y_message1,
		0xFFFFFF, "CONGRANTULATIONS!");
	mlx_string_put(e->mlx, e->mlx_win, x_message2, y_message2,
		0xFFFFFF, "CAT SPACE SCAPED!");
	mlx_key_hook(e->mlx_win, ft_press_key, e);
	mlx_hook(e->mlx_win, 17, 0, ft_error, e);
	mlx_loop(e->mlx);
	exit(1);
}

void	ft_dead(t_list *e)
{
	int	y_message1;
	int	x_message1;
	int	y_message2;
	int	x_message2;

	y_message1 = e->height_win / 2 - 80;
	x_message1 = e->width_win / 2 - 10 ;
	y_message2 = e->height_win / 2 - 40;
	x_message2 = e->width_win / 2 - 80;
	mlx_clear_window(e->mlx, e->mlx_win);
	mlx_string_put(e->mlx, e->mlx_win, x_message1, y_message1,
		0xFFFFFF, "GAME OVER");
	mlx_string_put(e->mlx, e->mlx_win, x_message2, y_message2,
		0xFFFFFF, "CAT FELL INTO THE BLACK HOLE");
	mlx_key_hook(e->mlx_win, ft_press_key, e);
	mlx_hook(e->mlx_win, 17, 0, ft_error, e);
	mlx_loop(e->mlx);
	exit(1);
}

int	ft_end_game(t_list *e)
{
	if (e->collectable == e-> collected && (e->map[e->i][e->j] == 'E'))
	{
		ft_win(e);
		return (1);
	}
	if (e->map[e->i][e->j] == 'X')
	{	
		ft_dead(e);
		return (1);
	}
	return (0);
}
