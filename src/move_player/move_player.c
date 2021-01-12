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

void			update_position(float x, float y)
{	
	update_sprite();
	update_player_position(x, y);
}

void			move_player(void) //co van de o day
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;
	int 	player_orientation;
	float	angle;

	player_orientation = player_orientation_angle(g_player.rotation_angle); // cai nay de lam gi?
	g_player.rotation_angle += g_player.turn_direction * g_player.turn_speed;
	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
	move_step = g_player.walk_direction * g_player.walk_speed;
	new_player_x = g_player.x + cos(g_player.rotation_angle) * move_step;
	new_player_y = g_player.y + sin(g_player.rotation_angle) * move_step;
	if(g_player.shift_right == -1 || g_player.shift_right == 1)
	{
		angle = (M_PI * 0.5) - g_player.rotation_angle;
		if (player_orientation == 1)
		{
			new_player_x = g_player.x - cos(angle) * move_step;
			new_player_y = g_player.y + sin(angle) * move_step;
		}
		else if (player_orientation == 0)
		{
			new_player_x = g_player.x + cos(angle) * -move_step;
			new_player_y = g_player.y - sin(angle) * -move_step;
		}
	}
	update_position(new_player_x, new_player_y);
}
