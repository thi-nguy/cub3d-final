/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:41:59 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 12:43:35 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_transform_x(int id)
{
	float		spritex;
	float		spritey;
	float		transformx;

	spritex = g_sprite.x[id] - g_player.x;
	spritey = g_sprite.y[id] - g_player.y;
	transformx = g_sprite.inv_det * (g_sprite.diry * spritex - g_sprite.dirx * spritey);
	return (transformx);
}

float	get_transform_y(int id)
{
	float		spritex;
	float		spritey;
	float		transformy;

	spritex = g_sprite.x[id] - g_player.x;
	spritey = g_sprite.y[id] - g_player.y;
	transformy =  g_sprite.inv_det * (-g_sprite.planey * spritex + g_sprite.planex * spritey);
	return (transformy);
}

int		is_sprite_visible(int id, float sprite_size)
{
	float	spriteangle;
	float	spriteangle_end;
	float	whole_sprite_angle;
	float	fov_sprite;

	spriteangle = calculate_relative_sprite_angle(&g_player, g_sprite.x[id],
		g_sprite.y[id]);
	spriteangle_end = calculate_relative_sprite_angle(&g_player, (g_sprite.x[id]
		+ sprite_size), (g_sprite.y[id] + sprite_size));
	whole_sprite_angle = fabs(spriteangle_end - spriteangle);
	fov_sprite = g_fov / 2 + whole_sprite_angle;
	if (spriteangle < fov_sprite)
		return (1);
	return (0);
}

void	put_elements_in_sprite_to_zero(void)
{
	g_sprite.drawstartx = 0;
	g_sprite.drawendx = 0;
	g_sprite.drawstarty = 0;
	g_sprite.drawendy = 0;
	g_sprite.spritescreenx = 0;
}

void	sort_sprite_distance(void)
{
	int	j;
	int	i;

	i = 0;
	while (i < g_sprite.nb_sprite)
	{
		j = i + 1;
		while (j < g_sprite.nb_sprite)
		{
			if (g_sprite.distance[j] > g_sprite.distance[i])
				switch_sprite(&g_sprite, i, j);
			j++;
		}
		i++;
	}
}

void	get_sprite_distance_to_player(void)
{
	int	id;

	id = 0;
	while (id < g_sprite.nb_sprite)
	{
		g_sprite.distance[id] = distance_between_points(g_player.x,
				g_player.y, g_sprite.x[id], g_sprite.y[id]);
		id++;
	}
}

void	put_sprite(void)
{
	float		distance_player_to_projection_plane;
	float		sprite_size;
	int			id;
	float		transform_x;
	float		transform_y;

	id = 0;
	get_sprite_distance_to_player();
	sort_sprite_distance();
	distance_player_to_projection_plane = (g_window.width / 2) / tan(g_fov / 2);
	g_sprite.inv_det = 1.0 / (g_sprite.planex * g_sprite.diry -
		g_sprite.dirx * g_sprite.planey);
	while (id < g_sprite.nb_sprite)
	{
		sprite_size = g_tile_size * 0.5 / g_sprite.distance[id] *
			distance_player_to_projection_plane;
		put_elements_in_sprite_to_zero();
		if (is_sprite_visible(id, sprite_size) == 1)
		{
			transform_x = get_transform_x(id);
			transform_y = get_transform_y(id);
			g_sprite.spritescreenx = (int)((g_window.width / 2) * (1 - transform_x / transform_y));
			ft_getstart(&g_sprite, sprite_size, transform_y);
			render_sprite(&g_sprite, transform_y, sprite_size);
		}
		id++;
	}
}


