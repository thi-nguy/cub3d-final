#include "cub3d.h"

int has_wall_at(float x, float y)
{
    int map_grid_index_x;
    int map_grid_index_y;

    if (x < 0 || x > g_window.width || y < 0 || y > g_window.height)
        return (1);
    map_grid_index_x = floor(x / g_tile_size);
    map_grid_index_y = floor (y / g_tile_size);
    return (g_grid_array[map_grid_index_y][map_grid_index_x] == 1);
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

    //Can tuong tac voi sprite

    if (!has_wall_at(new_player_x, new_player_y))
    {
        player.x = new_player_x;
        player.y = new_player_y;
    }

}
