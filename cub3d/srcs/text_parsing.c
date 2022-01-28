/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:13:31 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/01/26 20:56:22 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Gestion d'erreur et parsing du path dans la stucture */

int		ft_get_path(char *str, char **texture, t_datastock *datacube, int j)
{
	datacube->path_size = 0;
	if (*texture != NULL)
	{
		datacube->error = 2;
		return (0);
	}
	if (ft_check_char(str, '.') == 0 || ft_check_char(str, '/') == 0
			|| ft_strlen2(str) <= 2)
		datacube->error = 2;
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.')
			datacube->error = 2;
		j++;
	}
	if (!(*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)))))
		datacube->error = 2;
	while (str[j] != '\0')
	{
		(*texture)[datacube->path_size] = str[j];
		datacube->path_size++;
		j++;
	}
	(*texture)[datacube->path_size] = '\0';
	return (0);
}

/* Detection et parsing des textures */

void check_texture(char *str, t_datastock *datacube)
{
    int			i;
	static int	j = 0;

	i = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		ft_get_path(str, &datacube->so, datacube, 2);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_get_path(str, &datacube->no, datacube, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_get_path(str, &datacube->ea, datacube, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_get_path(str, &datacube->we, datacube, 2);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
			&& str[0] != 'F' && str[0] != 'C'
			&& str[0] > 65 && str[0] < 122)
		datacube->error = 2;
	j++;
}

