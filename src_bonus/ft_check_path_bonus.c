/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:32:20 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/16 14:48:14 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_player_position(t_list *e)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (e->map[y] != NULL)
	{
		while (e->map[y][x] != '\0')
		{
			if (e->map[y][x] == 'P')
			{
				ft_check_path(e, y, x);
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_check_path(t_list *e, int y, int x)
{	
	if (e->count_collect == e->collectable && e->count_exit == 1)
		return (1);
	if (e->m[y][x] == 'C')
	{
		e->count_collect++;
		e->m[y][x] = '0';
	}
	if (e->m[y][x] == 'E')
	{
		e->count_exit = 1;
		e->m[y][x] = '0';
	}
	if (e->m[y + 1][x] != '1' || e->m[y - 1][x] != '1'
		|| e->m[y][x + 1] != '1' || e->m[y][x - 1] != '1')
		e->m[y][x] = '1';
	if (e->m[y + 1][x] != '1')
		ft_check_path(e, y + 1, x);
	if (e->m[y - 1][x] != '1')
		ft_check_path(e, y - 1, x);
	if (e->m[y][x + 1] != '1')
		ft_check_path(e, y, x + 1);
	if (e->m[y][x - 1] != '1')
		ft_check_path(e, y, x - 1);
	e->m[y][x] = '1';
	return (0);
}

void	ft_check_valid_path(t_list *e)
{
	ft_player_position(e);
	if (e->count_collect != e->collectable || e->count_exit != 1)
		ft_error(e, 7);
}
