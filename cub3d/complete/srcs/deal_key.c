/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyuki <junhyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:58 by junhyuki          #+#    #+#             */
/*   Updated: 2022/10/26 15:15:47 by junhyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

static void	deal_key_w(int key_code, t_game *game)
{
	(void)key_code;
	if (!game->parsing_info->map[(int)(game->player->pos_y)] \
		[(int)(game->player->pos_x + game->player->dir_x * MOV_SPEED)])
		game->player->pos_x += game->player->dir_x * MOV_SPEED;
	if (!game->parsing_info->map[(int)(game->player->pos_y \
		+ game->player->dir_y * MOV_SPEED)][(int)(game->player->pos_x)])
		game->player->pos_y += game->player->dir_y * MOV_SPEED;
}

static void	deal_key_s(int key_code, t_game *game)
{
	(void)key_code;
	if (!game->parsing_info->map[(int)(game->player->pos_y)] \
		[(int)(game->player->pos_x - game->player->dir_x * MOV_SPEED)])
		game->player->pos_x -= game->player->dir_x * MOV_SPEED;
	if (!game->parsing_info->map[(int)(game->player->pos_y - \
		game->player->dir_y * MOV_SPEED)][(int)(game->player->pos_x)])
		game->player->pos_y -= game->player->dir_y * MOV_SPEED;
}

static void	deal_key_d(int key_code, t_game *game)
{
	(void)key_code;
	if (!game->parsing_info->map[(int)(game->player->pos_y)] \
		[(int)(game->player->pos_x + game->player->plane_x * MOV_SPEED)])
		game->player->pos_x += game->player->plane_x * MOV_SPEED;
	if (!game->parsing_info->map[(int)(game->player->pos_y \
		+ game->player->plane_y * MOV_SPEED)][(int)(game->player->pos_x)])
		game->player->pos_y += game->player->plane_y * MOV_SPEED;
}

static void	deal_key_a(int key_code, t_game *game)
{
	(void)key_code;
	if (!game->parsing_info->map[(int)(game->player->pos_y)] \
		[(int)(game->player->pos_x - game->player->plane_x * MOV_SPEED)])
		game->player->pos_x -= game->player->plane_x * MOV_SPEED;
	if (!game->parsing_info->map[(int)(game->player->pos_y \
		- game->player->plane_y * MOV_SPEED)][(int)(game->player->pos_x)])
		game->player->pos_y -= game->player->plane_y * MOV_SPEED;
}

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_W)
		deal_key_w(key_code, game);
	if (key_code == KEY_S)
		deal_key_s(key_code, game);
	if (key_code == KEY_D)
		deal_key_d(key_code, game);
	if (key_code == KEY_A)
		deal_key_a(key_code, game);
	if (key_code == KEY_RIGHT)
		deal_key_right(key_code, game);
	if (key_code == KEY_LEFT)
		deal_key_left(key_code, game);
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}
