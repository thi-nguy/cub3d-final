/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:58:06 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 11:00:58 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		load_wall_texture_ptr(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		g_texture[i].mlx_ptr = mlx_xpm_file_to_image(g_mlx, g_texture[i].path,
				&g_texture[i].width, &g_texture[i].height);
		if (!g_texture[i].mlx_ptr)
		{
			ft_putstr_fd("Error\nCan not get xpm file.\n", 1);
			return (ERROR);
		}
		g_texture[i].data_addr = (int *)mlx_get_data_addr(g_texture[i].mlx_ptr,
				&g_texture[i].bpp, &g_texture[i].line_length,
				&g_texture[i].endian);
		if (!g_texture[i].data_addr)
		{
			printf("At position i = %d\n", i);
			ft_putstr_fd("Error\nCan not get data address from wall
					texture's path.\n", 1);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

void	get_global(t_info *info)
{
	g_map_row = info->map_row;
	g_map_col = info->map_col;
	g_texture[0].mlx_ptr = 0;
	g_wall_strip_width = 1;
	g_tile_size = g_window.width / g_map_col;
	g_num_rays = g_window.width / g_wall_strip_width;
	g_fov = (60 * (M_PI / 180));
}

float	get_rotation_angle(double angle)
{
	if (angle == 'N')
		return (1.5 * M_PI);
	else if (angle == 'W')
		return (M_PI);
	else if (angle == 'E')
		return (0);
	else if (angle == 'S')
		return (0.5 * M_PI);
}
