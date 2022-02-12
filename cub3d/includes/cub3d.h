/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:42:28 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/12 14:11:17 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>

# define WIDTH	700
# define HEIGHT	700
# define BLOC	40
# define BLOCPLAYER	20
# define LEFT 0
# define RIGHT 2
# define TOP 13
# define BOTTOM 1
# define ROTATE_LEFT    123
# define ROTATE_RIGHT   124

typedef struct s_display
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_player;
	void	*img_wall;
	void	*img_empty;
	void	*img;
	void	*img2;
	int		*data_wall;
	int		*data_player;
	int		*data_empty;
	int		*img_data;
	int		*img_data2;
	double	posx;
	double	posy;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		forward;
	int		back;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		minimapechelle;
}	t_display;

typedef struct s_text
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_text;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			x;
	double		ratio;
	double		movespeed;
	double		rotspeed;
}	t_ray;

typedef struct s_datastock
{
	int					bad_xpm;
	int					i;
	int					rx;
	int					ry;
	int					rx_mini;
	int					ry_mini;
	int					rx_bloc;
	int					ry_bloc;
	int					f;
	int					c;
	int					ret;
	int					indicateur2;
	int					error;
	int					width;
	int					height;
	int					bad_filename;
	int					bad_char;
	int					path_size;
	int					inmap;
	int					count;
	int					emptyline;
	int					depx;
	int					depy;
	int					player;
	int					multijoueurs;
	int					err;
	int					wrongwall;
	char				depart;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				**map;
	int					dx;
	int					dy;
	double				center;
	void				*mlx_ptr;
	void				*mlx_win;
	t_display			three_d;
	t_display			mini;
	t_display			text[4];
	t_text				t;
	t_ray				raycast;
}	t_datastock;

int		ft_parsing(char *file, t_datastock *cubstock);
int		check_error(char *file, t_datastock *datacube);
void	check_texture(char *str, t_datastock *datacube);
int		ft_get_path(char *str, char **texture, t_datastock *datacube, int j);
void	ft_check_map(char *str, t_datastock *datacube);
int		ft_check_char(char *str, char c);
void	check_color(char **str, t_datastock *datacube);
int		ft_strlen2(char *str);
int		empty_line(char *str);
int		parsing_map(char *fichier, t_datastock *datacube);
int		get_next_line(int fd, char **line);
void	print_map(char **map);
int		ft_error(t_datastock *datacube, int err);
void	free_data(t_datastock *datacube);
void	free_tab(char **tab, t_datastock *datacube);
void	fill_img(int *img, int color, int width, int height);
void	fill_minimap(t_datastock *datacube);
int		start_game(t_datastock *datacube);
int		init_minimap(t_datastock *datacube);
int		moove_player(int keycode, t_datastock *datacube);
int		texture_parse(t_datastock *datacube);
int		ft_exit(t_datastock *datcube);
int		get_depart_position(char c, t_datastock *datacube, int i, int j);
int		is_wall(char *str);
void	ft_init_datastock(t_datastock *datacube);
void	ft_init_datastock2(t_datastock *datacube);
void	ft_init_raycast(t_datastock *datacube);
void	ft_init_raycast2(t_datastock *datacube);
void	ft_init_raycast3(t_datastock *datacube);
int		ft_raycasting(t_datastock *datacube);
int		ft_col_draw(t_datastock *datacube);
void	front_back(t_datastock *datacube);
void	left_rotate(t_datastock *datacube, double olddirx);
void	ft_left_right(t_datastock *datacube);
void	rotate_right_left(t_datastock *datacube);
void	ft_swap(t_datastock *datacube);
int		key_press(int keycode, t_datastock *datacube);
int		key_release(int keycode, t_datastock *datacube);
int		check_space(char *str);
void	check_around(t_datastock *datacube, int i, int j, int excess);
void	check_len(t_datastock *datacube);
void	check_len1(t_datastock *datacube);
void	check_len2(t_datastock *datacube);
int		check_len3(t_datastock *datacube);
void	ft_draw_texture(t_datastock *datacube, int x, int y);
void	ft_init_texture(t_datastock *datacube);
int		ft_color_column(t_datastock *datacube);
#endif
