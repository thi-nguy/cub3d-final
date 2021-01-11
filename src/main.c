/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:13:00 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 11:18:15 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_window(int key_code, t_info *info)
{
	if (g_image.mlx_ptr)
	{
		mlx_destroy_image(g_mlx, g_image.mlx_ptr);
		g_image.mlx_ptr = 0;
	}
	exit(free_memory(info, SUCCESS));
	(void)key_code;
}

int		key_pressed(int key_code, t_info *info)
{
	if (key_code == ESC)
		exit(SUCCESS);
	else if (key_code == KEY_W)
		g_player.walk_direction = +1;
	else if (key_code == KEY_S)
		g_player.walk_direction = -1;
	else if (key_code == KEY_RIGHT)
		g_player.turn_direction = +1;
	else if (key_code == KEY_LEFT)
		g_player.turn_direction = -1;
	else if (key_code == KEY_D)
	{
		g_player.shift_right = 1;
		g_player.walk_direction = +1;
	}
	else if (key_code == KEY_A)
	{
		g_player.shift_right = -1;
		g_player.walk_direction = -1;
	}
	return (0);
}

int		key_release(int key_code)
{
	if (key_code == KEY_W)
		g_player.walk_direction = 0;
	else if (key_code == KEY_S)
		g_player.walk_direction = 0;
	else if (key_code == KEY_LEFT)
		g_player.turn_direction = 0;
	else if (key_code == KEY_RIGHT)
		g_player.turn_direction = 0;
	else if (key_code == KEY_A || key_code == KEY_D)
	{
		g_player.shift_right = 0;
		g_player.walk_direction = 0;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_info info;

	setup_info(&info);
	setup_global();
	check_argument(ac, av, &info.screenshoot);
	get_fd(av[1], &info);
	if (parse(&info) == ERROR)
		return (free_memory(&info, ERROR));
	if (init_mlx() == ERROR)
		return (free_memory(&info, ERROR));
	if (init_window(&info) == ERROR)
		return (free_memory(&info, ERROR));
	if (init_texture() == ERROR)
		return (free_memory(&info, ERROR));
	setup_player(&info);
	if (setup_sprite() == ERROR)
		return (free_memory(&info, ERROR));
	if (info.screenshoot == 1)
		create_one_frame(&info);
	else
		game_loop(&info);
	free_memory(&info, ERROR);
	return (0);
}
