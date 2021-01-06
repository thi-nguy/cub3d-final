#include "cub3d.h"

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



