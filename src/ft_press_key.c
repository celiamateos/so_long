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
# include "../so_long.h"

void   ft_move_down(t_list *e, int s)
{
    if (e->map[e->i + 1][e->j] != '1')
    {
        mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
        e->cat_y = e->cat_y + s;
        mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, e->cat_x, e->cat_y);
        e->i = e->i + 1;
        if (e->map[e->i][e->j] == 'C')
        {
            e->map[e->i][e->j] = '0';
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, e->cat_x, e->cat_y);
            e->collected += 1;
        }
    }
}

void   ft_move_up(t_list *e, int s)
{
    if (e->map[e->i - 1][e->j] != '1')
    {
        mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
        e->cat_y = e->cat_y - s;
        mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, e->cat_x, e->cat_y);
        e->i = e->i - 1;
        if (e->map[e->i][e->j] == 'C')
        {
            e->map[e->i][e->j] = '0';
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, e->cat_x, e->cat_y);
            e->collected += 1;
        }
    }
}

void   ft_move_left(t_list *e, int s)
{
    if (e->map[e->i][e->j - 1] != '1')
    {
        mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
        e->cat_x = e->cat_x - s;
        mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, e->cat_x, e->cat_y);
        e->j = e->j - 1;
        if (e->map[e->i][e->j] == 'C')
        {
            e->map[e->i][e->j] = '0';
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, e->cat_x, e->cat_y);
            e->collected += 1;
        }
    }
}

void   ft_move_right(t_list *e, int s)
{
    if (e->map[e->i][e->j + 1] != '1')
    {
        mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
        e->cat_x = e->cat_x + s;
        mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, e->cat_x, e->cat_y);
        e->j = e->j + 1;
        if (e->map[e->i][e->j] == 'C')
        {
            e->map[e->i][e->j] = '0';
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->playerimg, e->cat_x, e->cat_y);
            e->collected += 1;
        }
    }
}

int ft_press_key(int keycode, t_list *e)
{
    int s = HEIGHT_IMG;
    printf("\ncollectable:%d", e->collectable);
    printf("\ncollected:%d", e->collected);
    printf("\ni:%d", e->i);
    if (keycode == ESC)
        ft_error(e, 2);
   if (keycode == S || keycode == UP)
        ft_move_down(e, s);
    if (keycode == W)
            ft_move_up(e, s);
    if (keycode == A)
        ft_move_left(e, s);
    if (keycode == D)
        ft_move_right(e, s);
    return (0);
}
//