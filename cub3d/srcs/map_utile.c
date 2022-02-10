/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:31:12 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/10 16:20:46 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	check_len(t_datastock *datacube)
{
	int	i;
	int	j;
	int	excess;

	i = 0;
	while (i < datacube->height - 1)
	{
		j = ft_strlen(datacube->map[i]) - 1;
		if (datacube->map[i + 1] && j > (ft_strlen(datacube->map[i + 1]) - 1))
		{
			excess = j - (ft_strlen(datacube->map[i + 1]) - 1);
			while (excess)
			{
				if (datacube->map[i][j] == '0' || datacube->map[i][j] == 'N'
					|| datacube->map[i][j] == 'S' || datacube->map[i][j] == 'W'
						|| datacube->map[i][j] == 'E')
					datacube->wrongwall = 1;
				j--;
				excess--;
			}
		}
		i++;
	}
}

void	check_len2(t_datastock *datacube)
{
	int	i;
	int	j;
	int k;
    int	excess;

	i = 0;
	excess = 0;
    while (i < datacube->height - 1)
	{
		j = 0;
        k = 0;
        if (i > 0)
        {
            j = ft_strlen(datacube->map[i]) - 1;
		    k = ft_strlen(datacube->map[i - 1]) - 1;
            if (j > k)
		    {
                excess = (j - k) - 1;
                while (excess)
			    {
				    if (datacube->map[i][j -1 ] == '0' || datacube->map[i][j - 1] == 'N'
					    || datacube->map[i][j - 1] == 'S' || datacube->map[i][j - 1] == 'W'
						    || datacube->map[i][j -1] == 'E')
					    datacube->wrongwall = 1;
				    j--;
				    excess--;
			    }
		    }
        }
        i++;
    }
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
	check_len2(datacube);
    check_len3(datacube);
	fill_map(datacube);
    if (datacube->bad_char != 0 || datacube->emptyline != 0 || datacube->multijoueurs != 0 
                        || datacube->player == 0 || datacube->wrongwall != 0)
    {
	    ft_error(datacube, 0);
		return (1);
	}
	return (0);
}