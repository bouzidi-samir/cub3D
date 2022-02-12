/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:19:38 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/11 11:24:44 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int moove_player(int keycode, t_datastock *datacube)
{
    int	x;
	int y;
	
	x = datacube->raycast.posx;
	y = datacube->raycast.posy;
	if (keycode == LEFT && datacube->map[(int)datacube->raycast.posy / 40][((int)datacube->raycast.posx + 10)/ 40] != '1')
		datacube->raycast.posx++;
	if (keycode == RIGHT && datacube->map[((int)datacube->raycast.posy) / 40][((int)datacube->raycast.posx) / 40] != '1')
    {
		ft_putnbr_fd(datacube->raycast.posx, 1);
	    datacube->raycast.posx--;
	}
	if (keycode == TOP && datacube->map[((int)datacube->raycast.posy) / 40][((int)datacube->raycast.posx) / 40] != '1')
		datacube->raycast.posy--;
    if (keycode == BOTTOM && datacube->map[((int)datacube->raycast.posy + 10) / 40][((int)datacube->raycast.posx)/ 40] != '1') 
        datacube->raycast.posy++;
	mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win, datacube->mini.img, 0, 0);
	fill_minimap(datacube);
	mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win,datacube->mini.img_player, datacube->raycast.posx, datacube->raycast.posy);
	return (0);
}

void fill_img(int *img, int color, int width, int height)
{
	int size;
	int i;

	size = ft_strlen((char *)img);
	i = 0;
	while (i <= (width * height))
	{
		img[i] = color;
		i++;
	}	
}

void fill_minimap(t_datastock *datacube)
{
	int x;
	int	y;
	int	cx;
	int	cy;

	x = 0;
	y = 0;
	cy = 0;	
	while (y < datacube->height)
	{
		cx = -datacube->rx_bloc;
		x = 0;
		while (x < datacube->width)
		{
			cx += datacube->rx_bloc;
			if (datacube->map[y][x] == '1')	
				mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win, datacube->mini.img_wall, cx, cy);
			if (datacube->map[y][x] == '0')	
				mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win, datacube->mini.img_empty, cx, cy);
			if (x == datacube->depy && y == datacube->depx) 
			{
			
				if (datacube->raycast.posx == 0 && datacube->raycast.posy == 0)
				{
					datacube->mini.posx = cx;
					datacube->mini.posy = cy;
				}
			}
			x++;
		}
		cy += datacube->ry_bloc;
		y++;
	}
}

int init_minimap(t_datastock *datacube)
{
	int     bpp;
	int     size_line;
	int     endian;

	//ft_putnbr_fd(datacube->raycast.posx, 1);
	datacube->mini.posx = ((double)datacube->raycast.posy - 0.5) * datacube->rx_bloc ;
	datacube->mini.posy = ((double)datacube->raycast.posx - 0.5) * datacube->ry_bloc ;
	datacube->rx_bloc = datacube->rx / 30 - 1;
	datacube->ry_bloc = datacube->ry / 30 - 1;
	datacube->rx_mini = datacube->rx_bloc * datacube->width;
	datacube->ry_mini = datacube->ry_bloc * datacube->height;
	datacube->mini.img =  mlx_new_image(datacube->mlx_ptr, datacube->rx_mini, datacube->ry_mini);
	datacube->mini.img_data = (int *)mlx_get_data_addr(datacube->mini.img, &bpp, &size_line, &endian);
	fill_img(datacube->mini.img_data, 025500, datacube->rx_mini, datacube->ry_mini);
	mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win, datacube->mini.img, 0, 0);
	datacube->mini.img_player =  mlx_new_image(datacube->mlx_ptr, datacube->rx_bloc / 2, datacube->ry_bloc / 2);
	datacube->mini.img_wall  =  mlx_new_image(datacube->mlx_ptr, datacube->rx_bloc, datacube->ry_bloc);
	datacube->mini.img_empty  =  mlx_new_image(datacube->mlx_ptr, datacube->rx_bloc, datacube->ry_bloc );
	datacube->mini.data_wall = (int *)mlx_get_data_addr(datacube->mini.img_wall, &bpp, &size_line, &endian);
	datacube->mini.data_player = (int *)mlx_get_data_addr(datacube->mini.img_player, &bpp, &size_line, &endian);
	datacube->mini.data_empty = (int *)mlx_get_data_addr(datacube->mini.img_empty, &bpp, &size_line, &endian);
	fill_img(datacube->mini.data_wall, 135245251, datacube->rx_bloc, datacube->ry_bloc);			
	fill_img(datacube->mini.data_empty, 025500, datacube->rx_bloc, datacube->ry_bloc);
	fill_img(datacube->mini.data_player, 12414212, datacube->rx_bloc / 2, datacube->ry_bloc / 2);
	fill_minimap(datacube);
	//mlx_put_image_to_window(datacube->mlx_ptr,datacube->mlx_win,datacube->mini.img_player, datacube->mini.posx, datacube->mini.posy);
	return (0);
}
