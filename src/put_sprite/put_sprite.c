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

int		is_sprite_visible(int id)
{
	float		spritex;
	float		spritey;
	float		invdet;
	float		transformx;
	float		transformy;

	spritex = g_sprite.x[id] - g_player.x;
	spritey = g_sprite.y[id] - g_player.y;
	invdet = 1.0 / (g_sprite.planex * g_sprite.diry -
			g_sprite.dirx * g_sprite.planey);
	transformx = invdet * (g_sprite.diry * spritex - g_sprite.dirx * spritey);
	transformy = invdet * (-g_sprite.planey * spritex + g_sprite.planex * spritey);
	if (transformx / transformy > 1)
		return (0);
	else
		return (1);
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
	float		transformed_y;

	id = 0;
	get_sprite_distance_to_player();
	sort_sprite_distance();
	while (id < g_sprite.nb_sprite)
	{
		distance_player_to_projection_plane = (g_window.width / 2) / tan(g_fov / 2);
		sprite_size = g_tile_size * 0.5 / g_sprite.distance[id] *
			distance_player_to_projection_plane;
		put_elements_in_sprite_to_zero();
		if (is_sprite_visible(id) == 1)
		{
			transformed_y = get_transformed_y(&g_sprite, &g_player, id);
			ft_getstart(&g_sprite, sprite_size, transformed_y);
			render_sprite(&g_sprite, transformed_y, sprite_size);
		}
		id++;
	}
}


