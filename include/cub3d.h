/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:46:50 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/09/22 11:30:27 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#include "../libft/libft.h"
//----------- Open this on when compiling on Linux-----------
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
//-----------------------------------------------------------

#include "constant.h"
#include "struct.h"
#include "global.h"

void init_info(t_info* info);

void    check_argument(int ac, char** av, int* save);
int		check_format(char *av, char *format);
void    get_fd(char* arg, t_info* info);
int     parse(t_info* info);
int read_line_into_linked_list(t_list** head_llist, int fd);
int   free_memory(t_info* info, int return_code);

int parse_info(t_info* info);
int parse_resolution(t_list** lst);
t_list*  get_node(t_list** llist, char* item);
t_list* ft_lstfind(t_list*lst, char* item, int f(const char *, char *));
int lst_find_item(const char *content, char* x);
void   free_array(char** array, int len);
int check_number_of_element(char* line, int num);
int check_number_of_element_color(char* line, int num);
int parse_floor_color(t_list** lst);
int parse_ceiling_color(t_list** lst);
int get_rgb_int(char** tab);

int parse_sprite_path(t_list** lst);
int parse_NO_path(t_list** lst);

int parse_SO_path(t_list** lst);
int parse_WE_path(t_list** lst);
int parse_EA_path(t_list** lst);

int parse_map(t_info* info);
int get_row_column(t_list **lst, int *row, int *col);
int put_map_in_array(t_list **lst, int row, int col);

t_list*	get_first_line_map(t_list **lst);
int			skip_space(char *str);
int		line_is_map(char *line);
int get_size_node(t_list *lst);
int** alloc_memory(int row, int col);
int **copy_map_grid(int map_row, int map_col);
int check_copy_map_element_into_array(t_list *map_lst, int row, int col);
char    check_valid_element(char c);

int check_if_map_close(t_info *info);
int flood_fill(int **map_copy, int map_row, int map_col, int row, int col, int i);

void     get_player_position(t_info *info, int row, int col);

int init_mlx(void);
void  init_player(t_info *info);
void init_global(void);

void    put_wall_texture_into_array(void);
int  load_wall_texture_ptr(void);

void  init_g_wall_texture(void);
void  get_global(t_info *info);
float get_rotation_angle(double angle);

int  init_sprite(void);
int		count_sprite(int **map);
int		load_ptr_and_data_sprite(void);
void		get_position_sprite(t_sprite *sprite, int **map);
int	ft_mallocsprite(t_sprite *sprite);

int			init_window(t_info *info);

static void		draw_player_rect(int cor_x, int cor_y, int width, int height);



int init_image(void);
void draw_mini_map(void);
void	draw_map(int color_wall, int color_space);
void	draw_grid(int x, int y, int x1, int y1, int tileColor);
void	my_mlx_put_pixel(int x, int y, int color);

void	game_loop(t_info *info);
int create_one_frame(t_info *info);
int		close_window(int key_code, t_info *info);

int		key_release(int key_code);
int		key_pressed(int key_code, t_info *info);

void	draw_ceiling(void);
void	draw_floor(void);
void	draw_sprite(int color);
void	draw_player(int color);

#endif
