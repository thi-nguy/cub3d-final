#include "cub3d.h"

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
   if(load_wall_texture_ptr(g_wall_texture) == ERROR)
      return (free_memory(&info, ERROR));
   get_global(&info);
   init_player(&info);
   if (init_sprite() == ERROR)
      return (free_memory(&info, ERROR));

   printf("Player:\n");
   printf("radius:%i\n", player.radius);
   printf("turnDirection:%i\n", player.turnDirection);
   printf("walkDirection:%i\n", player.walkDirection);
   printf("walkSpeeds:%f\n", player.walkSpeed);
   printf("turnSpeed:%f\n", player.turnSpeed);
   printf("x:%f\n", player.x);
   printf("y:%f\n", player.y);
   printf("rotationAngle:%f\n", player.rotationAngle);
   
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
   free(g_mlx_ptr);
   g_mlx_ptr = NULL;
   // Cần kiểm tra memory leak
   return (0);
}