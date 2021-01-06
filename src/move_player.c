/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:18:29 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 11:38:46 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		player_orientation_angle(float angle)
{
	angle = normalize_angle(angle);
	if ((angle > M_PI * 0.25) && (angle < 0.75 * M_PI))
		return (1);
	else if ((angle > M_PI * 1.25) && (angle < 1.75 * M_PI))
		return (1);
	return (0);
}

int				has_wall_at(float y, float x)
{
	int map_grid_index_x;
	int map_grid_index_y;

	if (x < 0 || x > g_window.width || y < 0 || y > g_window.height)
		return (1);
	map_grid_index_x = floor(x / g_tile_size);
	map_grid_index_y = floor(y / g_tile_size);
	return (g_grid_array[map_grid_index_y][map_grid_index_x] == 1);
}

static void		update_position(t_player *player, float y,
		float x, t_sprite *sprite)
{
	float		olddirx;
	float		oldplanx;
	float		vectangle;

	olddirx = sprite->dirx;
	oldplanx = sprite->planx;
	vectangle = player->turn_direction * player->turn_speed;
	sprite->dirx = sprite->dirx * cos(vectangle) - sprite->diry *
		sin(vectangle);
	sprite->diry = olddirx * sin(vectangle) + sprite->diry * cos(vectangle);
	sprite->planx = sprite->planx * cos(vectangle) - sprite->plany *
		sin(vectangle);
	sprite->plany = oldplanx * sin(vectangle) + sprite->plany * cos(vectangle);
	if (!has_wall_at(y, x))
	{
		player->y = y;
		player->x = x;
	}
}

void			move_player(void)
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;
	int		player_orientation;

	player_orientation = player_orientation_angle(player.rotation_angle);
	player.rotation_angle += player.turn_direction * player.turn_speed;
	move_step = player.walk_direction * player.walk_speed;
	new_player_x = player.x + cos(player.rotation_angle) * move_step;
	new_player_y = player.y + sin(player.rotation_angle) * move_step;
	update_position(&player, new_player_y, new_player_x, &g_sprite);
}
