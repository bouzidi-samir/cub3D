/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:05 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/03 15:57:15 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// fonction sui fait avancer le rayon jusqu'a qu'il touche un mur

void	ft_ray_progress(t_datastock *datacube)
{
	while (datacube->raycast.hit == 0)
	{
		if (datacube->raycast.sidedistx < datacube->raycast.sidedisty)
		{
			datacube->raycast.sidedistx += datacube->raycast.deltadistx;
			datacube->raycast.mapx += datacube->raycast.stepx;
			datacube->raycast.side = 0;
		}
		else
		{
			datacube->raycast.sidedisty += datacube->raycast.deltadisty;
			datacube->raycast.mapy += datacube->raycast.stepy;
			datacube->raycast.side = 1;
		}
		if (datacube->map[datacube->raycast.mapx][datacube->raycast.mapy] == '1')
			datacube->raycast.hit = 1;
	}
	//ft_ray_progress(datacube);
}

void	ft_get_distance(t_datastock *datacube)
{
	if (datacube->raycast.raydirx < 0)
	{
		datacube->raycast.stepx = -1;
		datacube->raycast.sidedistx = (datacube->raycast.posx - datacube->raycast.mapx) \
							* datacube->raycast.deltadistx;
	}
	else
	{
		datacube->raycast.stepx = 1;
		datacube->raycast.sidedistx = (datacube->raycast.mapx + 1.0 - datacube->raycast.posx) \
							* datacube->raycast.deltadistx;
	}
	if (datacube->raycast.raydiry < 0)
	{
		datacube->raycast.stepy = -1;
		datacube->raycast.sidedisty = (datacube->raycast.posy - datacube->raycast.mapy) \
							* datacube->raycast.deltadisty;
	}
	else
	{
		datacube->raycast.stepy = 1;
		datacube->raycast.sidedisty = (datacube->raycast.mapy + 1.0 - datacube->raycast.posy) \
							* datacube->raycast.deltadisty;
	}
	ft_ray_progress(datacube);
}

// fonction de raycasting qui passe par tous les x

int		ft_raycasting(t_datastock *datacube)
{
	datacube->raycast.x = 0;
	while (datacube->raycast.x < datacube->rx)
	{
		ft_init_raycast2(datacube);
		ft_get_distance(datacube);
		//ft_color_column(recup);		
		datacube->raycast.x++;
	}
	//mlx_put_image_to_window(recup->data.mlx_ptr, recup->data.mlx_win,
			//recup->data.img, 0, 0);
	
	return (0);
}