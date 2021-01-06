/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:33:41 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 10:35:10 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_put_pixel(int x, int y, int color)
{
	g_image.data_addr[x * g_window.width + y] = color;
}

void	draw_grid(int x, int y, int x1, int y1, int tilecolor)
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

void	draw_line(int cor_y, int cor_x)
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
		g_image.data_addr[(cor_y + y) * g_window.width +
			(cor_x + x)] = 0xff0000;
		x = cos(player.rotation_angle) * longeur;
		y = sin(player.rotation_angle) * longeur;
		longeur++;
		i++;
	}
}
