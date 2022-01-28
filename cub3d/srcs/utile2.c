/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:55:45 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/01/28 15:20:03 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_wall(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_wall(t_datastock *datacube)
{
	int i;

	i = 0;
	//ft_putchar_fd(datacube->map[0][0], 1);
    while (i < datacube->height)
	{
		if (datacube->map[i][0] != '1' || datacube->map[i][0] == ' ' )
		{
            ft_putendl_fd("here", 1);
        	return (1);
        }
        i++;
	}
	i = 0;
	while (i < datacube->height)
	{
		if (datacube->map[i][datacube->width - 1] != '1')
			return (1);
		i++;
	}
	if (is_wall(datacube->map[0]) == 1)
		return (1);
	if (is_wall(datacube->map[datacube->height - 1]) == 1)
		return (1);
	return (0);
}

int ft_error(t_datastock *datacube)
{
	if (datacube->error == 2)
		ft_putendl_fd("Error: Textures informations are wrong", 2);
	if (datacube->error == 3)
		ft_putendl_fd("Error: Colors informations are wrong", 2);
	if (datacube->width == 0 || datacube->height == 0)
		ft_putendl_fd("Error: No map in the file", 2);
	if (datacube->emptyline != 0)
		ft_putendl_fd("Error: The map has an empty line", 2);
	if (datacube->bad_char != 0)
		ft_putendl_fd("Error: The map has a wrong character", 2);
	if (datacube->player == 0)
		ft_putendl_fd("Error: There isn't any direction", 2);
	if (datacube->multijoueurs != 0)
		ft_putendl_fd("Error: The map has more than one player", 2);
	if (datacube->wrongwall != 0)
		ft_putendl_fd("Error: The wall is not close", 2);
	datacube->err = 1;
	return (0);
}

int check_error(char *file, t_datastock *datacube)
{
    if (datacube->error == 2 || datacube->width == 0 || datacube->height == 0)
	{	
		ft_error(datacube);
		return (1);
	}	
	datacube->inmap = 1;
	parsing_map(file, datacube);
	if (datacube->bad_char != 0 || datacube->emptyline != 0 || datacube->multijoueurs != 0 || datacube->player == 0)
    {
	    ft_error(datacube);
		return (1);
	}
    if (ft_check_wall(datacube) != 0)
    {
        datacube->wrongwall = 1;
        ft_error(datacube);
		return (1);
    }
    return (0);
}

