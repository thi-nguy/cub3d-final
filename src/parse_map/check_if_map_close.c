/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:47:37 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 09:54:28 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(int **map_copy, int row, int col)
{
	if (row < 0 || row >= g_map_row || col < 0 || col >= g_map_col)
		return (1);
	else if (map_copy[row][col] == 1)
		return (0);
	else if (map_copy[row][col] == 43)
		return (WALL_ERROR);
	map_copy[row][col] = 1;
	return (flood_fill(map_copy, row - 1, col) +
			flood_fill(map_copy, row + 1, col) +
			flood_fill(map_copy, row, col - 1) +
			flood_fill(map_copy, row, col + 1));
}

int	check_if_map_close(t_info *info)
{
	int borken_wall;
	int **tmp;

	tmp = copy_map_grid(info->map_row, info->map_col);
	borken_wall = 0;
	borken_wall = flood_fill(tmp, info->player_start_x, info->player_start_y);
	free_array((char**)tmp, info->map_row);
	tmp = NULL;
	if (borken_wall > 0)
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
