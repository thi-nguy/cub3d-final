/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:41:17 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 11:51:05 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgb_int(char **tab)
{
	int red;
	int green;
	int blue;
	int color_int;

	red = ft_atoi(tab[0]);
	green = ft_atoi(tab[1]);
	blue = ft_atoi(tab[2]);
	if (red > 255 || green > 255 || blue > 255 || red < 0 ||
			green < 0 || blue < 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Color code is not in range [0,255].\n", 1);
		return (-1);
	}
	color_int = 65536 * red + 256 * green + blue;
	return (color_int);
}

int	parse_info(t_info *info)
{
	if (parse_resolution(&info->head_llist) == ERROR)
		return (free_memory(info, ERROR));
	if (parse_floor_color(&info->head_llist) == ERROR)
		return (free_memory(info, ERROR));
	if (parse_ceiling_color(&info->head_llist) == ERROR)
		return (free_memory(info, ERROR));
	if (parse_sprite_path(&info->head_llist) == ERROR)
		return (free_memory(info, ERROR));
	if (parse_no_path(&info->head_llist) == ERROR)
		return (free_memory(info, ERROR));
	if (parse_so_path(&info->head_llist) == ERROR)
		return (free_memory(info, ERROR));
	if (parse_we_path(&info->head_llist) == ERROR)
		return (free_memory(info, ERROR));
	if (parse_ea_path(&info->head_llist) == ERROR)
		return (free_memory(info, ERROR));
	return (SUCCESS);
}
