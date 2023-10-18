/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:09:51 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/09 20:06:11 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_count(t_mlxdata *data)
{
	char	*count;

	data->m_count++;
	count = ft_itoa(data->m_count);
	write(1, "moving count : ", 15);
	ft_putnbr(data->m_count);
	write(1, "\n", 1);
	mlx_string_put(data->mlx, data->win, 100, 100, 0x000000, count);
}

void	x_move_character(int x, t_mlxdata *d)
{
	if (d->map[d->loc.y][d->loc.x + x] == 'E')
	{
		if (d->carrot == 0)
		{
			put_image(d, 0, 0);
			exit(0);
		}
	}
	else if (d->map[d->loc.y][d->loc.x + x] == 'C')
	{
		d->map[d->loc.y][d->loc.x] = '0';
		d->map[d->loc.y][d->loc.x + x] = 'P';
		d->loc.x += x;
		d->carrot--;
		print_count(d);
	}
	else if (d->map[d->loc.y][d->loc.x + x] == '0')
	{
		d->map[d->loc.y][d->loc.x] = '0';
		d->map[d->loc.y][d->loc.x + x] = 'P';
		d->loc.x += x;
		print_count(d);
	}
	put_image(d, 0, 0);
}

void	y_move_character(int y, t_mlxdata *d)
{
	if (d->map[d->loc.y + y][d->loc.x] == 'E')
	{
		if (d->carrot == 0)
		{
			put_image(d, 0, 0);
			exit(0);
		}
	}
	else if (d->map[d->loc.y + y][d->loc.x] == 'C')
	{
		d->map[d->loc.y][d->loc.x] = '0';
		d->map[d->loc.y + y][d->loc.x] = 'P';
		d->loc.y += y;
		d->carrot--;
		print_count(d);
	}
	else if (d->map[d->loc.y + y][d->loc.x] == '0')
	{
		d->map[d->loc.y][d->loc.x] = '0';
		d->map[d->loc.y + y][d->loc.x] = 'P';
		d->loc.y += y;
		print_count(d);
	}
	put_image(d, 0, 0);
}

int	key_press(int keycode, t_mlxdata *data)
{
	if (keycode == A_KEY)
		x_move_character(-1, data);
	else if (keycode == D_KEY)
		x_move_character(1, data);
	else if (keycode == W_KEY)
		y_move_character(-1, data);
	else if (keycode == S_KEY)
		y_move_character(1, data);
	else if (keycode == ESC_KEY)
		exit_game(data);
	return (0);
}
