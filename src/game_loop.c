# include "cub3d.h"

int init_image(void)
{
    if (!(g_image.mlx_ptr = mlx_new_image(g_mlx, g_window.width, g_window.height)))
    {
        ft_putstr_fd("Error\nCannot get image pointer.\n", 1);
        return (ERROR);
    }
    g_image.data_addr = (int *)mlx_get_data_addr(g_image.mlx_ptr, &g_image.bpp, &g_image.line_length, &g_image.endian);
    if (!(g_image.data_addr))
    {
        ft_putstr_fd("Error\nCannont get image data.\n", 1);
        return(ERROR);
    }
    return (SUCCESS);
}

void move_player(void)
{
    float move_step;
    float new_player_x;
    float new_player_y;

    player.rotationAngle += player.turnDirection * player.turnSpeed;
    move_step = player.walkDirection * player.walkSpeed;
    new_player_x = player.x + cos(player.rotationAngle) * move_step;
    new_player_y = player.y + sin(player.rotationAngle) * move_step;

    player.x = new_player_x;
    player.y = new_player_y;

// Wall collision


}




int				create_one_frame(t_info *info)
{
    if (init_image() == ERROR)
        return (free_memory(info, ERROR));
	draw_ceiling();
    draw_floor();
    move_player();

    draw_mini_map();


   mlx_put_image_to_window(g_mlx, g_window.mlx_ptr, g_image.mlx_ptr, 0, 0);
   mlx_destroy_image(g_mlx, g_image.mlx_ptr);
   g_image.mlx_ptr = 0;
    
}
