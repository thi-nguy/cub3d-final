/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:22:42 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/05 18:33:31 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

void			*g_mlx;
t_window		g_window;
t_wall_texture	g_texture[4];
t_player		g_player;
t_sprite		g_sprite;
t_image			g_image;
int				g_floor_color;
int				g_ceiling_color;
char			*g_no_path;
char			*g_so_path;
char			*g_we_path;
char			*g_ea_path;
int				g_map_row;
int				g_map_col;
int				g_wall_strip_width;
int				g_tile_size;
float			g_num_rays;
float			g_fov;
int				**g_grid_array;
int				g_count_player;
t_ray			g_ray;

#endif
