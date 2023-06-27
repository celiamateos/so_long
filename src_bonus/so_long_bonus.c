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
#include "../so_long_bonus.h"

void	*ft_init(t_list *e)
{
	e->htimg = HEIGHT_IMG;
	e->whimg = WIDTH_IMG;
	e->height_win = e->htimg * e->heightmap;
	e->width_win = e->whimg * e->widthmap;
	e->mlx = mlx_init();
	e->mlx_win = mlx_new_window(e->mlx, e->width_win, e->height_win, "MEOW!:3");
	e->playerup = mlx_xpm_file_to_image(e->mlx, PLAYERUP,
			&e->whimg, &e->htimg);
	e->playerleft = mlx_xpm_file_to_image(e->mlx, PLAYERLEFT,
			&e->whimg, &e->htimg);
	e->playerright = mlx_xpm_file_to_image(e->mlx, PLAYERRIGHT,
			&e->whimg, &e->htimg);
	e->playerdown = mlx_xpm_file_to_image(e->mlx, PLAYERDOWN,
			&e->whimg, &e->htimg);
	e->floorimg = mlx_xpm_file_to_image(e->mlx, FLOOR, &e->whimg, &e->htimg);
	e->wallimg = mlx_xpm_file_to_image(e->mlx, WALL, &e->whimg, &e->htimg);
	e->collectimg = mlx_xpm_file_to_image(e->mlx, COLLECT,
			&e->whimg, &e->htimg);
	e->exitimg = mlx_xpm_file_to_image(e->mlx, EXIT, &e->whimg, &e->htimg);
	if (!e->playerup || !e->playerleft || !e->playerdown || !e->playerright
		|| !e->floorimg || !e->wallimg || !e->collectimg || !e->exitimg
		|| !e->mlx || !e->mlx_win)
		ft_error2(e, 8);
	ft_init_bonus(e);
	return (e->mlx_win);
}

void	ft_init_bonus(t_list *e)
{
	e->blackhole1 = mlx_xpm_file_to_image(e->mlx, BLACKHOLE1,
			&e->whimg, &e->htimg);
	e->blackhole2 = mlx_xpm_file_to_image(e->mlx, BLACKHOLE2,
			&e->whimg, &e->htimg);
	e->blackhole3 = mlx_xpm_file_to_image(e->mlx, BLACKHOLE3,
			&e->whimg, &e->htimg);
	if (!e->blackhole1 || !e->blackhole2 || !e->blackhole3)
		ft_error2(e, 8);
}

void	ft_check_name_ber(t_list *e, char *map)
{
	int		i;

	e->namemap = map;
	i = ft_strlen(e->namemap);
	if (i < 2 || e->namemap[i - 4] != '.' || e->namemap[i - 3] != 'b'
		|| e->namemap[i - 2] != 'e' || e->namemap[i - 1] != 'r')
	{
		perror("\x1b[1;31m Error\n The map name is invalid\x1b[0m");
		atexit(leaks);
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
		perror("\x1b[1;31m Error\n You must enter 2 arguments\x1b[0m");
		return (0);
	}
	e = ft_calloc(1, sizeof(t_list));
	if (!e)
		return (0);
	ft_check_name_ber(e, argv[1]);
	ft_readmap(e, argv[1]);
	ft_init(e);
	ft_print_map(e);
	mlx_key_hook(e->mlx_win, ft_press_key, e);
	mlx_hook(e->mlx_win, 17, 0, ft_error, e);
	mlx_loop_hook(e->mlx, ft_animation, e);
	mlx_loop(e->mlx);
	free(e);
	atexit(leaks);
	exit(1);
	return (0);
}
