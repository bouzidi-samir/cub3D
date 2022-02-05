/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:40:56 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/05 17:44:41 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_char(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0' &&
				str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
				&& str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen2(char *str)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

void free_data(t_datastock *datacube)
{
	if (datacube->no != NULL)
		free(datacube->no);
	if (datacube->so != NULL)
		free(datacube->so);
	if (datacube->we != NULL)
		free(datacube->we);
	if (datacube->ea != NULL) 
		free(datacube->ea);
	if (datacube->map != NULL)
		free_tab(datacube->map);
	if (datacube != NULL)
		free(datacube);	
}

void	free_tab(char **tab)
{
	int	i;
	int size; 
	
	i = 0;
	size = 0;
	while (tab[size])
		size++;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
