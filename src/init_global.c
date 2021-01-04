#include "cub3d.h"

void init_global(void)
{
   g_window.width = 0;
   g_window.height = 0;
   g_ceiling_color = 0;
   g_floor_color = 0;
   g_count_player = 0;
   g_sprite.path = NULL;
   g_WE_path = NULL;
   g_EA_path = NULL;
   g_SO_path = NULL;
   g_NO_path = NULL;
   g_grid_array = NULL;
   
}

int  init_mlx(void)
{
   void  *mlx_ptr;

   g_mlx = 0;

   if (!(mlx_ptr = mlx_init()))
   {
      ft_putstr_fd("Error\nCan not init mlx\n", 1);
      return (ERROR);
   }
   g_mlx = mlx_ptr;
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
   // player.radius = 4;
   player.turnDirection = 0;
   player.walkDirection = 0;
   player.walkSpeed = 1;
   player.turnSpeed = 3 * (M_PI / 180);
   player.x = g_tile_size * info->player_start_x;
   player.y = g_tile_size * info->player_start_y;
   player.rotationAngle = get_rotation_angle(info->player_start_angle);
   player.rotaion_line_length = 20;
   player.width = 5;
   player.height = 5;
}

int			init_window(t_info *info)
{
	int			screen_width;
	int			screen_height;
	void		*win_mlx;

	mlx_get_screen_size(g_mlx, &screen_width, &screen_height); //Get size cua screen vao width va height
	if (g_window.width > screen_width)
		g_window.width = screen_width;
	if (g_window.height > screen_height)
		g_window.height = screen_height;
	win_mlx = 0;
	if (!info->screenshoot)
	{
		if (!(win_mlx = mlx_new_window(g_mlx, g_window.width, g_window.height, "3D")))
		{
			ft_putstr_fd("Error\nCannot open window\n", 1);
         return (ERROR);
		}
	}
   g_window.mlx_ptr = win_mlx;
	return (SUCCESS);
}