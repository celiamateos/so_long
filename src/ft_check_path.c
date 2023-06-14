/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:32:20 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/14 18:32:56 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../so_long.h"

int	ft_check_path(t_list *e, int y, int x)
{	
	int valid;

	valid = 0;
	if (valid && (e->m[y + 1][x] == '0' || e->m[y - 1][x] == '0'
		|| e->m[y][x + 1] == '0' || e->m[y + 1][x - 1] == '0'))
		e->m[y][x] = '.';
	if (valid && e->m[y + 1][x] == '0')
		valid = ft_check_path(e, y + 1, x);
	if (valid && e->m[y - 1][x] == '0')
		valid = ft_check_path(e, y - 1, x);
	if (valid && e->m[y][x + 1] == '0')
		valid = ft_check_path(e, y, x + 1);
	if (valid && e->m[y][x - 1] == '0')
		valid = ft_check_path(e, y, x - 1);
	e->m[y][x] = '.';
	return (1);
}

void	ft_check_valid_path(t_list *e)
{
	//int ft_check_path(e, y, x);
	printf("estamos en ello!");
}