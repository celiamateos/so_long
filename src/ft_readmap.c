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

int	ft_first_read(t_list *e, int fd)
{
 	while (1)
	{
		e->gnl = get_next_line(fd);
		printf("gnl: %s", e->gnl);
		if (e->gnl != NULL)
			e->longline = ft_strjoin_gnl(e->longline, e->gnl);
		printf("longline:\n%s", e->longline);
		free(e->gnl);
		if (e->gnl == NULL)
			break ;
	}
	return (0);
}

int	ft_readmap(t_list *e, char *map)
{
	int	fd;
    int error;

	e->longline = NULL;
    error = 0;
	fd = open(map, O_RDONLY);
	//printf("\nfd asignado:%i", fd);
	if (fd < 0)
		ft_error(e, 1 , fd);
	ft_first_read(e, fd);
	e->map = ft_split(e->longline, '\n');
	printf("\nelputomapa\n%s", e->map[1]);
	
	/*if (e->line[e->lenline - 1] != '\n' || e->line[e->lenline - 2] != '1')
	{
		ft_error(e, 1, fd);
	}
	else
		write (1, "ok!", 3);*/
	close(fd);
	return (0);
}