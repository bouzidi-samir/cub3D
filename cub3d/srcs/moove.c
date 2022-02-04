/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:22:39 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/04 13:22:53 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
void	ft_draw_texture(t_recup *recup, int x, int y)
{
	y = recup->ray.drawstart - 1;
	ft_init_texture(recup);
	recup->t.step = 1.0 * recup->texture[0].height / recup->ray.lineheight;
	recup->t.texx = (int)(recup->t.wallx * (double)recup->texture
			[recup->t.texdir].width);
	if (recup->ray.side == 0 && recup->ray.raydirx > 0)
		recup->t.texx = recup->texture[recup->t.texdir].width -
			recup->t.texx - 1;
	if (recup->ray.side == 1 && recup->ray.raydiry < 0)
		recup->t.texx = recup->texture[recup->t.texdir].width -
			recup->t.texx - 1;
	recup->t.texpos = (recup->ray.drawstart - recup->ry / 2 +
			recup->ray.lineheight / 2) * recup->t.step;
	while (++y <= recup->ray.drawend)
	{
		recup->t.texy = (int)recup->t.texpos &
			(recup->texture[recup->t.texdir].height - 1);
		recup->t.texpos += recup->t.step;
		if (y < recup->ry && x < recup->rx)
			recup->data.addr[y * recup->data.line_length / 4 + x] =
				recup->texture[recup->t.texdir].addr[recup->t.texy *
					recup->texture[recup->t.texdir].line_length /
					4 + recup->t.texx];
	}
}*/

int		ft_col_draw(t_datastock *datacube)
{
	int j;
	int i;

	j = -1;
	datacube->raycast.drawend = datacube->ry - datacube->raycast.drawstart;
	i = datacube->raycast.drawend;
	while (++j < datacube->raycast.drawstart)
		datacube->three_d.img_data[j * datacube->three_d.size_line / 4 +
			datacube->raycast.x] = datacube->c;
	//if (j <= datacube->raycast.drawend)
	//	ft_draw_texture(datacube, datacube->raycast.x, j);
	j = i;
	while (++j < datacube->ry)
		datacube->three_d.img_data[j * datacube->three_d.size_line / 4 +
			datacube->raycast.x] = datacube->f;
	return (0);
}