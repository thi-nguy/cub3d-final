/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:01:09 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 11:11:33 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				load_ptr_and_data_sprite(void)
{
	g_sprite.mlx_ptr = mlx_xpm_file_to_image(g_mlx, g_sprite.path,
			&g_sprite.width, &g_sprite.height);
	if (!g_sprite.mlx_ptr)
	{
		ft_putstr_fd("Error\nCannot get pointer to sprite's texture\n", 1);
		return (ERROR);
	}
	g_sprite.data_addr = (int *)mlx_get_data_addr(g_sprite.mlx_ptr,
			&g_sprite.bpp, &g_sprite.line_length, &g_sprite.endian);
	if (!g_sprite.data_addr)
	{
		ft_putstr_fd("Error\nCannot get data address of sprite's texture\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

static	void	put_to_zero(t_sprite *sprite)
{
	sprite->angle = 0;
	sprite->mlx_ptr = 0;
	sprite->data_addr = 0;
	sprite->bpp = 0;
	sprite->endian = 0;
	sprite->line_length = 0;
	sprite->width = 0;
	sprite->height = 0;
}

int				ft_mallocsprite(t_sprite *sprite)
{
	if (!(sprite->x = malloc(sizeof(float) * sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", 1);
		return (ERROR);
	}
	if (!(sprite->y = malloc(sizeof(float) * sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", 1);
		return (ERROR);
	}
	if (!(sprite->distance = (float *)malloc(sizeof(float) *
					sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", 1);
		return (ERROR);
	}
	if (!(sprite->buffer = malloc(sizeof(float) * g_window.width)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", 1);
		return (ERROR);
	}
	ft_bzero(sprite->buffer, sizeof(float) * g_window.width);
	return (SUCCESS);
}

int				count_sprite(int **map)
{
	int	i;
	int	j;
	int	nb_sprite;

	i = 0;
	nb_sprite = 0;
	while (i < g_map_row)
	{
		j = 0;
		while (j < g_map_col)
		{
			if (map[i][j] == 2)
				nb_sprite++;
			j++;
		}
		i++;
	}
	return (nb_sprite);
}

int				init_sprite(void)
{
	g_sprite.nb_sprite = count_sprite(g_grid_array);
	if (g_sprite.nb_sprite <= 0)
	{
		ft_putstr_fd("Error\nThere is no sprite in the map.\n", 1);
		return (ERROR);
	}
	if (ft_mallocsprite(&g_sprite) == ERROR)
		return (ERROR);
	put_to_zero(&g_sprite);
	if (load_ptr_and_data_sprite() == ERROR)
		return (ERROR);
	get_position_sprite(&g_sprite, g_grid_array);
	init_vecteur(&g_sprite, g_player.position);
	return (SUCCESS);
}
