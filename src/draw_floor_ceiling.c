/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:06:59 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 10:07:12 by thi-nguy         ###   ########.fr       */
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
