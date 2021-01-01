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

typedef struct s_wall_texture
{
	char *id;
	char *path;
	void *texture_ptr;
	int height;
	int width;
	int *texture;

}	t_wall_texture;

typedef struct s_player
{
	float x;
	float y;
	float width;// width, height of a rectangle
	float height;
	float view_arrow; //length of view arrow
	int		turnDirection; // -1 for left, +1 for right
	int		walkDirection; // -1 for backward, +1 forward
	float	rotationAngle;
	float	walkSpeed; // how fast going front back
	float	turnSpeed; //Moi lan an nut la cong them bao nhieu angle? how fast in angle per second we change per frame, here is 3 degree/frame
	int		radius;
}	t_player;

typedef struct		s_sprite
{
	int				nb_sprite;
	void			*ptr;
	int				width;
	int				height;
	int				*data_addr;
	float			*x;
	float			*y;
	float			*distance;
	float			*buffer;
	// float			diry;
	// float			dirx;
	// float			plany;
	// float			planx;
	// int				size_l;
	// float			angle;
	// int				bpp;
	// int				endian;
	// char			*path;
	// int				spritescreenx;
	// int				drawstarty;
	// int				drawendy;
	// int				drawstartx;
	// int				drawendx;
}					t_sprite;

#endif