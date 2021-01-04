#include "cub3d.h"

void	my_mlx_put_pixel(int x, int y, int color)
{
	g_image.data_addr[x * g_window.width + y] = color;
}

void	draw_grid(int x, int y, int x1, int y1, int tileColor)
{
	int tmp_y;

	while (x <= x1)
	{
		tmp_y = y;
		while (tmp_y <= y1)
		{
			my_mlx_put_pixel(x, tmp_y, tileColor);
			tmp_y++;
		}
		x++;
	}
}

void	draw_map(int color_wall, int color_space) 
{
	int i;
	int j;
	int tileColor;
    int x;
    int y;
    int tileX;
    int tileY;
	
	i = 0;
	while (i < g_map_row)
	{
		y = i * g_tile_size * SIZE_MINI_MAP;
		tileY = y + g_tile_size * SIZE_MINI_MAP;
		j = 0;
		while (j < g_map_col)
		{
			x = j * g_tile_size * SIZE_MINI_MAP;
			tileX = x + g_tile_size * SIZE_MINI_MAP;

            tileColor = (g_grid_array[i][j] != 1 ? color_space : color_wall);
            draw_grid(y, x, tileY, tileX, tileColor); // vẽ một ô grid
			j++;
		}
		i++;
	}
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

void draw_player(int color)
{
	float x_minimap;
	float y_minimap;

	x_minimap = player.x * SIZE_MINI_MAP;
	y_minimap = player.y * SIZE_MINI_MAP;

	draw_grid(y_minimap, x_minimap, y_minimap + player.height , x_minimap + player.width, color);
}

void		draw_line(int cor_y, int cor_x)
{
	float		i;
	int			x;
	int			y;
	int			longeur;

	longeur = 0;
	i = 0;
	x = 0;
	y = 0;
	while (i < player.rotaion_line_length)
	{
		if (&g_image.data_addr[(cor_y + y) * g_window.width +
		(cor_x + x)] < g_image.data_addr)
			return ;
		g_image.data_addr[(cor_y + y) * g_window.width + (cor_x + x)] = 0xff0000;
		x = cos(player.rotationAngle) * longeur;
		y = sin(player.rotationAngle) * longeur;
		longeur++;
		i++;
	}
}

void	draw_rotation_line(void)
{
	float x_minimap;
	float y_minimap;

	x_minimap = player.x * SIZE_MINI_MAP;
	y_minimap = player.y * SIZE_MINI_MAP;
	draw_line(y_minimap, x_minimap);
}

void draw_mini_map(void)
{
    draw_map(0Xaa5555, 0Xc1e2f1);
    draw_sprite(0X5175bc);
	draw_player(0X2345bc);
    draw_rotation_line();
}