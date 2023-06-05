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
/*
char	*ft_first_read(t_list *e, int fd)
{
	static char *longline;
	while (1)
	{
		e->num_line++;
		e->line = get_next_line(fd);
		e->lenline = ft_strlen(e->line);
		printf("lenline:%i", e->lenline);
		free(e->line);
		longline = ft_strjoin(longline, e->line);
		if (e->line == NULL)
		{
			printf("longline:%s", longline);
			return(num_line);
			break ;
		}
	}
}*/

void	ft_readmap(t_list *e, char *map)
{
	int	fd;
    int error;
	int	i;
	//static char	*longline;

	i = 0;
    error = 0;
	fd = open(map, O_RDONLY);
	printf("fd asignado:%i", fd);
	if (fd < 0)
		ft_error(e, 1 , fd);
	ft_first_read(e, fd);
	
	//if (e->num_line * e->lenline < 15)
	//	ft_error(e, 1, fd);
	

	//longline[ft_strlen(longline) + 1] = '\0';
	//printf("\nlongline: %s", longline);
	//printf("%s", e->longline);
    /*printf("\n%i", e->lenline);
	if (e->line[e->lenline - 1] != '\n' || e->line[e->lenline - 2] != '1')
	{
		ft_error(e, 1, fd);
	}
	else
		write (1, "ok!", 3);*/
	close(fd);
}