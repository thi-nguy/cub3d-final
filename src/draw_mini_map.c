/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:07:34 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 16:11:12 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rotation_line(void)
{
	float x_minimap;
	float y_minimap;

	x_minimap = g_player.x * SIZE_MINI_MAP;
	y_minimap = g_player.y * SIZE_MINI_MAP;
	draw_line(y_minimap, x_minimap);
}

void	draw_player(void)
{
	float x_minimap;
	float y_minimap;

	x_minimap = g_player.x * SIZE_MINI_MAP;
	y_minimap = g_player.y * SIZE_MINI_MAP;
	draw_grid_player(y_minimap, x_minimap, y_minimap +
			g_player.height, x_minimap + g_player.width);
}

void	draw_sprite(void)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < g_map_row)
	{
		y = i * g_tile_size * SIZE_MINI_MAP;
		j = 0;
		while (j < g_map_col)
		{
			x = j * g_tile_size * SIZE_MINI_MAP;
			if (g_grid_array[i][j] == 2)
				draw_grid(y, x, y + 5, x + 5, color);
			j++;
		}
		i++;
	}
}

void	draw_map(int x, int y)
{
	int i;
	int j;
	int tile_x;
	int tile_y;

	i = 0;
	while (i < g_map_row)
	{
		y = i * g_tile_size * SIZE_MINI_MAP;
		tile_y = y + g_tile_size * SIZE_MINI_MAP;
		j = 0;
		while (j < g_map_col)
		{
			x = j * g_tile_size * SIZE_MINI_MAP;
			tile_x = x + g_tile_size * SIZE_MINI_MAP;
			if (g_grid_array[i][j] == 1)
				draw_grid_wall(y, x, tile_y, tile_x);
			else
				draw_grid_space(y, x, tile_y, tile_x);
			j++;
		}
		i++;
	}
}

void	draw_mini_map(void)
{
	int x0;
	int y0;

	x0 = 0;
	y0 = 0;
	draw_map(x0, y0);
	draw_sprite();
	draw_player();
	draw_rotation_line();
}
