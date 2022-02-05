/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:55:45 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/05 17:48:10 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_wall(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

/*int		ft_check_wall(t_datastock *datacube)
{
	int i;

	i = 0;
	//ft_putchar_fd(datacube->map[1][5], 1);
    while (i < datacube->height)
	{
		if (datacube->map[i][0] != '1')
        	return (1);
        i++;
	}
	i = 0;
	while (i < datacube->height)
	{
		if (datacube->map[i][datacube->width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}*/

int ft_error(t_datastock *datacube, int err)
{
	if (err == 3)
		ft_putendl_fd("Error: Problem with the xpm file", 2);
	if (datacube->error == 2)
		ft_putendl_fd("Error: Textures informations are wrong", 2);
	if (datacube->error == 3)
		ft_putendl_fd("Error: Colors informations are wrong", 2);
	if (datacube->width == 0 || datacube->height == 0)
		ft_putendl_fd("Error: No map in the file", 2);
	if (datacube->emptyline != 0 && datacube->inmap == 1) 
		ft_putendl_fd("Error: The map has an empty line", 2);
	if (datacube->bad_char != 0)
		ft_putendl_fd("Error: The map has a wrong character", 2);
	if (datacube->player == 0)
		ft_putendl_fd("Error: There isn't any direction", 2);
	if (datacube->multijoueurs != 0)
		ft_putendl_fd("Error: The map has more than one player", 2);
	if (datacube->wrongwall != 0)
		ft_putendl_fd("Error: The wall is not close", 2);
	err = 0;
	datacube->err = 1;
	free_data(datacube);
	return (0);
}

int		ft_exit(t_datastock *datcube)
{
	if (datcube->three_d.img)
		mlx_destroy_image(datcube->mlx_ptr, datcube->three_d.img);
	if (datcube->text[0].img)
		mlx_destroy_image(datcube->mlx_ptr, datcube->text[0].img);
	if (datcube->text[1].img)
		mlx_destroy_image(datcube->mlx_ptr, datcube->text[1].img);
	if (datcube->text[2].img)
		mlx_destroy_image(datcube->mlx_ptr, datcube->text[2].img);
	if (datcube->text[3].img)
		mlx_destroy_image(datcube->mlx_ptr, datcube->text[3].img);
	if (datcube->mlx_win)
		mlx_destroy_window(datcube->mlx_ptr, datcube->mlx_win);
	//free_data(datcube);
	datcube->rx = 0;
	exit(0);
}