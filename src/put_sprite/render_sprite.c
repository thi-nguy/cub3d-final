/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:10:21 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/20 21:38:25 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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



void	render_sprite(t_sprite *sprite, float transformy, float sprite_size)
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
	textureoffsetx = (int)(256 * (x - (-sprite_size / 2
					+ sprite->spritescreenx)) *
			sprite->width / sprite_size) / 256;
	distancefromtop = (y) * 256 - g_window.height * 128 + sprite_size * 128;
	textureoffsety = ((distancefromtop * sprite->height) / sprite_size) / 256;
	if (((textureoffsety * sprite->width) + textureoffsetx) < a)
		return ;
	color = sprite->data_addr[(textureoffsety * sprite->width)
		+ textureoffsetx];
	if (color > 0)
		g_image.data_addr[y * g_window.width + x] = color;
}
