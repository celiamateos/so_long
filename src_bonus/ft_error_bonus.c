/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:40:36 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/01 19:43:15 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

int	ft_error(t_list *e, int error)
{
	if (error == 1)
		perror("\x1b[1;31mError\ncan`t read the map\x1b[0m");
	if (error == 2)
		ft_end_game(e);
	if (error == 3)
		perror("\x1b[1;31mError\nMap should be rectangular and close\x1b[0m");
	if (error == 4 && e->collectable < 1)
		perror("\x1b[1;31mError\nNot enough collectables\x1b[0m");
	if (error == 4 && e->player != 1)
		perror("\x1b[1;31mError\nThe map must have only one player\x1b[0m");
	if (error == 4 && e->exit != 1)
		perror("\x1b[1;31mError\nThe map must have only one exit\x1b[0m");
	if (error == 5)
		perror("\x1b[1;31mError\nthe map has invalid characters\x1b[0m");
	if (error == 6)
		perror("\x1b[1;31mError\nMap isn't surrounded by walls\x1b[0m");
	if (error == 7)
		perror("\x1b[1;31mError\nMap must have a valid path\x1b[0m");
	if (error == 8)
		perror("\x1b[1;31mError\nThe image path is invalid\x1b[0m");
	if (e->fd != -1)
		close(e->fd);
	atexit(leaks);
	exit(1);
	return (0);
}

int	ft_error2(t_list *e, int error)
{
	if (error == 1)
		perror("\x1b[1;31mError\nMap is too big\x1b[0m");
	if (e->fd != -1)
		close(e->fd);
	atexit(leaks);
	exit(1);
	return (0);
}
