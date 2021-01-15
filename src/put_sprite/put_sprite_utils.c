/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:44:03 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 12:44:46 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	switch_sprite(t_sprite *sprite, int i, int j)
{
	float		temp_distance;
	float		temp_y;
	float		temp_x;

	temp_distance = sprite->distance[j];
	temp_x = sprite->x[j];
	temp_y = sprite->y[j];
	sprite->distance[j] = sprite->distance[i];
	sprite->x[j] = sprite->x[i];
	sprite->y[j] = sprite->y[i];
	sprite->distance[i] = temp_distance;
	sprite->x[i] = temp_x;
	sprite->y[i] = temp_y;
}

float	make_sense_angle(float angle)
{
	if (angle < -3.14159)
		angle += 2.0 * 3.14159;
	if (angle > 3.14159)
		angle -= 2.0 * 3.14159;
	return (angle);
}

float	calculate_relative_sprite_angle(t_player *player, float x, float y)
{
	float	vectx;
	float	vecty;
	float	relative_sprite_angle;
	float	found_angle;
	float	player_rotation_angle;

	vectx = x - player->x;
	vecty = y - player->y;
	relative_sprite_angle = atan2(vecty, vectx);
	player_rotation_angle = normalize_angle(player->rotation_angle);
	found_angle = player_rotation_angle - relative_sprite_angle;
	found_angle = make_sense_angle(found_angle);
	found_angle = fabs(found_angle);
	return (found_angle);
}
