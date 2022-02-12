/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:25:41 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/02/12 10:28:07 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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