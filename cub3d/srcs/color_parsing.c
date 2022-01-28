/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:23:09 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/01/26 14:55:30 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_nb_virgule(const char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	return (j);
}

/* Je check si la ligne de couleur respecte la bonne syntaxe */

void	ft_check_data_color(const char *str, t_datastock *datacube)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != ',')
		i++;
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		datacube->error = 3;
	if (ft_nb_virgule(str) != 2)
		datacube->error = 3;
}

int		ft_atoi_color(const char *str, t_datastock *datacube)
{
	int		check;

	check = 0;
	datacube->ret = 0;
    if (str[1] != ' ')
		datacube->error = 3;
	ft_check_data_color(str, datacube);
	while (str[datacube->i] == ' ' || str[datacube->i] == '\t' || str[datacube->i]
			== ',' || str[datacube->i] == '\n' || str[datacube->i] == '\r'
			|| str[datacube->i] == '\v' || str[datacube->i] == '\f')
	{
		datacube->i++;
		check = 0;
		if (str[datacube->i] >= '0' && str[datacube->i] <= '9')
			datacube->indicateur2++;
		while (str[datacube->i] >= '0' && str[datacube->i] <= '9')
		{
			check = (check * 10) + str[datacube->i] - 48;
			datacube->ret = (datacube->ret * 10) + (str[datacube->i] - 48);
			datacube->i++;
		}
		if (check > 255 || check < 0)
			datacube->error = 3;
	}
	return (datacube->ret);
}

/* Parsing des couleurs du sol et et du plafond */

void	check_color(char **str, t_datastock *datacube)
{
	int			i;

	i = 0;
	datacube->i = 1;
	if (datacube->width > 0 && (datacube->no == NULL || datacube->so == NULL ||
				datacube->we == NULL || datacube->ea == NULL))
    	datacube->error = 3;
    //if ((datacube->no != NULL || datacube->so != NULL || datacube->we != NULL ||
	//			datacube->ea != NULL))
	//	datacube->error = 2;
	if (*str[i] == 'F')
		datacube->f = ft_atoi_color(*str, datacube);
	else if (*str[i] == 'C')
		datacube->c = ft_atoi_color(*str, datacube);
}