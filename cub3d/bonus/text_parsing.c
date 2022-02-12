/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:13:31 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/11 18:39:47 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Gestion d'erreur et parsing du path dans la stucture */

int	ft_get_path(char *str, char **texture, t_datastock *datacube, int j)
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
	*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)));
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

void	check_texture(char *str, t_datastock *datacube)
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
	else if (str[i] == 'S' && str[i + 1] != '0')
		datacube->error = 2;
	j++;
}

void	ft_get_texture_adress(t_datastock *datacube)
{
	datacube->text[0].img_data = (int *)mlx_get_data_addr(datacube->text[0].img,
			&datacube->text[0].bpp,
			&datacube->text[0].size_line, &datacube->text[0].endian);
	datacube->text[1].img_data = (int *)mlx_get_data_addr(datacube->text[1].img,
			&datacube->text[1].bpp,
			&datacube->text[1].size_line, &datacube->text[1].endian);
	datacube->text[2].img_data = (int *)mlx_get_data_addr(datacube->text[2].img,
			&datacube->text[2].bpp,
			&datacube->text[2].size_line, &datacube->text[2].endian);
	datacube->text[3].img_data = (int *)mlx_get_data_addr(datacube->text[3].img,
			&datacube->text[3].bpp,
			&datacube->text[3].size_line, &datacube->text[3].endian);
}

int	texture_parse(t_datastock *datacube)
{
	datacube->text[0].img = mlx_xpm_file_to_image(datacube->mlx_ptr,
			datacube->no, &(datacube->text[0].width),
			&(datacube->text[0].height));
	if (!datacube->text[0].img)
		return (1);
	datacube->text[1].img = mlx_xpm_file_to_image(datacube->mlx_ptr,
			datacube->so, &(datacube->text[1].width),
			&(datacube->text[1].height));
	if (!datacube->text[1].img)
		return (1);
	datacube->text[2].img = mlx_xpm_file_to_image(datacube->mlx_ptr,
			datacube->we, &(datacube->text[2].width),
			&(datacube->text[2].height));
	if (!datacube->text[2].img)
		return (1);
	datacube->text[3].img = mlx_xpm_file_to_image(datacube->mlx_ptr,
			datacube->ea, &(datacube->text[3].width),
			&(datacube->text[3].height));
	if (!datacube->text[3].img)
		return (1);
	ft_get_texture_adress(datacube);
	return (0);
}
