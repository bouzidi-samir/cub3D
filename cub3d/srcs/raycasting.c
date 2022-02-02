/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:05 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/02 15:53:28 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_raycasting(t_datastock *datacube)
{
	datacube->raycast.x = 0;
	while (datacube->raycast.x < datacube->rx)
	{
		ft_init_raycast2(datacube);
		//ft_stepsidedist(recup);
		//ft_color_column(recup);		
		datacube->raycast.x++;
	}
	//mlx_put_image_to_window(recup->data.mlx_ptr, recup->data.mlx_win,
			//recup->data.img, 0, 0);
	
	return (0);
}