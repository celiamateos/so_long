/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:30:34 by cmateos           #+#    #+#             */
/*   Updated: 2023/05/31 15:55:09 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_init(t_list *e)
{
	int		width = 80;
	int		height = 80;

	e->mlx =  mlx_init();
	e->mlx_win = mlx_new_window(e->mlx, width, height, "MEOW!:3");
	e->player = mlx_xpm_file_to_image(e->mlx, "./images/player.xpm", &width, &height);
	e->floor = mlx_xpm_file_to_image(e->mlx, "./images/floor.xpm", &width, &height);
	e->wall = mlx_xpm_file_to_image(e->mlx, "./images/asteroid.xpm", &width, &height);
	e->collectable = mlx_xpm_file_to_image(e->mlx, "./images/collectable.xpm", &width, &height);
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->floor, 80, 0);
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->player, 160, 0);
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->wall, 240, 0);
	mlx_put_image_to_window(e->mlx, e->mlx_win, e->collectable, 320, 1);
	mlx_loop(e->mlx);
}

int	main(int argc, char **argv)
{
	t_list	*e;

	int		i;

	if (argc != 2)
	{
		write(1,"\x1b[1;31m Wrong! You must enter 2 arguments", 42);
		return (0);
	}
	e = (t_list *)malloc(sizeof(t_list));
	if (!e)
		return (0);
	e->namemap = argv[1];
	i = ft_strlen(e->namemap);
	if (i < 2 || e->namemap[i - 4] != '.' || e->namemap[i - 3] != 'b'
		|| e->namemap[i - 2] != 'e' || e->namemap[i - 1] != 'r')
	{
		write (1, "\x1b[1;31m Wrong! The map name is invalid", 38);
		free(e);
		return (0);
	}
	ft_readmap(e, argv[1]);
	//ft_init(e);
	free(e);
	return (0);
}
