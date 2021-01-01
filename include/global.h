#ifndef GLOBAL_H
# define GLOBAL_H


int				g_window_width;
int				g_window_height;
int             g_floor_color;
int             g_ceiling_color;
char*           g_sprite_path;
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
void    *g_mlx_ptr;

t_player player;
t_sprite sprite;
t_wall_texture g_wall_texture[4];
#endif

