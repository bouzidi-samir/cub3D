/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:31:12 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/11 11:52:13 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_space(char *str)
{
	int i;
	int space;

	i = 0;
	space = 0;
	while (str[i] != '\0' && str[i] == ' ')
	{
		i++;
	}
	return (i);
}

void fill_map(t_datastock *datacube)
{
    int	i;
	int	j;
	
	i = 0;
    while (i < datacube->height)
	{
		j = 0;
		while (datacube->map[i][j] != '\0')
		{
            if (datacube->map[i][j] == ' ')
			    datacube->map[i][j] = '1';
            j++;
        }
        while (j <= (datacube->width - 1))
	    {
		datacube->map[i][j] = '1';
		j++;
	    }   
        datacube->map[i][j] = '\0';
        i++;
	}
}

int		get_depart_position(char c, t_datastock *datacube, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		datacube->player = 1;
        if (datacube->depart != 'o')
            datacube->multijoueurs = 1;
        datacube->depart = c;
		datacube->depx = i;
		datacube->depy = j;
		return (1);
	}
	return (0);
}

void	check_wall(t_datastock *datacube)
{
	int	i;
	int	j;

	i = 0;
    while (i < datacube->height)
	{
		j = 0;
		while (datacube->map[i][j] == ' ')
			j++;
		if (datacube->map[i][j] != '1'
			|| datacube->map[i][ft_strlen(datacube->map[i]) - 1] != '1')
			datacube->wrongwall = 1;
		if (i == 0 || i == datacube->height - 1)
		{
			if (is_wall(datacube->map[i]) == 1)
                datacube->wrongwall = 1;
		}
		i++;
	}
}

int check_error(char *file, t_datastock *datacube)
{
   if (datacube->error == 2)
	{	
		ft_error(datacube, 0);
		return (1);
	}	
	//datacube->inmap = 1;
	parsing_map(file, datacube);
	datacube->inmap = 1;
    if (datacube->width == 0 || datacube->height == 0)
	{	
		ft_error(datacube, 0);
		return (1);
	}
    check_wall(datacube);
	check_len(datacube);	
	fill_map(datacube);
    if (datacube->bad_char != 0 || datacube->emptyline != 0 || datacube->multijoueurs != 0 
                        || datacube->player == 0 || datacube->wrongwall != 0)
    {
	    ft_error(datacube, 0);
		return (1);
	}
	return (0);
}