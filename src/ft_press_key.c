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

void   ft_move_down(t_list *e)
{
    if (e->map[e->i + 1][e->j] != '1')
    {
        e->steps++;
        printf("Steps:%d\n", e->steps);
        if (e->map[e->i][e->j] != 'E')
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
        if (e->map[e->i][e->j] == 'E' && !ft_open_exit(e))
        {
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->exitimg, e->cat_x, e->cat_y);
        }
        e->cat_y += HEIGHT_IMG;
        if (e->map[e->i][e->j + 1] == 'E' && ft_open_exit(e))
            ft_error(e, 2);
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

void   ft_move_up(t_list *e)
{
    if (e->map[e->i - 1][e->j] != '1')
    {
        e->steps++;
        printf("Steps:%d\n", e->steps);
        if (e->map[e->i][e->j] != 'E')
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
        if (e->map[e->i][e->j] == 'E' && !ft_open_exit(e))
        {
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->exitimg, e->cat_x, e->cat_y);
        }
        e->cat_y -= HEIGHT_IMG;
        if (e->map[e->i - 1][e->j] == 'E' && ft_open_exit(e))
            ft_error(e, 2);
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

void   ft_move_left(t_list *e)
{
    if (e->map[e->i][e->j - 1] != '1')
    {
        e->steps++;
        printf("Steps:%d\n", e->steps);
        if (e->map[e->i][e->j] != 'E')
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
        if (e->map[e->i][e->j] == 'E' && !ft_open_exit(e))
        {
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->exitimg, e->cat_x, e->cat_y);
        }
        e->cat_x -=WIDTH_IMG;
        if (e->map[e->i][e->j - 1] == 'E' && ft_open_exit(e))
            ft_error(e, 2);
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

void   ft_move_right(t_list *e)
{
    if (e->map[e->i][e->j + 1] != '1')
    {
        e->steps++;
        printf("Steps:%d\n", e->steps);
        if (e->map[e->i][e->j] != 'E')
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
        if (e->map[e->i][e->j] == 'E' && !ft_open_exit(e))
        {
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, e->cat_x, e->cat_y);
            mlx_put_image_to_window(e->mlx, e->mlx_win, e->exitimg, e->cat_x, e->cat_y);
        }
        e->cat_x +=WIDTH_IMG;
        if (e->map[e->i][e->j + 1] == 'E' && ft_open_exit(e))
            ft_error(e, 2);
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
    if (keycode == ESC)
        ft_error(e, 2);
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
