#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_info
{
    t_list* head_llist;
    int screenshoot;
    int fd;
	int map_row;
	int map_col;
	int player_start_x;
	int player_start_y;
	int player_start_angle;
} t_info;

typedef struct s_window
{
	void *mlx_ptr;
	int width;
	int height;

} t_window;

typedef struct s_wall_texture
{
	char *id;
	char *path;
	void *mlx_ptr;
	char *data_addr;
	int width;
	int height;
	int				bpp;
	int				endian;
	int				line_length;
}	t_wall_texture;



typedef struct s_player
{
	float x;
	float y;
	float width;// width, height of the rectangle player
	float height;
	float rotaion_line_length; //length of rotation line
	int		turnDirection; // -1 for left, +1 for right
	int		walkDirection; // -1 for backward, +1 forward
	float	rotationAngle;
	float	walkSpeed; // how fast going front back
	float	turnSpeed; //Moi lan an nut la cong them bao nhieu angle? how fast in angle per second we change per frame, here is 3 degree/frame
	// int		radius;
}	t_player;

typedef struct		s_sprite
{
	int				nb_sprite;
	char			*path;
	void			*mlx_ptr;
	char			*data_addr;
	int				bpp;
	int				endian;
	int				line_length;
	int				width;
	int				height;

	float			*x;
	float			*y;
	float			*distance;
	float			*buffer;
	// float			diry;
	// float			dirx;
	// float			plany;
	// float			planx;
	// float			angle;
	// char			*path;
	// int				spritescreenx;
	// int				drawstarty;
	// int				drawendy;
	// int				drawstartx;
	// int				drawendx;
}					t_sprite;

typedef struct		s_image
{
	void			*mlx_ptr;
	int				*data_addr;
	int				bpp;
	int				endian;
	int				line_length;
	// int				width;
	// int				height;
}					t_image;

#endif