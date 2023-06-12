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

int	ft_first_read(t_list *e)
{
	while (1)
	{
		e->gnl = get_next_line(e);
		if (e->gnl != NULL)
			e->longline = ft_strjoin_gnl(e->longline, e->gnl);
		free(e->gnl);
		if (e->gnl == NULL)
			break ;
	}
	return (0);
}

void	ft_check_map_objects(t_list *e)
{
	int	i;

	i = 0;
	while (e->longline[i] != '\0')
	{	
		e->objects++;
		if (e->longline[i] == '1')
			e->wall++;
		if (e->longline[i] == 'C')
			e->collectable++;
		if (e->longline[i] == 'P')
			e->player++;
		if (e->longline[i] == 'E')
			e->exit++;
		if (e->longline[i] == '0')
			e->floor++;
		if (e->longline[i] == '\n')
			e->objects--;
		i++;
	}
	if (e->player != 1 || e->collectable < 1 || e->exit != 1)
		ft_error(e, 4);
	if (e->player + e->collectable + e->exit + e->wall + e->floor != e->objects)
		ft_error(e, 5);
}

void	ft_check_map_rectangular(t_list *e)
{
	int	i;

	i = 0;
	while (e->map[i++] != NULL)
		e->row++;
	i = 0;
	while (e->map[i] != NULL && i < e->row - 1)
	{
		e->lenline = ft_strlen(e->map[i]) - 1;
		i++;
		e->lenline2 = ft_strlen(e->map[i]) - 1;
		if (e->lenline != e->lenline2)
			ft_error(e, 6);
	}
}

void	ft_check_map_closed(t_list *e)
{
	e->c = '1';
	e->p = 'P';
	e->i = 0;
	
	e->lenstr = ft_strlen(e->map[1]);
	while (e->map[e->i] != NULL)
	{
		while (e->map[e->i][e->j] != '\0')
		{
			if (e->map[0][e->j] != e->c || e->map[e->row - 1][e->j] != e->c)
				ft_error(e, 3);
			e->j++;
		}
		if (e->map[e->i][0] != e->c || e->map[e->i][e->lenstr - 1] != e->c)
			ft_error(e, 3);
		e->i++;
	}
}

int	ft_readmap(t_list *e, char *map)
{
	e->fd = open(map, O_RDONLY);
	if (e->fd == -1)
		ft_error(e, 1);
	ft_first_read(e);
	ft_check_map_objects(e);
	e->map = ft_split(e->longline, '\n');
	ft_check_map_rectangular(e);
	ft_check_map_closed(e);
	//ft_check_path(e);
	close(e->fd);
	return (0);
}
