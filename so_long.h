/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:54:09 by cmateos           #+#    #+#             */
/*   Updated: 2023/05/31 15:55:05 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
typedef struct	s_list
{	
	void	*mlx;
	void	*mlx_win;
	void	*floor;
	void	*player;
	void	*wall;
	void	*collectable;
	void	**map;
	void	*line;
	int		lenline;
	int		lenarray;
	int		i;
	int		j;
}	t_list;

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin_gnl(char *aux, char *buffer);
char	*get_next_line(int fd);
int		main(int argc, char **argv);
int		ft_init(t_list *element);
#endif
