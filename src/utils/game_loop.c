/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:39:24 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 11:15:23 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	draw_floor(void)
{
	int i;
	int j;
	int	color;

	i = g_window.height / 2;
	j = 0;
	color = g_floor_color;
	while (i < (g_window.height))
	{
		while (j < g_window.width)
		{
			g_image.data_addr[i * g_window.width + j] = color;
			j++;
		}
		j = 0;
		i++;
	}
}

int		init_image(void)
{
	if (!(g_image.mlx_ptr = mlx_new_image(g_mlx, g_window.width,
					g_window.height)))
	{
		ft_putstr_fd("Error\nCannot get image pointer.\n", 1);
		return (ERROR);
	}
	g_image.data_addr = (int *)mlx_get_data_addr(g_image.mlx_ptr,
			&g_image.bpp, &g_image.line_length, &g_image.endian);
	if (!(g_image.data_addr))
	{
		ft_putstr_fd("Error\nCannont get image data.\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

int		create_one_frame(t_info *info)
{
	if (init_image() == ERROR)
		return (free_memory(info, ERROR));
	move_player();
	draw_ceiling();
	draw_floor();
	cast_rays();
	draw_mini_map();
	put_sprite();
	if (info->screenshoot == 1)
		bmp_exporter("my_screenshoot.bmp");
	else
	{
		mlx_put_image_to_window(g_mlx, g_window.mlx_ptr, g_image.mlx_ptr, 0, 0);
		mlx_destroy_image(g_mlx, g_image.mlx_ptr);
		g_image.mlx_ptr = 0;
	}
}

void	game_loop(t_info *info)
{
	int	key_code;

	key_code = 0;
	mlx_hook(g_window.mlx_ptr, 17, (1<<12), &close_window, &info);
	mlx_hook(g_window.mlx_ptr, 2, (1L << 0), &key_pressed, &info);
	mlx_hook(g_window.mlx_ptr, 3, (1L << 1), &key_release, &key_code);
	mlx_loop_hook(g_mlx, &create_one_frame, &info);
	mlx_loop(g_mlx);
}
