/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:22:39 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/04 23:15:11 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_texture(t_datastock *datacube)
{
	if (datacube->raycast.side == 0 && datacube->raycast.raydirx < 0)
		datacube->t.texdir = 0;
	if (datacube->raycast.side == 0 && datacube->raycast.raydirx >= 0)
		datacube->t.texdir = 1;
	if (datacube->raycast.side == 1 && datacube->raycast.raydiry < 0)
		datacube->t.texdir = 2;
	if (datacube->raycast.side == 1 && datacube->raycast.raydiry >= 0)
		datacube->t.texdir = 3;
	if (datacube->raycast.side == 0)
		datacube->t.wallx = datacube->raycast.posy + datacube->raycast.perpwalldist \
						* datacube->raycast.raydiry;
	else
		datacube->t.wallx = datacube->raycast.posx + datacube->raycast.perpwalldist \
						* datacube->raycast.raydirx;
	datacube->t.wallx -= floor((datacube->t.wallx));
}

void	ft_text_draw(t_datastock *datacube, int x, int y)
{
	y = datacube->raycast.drawstart - 1;
	ft_init_texture(datacube);
	datacube->t.step = 1.0 * datacube->text[0].height / datacube->raycast.lineheight;
	datacube->t.texx = (int)(datacube->t.wallx * (double)datacube->text
			[datacube->t.texdir].width);
	if (datacube->raycast.side == 0 && datacube->raycast.raydirx > 0)
		datacube->t.texx = datacube->text[datacube->t.texdir].width -
			datacube->t.texx - 1;
	if (datacube->raycast.side == 1 && datacube->raycast.raydiry < 0)
		datacube->t.texx = datacube->text[datacube->t.texdir].width -
			datacube->t.texx - 1;
	datacube->t.texpos = (datacube->raycast.drawstart - datacube->ry / 2 +
			datacube->raycast.lineheight / 2) * datacube->t.step;
	while (++y <= datacube->raycast.drawend)
	{
		datacube->t.texy = (int)datacube->t.texpos &
			(datacube->text[datacube->t.texdir].height - 1);
		datacube->t.texpos += datacube->t.step;
		if (y < datacube->ry && x < datacube->rx)
			datacube->three_d.img_data[y * datacube->three_d.size_line / 4 + x] =
				datacube->text[datacube->t.texdir].img_data[datacube->t.texy *
					datacube->text[datacube->t.texdir].size_line /
					4 + datacube->t.texx];
	}
}

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
	if (j <= datacube->raycast.drawend)
		ft_text_draw(datacube, datacube->raycast.x, j);
	j = i;
	while (++j < datacube->ry)
		datacube->three_d.img_data[j * datacube->three_d.size_line / 4 +
			datacube->raycast.x] = datacube->f;
	return (0);
}

void	ft_swap(t_datastock *datacube)
{
	void *tmp;

	tmp = datacube->three_d.img;
	datacube->three_d.img = datacube->three_d.img2;
	datacube->three_d.img2 = tmp;
	tmp = datacube->three_d.img_data;
	datacube->three_d.img_data = datacube->three_d.img_data2;
	datacube->three_d.img_data2 = tmp;
}