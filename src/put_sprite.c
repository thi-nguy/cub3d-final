#include "cub3d.h"

int		ft_spritevisible(int id, float sprite_size)
{
	float	spriteangle;
	float	spriteangle_end;
	float	wallspriteangle;
	float	fovsprite;

	spriteangle = fabs(ft_calculangle(&player, g_sprite.x[id],
				g_sprite.y[id]));
	spriteangle_end = fabs(ft_calculangle(&player, (g_sprite.x[id]
					+ sprite_size), (g_sprite.y[id] + sprite_size)));
	wallspriteangle = fabs(spriteangle_end - spriteangle);
	fovsprite = g_fov / 2 + wallspriteangle;
	if (spriteangle < fovsprite)
		return (1);
	return (0);
}

void		ft_zero(void)
{
	g_sprite.drawstartx = 0;
	g_sprite.drawendx = 0;
	g_sprite.drawstarty = 0;
	g_sprite.drawendy = 0;
	g_sprite.spritescreenx = 0;
}


void	ft_sortsprite()
{
	int			j;
	int			i;

	i = -1;
	while (i++ < g_sprite.nb_sprite)
	{
		j = i + 1;
		while (j < g_sprite.nb_sprite)
		{
			if (g_sprite.distance[j] > g_sprite.distance[i])
				ft_switch(&g_sprite, i, j);
			j++;
		}
	}
}


void			ft_spritedistance(void)
{
	int			id;

	id = 0;
	while (id < g_sprite.nb_sprite)
	{
		g_sprite.distance[id] = distance_between_points(player.x,
				player.y, g_sprite.x[id], g_sprite.y[id]);
		id++;
	}
}

void			put_sprite(void)
{
	float		distanceprojection;
	float		sprite_size;
	int			id;
	float		transformy;

	id = 0;
	ft_spritedistance();
	ft_sortsprite(g_sprite);
	while (id < g_sprite.nb_sprite)
	{
		distanceprojection = (g_window.width / 2) / tan(g_fov / 2);
		sprite_size = g_tile_size * 0.5 / g_sprite.distance[id] *
			distanceprojection;
		ft_zero();
		if (ft_spritevisible(id, sprite_size) == 1)
		{
			transformy = ft_gettransformy(&g_sprite, &player, id);
			ft_getstart(&g_sprite, sprite_size, transformy);
			ft_drawsprite(&g_sprite, transformy, sprite_size);
		}
		id++;
	}
}
