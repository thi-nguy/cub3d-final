/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:58:06 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 15:32:07 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_texture(void)
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
			ft_putstr_fd("Error\nCan't get data from texture path.\n", 1);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
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
