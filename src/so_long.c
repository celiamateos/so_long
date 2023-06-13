/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:30:34 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/08 17:57:53 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void *ft_init(t_list *e)
{
	e->htimg = HEIGHT_IMG;
	e->whimg = WIDTH_IMG;
	e->height_win = e->htimg * e->heightmap;
	e->width_win = e->whimg * e->widthmap;
	printf("\nheight window:%d", e->height_win);
	printf("\nwidth window:%d", e->width_win);
	
	e->mlx =  mlx_init();
	e->mlx_win = mlx_new_window(e->mlx, e->width_win, e->height_win, "MEOW!:3");
	e->playerimg = mlx_xpm_file_to_image(e->mlx, PLAYER, &e->whimg, &e->htimg);
	e->floorimg = mlx_xpm_file_to_image(e->mlx, FLOOR, &e->whimg, &e->htimg);
	e->wallimg = mlx_xpm_file_to_image(e->mlx, WALL, &e->whimg, &e->htimg);
	e->collectimg = mlx_xpm_file_to_image(e->mlx, COLLECTABLE, &e->whimg, &e->htimg);
	e->exitimg = mlx_xpm_file_to_image(e->mlx, EXIT, &e->whimg, &e->htimg);
	//mlx_put_image_to_window(e->mlx, e->mlx_win, e->floorimg, 0, 0);

	return (e->mlx_win);
}

void	ft_check_name_ber(t_list *e, char *map)
{
	int		i;

	e->namemap = map;
	i = ft_strlen(e->namemap);
	if (i < 2 || e->namemap[i - 4] != '.' || e->namemap[i - 3] != 'b'
		|| e->namemap[i - 2] != 'e' || e->namemap[i - 1] != 'r')
	{
		perror("\x1b[1;31m Wrong! The map name is invalid\x1b[0m");
		free(e);
		exit(1);
	}
}

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_list	*e;

	if (argc != 2)
	{
		perror("\x1b[1;31m Wrong! You must enter 2 arguments\x1b[0m");
		return (0);
	}
	e = ft_calloc(1, sizeof(t_list));
	if (!e)
		return (0);
	ft_check_name_ber(e, argv[1]);
	ft_readmap(e, argv[1]);
	printf("\nheigtmap:%d", e->heightmap);
	printf("\nwidthmap:%d", e->widthmap);
	ft_init(e);
	ft_print_map(e);
	ft_press_key(e);
	mlx_loop(e->mlx);
	free(e);
	atexit(leaks);
	exit(1);
	return (0);
}
