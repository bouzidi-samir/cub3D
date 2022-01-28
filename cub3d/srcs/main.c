/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:18:08 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/01/28 15:22:09 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_init_struct(t_datastock *datacube)
{
	datacube->i = 0;
    datacube->f = -1;
    datacube->c = -1;
    datacube->ret = 0;
    datacube->indicateur2 = 0;
    datacube->width = 0;
    datacube->height = 0;
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
	datacube->wrongwall = 0;
	datacube->depart = 'o';
	datacube->no = NULL; // malloc
	datacube->so = NULL; // malloc
	datacube->we = NULL; // malloc
	datacube->ea = NULL; // malloc
	datacube->map = NULL; // malloc
}

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

int main(int ac, char **av)
{
    t_datastock *datacube;
    
    datacube = malloc(sizeof(*datacube));
	if (datacube == NULL)
		return (-1);
    ft_init_struct(datacube);
	if (ac == 2)
	{
        if (check_filename(av[1], datacube) == 1)
            return (1);
        ft_parsing(av[1], datacube);        
		if (check_error(av[1], datacube) == 1)
			return (1);
		//ft_putchar_fd(datacube->map[1][1], 1);
		//ft_putnbr_fd(datacube->depy, 1);
		init_mini(datacube);
	}
    else
		ft_putendl_fd("Error: You must give one argument", 2);
	return (0);
}