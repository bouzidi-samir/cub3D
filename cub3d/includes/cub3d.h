/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:42:28 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/01/28 15:26:54 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>

# define WIDTH	800
# define HEIGHT	600
# define BLOC	40
# define BLOCPLAYER	20
# define GAUCHE 0
# define DROITE 2
# define HAUT 13
# define BAS 1

typedef struct s_window
{
    void    *mlx_ptr;
    void	*mlx_win;
    void	*img_mini;
    int    *img_mini_data;
} t_window;

typedef struct	s_ray
{
	double		posx; //position x du joueur
	double		posy; //position y du joueur
	double		dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		mapx; // coordonée x du carré dans lequel est pos
	int		mapy; // coordonnée y du carré dans lequel est pos
	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	int		x; //permet de parcourir tous les rayons
} t_ray;

typedef struct s_datastock
{
    int i;
    int rx;
    int ry;
    int f;
    int c;
    int ret;
    int indicateur2;
    int error;
    int width;
    int height;
    int bad_filename;
    int bad_char;
    int path_size;
    int inmap;
    int count;
    int emptyline;
    int depx;
    int depy;
    int player;
    int multijoueurs;
    int err;
    int wrongwall;
    char    depart;
    char			*no;
	char			*so;
	char			*we;
	char			*ea;
    char **map;
    t_window display;
} t_datastock;

int	ft_parsing(char *file, t_datastock *cubstock);
int check_error(char *file, t_datastock *datacube);
void check_texture(char *str, t_datastock *datacube);
int		ft_get_path(char *str, char **texture, t_datastock *datacube, int j);
void	ft_check_map(char *str, t_datastock *datacube);
int		ft_check_char(char *str, char c);
void	check_color(char **str, t_datastock *datacube);
int		ft_strlen2(char *str);
int		empty_line(char *str);
int		parsing_map(char *fichier, t_datastock *datacube);
int	get_next_line(int fd, char **line);
void print_map(char **map);
int ft_error(t_datastock *datacube);
void free_data(t_datastock *datacube);
void	free_tab(char **tab);
void fill_img(int *img, int color, int width, int height);
void fill_minimap(t_datastock *datacube);
void init_mini(t_datastock *datacube);

#endif