/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:44:58 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 12:48:28 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		choice_of_texture(void)
{
	if (g_ray.is_ray_facing_up && !g_ray.was_hit_vertical)
		return (0);
	if (g_ray.is_ray_facing_down && !g_ray.was_hit_vertical)
		return (1);
	if (g_ray.is_ray_facing_left && g_ray.was_hit_vertical)
		return (2);
	if (g_ray.is_ray_facing_right && g_ray.was_hit_vertical)
		return (3);
	(void)g_ray;
}

void	draw_wall(t_wall *wall, int column_id)
{
	int	texture_offset_x;
	int	texture_offset_y;
	int	texture_color;
	int	distance_from_top;
	int	index;

	index = choice_of_texture();
	if (g_ray.was_hit_vertical == 1)
		texture_offset_x = (int)(g_ray.wall_hit_y * g_texture[index].width /
				g_tile_size) % g_texture[index].width;
	else
		texture_offset_x = (int)(g_ray.wall_hit_x * g_texture[index].width /
				g_tile_size) % g_texture[index].width;
	while (wall->wall_top < wall->wall_bottom)
	{
		distance_from_top = wall->wall_top + (wall->wall_strip_height / 2) -
			(g_window.height / 2);
		texture_offset_y = distance_from_top * ((float)g_texture[index].height /
				wall->wall_strip_height);
		texture_color = g_texture[index].data_addr[(g_texture[index].width *
				texture_offset_y) + texture_offset_x];
		g_image.data_addr[(wall->wall_top * g_window.width) +
			column_id] = texture_color;
		wall->wall_top++;
	}
}

void	render_ray(int column_id)
{
	t_wall	wall;

	wall.correct_wall_distance = g_ray.distance * cos(g_ray.ray_angle -
			g_player.rotation_angle);
	g_sprite.buffer[column_id] = wall.correct_wall_distance;
	wall.distance_projection_plane = (g_window.width / 2) / tan(g_fov / 2);
	wall.wall_strip_height = (g_tile_size / wall.correct_wall_distance) *
		wall.distance_projection_plane;
	wall.wall_top = (g_window.height / 2) - (wall.wall_strip_height / 2);
	if (wall.wall_top < 0)
		wall.wall_top = 0;
	wall.wall_bottom = (g_window.height / 2) + (wall.wall_strip_height / 2);
	if (wall.wall_bottom > g_window.height)
		wall.wall_bottom = g_window.height;
	draw_wall(&wall, column_id);
}