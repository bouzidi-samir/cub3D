/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:04:04 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/10 22:06:43 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	rotate_right_left(t_datastock *datacube)
{
	double oldplanx;
	double olddirx;

	oldplanx = datacube->raycast.planx;
	olddirx = datacube->raycast.dirx;
	if (datacube->three_d.rotate_right == 1)
	{
		datacube->raycast.dirx = datacube->raycast.dirx * cos(-datacube->raycast.rotspeed / 2) -
			datacube->raycast.diry * sin(-datacube->raycast.rotspeed / 2);
		datacube->raycast.diry = olddirx * sin(-datacube->raycast.rotspeed / 2) +
			datacube->raycast.diry * cos(-datacube->raycast.rotspeed / 2);
		datacube->raycast.planx = datacube->raycast.planx * cos(-datacube->raycast.rotspeed / 2)
			- datacube->raycast.plany * sin(-datacube->raycast.rotspeed / 2);
		datacube->raycast.plany = oldplanx * sin(-datacube->raycast.rotspeed / 2) +
			datacube->raycast.plany * cos(-datacube->raycast.rotspeed / 2);
	}
	left_rotate(datacube, olddirx);
}

void	left_rotate(t_datastock *datacube, double olddirx)
{
	double oldplanex;

	if (datacube->three_d.rotate_left == 1)
	{
		olddirx = datacube->raycast.dirx;
		oldplanex = datacube->raycast.planx;
		datacube->raycast.dirx = datacube->raycast.dirx * cos(datacube->raycast.rotspeed / 2) -
			datacube->raycast.diry * sin(datacube->raycast.rotspeed / 2);
		datacube->raycast.diry = olddirx * sin(datacube->raycast.rotspeed / 2) + datacube->
			raycast.diry * cos(datacube->raycast.rotspeed / 2);
		datacube->raycast.planx = datacube->raycast.planx * cos(datacube->raycast.rotspeed / 2) -
			datacube->raycast.plany * sin(datacube->raycast.rotspeed / 2);
		datacube->raycast.plany = oldplanex * sin(datacube->raycast.rotspeed / 2) +
			datacube->raycast.plany * cos(datacube->raycast.rotspeed / 2);
	}
}