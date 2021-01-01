#include "cub3d.h"

int flood_fill(int **map_copy, int map_row, int map_col, int row, int col, int i)
{
    if (row < 0 || row >= map_row || col < 0 || col >= map_col) //.|| map_copy[row][col] == 2|| map_copy[row][col] == 'N'|| map_copy[row][col] == 'S'|| map_copy[row][col] == 'E'|| map_copy[row][col] == 'W')
		return (i);
	else if (map_copy[row][col] == 1)
		return (0);
    else if (map_copy[row][col] == 43) //space
        return (WALL_ERROR);
	map_copy[row][col] = 1;
	// return (flood_fill(map_copy, map_row, map_col, row - 1, col - 1, 0) +
	// 		flood_fill(map_copy, map_row, map_col, row - 1, col + 1, 0) +
	// 		flood_fill(map_copy, map_row, map_col, row + 1, col - 1, 0) +
	// 		flood_fill(map_copy, map_row, map_col, row + 1, col + 1, 0) +
	return(flood_fill(map_copy, map_row, map_col, row - 1, col, 1) +
			flood_fill(map_copy, map_row, map_col, row + 1, col, 1) +
			flood_fill(map_copy, map_row, map_col, row, col - 1, 1) +
			flood_fill(map_copy, map_row, map_col, row, col + 1, 1));
}

int check_if_map_close(t_info *info)
{
    int borken_wall;
    int **tmp;

    tmp = copy_map_grid(info->map_row, info->map_col); //free sau day
    borken_wall = 0;
    borken_wall = flood_fill(tmp, info->map_row, info->map_col, info->player_start_x, info->player_start_y, 1);
    free_array((char**)tmp, info->map_row);
    tmp = NULL;
    if(borken_wall > 0)
    {
        ft_putstr_fd("Error\nMap is not surrounded by walls.\n", 1);
        return (ERROR);
    }
    else if (borken_wall < 0)
    {
        ft_putstr_fd("Error.\nInside map has empty space.\n", 1);
        return (ERROR);
    }
    return (SUCCESS);
}
