/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:57:14 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/02/04 23:11:25 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_dir(t_datastock *datacube)
{
	if (datacube->depart == 'N')
		datacube->raycast.dirx = -1;
	if (datacube->depart == 'S')
		datacube->raycast.dirx = 1;
	if (datacube->depart == 'E')
		datacube->raycast.diry = 1;
	if (datacube->depart == 'W')
		datacube->raycast.diry = -1;
	if (datacube->depart == 'N')
		datacube->raycast.plany = 0.66;
	if (datacube->depart == 'S')
		datacube->raycast.plany = -0.66;
	if (datacube->depart == 'E')
		datacube->raycast.planx = 0.66;
	if (datacube->depart == 'W')
		datacube->raycast.planx = -0.66;
}

void ft_init_datastock(t_datastock *datacube)
{
	datacube->bad_xpm = 0;
	datacube->i = 0;
    datacube->f = -1;
    datacube->c = -1;
    datacube->ret = 0;
    datacube->indicateur2 = 0;
    datacube->width = 0;
    datacube->height = 0;
    datacube->rx = 0;
	datacube->ry = 0;
	datacube->rx_mini = 0;
	datacube->ry_mini = 0;
    datacube->bad_filename = 0;
    datacube->path_size = 0;	
	datacube->error = 0;
	datacube->inmap = 0;
	datacube->count = 0;
	datacube->emptyline = 0;
	datacube->depx = 0;
	datacube->depy = 0;
	datacube->player = 0;
	datacube->multijoueurs = 0;
	datacube->err = 0;
	datacube->bad_char = 0;
	datacube->wrongwall = 0;
	datacube->dx = 0;
    datacube->dy = 0;
    datacube->depart = 'o';
	datacube->no = NULL; // malloc
	datacube->so = NULL; // malloc
	datacube->we = NULL; // malloc
	datacube->ea = NULL; // malloc
	datacube->map = NULL; // malloc
}

void	ft_init_raycast(t_datastock *datacube)
{
	datacube->raycast.posx = 0;
	datacube->raycast.posy = 0;
    datacube->rx = datacube->width * 80;
	datacube->ry = datacube->height * 80;
    datacube->three_d.forward = 0;
	datacube->three_d.back = 0;
	datacube->three_d.left = 0;
	datacube->three_d.right = 0;
	datacube->three_d.rotate_right = 0;
	datacube->three_d.rotate_left = 0;
	datacube->raycast.posx = (double)datacube->depx + 0.5;
	datacube->raycast.posy = (double)datacube->depy + 0.5;
	datacube->raycast.dirx = 0;
	datacube->raycast.diry = 0;
	datacube->raycast.planx = 0;
	datacube->raycast.plany = 0;
	ft_init_dir(datacube);
}

void	ft_init_raycast2(t_datastock *datacube)
{
    datacube->raycast.hit = 0;
	datacube->raycast.perpwalldist = 0;
	datacube->raycast.camerax = 2 * datacube->raycast.x / (double)datacube->rx - 1;
	datacube->raycast.raydirx = datacube->raycast.dirx + datacube->raycast.planx * \
						datacube->raycast.camerax;
	datacube->raycast.raydiry = datacube->raycast.diry + datacube->raycast.plany * \
						datacube->raycast.camerax;
	datacube->raycast.mapx = (int)datacube->raycast.posx;
	datacube->raycast.mapy = (int)datacube->raycast.posy;
	datacube->raycast.movespeed = 0.1;
	datacube->raycast.rotspeed = 0.033 * 1.8;
	ft_init_raycast3(datacube);
}

void	ft_init_raycast3(t_datastock *datacube)
{
	if (datacube->raycast.raydiry == 0)
		datacube->raycast.deltadistx = 0;
	else if (datacube->raycast.raydirx == 0)
		datacube->raycast.deltadistx = 1;
	else
		datacube->raycast.deltadistx = sqrt(1 + (datacube->raycast.raydiry
			* datacube->raycast.raydiry) / (datacube->raycast.raydirx *
			datacube->raycast.raydirx));
	if (datacube->raycast.raydirx == 0)
		datacube->raycast.deltadisty = 0;
	else if (datacube->raycast.raydiry == 0)
		datacube->raycast.deltadisty = 1;
	else
		datacube->raycast.deltadisty = sqrt(1 + (datacube->raycast.raydirx *
			datacube->raycast.raydirx) / (datacube->raycast.raydiry *
			datacube->raycast.raydiry));
}
