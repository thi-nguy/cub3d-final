/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:43:58 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/05 18:22:15 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "constant.h"
# include "struct.h"
# include "global.h"

void		setup_info(t_info *info);
void		check_argument(int ac, char **av, int *save);
void		check_extension(char **av);
int			check_format(char *av, char *format);
void		get_fd(char *arg, t_info *info);
int			parse(t_info *info);
int			read_line_into_linked_list(t_list **head_llist, int fd);
int			free_memory(t_info *info, int return_code);
int			parse_info(t_info *info);
int			parse_resolution(t_list **lst);
t_list		*get_node(t_list **llist, char *item);
t_list		*ft_lstfind(t_list *lst, char *item, int f(const char *, char *));
int			lst_find_item(const char *content, char *x);
void		free_array(char **array, int len);
int			check_number_of_element(char *line, int num);
int			check_number_of_element_color(char *line, int num);
int			parse_floor_color(t_list **lst);
int			parse_ceiling_color(t_list **lst);
int			get_rgb_int(char **tab);
int			parse_sprite_path(t_list **lst);
int			parse_no_path(t_list **lst);
int			parse_so_path(t_list **lst);
int			parse_we_path(t_list **lst);
int			parse_ea_path(t_list **lst);
int			parse_map(t_info *info);
int			get_row_column(t_list **lst, int *row, int *col);
int			put_map_in_array(t_list **lst, int row, int col);
t_list		*get_first_line_map(t_list **lst);
int			skip_space(char *str);
int			line_is_map(char *line);
int			get_size_node(t_list *lst);
int			**alloc_memory(int row, int col);
int			**copy_map_grid(int map_row, int map_col);
int			check_copy_map_element_into_array(t_list *map_lst,
			int row, int col);
char		check_valid_element(char c);
int			check_if_map_close(t_info *info);
int			flood_fill(int **map_copy, int row, int col);
void		get_player_position(t_info *info, int row, int col);
int			init_mlx(void);
void		setup_player(t_info *info);
void		setup_global(void);
void		put_wall_texture_into_array(void);
int			init_texture(void);
void		init_g_wall_texture(void);
float		get_rotation_angle(double angle);
int			setup_sprite(void);
int			count_sprite(int **map);
int			init_sprite(void);
void		get_position_sprite(t_sprite *sprite, int **map);
int			ft_mallocsprite(t_sprite *sprite);
int			init_window(t_info *info);
int			init_image(void);
void		draw_mini_map(void);
void		draw_map(int x, int y);
void		draw_grid_wall(int x, int y, int x1, int y1);
void		draw_grid_space(int x, int y, int x1, int y1);
void		draw_grid_player(int x, int y, int x1, int y1);
void		draw_grid_sprite(int x, int y, int x1, int y1);
void		game_loop(t_info *info);
int			create_one_frame(t_info *info);
int			close_window(int key_code, t_info *info);
int			key_release(int key_code);
int			key_pressed(int key_code, t_info *info);
void		draw_ceiling(void);
void		draw_floor(void);
void		draw_sprite(void);
void		draw_player(void);
void		draw_rotation_line(void);
void		draw_line(int cor_y, int cor_x);
void		move_player(void);
int			has_wall_at(float x, float y);
void		cast_rays(void);
void		cast_one_ray(float ray_angle, int strip_id);
void		render_ray(int column_id);
void		draw_wall_strip_with_texture(t_wall *wall, int column_id);
int			choice_of_texture(void);
void		find_smallest_distance(void);
void		the_smallest_of_the_distances_utile(float vert_hit_distance,
			float horz_hit_distance);
float		distance_between_points(float x1, float y1, float x2, float y2);
void		init_ray();
void		find_vert_intercept(t_ray *ray, t_player *player);
void		get_first_vert_intercept(t_ray *ray, t_player *player);
void		get_last_vert_intercept(float next_y, float next_x);
void		get_last_horz_intercept(float next_y, float next_x);
void 		get_first_horz_intercept(t_ray *ray, t_player *player);
void		find_horz_intercept(t_ray *ray, t_player *player);
void		find_where_ray_face();
float		normalize_angle(float angle);
void		get_bmp(char *file_name);
void		write_file(int fd, int imagesize);
void		write_header(int fd, t_bmp_file info_bmp_file);
void		create_header(t_bmp_file *info_bmp_file);
int			create_file(char *file_name);
void		put_sprite(void);
void		ft_getstart(t_sprite *sprite, float sprite_size, float transformy);
void		render_sprite(t_sprite *sprite, float transformy,
			float sprite_size);
void		ft_puttexture(t_sprite *sprite, int x, int y, float sprite_size);
int			is_sprite_visible(int id, float sprite_size);
float		calculate_relative_sprite_angle(t_player *player, float x, float y);
void		get_sprite_distance_to_player(void);
void		sort_sprite_distance(void);
void		switch_sprite(t_sprite *sprite, int i, int j);
void		put_elements_in_sprite_to_zero(void);
void		init_vecteur_north(t_sprite *sprite);
void		get_position_sprite(t_sprite *sprite, int **map);
void		init_vecteur(t_sprite *sprite, char player_position);
void 		get_first_horz_intercept(t_ray *ray, t_player *player);
void		get_last_horz_intercept(float next_y, float next_x);
void		update_position(float x, float y);
int			player_orientation_angle(float angle);
void		update_sprite(void);
void		update_player_position(float x, float y);
float		make_sense_angle(float angle);
float		get_transform_x(int id);
float		get_transform_y(int id);
float		calculate_relative_sprite_angle(t_player *player, float x, float y);



#endif
