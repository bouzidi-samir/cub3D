/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:18:08 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/03 14:29:13 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_filename(char *str, t_datastock *datacube)
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

/* je parcour mon fichier et parse ligne par ligne si une erreur est détecter j'incremente la variable error et sors de ma boucle*/

int	ft_parsing(char *file, t_datastock *datacube)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	if ((fd = open(file, O_DIRECTORY)) != -1)
		ft_putendl_fd("error : the argument is not a file", 1);
	if ((fd = open(file, O_RDONLY)) == -1)
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
//fonction qui dessine une image entière et lit les données à chaque fois.

int init_display(t_datastock *datacube)
{	
	ft_init_raycast(datacube);
	datacube->mlx_ptr = mlx_init();
	if ((texture_parse(datacube)) == 1)
	{
		ft_error(datacube, 3);
		return (1);
	}
	datacube->mlx_win = mlx_new_window(datacube->mlx_ptr, datacube->rx, datacube->ry, "Hello world!");
	ft_putnbr_fd(datacube->raycast.posx, 1);
	datacube->three_d.img = mlx_new_image(datacube->mlx_ptr, datacube->rx, datacube->ry);
	datacube->three_d.img_data = (int *)mlx_get_data_addr(datacube->three_d.img, &datacube->three_d.
			bpp, &datacube->three_d.size_line, &datacube->three_d.endian);
	ft_raycasting(datacube);
	init_minimap(datacube);
	mlx_hook(datacube->mlx_win, 17, 0, ft_exit, datacube);
	mlx_hook(datacube->mlx_win, 2, 1L << 0, moove_player, datacube);
	mlx_hook(datacube->mlx_win, 33, 1L << 17, ft_exit, datacube);
	mlx_loop(datacube->mlx_ptr);
	return (0);
}

int main(int ac, char **av)
{
    t_datastock *datacube;
    
    datacube = malloc(sizeof(*datacube));
	if (datacube == NULL)
		return (-1);
    ft_init_datastock(datacube);
	if (ac == 2)
	{
        if (check_filename(av[1], datacube) == 1)
            return (1);
        ft_parsing(av[1], datacube);        
		if (check_error(av[1], datacube) == 1 || init_display(datacube) == 1)
			return (1);
	}
    else
		ft_putendl_fd("Error: You must give one argument", 2);
	return (0);
}