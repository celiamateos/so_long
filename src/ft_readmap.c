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
		if (e->gnl != NULL)
			e->longline = ft_strjoin_gnl(e->longline, e->gnl);
		free(e->gnl);
		if (e->gnl == NULL)
			break ;
	}
	return (0);
}

void	ft_check_map(t_list *e)
{
	int	row;
	int	i;
	int j;

	i = 0;
	j = 0;
	row = 0;
	while (e->map[i] != NULL)
	{
		row++;
		i++;
	}
	printf("i:%i", i);
	printf("\nrows:%i", row);
	i = 0;
	while (e->map[i] != NULL && i < row - 1)
	{
		e->lenline = ft_strlen(e->map[i]) - 1;
		printf("\nlenline:%i", e->lenline);
		printf("\nline:%i", i);
		i++;
		e->lenline2 = ft_strlen(e->map[i]) - 1;
		printf("\nlenline2:%i", e->lenline2);
		printf("\nline:%i", i);
		//printf("\ni:%i", i);
		if (e->lenline != e->lenline2)
		{
			ft_error(e, 3);
			break ;
		}
	}
}

int	ft_readmap(t_list *e, char *map)
{
	int	fd;

	e->longline = NULL;
	fd = open(map, O_RDONLY);
	//printf("\nfd asignado:%i", fd);
	if (fd == -1)
		ft_error(e, 1);
	ft_first_read(e, fd);
	e->map = ft_split(e->longline, '\n');
	//printf("\nelputomapa:\n%s", e->map[1]);
	ft_check_map(e);

	close(fd);
	return (0);
}

//e->map[0][ft_strlen(e->map[0])] != '\n' 
//printf("\nlen:%s", e->map[i]);