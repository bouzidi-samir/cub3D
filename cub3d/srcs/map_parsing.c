/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:44:39 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/10 18:14:52 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_map(char *str, t_datastock *datacube)
{
	static int	i = 0;
	int			j;

	j = 0;
	datacube->map[i] = NULL;
	if (!(datacube->map[i] = malloc(sizeof(char) * datacube->width + 1)))
		return (0);
	while (str[j] != '\0')
	{
		if (get_depart_position(str[j], datacube, i, j) == 1)
			datacube->map[i][j] = '0';
		else
			datacube->map[i][j] = str[j];
		j++;
	}
	datacube->map[i][j] = '\0';
	i++;
	return (0);
}

int		check_character(char *str, t_datastock *datacube)
{
	int i;

	i = 0;
	if (!str)
		return (0);

    if (ft_check_char(str, '1') == 1 || ft_check_char(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' \
					&& str[i] != 'N' && str[i] != 'S' \
					&& str[i] != 'E' && str[i] != 'W' && str[i] != '\n'
					&& str[i] != '\t')
			{
				if (datacube->inmap == 1)
					datacube->bad_char = 2;
                return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

/* Je check si ma map contient les bon char et si elle est bien à la fin du fichier et je recup sa largeur et sa hauteur */

void	ft_check_map(char *str, t_datastock *datacube)
{
	int			i;
	static int	height = 0;
	static int	width = 0;

	i = 0;
    if (check_character(str, datacube) == 1)
	{
		if (datacube->f == -1 || datacube->c == -1 || datacube->no == NULL ||
				datacube->so == NULL || datacube->we == NULL ||
				datacube->ea == NULL)
			datacube->error = 2;
		if ((i = ft_strlen(str)) > width)
			width = i;
		height = height + 1;
	}
	datacube->height = height;
	datacube->width = width;
}

int		parsing_map(char *fichier, t_datastock *datacube)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	fd = open(fichier, O_RDONLY);
    if (!(datacube->map = malloc(sizeof(char*) * datacube->height)))
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (datacube->inmap == 1 && empty_line(str) == 0 &&
				datacube->count < datacube->height)
			datacube->emptyline = 1;
		if ((datacube->inmap = check_character(str, datacube)) == 1)
		{
			datacube->count++;
			get_map(str, datacube);
		}
		free(str);
	}
	close(fd);
	return (0);
}