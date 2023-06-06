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

int	ft_error(t_list *e, int error, int fd)
{
	e->i = 0;
	if (error == 1)
		write (1, "Error\nMap is not valid", 22);
	close(fd);
	return(0);
}