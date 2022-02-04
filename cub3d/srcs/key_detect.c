/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_detect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:34:41 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/04 16:30:54 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int keycode, t_datastock *datacube)
{
	if (keycode == TOP)
		datacube->three_d.forward = 1;
	else if (keycode == BOTTOM)
		datacube->three_d.back = 1;
	else if (keycode == LEFT)
		datacube->three_d.left = 1;
	else if (keycode == RIGHT)
		datacube->three_d.right = 1;
	else if (keycode == ROTATE_LEFT)
		datacube->three_d.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		datacube->three_d.rotate_right = 1;
	return (1);
}

int		key_release(int keycode, t_datastock *datacube)
{
	if (keycode == TOP)
		datacube->three_d.forward = 0;
	else if (keycode == BOTTOM)
		datacube->three_d.back = 0;
	else if (keycode == LEFT)
		datacube->three_d.left = 0;
	else if (keycode == RIGHT)
		datacube->three_d.right = 0;
	else if (keycode == ROTATE_LEFT)
		datacube->three_d.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		datacube->three_d.rotate_right = 0;
	return (1);
}