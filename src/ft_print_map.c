/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:58:33 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/13 15:58:35 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_print_floor(t_list *e)
{
    int x;
    int y;

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

void	ft_print_object(t_list *e)
{
    int i;
    int j;
    int x;
    int y;

    y = 0;
    i = 0;
    j = 0;
	while (y < e->height_win)
	{
		while (x < e->width_win)
		{
            if (e->map[i][j] == '1')
                mlx_put_image_to_window(e->mlx, e->mlx_win, e->wallimg, x, y);
            if (e->map[i][j] == 'P')
                mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, x, y);
            if (e->map[i][j] == 'C')
                mlx_put_image_to_window(e->mlx, e->mlx_win, e->collectimg, x, y);
            if (e->map[i][j] == 'E')
                mlx_put_image_to_window(e->mlx, e->mlx_win, e->exitimg, x, y);
            printf("\nj:%i", j);
            printf("\nx:%d\ny:%d", x, y);
			j++;
            x += e->whimg;
		}
        j = 0;
        x = 0;
		i++;
        y += e->htimg;
        printf("i:%i", i);
	}
}

void    ft_print_map(t_list *e)
{
    ft_print_floor(e);
    ft_print_object(e);
    
}




	    // mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, 0, 0);
	    // mlx_put_image_to_window(e->mlx, e->mlx_win, e->wallimg, 240, 0);
	    // mlx_put_image_to_window(e->mlx, e->mlx_win, e->collectimg, 320, 1);
	    // mlx_put_image_to_window(e->mlx, e->mlx_win, e->exitimg, 320, 20);