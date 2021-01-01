#include "cub3d.h"

int  load_wall_texture_ptr(t_wall_texture *texture)
{
   int i;
   int bpp;
	int size_line;
	int endian;

   i = 0;

   while (i < 4)
   {
      texture[i].texture_ptr = mlx_xpm_file_to_image(g_mlx_ptr, texture[i].path, &texture[i].width, &texture[i].height);
      if (!texture[i].texture_ptr)
      {
         ft_putstr_fd("Error\nCan not get xpm file.\n", 1);
         return (ERROR);
      }
      texture[i].texture = (int *)mlx_get_data_addr(texture[i].texture_ptr, &bpp, &size_line, &endian);
      if (!texture[i].texture)
      {
         printf("At position i = %d\n", i);
         ft_putstr_fd("Error\nCan not get data address from wall texture's path.\n", 1);
         return (ERROR);
      }
      i++;
   }
   return(SUCCESS);
}

void  get_global(t_info *info)
{
   g_map_row = info->map_row;
   g_map_col = info->map_col;
   g_wall_strip_width = 1;
   g_tile_size = g_window_width / g_map_col;
   g_num_rays = g_window_width / g_wall_strip_width;
   g_fov = (60 * (M_PI / 180));
}

float get_rotation_angle(double angle)
{
   if (angle == 'N')
		return (1.5 * M_PI);
	else if (angle == 'W')
		return (M_PI);
	else if (angle == 'E')
		return (0);
	else if (angle == 'S')
		return (0.5 * M_PI);
}