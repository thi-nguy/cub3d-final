/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:07:34 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 10:33:59 by thi-nguy         ###   ########.fr       */
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

void	draw_player(int color)
{
	float x_minimap;
	float y_minimap;

	x_minimap = g_player.x * SIZE_MINI_MAP;
	y_minimap = g_player.y * SIZE_MINI_MAP;
	draw_grid(y_minimap, x_minimap, y_minimap + g_player.height, x_minimap +
			g_player.width, color);
}

void	draw_sprite(int color)
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

void	draw_map(int color_wall, int color_space)
{
	int i;
	int j;
	int tile_color;
	int x;
	int y;
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
			tile_color = (g_grid_array[i][j] != 1 ? color_space : color_wall);
			draw_grid(y, x, tile_y, tile_x, tile_color);
			j++;
		}
		i++;
	}
}

void	draw_mini_map(void)
{
	draw_map(0Xaa5555, 0Xc1e2f1);
	draw_sprite(0X5175bc);
	draw_player(0X2345bc);
	draw_rotation_line();
}
