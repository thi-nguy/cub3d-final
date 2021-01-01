#include "cub3d.h"

void init_global(void)
{
   g_window_width = 0;
   g_window_height = 0;
   g_ceiling_color = 0;
   g_floor_color = 0;
   g_count_player = 0;
   g_sprite_path = NULL;
   g_WE_path = NULL;
   g_EA_path = NULL;
   g_SO_path = NULL;
   g_NO_path = NULL;
   g_grid_array = NULL;
   
}

int  init_mlx(void)
{
   void  *mlx_ptr;

   g_mlx_ptr = 0;

   if (!(mlx_ptr = mlx_init()))
   {
      ft_putstr_fd("Error\nCan not init mlx\n", 1);
      return (ERROR);
   }
   g_mlx_ptr = mlx_ptr;
   return (SUCCESS);
}

void init_info(t_info* info)
{
   info->fd = 0;
   info->map_col = 0;
   info->map_row = 0;
   info->screenshoot = 0;
   info->head_llist = NULL;
   info->player_start_x = -1;
   info->player_start_y = -1;
}

void  init_player(t_info *info)
{
   player.radius = 4;
   player.turnDirection = 0;
   player.walkDirection = 0;
   player.walkSpeed = 1;
   player.turnSpeed = 3 * (M_PI / 180);
   player.x = g_tile_size * info->player_start_x + g_tile_size / 2; // why?
   player.y = g_tile_size * info->player_start_y + g_tile_size / 2; // why?
   player.rotationAngle = get_rotation_angle(info->player_start_angle);
}