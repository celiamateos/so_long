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
#include "../so_long.h"

int	ft_win(t_list *e)
{
	int	y_message1;
	int	x_message1;
	int	y_message2;
	int	x_message2;

	if (e->collectable == e-> collected && (e->map[e->i][e->j] == 'E'))
	{
		y_message1 = e->height_win / 2 - 80;
		x_message1 = e->width_win / 2 - 60 ;
		y_message2 = e->height_win / 2 - 40;
		x_message2 = e->width_win / 2 - 80;
		mlx_clear_window(e->mlx, e->mlx_win);
		mlx_string_put(e->mlx, e->mlx_win, x_message1, y_message1,
			0xFFFFFF, "CONGRATULATIONS!");
		mlx_string_put(e->mlx, e->mlx_win, x_message2, y_message2,
			0xFFFFFF, "THE CAT SPACE SCAPED!");
		mlx_key_hook(e->mlx_win, ft_press_key, e);
		mlx_hook(e->mlx_win, 17, 0, ft_error, e);
		mlx_loop(e->mlx);
		exit(1);
		return (1);
	}
	return (0);
}
