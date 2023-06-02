/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:51:46 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/01 19:51:48 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_readmap(t_list *e, char *map)
{
	int	fd;
    int error;

    error = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error(e, 1 , fd);
	e->line = get_next_line(fd);
	e->lenline = ft_strlen(e->line);
    //printf("\n%i", e->lenline);
	if (e->line[e->lenline - 1] != '\n' || e->line[e->lenline - 2] != '1')
	{
		ft_error(e, 1, fd);
	}
	else
		write (1, "ok!", 3);
		close(fd);
}
