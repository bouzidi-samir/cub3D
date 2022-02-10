/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:05 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/10 19:22:12 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Calcul de la distance entre le joueur et le mur 

void	ft_draw_distance(t_datastock *datacube)
{
	if (datacube->raycast.side == 0)
		datacube->raycast.perpwalldist = ((double)datacube->raycast.mapx - \
				datacube->raycast.posx + (1 - (double)datacube->raycast.
				stepx) / 2) / datacube->raycast.raydirx;
	else
		datacube->raycast.perpwalldist = ((double)datacube->raycast.mapy - \
				datacube->raycast.posy + (1 - (double)datacube->raycast.
				stepy) / 2) / datacube->raycast.raydiry;
	datacube->raycast.lineheight = (int)(datacube->ry / datacube->raycast.perpwalldist);
	datacube->raycast.drawstart = -datacube->raycast.lineheight / 2 + datacube->ry / 2;
	if (datacube->raycast.drawstart < 0)
		datacube->raycast.drawstart = 0;
	datacube->raycast.drawend = datacube->raycast.lineheight / 2 + datacube->ry / 2;
	if (datacube->raycast.drawend >= datacube->ry || datacube->raycast.drawend < 0)
		datacube->raycast.drawend = datacube->ry - 1;
}

// fonction qui fait avancer le rayon jusqu'a qu'il touche un mur

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
	ft_draw_distance(datacube);
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
		ft_col_draw(datacube);		
		datacube->raycast.x++;
	}
	mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win,
			datacube->three_d.img, 0, 0);
	//init_minimap(datacube);
	
	front_back(datacube);
	ft_left_right(datacube);
	rotate_right_left(datacube);
	init_minimap(datacube);
	mlx_put_image_to_window(datacube->mlx_ptr,datacube->mlx_win,datacube->mini.img_player, datacube->mini.posx, datacube->mini.posy);
	//mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win,datacube->mini.img_player, datacube->raycast.posx * datacube->rx_bloc, datacube->raycast.posy * datacube->rx_bloc);
	ft_swap(datacube);
	return (0);
}