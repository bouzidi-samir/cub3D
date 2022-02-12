/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:04:04 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/12 10:38:07 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_back(t_datastock *datacube)
{
	if (datacube->three_d.back == 1)
	{
		if (datacube->map[(int)(datacube->raycast.posx - (datacube->raycast.dirx * datacube->
						raycast.movespeed * 2))][(int)(datacube->raycast.posy)] == '0')
			datacube->raycast.posx -= datacube->raycast.dirx * datacube->raycast.movespeed;
		if (datacube->map[(int)(datacube->raycast.posx)][(int)(datacube->raycast.posy -
					(datacube->raycast.diry * datacube->raycast.movespeed * 2))] == '0')
			datacube->raycast.posy -= datacube->raycast.diry * datacube->raycast.movespeed;
	}
}


void	front_back(t_datastock *datacube)
{
	if (datacube->three_d.forward == 1)
	{
		if (datacube->map[(int)(datacube->raycast.posx + (datacube->raycast.dirx * datacube->
						raycast.movespeed * 2))][(int)datacube->raycast.posy] == '0')
			datacube->raycast.posx += datacube->raycast.dirx * datacube->raycast.movespeed;
		if (datacube->map[(int)(datacube->raycast.posx)][(int)(datacube->raycast.posy +
					(datacube->raycast.diry * datacube->raycast.movespeed * 2))] == '0')
			datacube->raycast.posy += datacube->raycast.diry * datacube->raycast.movespeed;
	}
	ft_back(datacube);
}

void ft_right(t_datastock *datacube)
{
	if (datacube->three_d.left == 1)
	{
		if (datacube->map[(int)(datacube->raycast.posx - datacube->raycast.diry *
					(datacube->raycast.movespeed * 2))][(int)datacube->raycast.posy] == '0')
			datacube->raycast.posx -= datacube->raycast.diry * datacube->raycast.movespeed;
		if (datacube->map[(int)datacube->raycast.posx][(int)(datacube->raycast.posy +
					datacube->raycast.dirx *
					(datacube->raycast.movespeed * 2))] == '0')
			datacube->raycast.posy += datacube->raycast.dirx * datacube->raycast.movespeed;
	}
}

void	ft_left_right(t_datastock *datacube)
{
	if (datacube->three_d.right == 1)
	{
		if (datacube->map[(int)(datacube->raycast.posx + datacube->raycast.diry *
					(datacube->raycast.movespeed * 2))][(int)datacube->raycast.posy] == '0')
			datacube->raycast.posx += datacube->raycast.diry * datacube->raycast.movespeed;
		if (datacube->map[(int)datacube->raycast.posx][(int)(datacube->raycast.posy -
					datacube->raycast.dirx *
					(datacube->raycast.movespeed * 2))] == '0')
			datacube->raycast.posy -= datacube->raycast.dirx * datacube->raycast.movespeed;
	}
	ft_right(datacube);
}