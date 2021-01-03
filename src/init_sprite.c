#include "cub3d.h"

int	ft_mallocsprite(t_sprite *sprite)
{
	if (!(sprite->x = malloc(sizeof(float) * sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", 1);
		return(ERROR);
	}
	if (!(sprite->y = malloc(sizeof(float) * sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", 1);
		return(ERROR);
	}
	if (!(sprite->distance = (float *)malloc(sizeof(float) *
	sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", 1);
		return(ERROR);
	}
	if (!(sprite->buffer = malloc(sizeof(float) * g_window.width)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", 1);
		return(ERROR);
	}
	ft_bzero(sprite->buffer, sizeof(float) * g_window.width);
   return (SUCCESS);
}


int		count_sprite(int **map)
{
	int	i;
	int	j;
	int	nb_sprite;

	i = 0;
	nb_sprite = 0;
	while (i < g_map_row)
	{
		j = 0;
		while (j < g_map_col)
		{
			if (map[i][j] == 2)
				nb_sprite++;
			j++;
		}
      i++;
	}
	return (nb_sprite);
}

void		get_position_sprite(t_sprite *sprite, int **map)
{
	int			i;
	int			j;
	int			id;

	id = 0;
	i = 0;
	while (i < g_map_row)
	{
		j = 0;
		while (j < g_map_col)
		{
			if (map[i][j] == 2)
			{
				sprite->x[id] = j * g_tile_size + g_tile_size / 2;
				sprite->y[id] = i * g_tile_size + g_tile_size / 2;
				sprite->distance[id] = 0;
				id++;
			}
			j++;
		}
      i++;
	}
}

int		load_ptr_and_data_sprite(void)
{
	g_sprite.mlx_ptr = mlx_xpm_file_to_image(g_mlx, g_sprite.path, &g_sprite.width, &g_sprite.height);
	if (!g_sprite.mlx_ptr)
	{
		ft_putstr_fd("Error\nCannot get pointer to file of sprite's texture\n", 1);
		return (ERROR);
	}
	g_sprite.data_addr = mlx_get_data_addr(g_sprite.mlx_ptr, &g_sprite.bpp, &g_sprite.line_length, &g_sprite.endian); //tai sao chuyen (int*) o day?
	if (!g_sprite.data_addr)
	{
		ft_putstr_fd("Error\nCannot get data address of sprite's texture\n", 1);
		return( ERROR);
	}
   return (SUCCESS);
}

int  init_sprite(void)
{
   g_sprite.nb_sprite = count_sprite(g_grid_array);
   if (g_sprite.nb_sprite <= 0)
   {
      ft_putstr_fd("Error\nThere is no sprite in the map.\n", 1);
      return (ERROR);
   }
   if (ft_mallocsprite(&g_sprite) == ERROR)
      return (ERROR);
   if (load_ptr_and_data_sprite() == ERROR)
      return (ERROR);
   get_position_sprite(&g_sprite, g_grid_array);
   return (SUCCESS);
}