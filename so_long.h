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
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef GAME_OBJECT
# define PLAYER "./images/player.xpm"
# define COLLECTABLE "./images/collectable.xpm"
# define EXIT "./images/exit.xpm"
# define WALL "./images/asteroid.xpm"
# define FLOOR "./images/floor.xpm"
# define WIDTH_IMG 80
# define HEIGHT_IMG 80
# endif 

typedef struct s_list
{	
	void	*mlx;
	void	*mlx_win;
	void	*playerimg;
	void	*collectimg;
	void	*exitimg;
	void 	*floorimg;
	void	*wallimg;
  	int   	fd;
	char	*namemap;
	char	*gnl;
	char	*longline;
	char	**map;
	int		error;
	int		row;
	int		wall;
	int		collectable;
	int		player;
	int		exit;
	int		floor;
	int		objects;
	int		heightmap;
	int		widthmap;
	int		height_win;
	int		width_win;
	int		htimg;
	int		whimg;
}	t_list;

// Fuctions libft 
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
// Fuctions GNL
char	*get_next_line(t_list *e);
size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);

int		main(int argc, char **argv);
void	ft_check_name_ber(t_list *e, char *map);
void	*ft_init(t_list *element);
void	ft_error(t_list *e, int error);
int		ft_readmap(t_list *e, char *map);
int		ft_first_read(t_list *e);
void	ft_check_map_objects(t_list *e);
void	ft_check_map_rectangular(t_list *e);
void	ft_check_map_closed(t_list *e);
void    ft_print_map(t_list *e);
void	ft_print_floor(t_list *e);
void	ft_print_object(t_list *e);

#endif
