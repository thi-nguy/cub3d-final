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


void	game_loop(t_info *info)
{
	int	key_code;

	key_code = 0;
   mlx_hook(g_window.mlx_ptr, 17, (1L<<17), &close_window, &info);
	mlx_hook(g_window.mlx_ptr, 2, (1L<<0), &key_pressed, &info);
	mlx_hook(g_window.mlx_ptr, 3, (1L<<1), &key_release, &key_code);
	mlx_loop_hook(g_mlx, &create_one_frame, &info);
	mlx_loop(g_mlx);
}




int     main(int ac, char** av)
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
   if(load_wall_texture_ptr() == ERROR)
      return (free_memory(&info, ERROR));
   get_global(&info);
   init_player(&info);
   if (init_sprite() == ERROR)
      return (free_memory(&info, ERROR));
   if(info.screenshoot == 1)
      create_one_frame(&info);
   else
      game_loop(&info);
   

   







   // printf("Player:\n");
   // // printf("radius:%i\n", player.radius);
   // printf("turnDirection:%i\n", player.turnDirection);
   // printf("walk_direction:%i\n", player.walk_direction);
   // printf("walkSpeeds:%f\n", player.walkSpeed);
   // printf("turnSpeed:%f\n", player.turnSpeed);
   // printf("x:%f\n", player.x);
   // printf("y:%f\n", player.y);
   // printf("rotationAngle:%f\n", player.rotationAngle);
   
   // Check
   // printf("Found Map is below:\n");
   // ft_lstiter(map_llist, printf);
   // ft_lstiter(info.head_llist, printf);
   // printf("Resolution is: W = %d, H = %d\n", g_window_width, g_window_height);
   // printf("Floor color is: %d\n", g_floor_color);
   // printf("Ceiling color is: %d\n", g_ceiling_color);
   // printf("Sprite's parth is: %s\n", g_sprite_path);
   // printf("NO's parth is: %s\n", g_NO_path );
   // printf("SO's parth is: %s\n", g_SO_path );
   // printf("WE's parth is: %s\n", g_WE_path );
   // // printf("EA's parth is: %s\n", g_EA_path );
   // printf("map_row is: %d\n", info.map_row);
   // printf("map_col is: %d\n", info.map_col);
   printf("player_start_x is: %i\n", info.player_start_x);
   printf("player_start_y is: %i\n", info.player_start_y);
   printf("player_start_angle is: %c\n", info.player_start_angle);

   
   // printf("screenshoot = %d\n", info.screenshoot);
   // int i = 0;

   // while (i < 4)
   // {
   //    printf("g_wall_texture[%i].texture_ptr = %p\n", i, g_wall_texture[i].texture_ptr);
   //    printf("id = %s\n", g_wall_texture[i].id);
   //    printf("height = %i\n", g_wall_texture[i].height);
   //    printf("w = %i\n", g_wall_texture[i].width);
   //    printf("texture = %i\n", g_wall_texture[i].texture);
   //    printf("\n");
   //    i++;
   // }

   // printf("g_map_row = %d\n", g_map_row);
   // printf("g_map_col = %d\n", g_map_col);
   // printf("g_wall_strip_width = %d\n", g_wall_strip_width);
   // printf("g_tile_size = %d\n", g_tile_size);
   // printf("g_num_rays = %f\n", g_num_rays);
   // printf("g_fov = %f\n", g_fov);
   // printf("g_window_width = %d\n", g_window_width);
   // printf("g_window_height = %d\n", g_window_height);

   printf("programm continues till this point.\n");
   
   free_memory(&info, ERROR);
   free(g_mlx);
   g_mlx = NULL;
   // Cần kiểm tra memory leak
   return (0);
}