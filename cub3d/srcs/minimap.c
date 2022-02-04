/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:19:38 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/04 23:58:24 by samirbouzid      ###   ########.fr       */
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
    //ft_putnbr_fd(datacube->raycast.posy, 1);
	mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win, datacube->mini.img, 0, 0);
	fill_minimap(datacube);
    //mlx_destroy_image(datacube->display.mlx_ptr, datacube->display.img_player);
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
		cx = -20;
		x = 0;
		while (x < datacube->width)
		{
			cx += 20;
			if (datacube->map[y][x] == '1')	
				mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win, datacube->mini.img_wall, cx, cy);
			if (datacube->map[y][x] == '0')	
				mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win, datacube->mini.img_empty, cx, cy);
			if (x == datacube->depy && y == datacube->depx) 
			{
			
				if (datacube->raycast.posx == 0 && datacube->raycast.posy == 0)
				{
					datacube->raycast.posx = cx;
					datacube->raycast.posy = cy;
				}
			}
			x++;
		}
		cy += 20;
		y++;
	}
}

int init_minimap(t_datastock *datacube)
{
	int     bpp;
	int     size_line;
	int     endian;

	datacube->rx_mini = datacube->rx / 2;
	datacube->ry_mini = datacube->ry / 2;
	datacube->mini.img =  mlx_new_image(datacube->mlx_ptr, 20 * datacube->width, 20 * datacube->height);
	datacube->mini.img_data = (int *)mlx_get_data_addr(datacube->mini.img, &bpp, &size_line, &endian);
	fill_img(datacube->mini.img_data, 025500, 20 * datacube->width, 20 * datacube->height);
	mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win, datacube->mini.img, 0, 0);
	datacube->mini.img_player =  mlx_new_image(datacube->mlx_ptr, 10, 10);
	datacube->mini.img_wall  =  mlx_new_image(datacube->mlx_ptr, 20, 20);
	datacube->mini.img_empty  =  mlx_new_image(datacube->mlx_ptr, 20, 20);
	datacube->mini.data_wall = (int *)mlx_get_data_addr(datacube->mini.img_wall, &bpp, &size_line, &endian);
	datacube->mini.data_player = (int *)mlx_get_data_addr(datacube->mini.img_player, &bpp, &size_line, &endian);
	datacube->mini.data_empty = (int *)mlx_get_data_addr(datacube->mini.img_empty, &bpp, &size_line, &endian);
	fill_img(datacube->mini.data_wall, 135245251, 20, 20);			
	fill_img(datacube->mini.data_empty, 025500, 20, 20);
	fill_img(datacube->mini.data_player, 11714279, 10, 10);
	mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win,datacube->mini.img_player, datacube->raycast.posx, datacube->raycast.posy);
	fill_minimap(datacube);
	//mlx_put_image_to_window(datacube->mlx_ptr, datacube->mlx_win,datacube->mini.img_player, datacube->raycast.posx, datacube->raycast.posy);
	return (0);
}
