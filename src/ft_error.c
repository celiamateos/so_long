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
#include "../so_long.h"

void	ft_error(t_list *e, int error)
{
	e->i = 0;
	if (error == 1)
		perror("\x1b[1;31mError\ncan`t read the map\x1b[0m");
	if (error == 2)
		perror("\x1b[1;31mError\nMap isn't rectangular\x1b[0m");
  // no estoy usando el error 2 aun.
	if (error == 3)
		perror("\x1b[1;31mError\nMap isn'trectangular\x1b[0m");
	if (error == 4 && e->collectable < 1)
		perror("\x1b[1;31mError\nNot enough collectables\x1b[0m");
	if (error == 4 && e->player != 1)
		perror("\x1b[1;31mError\nThe map must have only one player\x1b[0m");
  if (error == 4 && e->exit != 1)
		perror("\x1b[1;31mError\nThe map must have only one exit\x1b[0m");
  if (error == 5)
		perror("\x1b[1;31mError\nhay un puto intruso en el mapa\x1b[0m");
  if (error == 6)
    perror("\x1b[1;31mError\nMap isn't surrounded by walls\x1b[0m");
  free(e);
  close(e->fd);
	exit(1);
}
