/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:36:19 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 10:36:23 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	the_smallest_of_the_distances_utile(float vert_hit_distance,
		float horz_hit_distance)
{
	if (horz_hit_distance < vert_hit_distance)
	{
		g_ray.wall_hit_x = g_ray.horz_wall_hit_x;
		g_ray.wall_hit_y = g_ray.horz_wall_hit_y;
		g_ray.distance = horz_hit_distance;
	}
	else
	{
		g_ray.wall_hit_x = g_ray.vert_wall_hit_x;
		g_ray.wall_hit_y = g_ray.vert_wall_hit_y;
		g_ray.distance = vert_hit_distance;
		g_ray.was_hit_vertical = 1;
	}
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	find_smallest_distance(void)
{
	float		horz_hit_distance;
	float		vert_hit_distance;

	horz_hit_distance = 0;
	vert_hit_distance = 0;
	if (g_ray.found_horz_wall_hit == 1)
		horz_hit_distance = distance_between_points(g_player.x, g_player.y,
				g_ray.horz_wall_hit_x, g_ray.horz_wall_hit_y);
	else
		horz_hit_distance = MAX_VALUE;
	if (g_ray.found_vert_wall_hit == 1)
		vert_hit_distance = distance_between_points(g_player.x, g_player.y,
				g_ray.vert_wall_hit_x, g_ray.vert_wall_hit_y);
	else
		vert_hit_distance = MAX_VALUE;
	the_smallest_of_the_distances_utile(vert_hit_distance, horz_hit_distance);
}
