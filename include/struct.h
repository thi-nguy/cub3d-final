/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:33:41 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/05 18:45:45 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_info
{
	t_list			*head_llist;
	int				screenshoot;
	int				fd;
	int				map_row;
	int				map_col;
	int				player_start_x;
	int				player_start_y;
	int				player_start_angle;
	char			player_position;
}					t_info;

typedef struct		s_window
{
	void			*mlx_ptr;
	int				width;
	int				height;
}					t_window;

typedef struct		s_wall_texture
{
	char			*path;
	void			*mlx_ptr;
	int				*data_addr;
	int				width;
	int				height;
	int				bpp;
	int				endian;
	int				line_length;
}					t_wall_texture;

typedef struct		s_player
{
	float			x;
	float			y;
	float			width;
	float			height;
	float			rotaion_line_length;
	int				turn_direction;
	int				walk_direction;
	float			rotation_angle;
	float			walk_speed;
	float			turn_speed;
	char			position;
	int				translation;
	float			angle;
}					t_player;

typedef struct		s_sprite
{
	int				nb_sprite;
	char			*path;
	void			*mlx_ptr;
	int				*data_addr;
	int				bpp;
	int				endian;
	int				line_length;
	int				width;
	int				height;
	float			*x;
	float			*y;
	float			*distance;
	float			*buffer;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
	float			diry;
	float			dirx;
	float			plany;
	float			planx;
	float			angle;
	int				spritescreenx;
}					t_sprite;

typedef struct		s_image
{
	void			*mlx_ptr;
	int				*data_addr;
	int				bpp;
	int				endian;
	int				line_length;
}					t_image;

typedef struct		s_ray
{
	float			ray_angle;
	float			wall_hit_x;
	float			wall_hit_y;
	int				wall_hit_vertical;
	float			distance;
	int				is_ray_facing_up;
	int				is_ray_facing_down;
	int				is_ray_facing_left;
	int				is_ray_facing_right;
	int				wall_hit_content;
	float			y_intercept;
	float			x_intercept;
	float			x_step;
	float			y_step;
	float			horz_wall_hit_y;
	float			horz_wall_hit_x;
	int				found_horz_wall_hit;
	float			x_to_check;
	float			y_to_check;
	float			vert_wall_hit_y;
	float			vert_wall_hit_x;
	int				found_vert_wall_hit;
	float			was_hit_vertical;
}					t_ray;

typedef struct		s_wall
{
	float			correct_wall_distance;
	float			distance_projection_plane;
	int				wall_strip_height;
	int				wall_top;
	int				wall_bottom;
}					t_wall;

typedef struct		s_bmp_file
{
	char			byte_type[2];
	unsigned int	byte_size;
	unsigned int	byte_reserved;
	unsigned int	byte_offset;
	unsigned		header_size;
	int				image_width;
	int				image_height;
	unsigned short	color_planes;
	unsigned short	bits_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	int				bits_xpels_per_meter;
	int				bits_ypels_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}					t_bmp_file;

#endif
