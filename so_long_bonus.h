/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:54:09 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/27 17:01:56 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <stdarg.h>

# define BUFFER_SIZE 1

# define PLAYERUP "./textures/playerup.xpm"
# define PLAYERDOWN "./textures/playerleft.xpm"
# define PLAYERLEFT "./textures/playerleft.xpm"
# define PLAYERRIGHT "./textures/playerright.xpm"
# define COLLECT "./textures/collectable.xpm"
# define EXIT "./textures/exit.xpm"
# define WALL "./textures/newasteroid.xpm"
# define FLOOR "./textures/floor.xpm"
# define BLACKHOLE1 "./textures/blackhole1.xpm"
# define BLACKHOLE2 "./textures/blackhole2.xpm"
# define BLACKHOLE3 "./textures/blackhole3.xpm"
# define WIDTH_IMG 80
# define HEIGHT_IMG 80

# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define ESC 53

typedef struct s_position
{
	int	x;
	int	y;

}	t_position;

typedef struct s_list
{	
	void		*mlx;
	void		*mlx_win;
	void		*playerup;
	void		*playerright;
	void		*playerdown;
	void		*playerleft;
	void		*collectimg;
	void		*exitimg;
	void		*floorimg;
	void		*wallimg;
	void		*blackhole1;
	void		*blackhole2;
	void		*blackhole3;
	int			fd;
	char		*namemap;
	char		*gnl;
	char		*longline;
	char		**map;
	char		**m;
	int			error;
	int			row;
	int			wall;
	int			collectable;
	int			player;
	int			exit;
	int			floor;
	int			blackhole;
	int			objects;
	int			heightmap;
	int			widthmap;
	int			height_win;
	int			width_win;
	int			htimg;
	int			whimg;
	int			cat_y;
	int			cat_x;
	int			i;
	int			j;
	int			collected;
	int			steps;
	int			count_collect;
	int			count_exit;
	int			blackhole_x;
	int			blackhole_y;
	char		*steps_bns;
	int			loops;
	t_position	position;
}	t_list;

// Fuctions libft 
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_itoa(int n);

// Fuctions GNL
char	*get_next_line(t_list *e);
size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);

// Fuctions FT_PRINTF
int		ft_printf(char const *s, ...);
int		ft_putchr_pf(char c);
int		ft_puthex(unsigned int nbr, char *hex, int *count);
int		ft_putptr_pf(unsigned long nbr, char *hex, int count);
int		ft_putun(unsigned int nbr, int *count);
int		ft_putnbr_pf(long nbr, int *count);
int		ft_putstr_pf(char *s);

// Fuctions SO_LONG

int		main(int argc, char **argv);
int		ft_error(t_list *e, int error);
int		ft_error2(t_list *e, int error);
int		ft_readmap(t_list *e, char *map);
void	ft_print_map(t_list *e);
int		ft_press_key(int keycode, t_list *e);
int		ft_open_exit(t_list *e);
void	ft_check_valid_path(t_list *e);
int		ft_check_path(t_list *e, int y, int x);
int		ft_end_game(t_list *e);
void	ft_render_floor(t_list *e);
void	ft_render_player_down_or_left(t_list *e);
void	ft_render_player_up(t_list *e);
void	ft_render_player_right(t_list *e);
void	ft_render_exit(t_list *e);
void	ft_init_bonus(t_list *e);
int		ft_animation(t_list *e);
void	ft_printsteps(t_list *e);

#endif
