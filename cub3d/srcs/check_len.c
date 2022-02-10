/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:12:12 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/10 18:21:16 by samirbouzid      ###   ########.fr       */
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

int	check_len3(t_datastock *datacube)
{
	int	i;
	int	j;
	int	excess;

	i = 0;
	while (i < datacube->height - 1)
	{
		if (check_space(datacube->map[i + 1]) > check_space(datacube->map[i]))
		{
			excess = check_space(datacube->map[i + 1]);
			j = 0;
			while (j < excess)
			{
				if (datacube->map[i][j] != '1')
					datacube->wrongwall = 1;
				j++;
			}
		}
		i++;
	}
	return (0);
}

void	check_len1(t_datastock *datacube)
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