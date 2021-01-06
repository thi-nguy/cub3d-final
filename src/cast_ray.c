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
	if (ray.ray_angle > 0 && ray.ray_angle < M_PI)
		ray.is_ray_facing_down = 1;
	else
		ray.is_ray_facing_up = 1;
	if (ray.ray_angle < (0.5 * M_PI) || ray.ray_angle > (1.5 * M_PI))
		ray.is_ray_facing_right = 1;
	else
		ray.is_ray_facing_left = 1;
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
	{
		angle = (2 * M_PI) + angle;
	}
	return (angle);
}

void	cast_one_ray(float ray_angle, int strip_id)
{
	ray.ray_angle = normalize_angle(ray_angle);
	find_where_ray_face();
	find_horz_intercept(&ray, &player);
	find_vert_intercept(&ray, &player);
	find_smallest_distance();
	render_ray(strip_id);
}

void	init_ray(void)
{
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.was_hit_vertical = 0;
	ray.wall_hit_vertical = 0;
	ray.x_step = 0;
	ray.x_intercept = 0;
	ray.y_step = 0;
	ray.y_intercept = 0;
	ray.distance = 0;
	ray.is_ray_facing_down = 0;
	ray.is_ray_facing_up = 0;
	ray.is_ray_facing_right = 0;
	ray.is_ray_facing_left = 0;
	ray.wall_hit_content = 0;
	ray.vert_wall_hit_x = 0;
	ray.vert_wall_hit_y = 0;
	ray.horz_wall_hit_y = 0;
	ray.horz_wall_hit_x = 0;
	ray.found_vert_wall_hit = 0;
	ray.found_horz_wall_hit = 0;
}

void	cast_rays(void)
{
	int	strip_id;

	strip_id = 0;
	ray.ray_angle = player.rotation_angle - (g_fov / 2);
	while (strip_id < g_num_rays)
	{
		init_ray();
		cast_one_ray(ray.ray_angle, strip_id);
		ray.ray_angle += g_fov / g_num_rays;
		strip_id++;
	}
}
