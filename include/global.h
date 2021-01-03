#ifndef GLOBAL_H
# define GLOBAL_H

void    *g_mlx;
t_window g_window;
t_wall_texture g_texture[4];
t_player player;
t_sprite g_sprite;
t_image g_image;

int             g_floor_color;
int             g_ceiling_color;
char*           g_NO_path;
char*           g_SO_path;
char*           g_WE_path;
char*           g_EA_path;
int     g_map_row;
int     g_map_col;
int     g_wall_strip_width;
int     g_tile_size;
float     g_num_rays;
float     g_fov;
int **g_grid_array;
int g_count_player;

#endif

