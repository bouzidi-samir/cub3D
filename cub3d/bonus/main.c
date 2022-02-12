/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:18:08 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/11 18:39:28 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_datastock(t_datastock *datacube)
{
	datacube->bad_xpm = 0;
	datacube->i = 0;
	datacube->f = -1;
	datacube->c = -1;
	datacube->ret = 0;
	datacube->indicateur2 = 0;
	datacube->width = 0;
	datacube->height = 0;
	datacube->rx = 0;
	datacube->ry = 0;
	datacube->rx_mini = 0;
	datacube->ry_mini = 0;
	datacube->bad_filename = 0;
	datacube->path_size = 0;
	datacube->error = 0;
	datacube->inmap = 0;
	datacube->count = 0;
	datacube->emptyline = 0;
	datacube->depx = 0;
	datacube->depy = 0;
	datacube->player = 0;
	datacube->multijoueurs = 0;
	datacube->err = 0;
	datacube->bad_char = 0;
	ft_init_datastock2(datacube);
}

int	check_filename(char *str, t_datastock *datacube)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_putendl_fd("Nom de la map invalide", 2);
			free_data(datacube);
			return (1);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		return (0);
	else
	{
		ft_putendl_fd("Nom de la map invalide", 2);
		free_data(datacube);
		return (1);
	}
}

// je parcour mon fichier et parse ligne par ligne si une erreur est détecter 
// j'incremente la variable error et sors de ma boucle*/

int	ft_parsing(char *file, t_datastock *datacube)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		ft_putendl_fd("error : the argument is not a file", 1);
	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putendl_fd("error invalide file", 2);
	datacube->error = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		check_color(&str, datacube);
		check_texture(str, datacube);
		ft_check_map(str, datacube);
		free(str);
	}
	close(fd);
	return (0);
}
//fonction qui dessine une image en	tière et lit les données à chaque fois.

int	start_game(t_datastock *datacube)
{	
	ft_init_raycast(datacube);
	datacube->mlx_ptr = mlx_init();
	if ((texture_parse(datacube)) == 1)
		return (1);
	datacube->three_d.img
		= mlx_new_image(datacube->mlx_ptr, datacube->rx, datacube->ry);
	datacube->three_d.img_data = (int *)mlx_get_data_addr
		(datacube->three_d.img, &datacube->three_d.bpp,
			&datacube->three_d.size_line, &datacube->three_d.endian);
	datacube->three_d.img2
		= mlx_new_image(datacube->mlx_ptr, datacube->rx, datacube->ry);
	datacube->three_d.img_data2 = (int *)mlx_get_data_addr
		(datacube->three_d.img2, &datacube->three_d.bpp,
			&datacube->three_d.size_line, &datacube->three_d.endian);
	datacube->mlx_win = mlx_new_window(datacube->mlx_ptr, datacube->rx,
			datacube->ry, "Hello world!");
	ft_raycasting(datacube);
	mlx_hook(datacube->mlx_win, 17, 0, ft_exit, datacube);
	mlx_hook(datacube->mlx_win, 2, 1L << 0, key_press, datacube);
	mlx_loop_hook(datacube->mlx_ptr, ft_raycasting, datacube);
	mlx_hook(datacube->mlx_win, 3, 1L << 1, key_release, datacube);
	mlx_loop(datacube->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_datastock	*datacube;

	datacube = malloc(sizeof(*datacube));
	if (datacube == NULL)
		return (-1);
	ft_init_datastock(datacube);
	if (ac == 2)
	{
		if (check_filename(av[1], datacube) == 1)
			return (1);
		ft_parsing(av[1], datacube);
		if (check_error(av[1], datacube) == 1)
			return (1);
		if (start_game(datacube) == 1)
		{
			ft_error(datacube, 3);
			return (1);
		}
	}
	else
		ft_putendl_fd("Error: You must give one argument", 2);
	return (0);
}
