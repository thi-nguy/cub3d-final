/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:58:36 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 09:05:22 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_where_ray_face(void)
{
	if (g_ray.ray_angle > 0 && g_ray.ray_angle < M_PI)
		g_ray.is_ray_facing_down = 1;
	else
		g_ray.is_ray_facing_up = 1;
	if (g_ray.ray_angle < (0.5 * M_PI) || g_ray.ray_angle > (1.5 * M_PI))
		g_ray.is_ray_facing_right = 1;
	else
		g_ray.is_ray_facing_left = 1;
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	cast_one_ray(float ray_angle, int strip_id)
{
	find_where_ray_face();
	find_horz_intercept(&g_ray, &g_player);
	find_vert_intercept(&g_ray, &g_player);
	find_smallest_distance();
	render_ray(strip_id);
}

void	init_ray(void)
{
	g_ray.wall_hit_x = 0;
	g_ray.wall_hit_y = 0;
	g_ray.distance = 0;
	g_ray.is_ray_facing_down = 0;
	g_ray.is_ray_facing_up = 0;
	g_ray.is_ray_facing_right = 0;
	g_ray.is_ray_facing_left = 0;
	g_ray.found_horz_wall_hit = 0;
	g_ray.found_vert_wall_hit = 0;
	g_ray.horz_wall_hit_y = 0;
	g_ray.horz_wall_hit_x = 0;
	g_ray.vert_wall_hit_x = 0;
	g_ray.vert_wall_hit_y = 0;
	g_ray.x_step = 0;
	g_ray.y_step = 0;
	g_ray.x_intercept = 0;
	g_ray.y_intercept = 0;

	g_ray.was_hit_vertical = 0; //closest hit is horz or vertical
	g_ray.wall_hit_vertical = 0;
	g_ray.wall_hit_content = 0;
}

void	cast_rays(void)
{
	int	strip_id;

	strip_id = 0;
	g_ray.ray_angle = g_player.rotation_angle - (g_fov / 2); //neu rotaionangle < fov/2 thi sao?
	
	while (strip_id < g_num_rays)
	{
		g_ray.ray_angle = normalize_angle(g_ray.ray_angle);
		init_ray();
		cast_one_ray(g_ray.ray_angle, strip_id);
		g_ray.ray_angle += (g_fov / g_num_rays);
		strip_id++;
	}
}
