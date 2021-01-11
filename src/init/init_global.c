/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:55:16 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 10:59:13 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_global(void)
{
	g_window.width = 0;
	g_window.height = 0;
	g_ceiling_color = 0;
	g_floor_color = 0;
	g_count_player = 0;
	g_sprite.path = NULL;
	g_we_path = NULL;
	g_ea_path = NULL;
	g_so_path = NULL;
	g_no_path = NULL;
	g_grid_array = NULL;
	g_texture[0].mlx_ptr = 0;
	g_wall_strip_width = 1;
	g_fov = (60 * (M_PI / 180));
}

int		init_mlx(void)
{
	void	*mlx_ptr;

	g_mlx = 0;
	if (!(mlx_ptr = mlx_init()))
	{
		ft_putstr_fd("Error\nCan not init mlx\n", 1);
		return (ERROR);
	}
	g_mlx = mlx_ptr;
	return (SUCCESS);
}

void	setup_info(t_info *info)
{
	info->fd = 0;
	info->map_col = 0;
	info->map_row = 0;
	info->screenshoot = 0;
	info->head_llist = NULL;
	info->player_start_x = -1;
	info->player_start_y = -1;
}

void	setup_player(t_info *info)
{
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
	g_player.walk_speed = 1;
	g_player.turn_speed = 3 * (M_PI / 180);
	g_player.x = g_tile_size * info->player_start_x + g_tile_size / 2;
	g_player.y = g_tile_size * info->player_start_y + g_tile_size / 2;
	g_player.rotation_angle = get_rotation_angle(info->player_start_angle);
	g_player.rotaion_line_length = 20;
	g_player.width = 5;
	g_player.height = 5;
	g_player.position = info->player_position;
}

int		init_window(t_info *info)
{
	int			screen_width;
	int			screen_height;
	void		*win_mlx;

	mlx_get_screen_size(g_mlx, &screen_width, &screen_height);
	if (g_window.width > screen_width)
		g_window.width = screen_width;
	if (g_window.height > screen_height)
		g_window.height = screen_height;
	win_mlx = 0;
	if (!info->screenshoot)
	{
		if (!(win_mlx = mlx_new_window(g_mlx, g_window.width,
						g_window.height, "3D")))
		{
			ft_putstr_fd("Error\nCannot open window\n", 1);
			return (ERROR);
		}
	}
	g_window.mlx_ptr = win_mlx;
	g_tile_size = g_window.width / g_map_col;
	g_num_rays = g_window.width / g_wall_strip_width;
	return (SUCCESS);
}
