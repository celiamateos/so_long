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
	// aqui me da un segfault pero weno k le vamos a hacer jeje
	if (error == 2)
		perror("\x1b[1;31mError\nMap isn't rectangular\x1b[0m");
	if (error == 3)
		perror("\x1b[1;31mError\nMap isn't surrounded by walls\x1b[0m");
	exit(1);
}