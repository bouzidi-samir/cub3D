/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:19:38 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/01/28 15:54:44 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int moove_player(int keycode, t_datastock *datacube)
{
    if (keycode == DROITE)
        datacube->depy++;
    if (keycode == GAUCHE)
        datacube->depy--;
    if (keycode == HAUT)
        datacube->depy--;
    if (keycode == BAS)
        datacube->depy++;
    ft_putnbr_fd(datacube->depy, 1);

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
	void *img;
	int *tab_data;
	int     bpp;
	int     size_line;
	int     endian;

	x = 0;
	y = 0;
	cy = 0;	
	while (y < datacube->height)
	{
		cx = -40;
		x = 0;
		while (x < datacube->width)
		{
			cx += 40;
			if (x == datacube->depy && y == datacube->depx) 
				img = mlx_new_image(datacube->display.mlx_ptr, 10, 10);
			else
				img = mlx_new_image(datacube->display.mlx_ptr, 40, 40);
			tab_data = (int *)mlx_get_data_addr(img , &bpp, &size_line, &endian);
			if (datacube->map[y][x] == '1')
				fill_img(tab_data, 135245251, 40, 40);			
			if (x == datacube->depy && y == datacube->depx) 
				fill_img(tab_data, 11714279, 20, 20);
			mlx_put_image_to_window(datacube->display.mlx_ptr, datacube->display.mlx_win, img, cx, cy);
			x++;
		}
		cy += 40;
		y++;
	}
}

void init_mini(t_datastock *datacube)
{	
	datacube->display.mlx_ptr = mlx_init();
	datacube->display.mlx_win = mlx_new_window(datacube->display.mlx_ptr, datacube->width * 40, datacube->height * 40, "Hello world!");
	//datacube->display.img_mini = mlx_new_image(datacube->display.mlx_ptr, datacube->width * 40, datacube->height * 40);
	//datacube->display.img_mini_data = (int *)mlx_get_data_addr(datacube->display.img_mini , &bpp, &size_line, &endian);
	//fill_img(datacube->display.img_mini_data, 135245251, datacube->width * 40, datacube->height * 40);
	//datacube->display.img_data[datacube->depy * WIDTH / 4 + datacube->depx] = 135245251;
	fill_minimap(datacube);
	mlx_hook(datacube->display.mlx_win, 2, 1L << 0, moove_player, datacube);
    mlx_loop(datacube->display.mlx_ptr);
}