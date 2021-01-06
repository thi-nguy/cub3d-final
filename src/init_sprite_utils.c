/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:11:49 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 11:12:47 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			get_position_sprite(t_sprite *sprite, int **map)
{
	int			i;
	int			j;
	int			id;

	id = 0;
	i = 0;
	while (i < g_map_row)
	{
		j = 0;
		while (j < g_map_col)
		{
			if (map[i][j] == 2)
			{
				sprite->x[id] = j * g_tile_size + g_tile_size / 2;
				sprite->y[id] = i * g_tile_size + g_tile_size / 2;
				sprite->distance[id] = 0;
				id++;
			}
			j++;
		}
		i++;
	}
}

voidi			init_vecteur_north(t_sprite *sprite)
{
	sprite->dirx = 0;
	sprite->diry = -1;
	sprite->planx = -0.6;
	sprite->plany = 0;
}

static void		init_vecteur(t_sprite *sprite, char player_position)
{
	if (player_position == 'E')
	{
		sprite->dirx = 1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = -0.6;
	}
	else if (player_position == 'S')
	{
		sprite->dirx = 0;
		sprite->diry = 1;
		sprite->planx = 0.6;
		sprite->plany = 0;
	}
	else if (player_position == 'W')
	{
		sprite->dirx = -1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = 0.6;
	}
	else if (player_position == 'N')
		init_vecteur_north(sprite);
}
