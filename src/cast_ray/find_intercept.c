/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:35:29 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 10:36:57 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_last_horz_intercept(float next_y, float next_x)
{
	while (next_x >= 0 && next_x <= (g_tile_size * g_map_col) &&
			next_y >= 0 && next_y <= (g_tile_size * g_map_row))
	{
		if (has_wall_at(next_y - (g_ray.is_ray_facing_up ? 1 : 0) , next_x))
		{
			g_ray.found_horz_wall_hit = 1;
			g_ray.horz_wall_hit_x = next_x;
			g_ray.horz_wall_hit_y = next_y;
			return ;
		}
		else
		{
			next_x += g_ray.x_step;
			next_y += g_ray.y_step;
		}
	}
}

void 	get_first_horz_intercept(t_ray *ray, t_player *player)
{
	ray->y_intercept = floor(player->y / g_tile_size) * g_tile_size; //player.y < tile_size thi sao?
	if (ray->is_ray_facing_down)
		ray->y_intercept += g_tile_size;
	ray->x_intercept = player->x + ((ray->y_intercept - player->y) /
			tan(ray->ray_angle));
	ray->y_step = g_tile_size;
	if (ray->is_ray_facing_up)
		ray->y_step *= -1;
	ray->x_step = g_tile_size / tan(ray->ray_angle);
	if (ray->is_ray_facing_left && ray->x_step > 0)
		ray->x_step *= -1;
	if (ray->is_ray_facing_right && ray->x_step < 0)
		ray->x_step *= -1;
}

void	find_horz_intercept(t_ray *ray, t_player *player)
{
	float	next_horz_touch_y;
	float	next_horz_touch_x;

	get_first_horz_intercept(ray, player);
	next_horz_touch_x = ray->x_intercept;
	next_horz_touch_y = ray->y_intercept;
	get_last_horz_intercept(next_horz_touch_y, next_horz_touch_x);
}

void	get_last_vert_intercept(float next_y, float next_x)
{
	while (next_x >= 0 && next_x <= g_tile_size * g_map_col
			&& next_y >= 0 && next_y <= g_tile_size * g_map_row)
	{
		if (has_wall_at(next_y, next_x - (g_ray.is_ray_facing_left ? 1 : 0)))
		{
			g_ray.found_vert_wall_hit = 1;
			g_ray.vert_wall_hit_x = next_x;
			g_ray.vert_wall_hit_y = next_y;
			return ;
		}
		else
		{
			next_x += g_ray.x_step;
			next_y += g_ray.y_step;
		}
	}
}

void 	get_first_vert_intercept(t_ray *ray, t_player *player)
{
	ray->x_intercept = floor(player->x / g_tile_size) * g_tile_size;
	if (ray->is_ray_facing_right)
		ray->x_intercept += g_tile_size;
	ray->y_intercept = player->y + (ray->x_intercept - player->x) *
		tan(ray->ray_angle);
	ray->x_step = g_tile_size;
	if (ray->is_ray_facing_left)
		ray->x_step *= -1;
	ray->y_step = g_tile_size * tan(ray->ray_angle);
	if (ray->is_ray_facing_up && ray->y_step > 0)
		ray->y_step *= -1;
	if (ray->is_ray_facing_down && ray->y_step < 0)
		ray->y_step *= -1;
}

void	find_vert_intercept(t_ray *ray, t_player *player)
{
	float	next_vert_touch_x;
	float	next_vert_touch_y;

	get_first_vert_intercept(ray, player);
	next_vert_touch_x = ray->x_intercept;
	next_vert_touch_y = ray->y_intercept;
	get_last_vert_intercept(next_vert_touch_y, next_vert_touch_x);
}
