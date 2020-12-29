#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_info
{
	// int window_w;
	// int window_h;
	// int num_rows;
	// int num_cols;
	// char **map;
	// char *north_texture;
	// char *south_texture;
	// char *west_texture;
	// char *east_texture;
	// char *sprite_texture;
	// int floor_color;
	// int ceiling_color;
	// char	player_dir;
	// int	player_x0;
	// int player_y0;
    t_list* head_llist;
    int screenshoot;
    int fd;
	int map_row;
	int map_col;
	int player_start_x;
	int player_start_y;
	double player_start_angle;
} t_info;


// typedef struct s_graphic 
// {
//   void *mlx;
//   void *window;
// } t_graphic;

// typedef struct s_grid
// {
// 	int	x;
// 	int y;
// 	int tileX;
// 	int tileY;
// }	t_grid;


// typedef struct s_img_cub3d
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_img_cub3d;

// typedef struct s_move
// {
// 	int		esc;
// 	int		forward;
// 	int		retreat;
// 	int		left;
// 	int		right;
// 	int		turn_left;
// 	int		turn_right;
// 	int 	sprint;
// 	int		texture;
// }			t_move;

// typedef struct s_player
// {
// 	int x;
// 	int y;
// 	int w;// width, height of player
// 	int h;
// 	int ray_length;
// 	int		turnDirection; // -1 for left, +1 for right
// 	int		walkDirection; // -1 for backward, +1 forward
// 	float	rotationAngle;
// 	float	walkSpeed; // how fast going front back
// 	float	rotationSpeed; // how many degree we change per frame, here is 3 degree/frame
// }	t_player;


// typedef struct s_all
// {
// 	t_graphic graphic;
// 	t_img_cub3d	img;
// 	t_grid	grid;
// 	t_info	info;
// 	t_player player;
// 	t_move		move;
// 	int	screenshoot; // = 0 if not save, 1 if '--save'
	
// }	t_all;

#endif