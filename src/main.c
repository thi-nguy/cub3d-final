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
	exit(free_memory(info, SUCCESS));
	(void)key_code;
}

int		key_pressed(int key_code, t_info *info)
{
	if (key_code == ESC)
		exit(SUCCESS);
	else if (key_code == KEY_W)
		player.walk_direction = +1;
	else if (key_code == KEY_S)
		player.walk_direction = -1;
	else if (key_code == KEY_D || key_code == KEY_RIGHT)
		player.turn_direction = +1;
	else if (key_code == KEY_A || key_code == KEY_LEFT)
		player.turn_direction = -1;
	else if (key_code == TRANSLATION_RIGHT)
	{
		player.translation = 1;
		player.walk_direction = +1;
	}
	else if (key_code == TRANSLATION_LEFT)
	{
		player.translation = -1;
		player.walk_direction = -1;
	}
	return (0);
}

int		key_release(int key_code)
{
	if (key_code == KEY_W)
		player.walk_direction = 0;
	else if (key_code == KEY_S)
		player.walk_direction = 0;
	else if (key_code == KEY_A || key_code == KEY_LEFT)
		player.turn_direction = 0;
	else if (key_code == KEY_D || key_code == KEY_RIGHT)
		player.turn_direction = 0;
	else if (key_code == TRANSLATION_RIGHT || key_code == TRANSLATION_LEFT)
	{
		player.translation = 0;
		player.walk_direction = 0;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_info info;

	init_info(&info);
	init_global();
	check_argument(ac, av, &info.screenshoot);
	get_fd(av[1], &info);
	if (parse(&info) == ERROR)
		return (free_memory(&info, ERROR));
	if (init_mlx() == ERROR)
		return (free_memory(&info, ERROR));
	if (init_window(&info) == ERROR)
		return (free_memory(&info, ERROR));
	if (load_wall_texture_ptr() == ERROR)
		return (free_memory(&info, ERROR));
	get_global(&info);
	init_player(&info);
	if (init_sprite() == ERROR)
		return (free_memory(&info, ERROR));
	if (info.screenshoot == 1)
		create_one_frame(&info);
	else
		game_loop(&info);
	free_memory(&info, ERROR);
	return (0);
}
