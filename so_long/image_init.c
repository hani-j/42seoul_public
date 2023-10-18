/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:46:45 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/09 18:21:08 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlxdata *d, int wid, int hei)
{
	while (hei < d->height)
	{
		wid = 0;
		while (wid < d->width)
		{
			mlx_put_image_to_window(d->mlx, d->win, d->imgdata.back, \
				wid * 64, hei * 64);
			if (d->map[hei][wid] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->imgdata.wall, \
					wid * 64, hei * 64);
			if (d->map[hei][wid] == 'E')
				mlx_put_image_to_window(d->mlx, d->win, d->imgdata.door, \
					wid * 64, hei * 64);
			if (d->map[hei][wid] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->imgdata.carrot, \
					wid * 64, hei * 64);
			if (d->map[hei][wid] == 'P')
			{
				mlx_put_image_to_window(d->mlx, d->win, d->imgdata.rabbit, \
					wid * 64, hei * 64);
			}
			wid++;
		}
		hei++;
	}
}

void	image_init(t_mlxdata *d)
{
	int			wid;
	int			hei;
	t_imgdata	i;

	i.wall = mlx_xpm_file_to_image(d->mlx, "./images/wall.xpm", &wid, &hei);
	i.rabbit = mlx_xpm_file_to_image(d->mlx, "./images/rabbit.xpm", &wid, &hei);
	i.carrot = mlx_xpm_file_to_image(d->mlx, "./images/carrot.xpm", &wid, &hei);
	i.back = mlx_xpm_file_to_image(d->mlx, "./images/back.xpm", &wid, &hei);
	i.door = mlx_xpm_file_to_image(d->mlx, "./images/door.xpm", &wid, &hei);
	d->imgdata = i;
	put_image(d, 0, 0);
}
