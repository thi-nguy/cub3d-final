#include "cub3d.h"

int		player_orientation_angle(float angle)
{
	angle = normalize_angle(angle);
	if ((angle > M_PI * 0.25) && (angle < 0.75 * M_PI))
		return (1);
	else if ((angle > M_PI * 1.25) && (angle < 1.75 * M_PI))
		return (1);
	return (0);
}

int				has_wall_at(float y, float x)
{
	int map_grid_index_x;
	int map_grid_index_y;

	if (x < 0 || x > (g_tile_size * g_map_col)
	|| y < 0 || y > (g_tile_size * g_map_row))
		return (1);
	map_grid_index_x = floor(x / g_tile_size);
	map_grid_index_y = floor(y / g_tile_size);
	if (map_grid_index_x >= g_map_col || map_grid_index_y >= g_map_row ||
	g_grid_array[map_grid_index_y][map_grid_index_x] == 1)
		return (1);
	else
		return (0);
}

void			update_sprite(void)
{
    float		olddirx;
	float		oldplanx;
	float		vectangle;

	olddirx = g_sprite.dirx;
	oldplanx = g_sprite.planx;
	vectangle = g_player.turn_direction * g_player.turn_speed;
	g_sprite.dirx = g_sprite.dirx * cos(vectangle) - g_sprite.diry *
		sin(vectangle);
	g_sprite.diry = olddirx * sin(vectangle) + g_sprite.diry * cos(vectangle);
	g_sprite.planx = g_sprite.planx * cos(vectangle) - g_sprite.plany *
		sin(vectangle);
	g_sprite.plany = oldplanx * sin(vectangle) + g_sprite.plany * cos(vectangle);
}

void			update_player_position(float x, float y)
{
    if (has_wall_at(y, x) != 1 )
	{
		g_player.x = x;
		g_player.y = y;
	}
}