# include "cub3d.h"

int init_image(void)
{
    if (!(g_image.mlx_ptr = mlx_new_image(g_mlx, g_window.width, g_window.height)))
    {
        ft_putstr_fd("Error\nCannot get image pointer.\n", 1);
        return (ERROR);
    }
    g_image.data_addr = (int *)mlx_get_data_addr(g_image.mlx_ptr, &g_image.bpp, &g_image.line_length, &g_image.endian);
    if (!(g_image.data_addr))
    {
        ft_putstr_fd("Error\nCannont get image data.\n", 1);
        return(ERROR);
    }
    return (SUCCESS);
}

void	my_mlx_put_pixel(int x, int y, int color)
{
	g_image.data_addr[x * g_window.width + y] = color;
}

void	draw_grid(int x, int y, int x1, int y1, int tileColor)
{
	int tmp_y;

	while (x < x1)
	{
		tmp_y = y;
		while (tmp_y < y1)
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
			// if (g_grid_array[i][j] == 2)
			// 	my_mlx_put_pixel(x, y, tileColor);
			// else
			// {
			// 	tileColor = (g_grid_array[i][j] != 0 ? color_wall : color_space);
			// 	draw_grid(x, y, tileX, tileY, tileColor); // vẽ một ô grid
			// }
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

void	draw_player(int color)
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
			if (g_grid_array[i][j] == 'N' || g_grid_array[i][j] == 'S' ||g_grid_array[i][j] == 'W' ||g_grid_array[i][j] == 'E')
			    draw_grid(y, x, y + 5, x + 5, color);
			j++;
		}
		i++;
	}
}

void draw_mini_map(void)
{
    draw_map(0Xaa5555, 0Xc1e2f1);
    draw_sprite(0X5175bc);
	draw_player(0X2345bc);
    //draw_direction_line;

}

int				create_one_frame(t_info *info)
{
    if (init_image() == ERROR)
        return (free_memory(info, ERROR));
	draw_ceiling();
    draw_floor();
    draw_mini_map();


   mlx_put_image_to_window(g_mlx, g_window.mlx_ptr, g_image.mlx_ptr, 0, 0);
   mlx_destroy_image(g_mlx, g_image.mlx_ptr);
   g_image.mlx_ptr = 0;
    
}
