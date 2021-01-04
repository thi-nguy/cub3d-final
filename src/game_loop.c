# include "cub3d.h"

int init_image(void)
{
    if (!(g_image.mlx_ptr = mlx_new_image(g_mlx, g_window.width, g_window.height)))
    {
        ft_putstr_fd("Error\nCannot get image pointer.\n", 1);
        return (ERROR);
    }
    g_image.data_addr = (int *)mlx_get_data_addr(g_image.mlx_ptr, &g_image.bpp, &g_image.line_length, &g_image.endian);
    if (!(g_image.data_addr))
    {
        ft_putstr_fd("Error\nCannont get image data.\n", 1);
        return(ERROR);
    }
    return (SUCCESS);
}

float	ft_gettransformy(t_sprite *sprite, t_player *player, int id)
{
	float		spritex;
	float		spritey;
	float		invdet;
	float		transformx;
	float		transformy;

	spritex = sprite->x[id] - player->x;
	spritey = sprite->y[id] - player->y;
	invdet = 1.0 / (sprite->planx * sprite->diry -
	sprite->dirx * sprite->plany);
	transformx = invdet * (sprite->diry * spritex - sprite->dirx * spritey);
	transformy = invdet * (-sprite->plany * spritex + sprite->planx * spritey);
	sprite->spritescreenx = (int)((g_window.width / 2) *
	(1 + -transformx / transformy));
	return (transformy);
}


static void		ft_zero(void)
{
	g_sprite.drawstartx = 0;
	g_sprite.drawendx = 0;
	g_sprite.drawstarty = 0;
	g_sprite.drawendy = 0;
	g_sprite.spritescreenx = 0;
}

static void		ft_switch(t_sprite *sprite, int i, int j)
{
	float		temp_dist;
	float		temp_y;
	float		temp_x;

	temp_dist = sprite->distance[j];
	temp_x = sprite->x[j];
	temp_y = sprite->y[j];
	sprite->distance[j] = sprite->distance[i];
	sprite->x[j] = sprite->x[i];
	sprite->y[j] = sprite->y[i];
	sprite->distance[i] = temp_dist;
	sprite->x[i] = temp_x;
	sprite->y[i] = temp_y;
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

float	ft_calculangle(t_player *player, float x, float y)
{
	float	vectx;
	float	vecty;
	float	playertospriteangle;
	float	spriteangle;
	float	playerangle;

	vectx = x - player->x;
	vecty = y - player->y;
	playertospriteangle = atan2(vecty, vectx);
	playerangle = normalize_angle(player->rotationAngle);
	spriteangle = playerangle - playertospriteangle;
	if (spriteangle < -3.14159)
		spriteangle += 2.0 * 3.14159;
	if (spriteangle > 3.14159)
		spriteangle -= 2.0 * 3.14159;
	spriteangle = fabs(spriteangle);
	return (spriteangle);
}


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

void	ft_puttexture(t_sprite *sprite, int x, int y, float sprite_size)
{
	int	textureoffsetx;
	int	distancefromtop;
	int	textureoffsety;
	int	color;
	int	a;

	a = sizeof(sprite->data_addr);
	textureoffsetx = (int)(256 * (x - (-sprite_size / 2 +
	sprite->spritescreenx)) * sprite->width / sprite_size) / 256;
	distancefromtop = (y) * 256 - g_window.height * 128 + sprite_size * 128;
	textureoffsety = ((distancefromtop * sprite->height) / sprite_size) / 256;
	if (((textureoffsety * sprite->width) + textureoffsetx) < a)
		return ;
	color = sprite->data_addr[(textureoffsety * sprite->width) + textureoffsetx];
	if (color != 0x000000)
		g_image.data_addr[y * g_window.width + x] = color;
}

void	ft_drawsprite(t_sprite *sprite, float transformy, float sprite_size)
{
	int	y;
	int	x;

	x = sprite->drawstartx;
	while (x < sprite->drawendx)
	{
		if (transformy > 0 && x > 0 && x < g_window.width &&
		transformy < sprite->buffer[x])
		{
			y = sprite->drawstarty;
			while (y < sprite->drawendy)
			{
				ft_puttexture(sprite, x, y, sprite_size);
				y++;
			}
		}
		x++;
	}
}

void	ft_getstart(t_sprite *sprite, float sprite_size, float transformy)
{
	int	spriteheight;
	int	spritewidth;

	spritewidth = sprite_size;
	sprite->drawstartx = -spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= g_window.width)
		sprite->drawendx = g_window.width - 1;
	spriteheight = sprite_size;
	sprite->drawstarty = -spriteheight / 2 + g_window.height / 2;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = spriteheight / 2 + g_window.height / 2;
	if (sprite->drawendy >= g_window.height)
		sprite->drawendy = g_window.height - 1;
	(void)sprite_size;
	(void)transformy;
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



int				create_one_frame(t_info *info)
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
