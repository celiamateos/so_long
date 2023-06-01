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


void	ft_readmap(t_list *e, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	e->line = get_next_line(fd);
	e->lenline = ft_strlen(line);
	if (e->lenline != '\n' || e->lenline -1 != 1)
	//	ft_error()
	
	close(fd);
}

int ft_init(t_list *e)
{
	int		width = 500;
	int		height = 500;

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
	return(0);
}

int	main(int argc, char **argv)
{
	t_list	*element;
	int		i;

	i = ft_strlen(argv[1]);
	if (argc != 2)
		write(1, "Número de argumentos invalido", 1);
	if (i - 3 != '.' || i - 2 != 'b' || i - 1 != 'e' || i != 'r') 
		write (1, "Formato del mapa no valido", 1);
	element =  (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (0);
	ft_readmap(element, argv[1]);
	ft_init(element);
	free(element);
	return (0);
}
