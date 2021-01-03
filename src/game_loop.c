# include "cub3d.h"

int init_image(void)
{
    if (!(g_image.mlx_ptr = mlx_new_image(g_mlx, g_window.width, g_window.height)))
    {
        ft_putstr_fd("Error\nCannot get image pointer.\n", 1);
        return (ERROR);
    }
    g_image.data_addr = mlx_get_data_addr(g_mlx, &g_image.bpp, &g_image.line_length, &g_image.endian);
    if (!(g_image.data_addr))
    {
        ft_putstr_fd("Error\nCannont get image data.\n", 1);
        return(ERROR);
    }
}

// void	my_mlx_put_pixel(int x, int y, int color)
// {
// 	int position;

// 	position = y * g_image.line_length + x * (g_image.bpp / 8); //caa put size_line va bpp nua
// 	*(unsigned int*)(g_image.data_addr + position) = color;
// }

// void	draw_grid(int x, int y, int x1, int y1, int tileColor)
// {
// 	int tmp_y;

// 	while (x < x1)
// 	{
// 		tmp_y = y;
// 		while (tmp_y < y1)
// 		{
// 			my_mlx_put_pixel(x, tmp_y, tileColor);
// 			tmp_y++;
// 		}
// 		x++;
// 	}
// }

// void	draw_map(int color_wall, int color_space, int color_sprite) 
// {
// 	int i;
// 	int j;
// 	int tileColor;
//     int x;
//     int y;
//     int tileX;
//     int tileY;
	
// 	i = 0;
// 	while (i < g_map_row)
// 	{
// 		y = i * g_tile_size * SIZE_MINI_MAP;
// 		tileY = y + g_tile_size * SIZE_MINI_MAP;
// 		j = 0;
// 		while (j < g_map_col)
// 		{
// 			x = j * g_tile_size * SIZE_MINI_MAP;
// 			tileX = x + g_tile_size * SIZE_MINI_MAP;
// 			if (g_grid_array[i][j] == 2)
// 				draw_grid(x, y, tileX, tileY, color_sprite);
// 			else
// 			{
// 				tileColor = (g_grid_array[i][j] != 0 ? color_wall : color_space);
// 				draw_grid(x, y, tileX, tileY, tileColor); // vẽ một ô grid
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }


// void draw_mini_map(void)
// {
//     draw_map(0Xaa5555, 0Xc1e2f1, 0X5175bc);
// 	// draw_player_rect(player.x, player.y, player.radius, player.radius);

// }

void	draw_ceiling(void)
{
	int i;
	int j;
	int	color;

	i = 0;
	j = 0;
	color = g_ceiling_color;
	while (i < (g_window.height / 2))
	{
		while (j < g_window.width)
		{
			g_image.data_addr[(i + 0) * g_window.width + (j + 0)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}


int				create_one_frame(t_info *info)
{
    if (init_image() == ERROR)
        return (free_memory(info, ERROR));
    // draw_mini_map();
	draw_ceiling();


   mlx_put_image_to_window(g_mlx, g_window.mlx_ptr, g_image.mlx_ptr, 0, 0);
   mlx_destroy_image(g_mlx, g_image.mlx_ptr);
   g_image.mlx_ptr = 0;
    
}

