/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:39:32 by junhyuki          #+#    #+#             */
/*   Updated: 2022/10/24 14:40:05 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	ft_close(t_game *game)
{
	(void)game;
	exit(0);
}

int	main_loop(t_game *game)
{
	draw_screen(game);
	draw_minimap(game);
	return (0);
}
