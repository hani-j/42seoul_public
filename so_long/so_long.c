/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:56:52 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/09 20:04:05 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_print(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(1);
}

t_mlxdata	*data_init(void)
{
	t_mlxdata	*data;

	data = malloc(sizeof(t_mlxdata));
	data->mlx = 0;
	data->win = 0;
	data->map = 0;
	data->width = 0;
	data->height = 0;
	data->carrot = 0;
	data->m_count = 0;
	data->imgdata.wall = 0;
	data->imgdata.rabbit = 0;
	data->imgdata.carrot = 0;
	data->imgdata.back = 0;
	data->imgdata.door = 0;
	data->loc.x = 0;
	data->loc.y = 0;
	return (data);
}

int	exit_game(t_mlxdata *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlxdata	*data;

	if (argc != 2)
		error_print("no file\n");
	data = data_init();
	map_init(argv[1], data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width * 64, \
			data->height * 64, "yuuuuum");
	image_init(data);
	mlx_hook(data->win, KEY_PRESS, 0, &key_press, data);
	mlx_hook(data->win, KEY_EXIT, 0, &exit_game, data);
	mlx_loop(data->mlx);
	return (0);
}
